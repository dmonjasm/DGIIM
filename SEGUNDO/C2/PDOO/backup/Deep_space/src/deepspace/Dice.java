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
public class Dice {
    private static final float NHANGARSPROB =0.25f;
    private static final float NSHIELDSPROB = 0.25f;
    private static final float NWEAPONSPROB = 0.33f;
    private static final float FIRSTSHOTPROB = 0.5f;
    private Random generator = new Random();
    
    Dice(){
        generator.nextFloat();
    }
    
    public int initWithNHangar(){
        
        if((generator.nextFloat()) <= NHANGARSPROB){
            return 0;
        }
        
        else 
            return 1;
    }
    
    public int initWithWeapons(){
        if((generator.nextFloat()) <= NWEAPONSPROB){
            return 1;
        }
        
        else if((generator.nextFloat()) <= 2*NWEAPONSPROB)
            return 2;
        
        else
            return 3;     
    }
    
    public int initWithNShields(){
        if((generator.nextFloat()) <= NSHIELDSPROB){
            return 0;
        }
        
        else
            return 1;
    }
    
    public int whoStarts(int nPlayers){
        int jugador;
        
        jugador=generator.nextInt(nPlayers);
        
        return jugador;
    }
    
    public GameCharacter  firstShot(){
        GameCharacter personaje;
        
        if((generator.nextFloat()) <= FIRSTSHOTPROB){
            personaje=GameCharacter.SPACESTATION;
        }
        
        else{
            personaje=GameCharacter.ENEMYSTARSHIP;
        }
        
        return personaje;
    }
    
    public boolean spaceStationMoves(float speed){
        boolean salida;
        if((generator.nextFloat()) <= speed){
            salida=true;
        }
        
        else
            salida=false;
        
        return salida;
    }
    
    public String toString(){
        String salida = "Probabilidades: \n" + "De Hangar: " + NHANGARSPROB + "\nDe Escudo" + NSHIELDSPROB + "\nDe Armas: " + NWEAPONSPROB;
        salida = salida + "\nDe Primer Disparo: " + FIRSTSHOTPROB + "\n";
        
        return salida;
    }
    
}
