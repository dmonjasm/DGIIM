# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'DamageToUI'
require_relative 'WeaponType'
require_relative 'Weapon'
require_relative 'ShieldBooster'


module Deepspace
class Damage
  def initialize(w,s,array)
    @nShields=s
    @nWeapons=w
    @weapons=array
  end
  
  def self.newNumericWeapons(w, s)
    new(w,s,nil)   
  end
  
  def self.newSpecificWeapons(wl,s)
    new(-1,s,wl)
  end
  
  def self.newCopy(d)
    if(d.weapons != nil)
      newSpecificWeapons(d.weapons, d.nShields)
      
    else
      newNumericWeapons(d.nWeapons,d.nShields)
    end  
  end
  
  def getUIversion
    return DamageToUI.new(self)
  end
  
  def arrayContainsType(w,t)
    i=0
    encontrado=false
    
    while i < w.length && !encontrado
      if(w.at(i).type == t)
        encontrado=true
       
      else
        i += 1
      end
    end
    
    if(encontrado)
      return (i)
    else
      return -1
    end
    
  end 
  
  def adjust(w,s)
    nShields=[@nShields,s.length].min
    
    if(@weapons == nil)
      nWeapons=[@nWeapons, w.length].min
      
      return Damage.newNumericWeapons(nWeapons, nShields)
      
    else
      laser_1=0
      plasma_1=0
      missile_1=0
      laser_2=0
      plasma_2=0
      missile_2=0
      
      i=0
      
      while i < w.length
        if(w.at(i).type == WeaponType::LASER)
          laser_1+=1
        end 
        
        if(w.at(i).type == WeaponType::PLASMA)
          plasma_1+=1
        end
        
        if(w.at(i).type == WeaponType::MISSILE)
          missile_1+=1
        end
        
        i+=1
      end
      
      i=0
      
      while i < @weapons.length
        if(@weapons.at(i) == WeaponType::LASER)
          laser_2+=1
        end 
        
        if(@weapons.at(i) == WeaponType::PLASMA)
          plasma_2+=1
        end 
        
        if(@weapons.at(i)== WeaponType::MISSILE)
          missile_2+=1
        end
        
        i+=1
      end
      
      laser_1=[laser_1,laser_2].min
      plasma_1=[plasma_1, plasma_2].min
      missile_1=[missile_1, missile_2].min 
      
      tipos_armas=Array.new
      if((laser_1+plasma_1+missile_1) <= 0)
        return Damage.newSpecificWeapons(tipos_armas,nShields)
        
      else
        i=0
        nWeapons=laser_1+plasma_1+missile_1
        
        while i < nWeapons
          if(laser_1 != 0)
            tipos_armas.push(WeaponType::LASER)
            laser_1+= -1
          elsif(plasma_1 != 0)
            tipos_armas.push(WeaponType::PLASMA)
            plasma_1 += -1
          else
            tipos_armas.push(WeaponType::MISSILE)
            
          end
          
          i+=1
        end
        
        return Damage.newSpecificWeapons(tipos_armas,nShields)
      end
    end  
  end
  
  def discardWeapon(w)
    i = 0
    
    if(@weapons != nil)
      while i < @weapons.length
        if(@weapons.at(i) == w.type)
          @weapons.delete_at(i)
        end
      
        i += 1 
      end
    
    else
      if(@nWeapons > 0)
        @nWeapons += -1
      end
    end
    
  end
  
  def discardShieldBooster
    if(@nShields > 0)
      @nShields += -1
    end
  end
  
  def hasNoEffect
    if(@weapons == nil)
      if(@nShields == 0 && @nWeapons == 0)
        return true
      
      else
        return false
      end
    
    else
      if(@nShields == 0 && @weapons.length == 0)
        return true
      
      else
        return false
      end
    end
    
  end
  
  def nShields
    @nShields
  end
  
  def nWeapons
    @nWeapons
  end
  
  def weapons
    return @weapons
  end
  
  def to_s
    salida="N escudos: #{@nShields}\nN Armas: #{@nWeapons}\n"
    
    if(@weapons != nil)
      salida = salida + @weapons.join("\n")
    end
    
    return salida
  end 
  
  private :arrayContainsType
end

end
