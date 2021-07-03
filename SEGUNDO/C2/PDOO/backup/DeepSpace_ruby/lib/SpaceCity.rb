# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'SpaceStation'
require_relative 'SpaceCityToUI'

module Deepspace
  

class SpaceCity < SpaceStation
  def initialize( base, rest)
    @base = base
    @collaborators = rest
    copy(base)
  end
  
  def collaborators
    return @collaborators
  end
  
  def fire
    salida=0
    
    for i in @collaborators
      salida += i.fire
    end
    
    return salida
  end
  
  def protection
    salida = 0
    
    for i in @collaborators
      salida += i.protection
    end
    
    return salida
  end
  
  def setLoot(loot)
    loot_ajustado = Loot.new(loot.nSupplies, loot.nWeapons, loot.nShields, loot.nHangars, loot.nMedals)
    
    @base.setLoot(loot_ajustado)
    
    return Transformation::NOTRANSFORM
  end
  
  def getUIversion
    return SpaceCityToUI.new(self)
  end
  
end

end
