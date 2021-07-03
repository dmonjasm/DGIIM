# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'EnemyToUI'
require_relative 'ShotResult'
require_relative 'Damage'
require_relative 'Loot'
require_relative 'WeaponType'

module Deepspace
class EnemyStarShip
  def initialize(n,a,s,l,d)
    @ammoPower=a
    @name=n
    @shieldPower=s
    @damage=d
    @loot=l
  end
  
  def self.newCopy(e)
    new(e.name,e.ammoPower,e.shieldPower,e.loot,e.damage)
    
  end
  
  def getUIversion
    return EnemyToUI.new(self)
  end
  
  def fire
    @ammoPower
  end
  
  def ammoPower
    @ammoPower
  end
  
  def damage
    @damage
  end
  
  def loot
    @loot
  end
  
  def name
    @name
  end
  
  def shieldPower
    @shieldPower
  end
  
  def protection
    @shieldPower
  end
  
  def receiveShot(shot)
    if(@shieldPower < shot)
      return ShotResult::DONOTRESIST
      
    else
      return ShotResult::RESIST
    end
  end
  
  def to_s
    salida="Potencia de fuego: #{@ammoPower}\nNombre: #{@name}\nPotencia de escudo: #{@shieldPower}\nDamage: \n#{@damage.to_s}Loot: #{@loot.to_s}"
  end
  
  def self.main
    array_armas=Array.new
    
    i=0
    
    while i < 10
      if(i < 5)
        array_armas.push(WeaponType::LASER)
      
      else
        array_armas.push(WeaponType::PLASMA)
      end
      
      i+=1
    end 
    
    nave=EnemyStarShip.new(10,"Hugo",14,Damage.new(5,5,array_armas), Loot.new(100,100,30,40,34))
    
    nave.to_s
    
    resultado=nave.receiveShot(16)
    
    if(resultado==ShotResult::DONOTRESIST)
      puts "Nave derribada"
    
    else
      puts "Nave Danada"
    end
    
    resultado=nave.receiveShot(7)
    
    if(resultado==ShotResult::DONOTRESIST)
      puts "Nave derribada"
    
    else
      puts "Nave Danada"
    end
    
  end
  
  def self.main2
    objeto=EnemyStarShip.new(10,"Hugo", 10, Damage.newNumericWeapons(200,34),Loot.new(10,11,12,13,14))
    
    puts objeto.to_s
  end
  
  #EnemyStarShip.main2
  
end
end
