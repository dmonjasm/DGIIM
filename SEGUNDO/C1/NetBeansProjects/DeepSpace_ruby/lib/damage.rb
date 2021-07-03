# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'DamageToUI'
require_relative 'weapon_type'
require_relative 'weapon'
require_relative 'shield_booster'


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
    new(-1,s,Array.new(wl))
  end
  
  def self.newCopy(d)
    new(d.nShields,d.nWeapons,d.weapons)    
  end
  
  def getUIVersion
    new(self)
  end
  
  def arrayContainsType(w,t)
    i=0
    encontrado=false
    
    while i < w.length && !encontrado
      if(w.at(i).type == t)
        encontrado=true
      end
      
      i+=1
    end
    
    if(encontrado)
      return (i-1)
    else
      return -1
    end
    
  end 
  
  def adjust(w,s)
    nShields=[@nShields,s.length].min
    
    if(@weapons == nil)
      nWeapons=[@nWeapons, w.length].min
      
      return Damage.newNumericWeapons(nShields, nWeapons)
      
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
      if((laser_1+plasma_1+missile_1) == 0)
        tipos_armas=Array.new
        nWeapons=0
      
      else
        i=0
        nWeapons=laser_1+plasma_1+missile_1
        
        while i < (nWeapons)
          if(laser_1 != 0)
            tipos_armas.push(WeaponType::LASER)
            laser_1+=-1
          elsif(plasma_1 != 0)
            tipos_armas.push(WeaponType::PLASMA)
            plasma_1+=-1
          else
            tipos_armas.push(WeaponType::MISSILE)
            
          end
          
          i+=1
        end 
      end
      
      return Damage.newSpecificWeapons(Array.new(tipos_armas),nShields)
    end
    
  end
  
  def discardWeapon(w)
    i = 0
    encontrado=false
    
    while i < @weapons.length
      if(@weapons.at(i).type == w.type)
        @weapons.delete_at(i)
        encontrado=true
      end
      
      i += 1 
    end
    
    if((!encontrado) && (@nWeapons > 0))
      @nWeapons -= 1      
    end
  end
  
  def discardShieldBooster
    if((@nShields - 1) > 0)
      @nShields-=1
    end
  end
  
  def hasNoEffect
    if((@nShields==0 && @nWeapons==0)&&(@weapons.length==0))
      return true
    
    else
      return false
    end
    
  end
  
  def nShields
    @nShields
  end
  
  def nWeapons
    @nWeapons
  end
  
  def weapons
    @weapons
  end
  
  def to_s
    salida="Nº escudos: #{@nShields}\nNº Armas: #{@nWeapons}\n"
    
    if(@weapons != nil)
      salida = salida + @weapons.join("\n")
    end
    
    return salida
  end
  
  def self.main
    i=0
    
    arma=Weapon.new("Canon de Hadrones", WeaponType::LASER, 20)
    array_armas=Array.new
    
    for i in 0..9
      array_armas.push(arma)
    end
    
    prueba_1=Damage.new(10,10,Array.new(array_armas))
    
    puts "Numero de Escudos: " + prueba_1.nShields.to_s
    puts "Numero de Armas: " + prueba_1.nWeapons.to_s
    
    i=0
    
    for i in (0..prueba_1.weapons.length-1)
      puts prueba_1.weapons.at(i).to_s
    end
    
    prueba_1.discardWeapon(arma)
    
    puts "Numero de Escudos: " + prueba_1.nShields.to_s
    puts "Numero de Armas: " + prueba_1.nWeapons.to_s
    
    if(prueba_1.weapons.length == 0)
      puts "Se han descartado todas las armas"
    end
    
    3.times {prueba_1.discardShieldBooster}
    
    puts "Numero de Escudos: " + prueba_1.nShields.to_s
    puts "Numero de Armas: " + prueba_1.nWeapons.to_s
    
    prueba_2=Damage.new(0,0,Array.new)
    
    if(prueba_2.hasNoEffect)
      puts "\nNo tiene efecto"
      
    else
      puts "\nTiene efecto"
    end
    
    if(!prueba_1.hasNoEffect)
      puts "\nTiene efecto"
    end
    
    arma=Weapon.new("Canon de plasma", WeaponType::LASER, 20)
    array_2=Array.new
    i=1
    
    
    for i in 1..5
      array_2.push(arma)
    end
    
    escudo=ShieldBooster.new("Escudo Titanio", 2.0,20)
    array_3=Array.new
    i=1
    
    for i in 1..5
      array_3.push(escudo)
    end
    
    prueba_1=prueba_1.adjust(array_2, array_3)

    puts "Numero escudos: " + prueba_1.nShields.to_s
    puts "Numero armas: " + prueba_1.nWeapons.to_s
    
    i=0
    
    while i < prueba_1.weapons.length
      puts prueba_1.weapons.at(i).to_s
      i+=1
    end    
  end
  
  def self.main2
      objeto=Damage.newNumericWeapons(20,20)
      
      puts objeto.to_s
      
      array=Array.new
      
      i=0
      
      while i < 10
        array.push(WeaponType::LASER)
        i+=1
      end
      
      objeto=Damage.newSpecificWeapons(array,10)
      
      puts objeto.to_s
    end
  
  #Damage.main2
  
end

end
