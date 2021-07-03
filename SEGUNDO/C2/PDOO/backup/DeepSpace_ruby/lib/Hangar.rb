# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'HangarToUI'
require_relative 'Weapon'
require_relative 'ShieldBooster'
require_relative 'WeaponType'

module Deepspace
class Hangar
  def initialize(capacity)
    @maxElements=capacity
    @weapons=Array.new
    @shieldBoosters=Array.new
  end
  
  def self.newCopy(h)
    new(h.maxElements)
  end
  
  def getUIversion
    return HangarToUI.new(self)
  end
  
  def spaceAvailable
    return ((@weapons.length + @shieldBoosters.length) < @maxElements)
    
  end
  
  def addWeapon(w)
    salida=spaceAvailable
    
    if(salida)
      @weapons.push(w)
    end
    
    return salida    
  end
  
  def addShieldBoosters(s)
    salida=spaceAvailable
    
    if(salida)
      @shieldBoosters.push(s)
    end
    
    return salida    
  end
  
  def maxElements
    @maxElements
  end
  
  def shieldBoosters
    @shieldBoosters
  end
  
  def weapons
    @weapons
  end
  
  def removeShieldBoosters(s)
    return @shieldBoosters.delete_at(s)
    
  end
  
  def removeWeapon(w)
    return @weapons.delete_at(w)
  end
  
  def to_s
    salida="Elementos: #{@maxElements}\n"
    
    if(@weapons != nil)
      salida=salida + @weapons.join("\n")
    end
    
    if(@shieldBoosters != nil)
      salida=salida+ "\n" + @shieldBoosters.join("\n")
    end
    
    return salida
    
  end
  
  private :spaceAvailable
end

end
