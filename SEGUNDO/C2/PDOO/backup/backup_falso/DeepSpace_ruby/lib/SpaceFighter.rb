# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.


require_relative 'ShotResult'

module Deepspace
  

class SpaceFighter
  def initialize(ammoPower,name,shieldPower)
    @ammoPower=ammoPower
    @name=name
    @shieldPower=shieldPower
  end
  
  def ammoPower
    return @ammoPower
  end
  
  def name
    return @name
  end
  
  def shieldPower
    return @shieldPower
  end
  
  def fire
    return @shieldPower
  end
  
  def protection
    return @shieldPower
  end
  
  def receiveShot(shot)
    if(protection < shot)
      return ShotResult::DONOTRESIST
      
    else
      return ShotResult::RESIST
    end
  end
  
  def to_s
    salida = "Nombre: #{@name}\nAmmoPower: #{@ammoPower}\nshieldPower: #{@shieldPower}\n"
  end
end

end
