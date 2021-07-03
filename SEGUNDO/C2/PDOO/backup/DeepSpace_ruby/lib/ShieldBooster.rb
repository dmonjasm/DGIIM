# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'ShieldToUI'

module Deepspace
  

class ShieldBooster
  def initialize(name, boost, uses)
    @name = name
    @boost = boost
    @uses = uses    
  end
  
  def self.newCopy(copia)
    new(copia.name, copia.boost, copia.uses)
  end
  
  attr_reader :boost, :uses, :name
  
  def useIt
    if(@uses > 0)
      @uses -= 1
      return @boost
    else
      return 1.0
    end
  end
  
  def to_s
    return "Nombre de la mejora: #{@name}\nMejora: #{@boost}\nUsos restantes: #{@uses}"
  end
  
  def getUIversion
    return ShieldToUI.new(self)
  end

end

end
