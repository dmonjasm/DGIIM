# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'Damage'
require_relative 'ShieldBooster'
require_relative 'Hangar'
require_relative 'Weapon'
require_relative 'WeaponType'
require_relative 'ShotResult'
require_relative 'CardDealer'
require_relative 'Loot'
require_relative 'SuppliesPackage'
require_relative 'SpaceStationToUI'
require_relative 'Transformation'

module Deepspace
class SpaceStation < SpaceFighter
  @@MAXFUEL=100
  @@SHIELDLOSSPERUNITSHOT=0.1
  
  def initialize(n,supplies)
    @fuelUnits=supplies.fuelUnits
    @nMedals=0
    @weapons=Array.new
    @shieldBoosters=Array.new
    @hangar=nil
    @pendingDamage=nil
    super(supplies.ammoPower,n,supplies.shieldPower)
  end
  
  def assignFuelValue(f)
    if(f < @@MAXFUEL)
      @fuelUnits=f
    
    else
      @fuelUnits=@@MAXFUEL   
    end
    
  end
  
  def cleanPendingDamage
    if(@pendingDamage.hasNoEffect)
      @pendingDamage = nil
    end
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
    @hangar=nil
  end
  
  def discardShieldBooster(i)
    size=@shieldBoosters.length
    2
    
    if(i >= 0 && i < size)
      sh=@shieldBoosters.delete_at(i)
      
      if(@pendingDamage != nil)
        @pendingDamage.discardShieldBooster
        cleanPendingDamage
      end
    end
  end
  
  def discardShieldBoosterInHangar(i)
    if(@hangar != nil)
      @hangar.removeShieldBoosters(i)
    end
  end
  
  def discardWeapon(i)
    size=@weapons.length
    
    if(i >= 0 && i < size)
      w=@weapons.delete_at(i)
      
      if(@pendingDamage != nil)
        @pendingDamage.discardWeapon(w)
        cleanPendingDamage
      end
    end
  end
  
  def discardWeaponInHangar(i)
    if(@hangar != nil)
      @hangar.removeWeapon(i)
    end
  end
  
  def fire
    size=@weapons.length
    factor=1
    
    for i in 0..(size-1)
      w=@weapons.at(i)
      factor *= w.useIt
    end 
    
    return super*factor    
  end

  def fuelUnits
    return @fuelUnits
  end
  
  def hangar
    if(@hangar != nil)
      return @hangar
      
    else
      return nil
    end
  end
  
  def nMedals
    return @nMedals
  end
  
  def pendingDamage
    if(@pendingDamage != nil)
      return @pendingDamage
      
    else
      return nil
    end
  end
  
  def shieldBoosters
    Array.new(@shieldBoosters)
  end

  def getSpeed
    return (@fuelUnits/@@MAXFUEL)
    
  end
  
  def getUIversion
    return SpaceStationToUI.new(self)
  end
  
  def weapons
    @weapons
  end
  
  def mountShieldBooster(i)
    if(@hangar != nil)
      escudo=@hangar.removeShieldBoosters(i)
      
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
    if(@hangar != nil)
      arma=@hangar.removeWeapon(i)
      
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
    @fuelUnits += -(self.getSpeed * @fuelUnits)
  end
  
  def protection
    size=@shieldBoosters.length
    factor=1
    
    for i in 0..(size-1)
      s=@shieldBoosters.at(i)
      factor*=s.useIt
    end
    
    return super*factor
  end
  
  def receiveHangar(h)
    if(@hangar == nil)
      @hangar=h
    end
  end
  
  def receiveShieldBooster(s)
    if(@hangar != nil)
      return @hangar.addShieldBoosters(s)
    
    else
      return false
    end
  end
  
  def receiveShot(shot)
    myProtection=protection
    
    if(myProtection >= shot)
      @shieldPower -= @@SHIELDLOSSPERUNITSHOT*shot
      
      if(@shieldPower < 0)
        @shieldPower = 0.0
      end
      
      return ShotResult::RESIST
    
    else
      @shieldPower = 0.0
      return ShotResult::DONOTRESIST
    end
  end
  
  def receiveSupplies(s)
    @ammoPower += s.ammoPower
    @shieldPower += s.shieldPower
    
    if(@fuelUnits + s.fuelUnits <= @@MAXFUEL)
      @fuelUnits += s.fuelUnits
    
    else
      @fuelUnits = @@MAXFUEL
    end
  end
  
  def receiveWeapon(w)
    if(@hangar != nil)
      return @hangar.addWeapon(w)
      
    else
      return false
    end
    
  end
  
  def setLoot(loot)
    dealer=CardDealer.instance
    h=loot.nHangars
    
    if(h > 0)
      @hangar=dealer.nextHangar
      self.receiveHangar(h)
    end
    
    elements=loot.nSupplies
    
    for i in 1..elements
        sup=dealer.nextSuppliesPackage
        self.receiveSupplies(sup)
    end
    
    elements=loot.nWeapons
    
    for i in 1..elements
        weap=dealer.nextWeapon
        self.receiveWeapon(weap)
    end
    
    elements = loot.nShields
    
    for i in 1..elements
      sh=dealer.nextShieldBooster
      self.receiveShieldBooster(sh)
    end
    
    medals = loot.nMedals
    
    @nMedals+=medals
    
    if(loot.efficient)
      return Transformation::GETEFFICIENT
     
    else 
      if(loot.spaceCity)
        return Transformation::SPACECITY
      else
        return Transformation::NOTRANSFORM
    end
    
    end
  end
  
  def setPendingDamage(d)
    @pendingDamage=d.adjust(@weapons,@shieldBoosters) 
    cleanPendingDamage
  end
  
  def validState
    if(@pendingDamage == nil || @pendingDamage.hasNoEffect)
      return true
    
    else
      return false
    end
  end
  
  def to_s
    salida = super
    salida += "Combustible maximo: #{@@MAXFUEL}\nEscudo perdido/disparo: #{@@SHIELDLOSSPERUNITSHOT}\n"
    salida = salida + "N Medallas: #{@nMedals}\n"
    
    if(@weapons != nil)
      salida=salida + "\nArmas:\n" +@weapons.join("\n")
    end
    
    if(@shieldBoosters != nil)
      salida=salida + "\nEscudos:\n" + @shieldBoosters.join("\n")
    end
    
    if(@hangar != nil)
      salida=salida + "\nHangar:\n" + @hangar.to_s
    end
    
    if(@pendingDamage != nil)
      salida=salida + "\nDano Pendiente:\n" + @pendingDamage.to_s
    end
  end
  
  def copy(otraEstacion)
    @fuelUnits = otraEstacion.fuelUnits
    @nMedals = otraEstacion.nMedals
    @weapons=otraEstacion.weapons
    @shieldBoosters=otraEstacion.shieldBoosters
    @hangar=otraEstacion.hangar
    @pendingDamage=otraEstacion.pendingDamage
    super(otraEstacion.ammoPower,otraEstacion.name,otraEstacion.shieldPower)
  end
  
  private :assignFuelValue, :cleanPendingDamage
end
end

