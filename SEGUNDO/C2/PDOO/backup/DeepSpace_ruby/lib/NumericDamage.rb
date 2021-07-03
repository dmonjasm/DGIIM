# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'Damage'
require_relative 'NumericDamageToUI'
module Deepspace
  

class NumericDamage < Damage
  def initialize(w,s)
    super(s)
    @nWeapons=w
  end
  
  def copy(otro)
    new(otro.nWeapons,otro.nShields)
  end
  
  def nWeapons
    return @nWeapons
  end
  
  def adjust(w,s)
    @nWeapons=[@nWeapons,w.size].min
    
    return NumericDamage.new(@nWeapons,[@nShields,s.size].min)
  end
  
  def discardWeapon(w)
    if(@nWeapons > 0)
      @nWeapons -= 1
    end
  end
  
  def getUIversion
    return NumericDamageToUI.new(self)
  end
  
  def hasNoEffect
    if(super && @nWeapons == 0)
      return true
    
    else
      return false
    end
  end
  
  public_class_method :new
end
end
