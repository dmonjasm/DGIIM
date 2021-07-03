# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

class CombatElement
  def initialize(name,uses)
    @name=name
    @uses=uses    
  end
  
  def uses
    return @uses
  end
  
  def useIt
    return 1.0
  end
  
  def to_s
    salida="Nombre: #{@name}\t Usos: #{@uses}\t"
    
    return salida
  end
end
