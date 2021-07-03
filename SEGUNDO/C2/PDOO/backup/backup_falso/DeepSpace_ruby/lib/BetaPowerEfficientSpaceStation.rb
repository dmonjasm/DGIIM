# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'PowerEfficientSpaceStation'
require_relative 'BetaPowerEfficientSpaceStation'

class BetaPowerEfficientSpaceStation < PowerEfficientSpaceStation
  @@EXTRAEFFICIENCY=1.2
  def initialize(station)
    copy(station)
  end
  
  def fire
    dado=Dice.new
    if(dado.extraEfficiency)
      return super*@@EXTRAEFFICIENCY
    
    else
      return super
    end
  end
  
  def getUIversion
    return BetaPowerEfficientSpaceStationToUI.new(self)
  end
end
