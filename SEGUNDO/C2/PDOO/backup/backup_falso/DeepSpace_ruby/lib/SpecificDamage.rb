# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'WeaponType'
require_relative 'ShieldBooster'
require_relative 'SpecificDamageToUI'
require_relative 'Weapon'

module Deepspace
class SpecificDamage < Damage
  def initialize(wl,s)
    @weapons=wl
    super(s)
  end
  
  def copy
    new(@weapons,@nShields)
  end
  
  def hasNoEffect
    if(super && @weapons == nil)
      return true
    else
      return false
    end
  end
  
  def weapons
    return @weapons
  end
  
  def discardWeapon(w)
    for i in @weapons
      if(i == w.type)
        @weapons.delete_at(i)
      end
    end
  end
  
  def adjust(w,s)
    super(s)
    
    laser_1=0
    laser_2=0
    plasma_1=0
    plasma_2=0
    missile_1=0
    missile_2=0
    
    for i in w
      if(i.type == WeaponType::LASER)
        laser_1 += 1
      end
      
      if(i.type == WeaponType::PLASMA)
        plasma_1 += 1
      end
      
      if(i.type == WeaponType::MISSILE)
        missile_1 += 1
      end
    end
    
    for i in @weapons
      if(i == WeaponType::LASER)
        laser_2 += 1
      end
      
      if(i == WeaponType::PLASMA)
        plasma_2 += 1
      end
      
      if(i == WeaponType::MISSILE)
        missile_2 += 1
      end
      
      laser_1=[laser_1,laser_2].min
      plasma_1=[plasma_1,plasma_2].min
      missile_1=[missile_1,missile_2].min
      
      array_tipos=Array.new
      tamano=laser_1+plasma_1+missile_1
      
      i=0
      
      while i < tamano
        if(laser_1 > 0)
          array_tipos.push(WeaponType::LASER)
          laser_1 -= 1
        end
        
        if(plasma_1 > 0)
          array_tipos.push(WeaponType::PLASMA)
          plasma_1 -= 1
        end
        
        if(missile_1 > 0)
          array_tipos.push(WeaponType::MISSILE)
          missile_1 -= 1
        end
      end
      
      return new(array_tipos,@nShields)
    end
    
    def getUIversion
      return SpecificDamageToUI.new(self)
    end
  end
end

end
