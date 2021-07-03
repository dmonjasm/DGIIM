# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'LootToUI.rb'
module Deepspace

class Loot
  def initialize(nSupplies,nWeapons,nShields,nHangars,nMedals)
    @nSupplies=nSupplies;
    @nWeapons=nWeapons;
    @nShields=nShields;
    @nHangars=nHangars;
    @nMedals=nMedals; 
  end
  
  attr_reader :nSupplies, :nWeapons, :nShields, :nHangars, :nMedals
  
  def to_s
    "Numero de Suplementos: #{@nSupplies}\nNumero de Armas: #{@nWeapons}\nNumero de escudos: #{@nShields}\nNumero de Hangares: #{@nHangars}\nNumero de Medallas: #{@nMedals}"
  end
  
  def getUIVersion
    return LootToUI.new(self)
  end
  
end

end
