# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'HangarToUI'
require_relative 'weapon'
require_relative 'shield_booster'
require_relative 'weapon_type'

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
  
  def getUIVersion
    new(self)
  end
  
  def spaceAvailable
    return (@weapons.length + @shieldBoosters.length) < @maxElements
    
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
  
  def self.main
    i=1
    
    prueba = Hangar.new(10)
    arma=Weapon.new("Canon Hadrones", WeaponType::LASER, 20)
    
    for i in 1..10
      prueba.addWeapon(arma)
    end
    
    puts prueba.to_s 
    
    i=0
    while i < prueba.weapons.length
      if(prueba.removeWeapon(i) == nil)
        i+=1
      end
      
    end
    
    puts "Armas tras el borrado"
    puts prueba.to_s
    
    escudo=ShieldBooster.new("Escudo Titanio", 2.0, 20)
    
    i=1
    
    for i in 1..10
      prueba.addShieldBoosters(escudo)
    end
    
    puts prueba.to_s
    
    i=0
    
    while i < prueba.shieldBoosters.length
      if(prueba.removeShieldBoosters(i)== nil)
        i+=1
      end
      
    end
    
    puts "Escudos tras el borrado"
    puts prueba.to_s 
    
    prueba_2=Hangar.newCopy(prueba)
    
    puts "Copia: "
    puts prueba_2.to_s
  
  end
  
  def self.main2
    i=0
    objeto=Hangar.new(10)
    while i < 10
      objeto.addShieldBoosters(ShieldBooster.new("escudo",10, 10))
      objeto.addWeapon(Weapon.new("Canon", WeaponType::LASER, 20))
      
      i+=1
    end
    
    puts objeto.to_s
    
  end
  
  #Hangar.main2
end

end
