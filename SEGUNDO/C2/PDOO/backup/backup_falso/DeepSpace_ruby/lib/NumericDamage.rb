# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'NumericDamageToUI'

module Deepspace
  
class NumericDamage < Damage
  def initialize(w,s)
    super(s)
    @nWeapons = w
  end
  
  def copy
    new(@nWeapons,@nShields)
  end
  
  def nWeapons
    return @nWeapons
  end
  
  def hasNoEffect
    if(super && @nWeapons == 0)
      return true
    else
      return false
    end  
  end
  
  def adjust(w,s)
    @nWeapons = [w.size,@nWeapons].min
    super(s)
  end
  
  def discardWeapon(w)
    if(@nWeapons > 0)
      @nWeapons -= 1
    end
  end
  
  def getUIversion
    
  end
end

end
