# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding:utf-8
#Daniel Monjas Miguélez

require_relative'Dice'
require_relative 'CardDealer'

module MiPrimerModulo
    class MiPrimeraClase
      def initialize(nombre,edad)
        @nombre=nombre
        @edad=edad
      end
      
      def self.newCopy(edad)
        new("anónimo",edad)
      end
      
      def principal
        dado=Deepspace::Dice.new
        array_escudos=Array.new
        dealer=Deepspace::CardDealer.instance
        
        i=0
        while i < 3
          n_escudos=dado.initWithNShields
          
          if(n_escudos != 0)
            array_escudos.push(dealer.nextShieldBooster)
          end
          
          i+=1
        end
        
        puts "Nº de potenciadores de escudos creados: " + array_escudos.length.to_s
      end
      
      objeto=MiPrimeraClase.new("Daniel Monjas Miguélez", 19)
      
      objeto.principal
    end
end
