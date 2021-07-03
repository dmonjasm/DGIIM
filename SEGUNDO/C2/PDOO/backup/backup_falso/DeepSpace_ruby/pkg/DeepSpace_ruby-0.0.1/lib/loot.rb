# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
require_relative 'LootToUI.rb'
module Deepspace

class Loot
  def initialize(nSupplies,nWeapons,nShields,nHangars,nMedals,ef=false,city=false)
    @nSupplies=nSupplies
    @nWeapons=nWeapons
    @nShields=nShields
    @nHangars=nHangars
    @nMedals=nMedals
    @efficient=ef
    @spaceCity=city
  end
  
  attr_reader :nSupplies, :nWeapons, :nShields, :nHangars, :nMedals, :efficient, :spaceCity
  
  def to_s
    return "Numero de Suministros: #{@nSupplies}\nNumero de Armas: #{@nWeapons}\nNumero de escudos: #{@nShields}\nNumero de Hangares: #{@nHangars}\nNumero de Medallas: #{@nMedals}"
  end
  
  def getUIversion
    return LootToUI.new(self)
  end
  
end

end
