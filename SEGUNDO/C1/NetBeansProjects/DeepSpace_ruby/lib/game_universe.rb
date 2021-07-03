# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'space_station'
require_relative 'GameStateController'
require_relative 'dice'
require_relative 'enemy_star_ship'
require_relative 'GameState'

module Deepspace
class GameUniverse
  @@WIN=10
  
  def initialize(currentStationIndex,turns,currentStation,dice,gameState,currentEnemy)
    @currentStationIndex=currentStationIndex
    @turns=turns   
    @currentStation=currentStation
    @spaceStations=Array.new
    @dice=dice
    @gameState=gameState
    @currentEnemy=currentEnemy
  end
  
  def GameUniverse
    
  end
  
  def self.combat(station,enemy)
    
  end 
  
  def combat
    
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
      @currentStation.discardWeaponsInHangar(i)
    end
  end
  
  def getState
    @gameState.state
  end
  
  def getUIVersion
    new(self)
  end
  
  def haveAWinner
    if(@spaceStations != nil)
      if(@spaceStations.at(currentStationIndex).nMedals == @@WIN)
        true
      
      else
        false
      end
      
    else
      false
    end
    
  end
  
  def init(names)
    
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
    
  end
  
  def to_s
    salida="CurrentStationIndex: #{@currentStationIndex}\nTurnos: #{@turns}\nCurrentStation: #{@currentStation.to_s}\nDice: #{@dice.to_s}\n"
    
    if(@gameState==GameState::INIT)
      salida=salida +"Estado: iniciando\n" 
    elsif(@gameState==GameState::AFTERCOMBAT)
      salida=salida + "Estado: aftercombat\n"
    elsif(@gameState==GameState::BEFORECOMBAT)
      salida=salida + "Estado: beforecombat\n"
    else
      salida=salida + "Estado: cannotplay\n"
    end
    
    salida= salida + "Enemigo Actual: #{@currentEnemy.to_s}\n"
  end
  
  def self.main
    i=0
    armas=Array.new
    escudos=Array.new
    hangar=Hangar.new(10)
    pendingDamage=Damage.newNumericWeapons(10,20)
    
    while i < 10
      armas.push(Weapon.new("Canon", WeaponType::LASER, 20))
      escudos.push(ShieldBooster.new("escudo", 10, 12))
      
      i+=1
    end
    
    3.times { hangar.addShieldBoosters(escudos.at(1))  }
    2.times { hangar.addWeapon(armas.at(1))  }
    
    estacion=SpaceStation.new(10,11,"yo",13,14,armas,escudos,hangar,pendingDamage)
    dado=Dice.new
    
    
    objeto=GameUniverse.new(1,100,estacion,dado,GameState::INIT, EnemyStarShip.new(10,"Hugo", 10, Damage.newNumericWeapons(200,34),Loot.new(10,11,12,13,14)))
    
    puts objeto.to_s
  end
  
  #GameUniverse.main
  
end
end
