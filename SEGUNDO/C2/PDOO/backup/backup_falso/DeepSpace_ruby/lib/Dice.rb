# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'GameCharacter'

module Deepspace
class Dice
  
  def initialize
    @nhangarsprob = 0.25
    @nshieldsprob = 0.25
    @nweaponsprob = 0.33
    @firstshotprob = 0.5
    @extraefficiencyprob = 0.8
    @generator = rand
    
  end
  
  def initWithNHangars
    @generator = rand
    
    if(@generator <= @nhangarsprob)
      return 0
      
    else
      return 1
      
    end
    
  end
  
  def initWithNWeapons
    @generator = rand
    
    if(@generator <= @nweaponsprob)
      return 1
      
    elsif (@generator <= (@nweaponsprob)*2)
      
      return 2
    else
      return 3  
      
    end
  end
  
  def initWithNShields
    @generator = rand
    
    if(@generator <= @nshieldsprob)
      return 0
      
    else
      return 1
      
    end
  end
  
  def whoStarts(nPlayers)
    @generator = rand(nPlayers)
    
    return @generator
  end
  
  def firstShot
    @generator = rand
    
    if(@generator <= @firstshotprob)
      return GameCharacter::SPACESTATION
    
    else
      return GameCharacter::ENEMYSTARSHIP
      
    end
    
  end
  
  def spaceStationMoves(speed)
    @generator = rand
    
    if(@generator <= speed)
      return true
      
    else
      return false
      
    end
    
  end
  
  def extraEfficiency
    @generator = rand
    
    if(@generator <= @extraefficiencyprob)
      return true
    
    else
      return false
    end
  end
  
  def to_s
    "Probabilidad hangares: #{@nhangarsprob}\nProbabilidad escudos: #{@nshieldsprob}\nProbabilidad arma: #{@nweaponsprob}\nProbabilidad primer disparo: #{@firstshotprob}\nValor actual del dado: #{@generator}"
  end
  
end

end
