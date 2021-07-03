# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
module Deepspace
  
class SuppliesPackage
  attr_reader :ammoPower, :fuelUnits, :shieldPower
  
  def initialize(ammoPower,fuelUnits,shieldPower)
    @ammoPower = ammoPower
    @fuelUnits = fuelUnits
    @shieldPower = shieldPower    
  end
  
  def self.newCopy(copia)
    new(copia.ammoPower, copia.fuelUnits,copia.shieldPower)
  end
  
  def to_s
    return "Poder de Municion: #{@ammoPower}\nUnidades de Combustible: #{@fuelUnits}\nPoder de Escudo: #{@shieldPower}\n"
  end

end

end
