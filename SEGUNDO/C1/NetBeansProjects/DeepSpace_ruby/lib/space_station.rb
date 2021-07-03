# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'damage'
require_relative 'shield_booster'
require_relative 'hangar'
require_relative 'weapon'
require_relative 'weapon_type'

module Deepspace
class SpaceStation
  @@MAXFUEL=100
  @@SHIELDLOSSPERUNITSHOT=0.1
  
  def initialize(ammoPower,fuelUnits,name,nMedals,shieldPower,weapons,shieldBoosters,hangars,pendingDamage)
    @ammoPower=ammoPower
    @fuelUnits=fuelUnits
    @name=name
    @nMedals=nMedals
    @shieldPower=shieldPower
    @weapons=weapons
    @shieldBoosters=shieldBoosters
    @hangars=hangars
    @pendingDamage=pendingDamage
  end
  
  def assignFuelValue(f)
    if(f < @@MAXFUEL)
      @fuelUnits=f
    
    else
      @fuelUnits=@@MAXFUEL   
    end
    
  end
  
  def cleanPendingDamage
    if(@pendingDamage != nil)
      @pendingDamage = @pendingDamage.adjust(@weapons, @shieldBoosters)
      
      if(@pendingDamage.hasNoEffect)
        @pendingDamage = nil
      end
    end
    
  end
  
  def self.SpaceStation(n,supplies)
    new(supplies.ammoPower, supplies.fuelUnits, n, supplies.shieldPower, nil, nil, nil, nil)
  end
  
  def cleanUpMountedItems
    i=0
    
    if(@weapons != nil)
      while i < @weapons.length
        if(@weapons.at(i).uses == 0)
          @weapons.delete_at(i)
      
        else
          i+=1
        end    
      end
    end
    
    i=0
    
    if(@shieldBoosters != nil)
      while i < @shieldBoosters.length
        if(@shieldBoosters.at(i).uses == 0)
          @shieldBoosters.delete_at(i)
        
        else
          i+=1
        end
      end
    end
    
  end
  
  def discardHangar
    @hangars=nil
  end
  
  def discardShieldBooster(i)
    
  end
  
  def discardShieldBoosterInHangar(i)
    if(@hangars != nil)
      @hangars.removeShieldBoosters(i)
    end
  end
  
  def discardWeapon(i)
    
  end
  
  def discardWeaponInHangar(i)
    if(@hangars != nil)
      @hangars.removeWeapon(i)
    end
    
  end
  
  def fire
    
  end
  
  def getAmmoPower
    @AmmoPower
  end
  
  def getFuelUnits
    @fuelUnits
  end
  
  def getHangar
    if(@hangars != nil)
      Hangar.new(@hangars)
      
    else
      0
    end
  end
  
  def getName
    @name
    
  end
  
  def getNMedals
    @NMedals
  end
  
  def getPendingDamage
    if(@pendingDamage != nil)
      Damage.new(@pendingDamage)
      
    else
      0
    end
  end
  
  def getShieldBoosters
    Array.new(@shieldBoosters)
  end
  
  def getShieldPower
    @shieldPower
  end
  
  def getSpeed
    return (@fuelUnits/@@MAXFUEL)
    
  end
  
  def getUIVersion
    new(self)
  end
  
  def getWeapons
    Array.new(@weapons)
  end
  
  def mountShieldBooster(i)
    if(@hangars != nil)
      escudo=@hangars.removeShieldBoosters(i)
      
      if(escudo != nil)
        if(@shieldBoosters != nil)
          @shieldBoosters.push(escudo)
        
        else
          @shieldBoosters=Array.new
          @shieldBoosters.push(escudo)
        end
      end  
      
    end
  end
  
  def mountWeapon(i)
    if(@hangars != nil)
      arma=@hangars.removeWeapon(i)
      
      if(arma != nil)
        if(@weapons != nil)
          @weapons.push(arma)
          
        else
          @weapons=Array.new 
          @weapons.push(arma)
        end
      end  
    end 
  end
  
  def move
    @fuelUnits -= getSpeed * @fuelUnits
  end
  
  def protection
    
  end
  
  def receiveHangar(h)
    if(@hangars == nil)
      @hangars=h
    end
  end
  
  def receiveShieldBooster(s)
    if(@hangars != nil)
      @hangars.addShieldBoosters(s)
    
    else
      false
    end
  end
  
  def receiveShot(shot)
    
  end
  
  def receiveSupplies(s)
    @ammoPower+=s.ammoPower
    @shieldPower += s.shieldPower
    
    if(@fuelUnits + s.fuelUnits < @@MAXFUEL)
      @fuelUnits += s.fuelUnits
    
    else
      @fuelUnits = @@MAXFUEL
    end
  end
  
  def receiveWeapon(w)
    if(@hangars != nil)
      @hangars.addWeapon(w)
      
    else
      false
    end
    
  end
  
  def setLoot(loot)
    
  end
  
  def setPendingDamage(d)
    @pendingDamage=d.adjust(@weapons,@shieldBoosters)    
  end
  
  def validState
    if(@pendingDamage == nil || @pendingDamage.hasNoEffect)
      return true
    
    else
      return false
    end
  end
  
  private :assignFuelValue, :cleanPendingDamage
  
  def to_s
    salida = "Combustible máximo: #{@@MAXFUEL}\nEscudo perdido/disparo: #{@@SHIELDLOSSPERUNITSHOT}\nPotencia de fuego: #{@ammoPower}\n"
    salida = salida + "Nombre : #{@name}\nNº Medallas: #{@nMedals}\nPoder de Escudo: #{@shieldPower}\n"
    
    if(@weapons != nil)
      salida=salida + "\nArmas:\n" +@weapons.join("\n")
    end
    
    if(@shieldBoosters != nil)
      salida=salida + "\nEscudos:\n" + @shieldBoosters.join("\n")
    end
    
    if(@hangars != nil)
      salida=salida + "\nHangar:\n" + @hangars.to_s
    end
    
    if(@pendingDamage != nil)
      salida=salida + "\nDaño Pendiente:\n" + @pendingDamage.to_s
    end
  end
  def self.main
    armas=Array.new
    escudos=Array.new
    
    i=0
    
    while i < 5
      armas.push(Weapon.new("Canon de Hugos", WeaponType::LASER, 20))
      escudos.push(ShieldBooster.new("Escudo de Titanio", 10, 5))
      
      i+=1
    end
    
    hangar_milindron=Hangar.new(100)
    
    hangar_milindron.addWeapon(armas.at(1))
    hangar_milindron.addShieldBoosters(escudos.at(3))
    
    puts "Hangar_milindron"
    hangar_milindron.to_s
    
    armas_2=Array.new
    armas_2.push(WeaponType::LASER)
    armas_2.push(WeaponType::PLASMA)
    
    dano=Damage.new(-1,10,armas_2)
    
    
    estacion=SpaceStation.new(10, 10, "Estacion_milindrona", 10, 10, armas, escudos, hangar_milindron, dano)
    
    estacion.to_s
    
    estacion.setPendingDamage(dano)
    
    estacion.to_s  
  end
  
  def self.main2
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
    
    objeto=SpaceStation.new(10,11,"yo",13,14,armas,escudos,hangar,pendingDamage)
    
    puts objeto.to_s
    
    objeto.setPendingDamage(pendingDamage)
    
    puts objeto.to_s
    
  end

  #SpaceStation.main2
end
end

