/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepspace;
import java.util.Random;
/**
 *
 * @author daniel
 */
public class TestP1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Loot botin;
        SuppliesPackage paquete;
        ShieldBooster potenciador;
        Weapon arma1, arma2, arma3;
        Dice dado;
        int i=1;
        
        //Prueba de LOOT
        while(i <= 5){
            botin = new Loot(i,i*2,i*i,i*4,i*7);
            
            System.out.println("Cantidad de suplementos: " +botin.getNSupplies() + "\n");
            System.out.println("Cantidad de armas: " + botin.getNWeapons() + "\n");
            System.out.println("Cantidad de escudos: " + botin.getNShields() + "\n");
            System.out.println("Cantidad de hangares: " + botin.getNHangars() + "\n");
            System.out.println("Cantidad de medallas: " + botin.getNMedals() + "\n");
            
            i++;
        }
        
        i=1;
        
        //Prueba de SUPPLIESPACKAGE
        while(i <= 5){
            paquete=new SuppliesPackage(i*100,i*1000, i*500);
            
            System.out.println("Poder de armamento: " + paquete.getAmmoPower() + "\n");
            System.out.println("Unidades de combustible: " + paquete.getFuelUnits() + "\n");
            System.out.println("Poder de escudo: " + paquete.getShieldPower() + "\n");
            
            SuppliesPackage copia = new SuppliesPackage(paquete);
            
            System.out.println("Poder de armamento copiado: " + copia.getAmmoPower() + "\n");
            System.out.println("Unidades de combustible copiadas: " + copia.getFuelUnits() + "\n");
            System.out.println("Poder de escudo copiado: " + copia.getShieldPower() + "\n");
            
            i++;  
        }
        
        i=1;
        
        //Prueba SHIELDBOOSTER
        
        while(i <= 5){
            potenciador=new ShieldBooster("Escudo de hadrones", i*10.0f, i);
            
            System.out.println("El nombre del potenciador es " + potenciador.getName() + "\n");
            System.out.println("El poder del potenciador es " + potenciador.getBoost() + "\n");
            System.out.println("Los usos restantes del potenciador son " + potenciador.getUses() + "\n");
            
            for(int j=0; j < 7; j++)
                System.out.println("La salida de useIt es: " + potenciador.useIt() + "\n Los usos restantes son " + potenciador.getUses() + "\n");
            
            ShieldBooster copia = new ShieldBooster(potenciador);
            
            System.out.println("El nombre del potenciador copiado es " + copia.getName() + "\n");
            System.out.println("El poder del potenciador copiado es " + copia.getBoost() + "\n");
            System.out.println("Los usos restantes del potenciador copiado son " + copia.getUses() + "\n");
            
            for(int j=0; j < 7; j++)
                System.out.println("La salida de useIt es: " + potenciador.useIt() + "\n Los usos restantes son " + potenciador.getUses() + "\n");
            
            i++;
        }
        
        i=1;
        
        //Prueba WEAPON
        
        while (i <= 5){
            arma1= new Weapon("Arco_flecha", WeaponType.LASER, 10);
            arma2= new Weapon("Lanzamisiles", WeaponType.MISSILE, 4);
            arma3= new Weapon("Tanqueta_verde", WeaponType.PLASMA, 7);
            
            System.out.println("El arma 1 se llama: \n");
            
            if(arma1.getType()==WeaponType.LASER){
                System.out.println("EL arma 1 es de tipo laser\n");
            }
            
            else if (arma1.getType() == WeaponType.MISSILE)
                System.out.println("El arma 1 es de tipo misil");
            
            else
                System.out.println("El arma 1 es de tipo plasma");
            
            System.out.println("Al rama uno le quedan " + arma1.getUses() + "\n");
            
            for(int j=0; j <=10; j++){
                System.out.println("La salida de useIt en el arma 1 es: " + arma1.useIt() + "\n Los usos restantes del arma 1 son " + arma1.getUses() + "\n");
            }
            
            System.out.println("El arma 2 se llama: \n");
            
            if(arma2.getType()==WeaponType.LASER){
                System.out.println("EL arma 2 es de tipo laser\n");
            }
            
            else if (arma2.getType() == WeaponType.MISSILE)
                System.out.println("El arma 2 es de tipo misil");
            
            else
                System.out.println("El arma 2 es de tipo plasma");
            
            System.out.println("Al rama dos le quedan " + arma2.getUses() + "\n");
            
            for(int j=0; j <=10; j++){
                System.out.println("La salida de useIt en el arma 2 es: " + arma2.useIt() + "\n Los usos restantes del arma 2 son " + arma2.getUses() + "\n");
            }
            
            System.out.println("El arma 3 se llama: \n");
            
            if(arma3.getType()==WeaponType.LASER){
                System.out.println("EL arma 3 es de tipo laser\n");
            }
            
            else if (arma3.getType() == WeaponType.MISSILE)
                System.out.println("El arma 3 es de tipo misil");
            
            else
                System.out.println("El arma 3 es de tipo plasma");
            
            System.out.println("Al rama tres le quedan " + arma3.getUses() + "\n");
            
            for(int j=0; j <=10; j++){
                System.out.println("La salida de useIt en el arma 3 es: " + arma3.useIt() + "\n Los usos restantes del arma 3 son " + arma3.getUses() + "\n");
            }
            
            i++;            
        }
        
        i=1;
        
        int nhangars=0;
        int nweapons1=0;
        int nweapons2=0;
        int nweapons3=0;
        int nshields=0;
        int firstshot=0;
        //Prueba DICE
        
        while (i <= 100){
            System.out.println("Inicidando partida " + i +"\n");
            Random jugador=new Random();
            System.out.println("Se le ha asignado el jugador " + jugador.nextInt(100) + "\n");
            dado=new Dice();
            
            if(dado.initWithNHangar() == 0){
                System.out.println("Se le han asignado 0 hangares\n");
                nhangars++;
            }
            
            else
                System.out.println("Se le han asignado 1 hangar \n");
            
            int arma=dado.initWithWeapons();
            
            if(arma == 1){
                System.out.println("Se le ha asignado 1 arma\n");
                nweapons1++;
            }
            
            else if(arma == 2){
                System.out.println("Se le han asignado 2 armas\n");
                nweapons2++;
            }
            
            else{
                System.out.println("Se le han asignado 3 arma\n");
                nweapons3++;
            }
            
            if(dado.initWithNShields() == 0){
                System.out.println("No se le ha asignado escudo\n");
                nshields++;
            }
            
            else
                System.out.println("Se le ha asignado 1 escudo\n");
            
            
            System.out.println("La partida la comenzará el jugador: "+ dado.whoStarts(100) + "\n");
            
            
            if(dado.firstShot() == GameCharacter.SPACESTATION){
                System.out.println("El primer disparo lo realiza SPACESTATION");
                firstshot++;
            }
            
            else
                System.out.println("El primer disparo lo realiza ENEMYSTARSHIP");
            
            if(dado.spaceStationMoves(jugador.nextFloat()))
                System.out.println("Su nave ha esquivado el disparo\n");
            
            else
                System.out.println("Su nave ha recibido el disparo\n");
            
            i++;
            
            System.out.println("\n\n");
        }
        
        
        System.out.println("Estadísticas: \n Probabilidad hangar=0: " + nhangars / 100.0f + "\n Probabilidad arma=1: " +nweapons1/100.0f+ "\n Probabilidad arma=2: "+ nweapons2/100.0f +"\n Probabilidad arma=3: "+ nweapons3/100.0 + "\n Probabilidad firstshot=SPACESTATION: " + firstshot/100.0f + "\n");      
    }
    
}
