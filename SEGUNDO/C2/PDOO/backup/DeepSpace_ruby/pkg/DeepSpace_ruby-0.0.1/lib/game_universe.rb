# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'SpaceStation'
require_relative 'GameStateController'
require_relative 'Dice'
require_relative 'EnemyStarShip'
require_relative 'GameState'
require_relative 'GameUniverseToUI'
require_relative 'CombatResult'
require_relative 'CardDealer'
require_relative 'ShotResult'
require_relative 'GameCharacter'

module Deepspace
class GameUniverse
  @@WIN=10
  
  def initialize()
    @currentStationIndex=0
    @turns=0
    @currentStation=nil
    @spaceStations=Array.new
    @dice=Dice.new
    @gameState=GameStateController.new
    @currentEnemy=nil
  end
  
  def combatGo(station,enemy)
    ch=@dice.firstShot
      
      if(ch == GameCharacter::ENEMYSTARSHIP)
        fire = @currentEnemy.fire
        result = @currentStation.receiveShot(fire)
        
        if(result == ShotResult::RESIST)
          fire = @currentStation.fire
          
          result = @currentEnemy.receiveShot(fire)
          
          enemyWins =(result == ShotResult::RESIST)
          
        else
          enemyWins=true
        end
      
      else
        fire = @currentStation.fire
        result = @currentEnemy.receiveShot(fire)
        
        enemyWins=(result==ShotResult::RESIST)
      end
      
      if(enemyWins)
        s=@currentStation.getSpeed
        
        moves = @dice.spaceStationMoves(s)
        
        if(!moves)
          damage = @currentEnemy.damage
          
          @currentStation.setPendingDamage(damage)
          
          combatResult=CombatResult::ENEMYWINS
          
        else
          @currentStation.move
          combatResult=CombatResult::STATIONESCAPES
        end
        
      else
        aLoot = @currentEnemy.loot
        
        @currentStation.setLoot(aLoot)
        
        combatResult=CombatResult::STATIONWINS
      end
      
      @gameState.next(@turns,@spaceStations.length)
      
      return combatResult
  end 
  
  def combat
    state=@gameState.state
    
    if(state == GameState::BEFORECOMBAT || state == GameState::INIT)
      return self.combatGo(@currentStation,@currentEnemy)
      
    else
      return CombatResult::NOCOMBAT
    end 
    
  end
  
  def discardHangar
    if(@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
      @currentStation.discardHangar
    end
  end
  
  def discardShieldBooster(i)
    if(@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
      @currentStation.discardShieldBooster(i)
    end
  end
  
  def discardShieldBoosterInHangar(i)
    if(@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
      @currentStation.discardShieldBoosterInHangar(i)
    end
  end
  
  def discardWeapon(i)
    if(@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
      @currentStation.discardWeapon(i)
    end
  end
  
  def discardWeaponInHangar(i)
    if(@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
      @currentStation.discardWeaponInHangar(i)
    end
  end
  
  def state
    if(@gameState.state == GameState::INIT)
        return GameState::INIT
      else if(@gameState.state == GameState::CANNOTPLAY)
          return GameState::CANNOTPLAY
      else if(@gameState.state == GameState::BEFORECOMBAT)
          return GameState::BEFORECOMBAT
      else
        return GameState::AFTERCOMBAT
      end
    end
    end
  end
  
  def getUIversion
    return GameUniverseToUI.new(@currentStation,@currentEnemy)
  end
  
  def haveAWinner
    if(@currentStation.nMedals == @@WIN)
      true
      
    else
      false
    end    
  end
  
  def init(names)
    state=@gameState.state
    
    if(state == GameState::CANNOTPLAY)
      @spaceStations=Array.new
      
      dealer=CardDealer.instance
      
      for i in 0..(names.length-1)
        supplies = dealer.nextSuppliesPackage
        station = SpaceStation.new(names.at(i), supplies)
        
        @spaceStations.push(station)
        
        nh = @dice.initWithNHangars
        nw = @dice.initWithNWeapons
        ns = @dice.initWithNShields
        
        lo = Loot.new(0,nw,ns,nh,0)
        
        station.setLoot(lo)
      end
      
      @currentStationIndex = @dice.whoStarts(names.length)
      
      @currentStation = @spaceStations.at(@currentStationIndex)
      
      @currentEnemy = dealer.nextEnemy
      
      @gameState.next(@turns, @spaceStations.length)
    end
  end
  
  def mountShieldBooster(i)
    if(@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
      @currentStation.mountShieldBooster(i)
    end
  end
  
  def mountWeapon(i)
    if(@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
      @currentStation.mountWeapon(i)
    end
  end
  
  def nextTurn
    state=@gameState.state
    
    if(state==GameState::AFTERCOMBAT)
      stationState=@currentStation.validState
      
      if(stationState)
        @currentStationIndex=(@currentStationIndex + 1)%@spaceStations.length
        @turns += 1
        
        @currentStation=@spaceStations.at(@currentStationIndex)
        
        @currentStation.cleanUpMountedItems
        
        dealer=CardDealer.instance
        
        @currentEnemy=dealer.nextEnemy
        
        @gameState.next(@turns,@spaceStations.length)
        
        return true
      end
      
      return false
    end
    
    return false
  end
  
  def to_s
    salida="CurrentStationIndex: #{@currentStationIndex}\nTurnos: #{@turns}\nCurrentStation: #{@currentStation.to_s}\nDice: #{@dice.to_s}\n"
    
    if(@gameState.state==GameState::INIT)
      salida=salida +"Estado: iniciando\n" 
    elsif(@gameState.state==GameState::AFTERCOMBAT)
      salida=salida + "Estado: aftercombat\n"
    elsif(@gameState.state==GameState::BEFORECOMBAT)
      salida=salida + "Estado: beforecombat\n"
    else
      salida=salida + "Estado: cannotplay\n"
    end
    
    salida= salida + "Enemigo Actual: #{@currentEnemy.to_s}\n"
  end
  
end
end
