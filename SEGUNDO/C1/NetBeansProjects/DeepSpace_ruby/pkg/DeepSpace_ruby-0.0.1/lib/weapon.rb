# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'weapon_type'
require_relative 'WeaponToUI'

module Deepspace
  
class Weapon
  def initialize(name, type, uses)
    @name = name
    @type = type
    @uses = uses
  end
  
  def self.newCopy(copia)
    new(copia.name, copia.type, copia.uses)
  end
  
  attr_reader  :uses
  
  def power
    @type.power
  end
  
  def type 
    if(@type == WeaponType::LASER)
      WeaponType::LASER
    elsif (@type == WeaponType::MISSILE)
      WeaponType::MISSILE
    else
      WeaponType::PLASMA
    end
  end
  
  def useIt
    if(@uses > 0)
      @uses -= 1
      return self.power
    else
      return 1.0
    end
  end
  
  def to_s 
    salida="Nombre: #{@name}\t Usos: #{@uses}\t"
    
    if(@type == WeaponType::LASER)
      salida=salida+ " Tipo: LASER"
    elsif(@type == WeaponType::MISSILE)
      salida = salida + " Tipo: MISSILE"
    else
      salida = salida + " Tipo: PLASMA"
    end
    
    return salida
  end
  
  def getUIVersion()
    WeaponToUI.new(self)
  end

end

end
