# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.


require_relative 'PowerEfficientSpaceStationToUI'
require_relative 'Loot'
require_relative 'SpaceStation'

module Deepspace
  
class PowerEfficientSpaceStation < SpaceStation
  @@EFFICIENCYFACTOR=1.10
  def initialize(station)
    copy(station)
  end
  
  def fire
    return super*@@EFFICIENCYFACTOR
  end
  
  def protection
    return super*@@EFFICIENCYFACTOR
  end
  
  def setLoot(loot)
    loot_ajustado = Loot.new(loot.nSupplies, loot.nWeapons, loot.nShields, loot.nHangars, loot.nMedals,loot.getEfficient)
    
    super(loot_ajustado)
  end
  
  def getUIversion
    return PowerEfficientSpaceStationToUI.new(self)
  end
end

end
