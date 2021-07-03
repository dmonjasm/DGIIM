# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'ShieldToUI'
require_relative 'CombatElement'

module Deepspace
  

class ShieldBooster < CombatElement
  def initialize(name, boost, uses)
    @boost = boost
    super(name,uses)    
  end
  
  def self.newCopy(copia)
    new(copia.name, copia.boost, copia.uses)
  end
  
  attr_reader :boost, :name
  
  def useIt
    if(@uses > 0)
      @uses -= 1
      return @boost
    else
      super
    end
  end
  
  def to_s
    salida = super
    salida += "Boost: #{@boost}\n"
  end
  
  def getUIversion
    return ShieldToUI.new(self)
  end

end

end
