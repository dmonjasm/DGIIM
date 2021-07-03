# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'DamageToUI'
require_relative 'WeaponType'
require_relative 'Weapon'
require_relative 'ShieldBooster'


module Deepspace
  

class Damage  
  def initialize(s)
    @nShields=s
  end

  def getUIversion
    return DamageToUI.new(self)
  end
  
  def arrayContainsType(w,t)
    i=0
    encontrado=false
    
    while i < w.length && !encontrado
      if(w.at(i).type == t)
        encontrado=true
       
      else
        i += 1
      end
    end
    
    if(encontrado)
      return (i)
    else
      return -1
    end
    
  end 
  
  def adjustShieldBoosters(s)
    @nShields=[@nShields,s.length].min
    return Damage.new(@nShields)
  end

  
  def discardShieldBooster
    if(@nShields > 0)
      @nShields += -1
    end
  end
  
  def hasNoEffect
    return @nShields == 0
  end
  
  def nShields
    @nShields
  end

  def to_s
    salida="N escudos: #{@nShields}\n"
    
    return salida
  end 
  
  private :arrayContainsType
  private_class_method :new
end

end
