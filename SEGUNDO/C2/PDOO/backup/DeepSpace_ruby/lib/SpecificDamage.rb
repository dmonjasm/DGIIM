# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'Damage'
require_relative 'SpecificDamageToUI'
require_relative 'WeaponType'

module Deepspace
class SpecificDamage < Damage
  def initialize(array,s)
    super(s)
    @weapons=array
  end
  
  def copy(otro)
    new(otro.weapons,otro.s)
  end
  
  def weapons
    return @weapons
  end
  
  def adjust(w,s)
    laser_1=0
    laser_2=0
    plasma_1=0
    plasma_2=0
    missile_1=0
    missile_2=0
    
    for i in w
      if(i.type == WeaponType::LASER)
        laser_1+=1
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
        laser_2+=1
      end
      
      if(i == WeaponType::PLASMA)
        plasma_2 += 1
      end
      
      if(i == WeaponType::MISSILE)
        missile_2 += 1
      end
    end
    
    laser_1=[laser_1,laser_2].min
    plasma_1=[plasma_1,plasma_2].min
    missile_1=[missile_1,missile_2].min
    
    array_tipos = Array.new
    tamanio =(laser_1+plasma_1+missile_1)
    
    for i in 0...tamanio
      if(laser_1 > 0)
        array_tipos.push(WeaponType::LASER)
        laser_1-=1
        
      else
        
        if(plasma_1 > 0)
          array_tipos.push(WeaponType::PLASMA)
          plasma_1 -= 1
          
        else
          array_tipos.push(WeaponType::MISSILE)
        end
        
      end
      
    end
    
    return SpecificDamage.new(array_tipos,[@nShields,s.size].min)
  end
  
  def discardWeapon(w)
    for i in @weapons
      if(w.type == @weapons.at(i))
        @weapons.delete_at(i)
      end
    end
  end
  
  def getUIversion
    return SpecificDamageToUI.new(self)
  end
  
  def hasNoEffect
    if(super && @weapons.length == 0)
      return true
      
    else
      return false
    end
  end
  
  public_class_method :new
end

end
