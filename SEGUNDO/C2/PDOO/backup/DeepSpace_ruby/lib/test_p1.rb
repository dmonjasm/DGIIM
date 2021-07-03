# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

#encoding:utf-8

require_relative 'combat_result'
require_relative 'dice'
require_relative 'game_character'
require_relative 'loot'
require_relative 'shield_booster'
require_relative 'shot_result'
require_relative 'supplies_package'
require_relative 'weapon'
require_relative 'weapon_type'

  
class TestP1
  
  def self.main
    i = 1
    #Prueba de loot
    while i <= 5
      botin = Deepspace::Loot.new(i,i*2, i*3, i*4, i*10)
      puts "El valor de suplementos es ", botin.nSupplies
      puts "El valor de las armas es ", botin.nWeapons
      puts "El valor de los escudos es ", botin.nShields
      puts "El valor de los hangares es ", botin.nHangars
      puts "El valor de las medallas es ", botin.nMedals 

      i+= 1

      print "\n\n"
    end

    #Prueba de SuppliesPackage
    i = 1
    while i <= 5
      paquete=Deepspace::SuppliesPackage.new(i*100,i*1000,i*345)

      puts "El poder de municion es ", paquete.ammoPower
      puts "Las unidades de combustible son ", paquete.fuelUnits
      puts "El poder del escudo es ", paquete.shieldPower

      copia=Deepspace::SuppliesPackage.newCopy(paquete)
      puts "El poder de municion copiado es ", copia.ammoPower
      puts "Las unidades de combustible copiadas son ", copia.fuelUnits
      puts "El poder del escudo copiado es ", copia.shieldPower

      i+=1
      print "\n\n"
    end

    #Prueba de ShieldBooster
    i = 1
    while i <= 5
      potenciador_escudo=Deepspace::ShieldBooster.new("Escudo_de_obsidiana", i*10.0,i*i)

      puts "El valor de la mejora es ", potenciador_escudo.boost
      puts "Los usos restantes del escudo son ", potenciador_escudo.uses

      10.times {puts "La salida de useIt es ", potenciador_escudo.useIt, "Los usos restantes son ", potenciador_escudo.uses  }

      print "\n\n"

      copia=Deepspace::ShieldBooster.newCopy(potenciador_escudo)
      puts "El valor de la mejora es ", copia.boost
      puts "Los usos restantes del escudo son ", copia.uses

      10.times {puts "La salida de useIt copia es ", copia.useIt, "Los usos restantes de la copia son ", copia.uses  }

      i+=1

      print "\n\n"
    end

    #Prueba de Weapon
    i = 1
    while i <= 5
      arma1 = Deepspace::Weapon.new("Canon_de_protones",Deepspace::WeaponType::LASER, i)
      arma2 = Deepspace::Weapon.new("Canon_de_adrones", Deepspace::WeaponType::MISSILE,i*i)
      arma3 = Deepspace::Weapon.new("Arco_y_flecha", Deepspace::WeaponType::PLASMA, i*i*i)

      if(arma1.type == Deepspace::WeaponType::LASER)
        puts "El arma es LASER"
      end

      if(arma1.type == Deepspace::WeaponType::MISSILE)
        puts "El arma es MISSILE"
      end

      if(arma1.type == Deepspace::WeaponType::PLASMA)
        puts "El arma es PLASMA"
      end

      puts "Los usos restantes del arma 1 son " + arma1.uses.to_s
      puts "El poder del arma 1 es " + arma1.power.to_s
      10.times {puts "La salida de useIt en el arma 1 es " + arma1.useIt.to_s, "Los usos restantes son " + arma1.uses.to_s}

      print "\n\n"
      if(arma2.type == Deepspace::WeaponType::LASER)
        puts "El arma es LASER"
      end

      if(arma2.type == Deepspace::WeaponType::MISSILE)
        puts "El arma es MISSILE"
      end

      if(arma2.type == Deepspace::WeaponType::PLASMA)
        puts "El arma es PLASMA"
      end

      puts "Los usos restantes del arma 2 son " + arma2.uses.to_s
      puts "El poder del arma 2 es " + arma2.power.to_s
      10.times {puts "La salida de useIt en el arma 2 es " + arma2.useIt.to_s, "Los usos restantes son " + arma2.uses.to_s}

      print "\n\n"
      if(arma3.type == Deepspace::WeaponType::LASER)
        puts "El arma es LASER"
      end

      if(arma3.type == Deepspace::WeaponType::MISSILE)
        puts "El arma es MISSILE"
      end

      if(arma3.type == Deepspace::WeaponType::PLASMA)
        puts "El arma es PLASMA"
      end
      puts "Los usos restantes del arma 3 son " + arma3.uses.to_s
      puts "El poder del arma 3 es " + arma3.power.to_s
      10.times {puts "La salida de useIt en el arma 3 es " + arma3.useIt.to_s , "Los usos restantes son " + arma3.uses.to_s}

      i+=1

      print "\n\n"
    end

    #Prueba de Dice
    i=1
    nhangars=0
    nweapons=0
    nweapons2=0
    nweapons3=0
    nshields=0
    firstshot=0
    while i <= 100
      puts "Iniciando partida " + i.to_s
      jugador=rand(1..100)
      puts "Usted es el jugador " + jugador.to_s

      dado=Deepspace::Dice.new

      valorh=dado.initWithNHangars
      valorw=dado.initWithNWeapons
      valors=dado.initWithNShields

      if(valorh==0)
        nhangars += 1
      end

      if(valorw == 1)
        nweapons += 1

      elsif(valorw == 2)
        nweapons2 += 1

      else 
        nweapons3 += 1
      end




      if(valors == 0)
        nshields += 1
      end  

      puts "Numero de hangares asignado " + valorh.to_s
      puts "Numero de armas asignado " + valorw.to_s
      puts "Numero de escudos asignado " + valors.to_s

      puts "Empieza la partida el jugador " + dado.whoStarts(100).to_s

      if(dado.firstShot == Deepspace::GameCharacter::SPACESTATION)
        puts "El primer disparo lo realiza SPACESTATION"
        firstshot+=1

      else
        puts "El primer disparo lo realiza ENEMY STARSHIP"
      end

      velocidad=rand

      puts "La velocidad de su nave es ", velocidad
      if(dado.spaceStationMoves(velocidad))
        puts "Su nave ha esquivado el ataque de una nave enemiga"
      else
        puts "Su nave ha recibido un disparo y pierde una unidad de escudo"
      end

      i+=1

      print "\n\n"
    end

    puts "Estadisiticas"
    puts "Probabilidad de Hangar=0 ", nhangars/100.0
    puts "Probabilidad de Weapons=1", nweapons/100.0
    puts "Probabilidad de Weapons=2", nweapons2/100.0
    puts "Probabilidad de Weapons=3", nweapons3/100.0
    puts "Probabilidad de Shields=0", nshields/100.0
    puts "Probabilidad de FirstShot=SPACESTATION", firstshot/100.0
  
  end
  
  TestP1.main
end
