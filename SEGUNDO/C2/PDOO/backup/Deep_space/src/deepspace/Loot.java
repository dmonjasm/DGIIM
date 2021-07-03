/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepspace;

/**
 *
 * @author daniel
 */
public class Loot {
    private int nSupplies;
    private int nWeapons;
    private int nShields;
    private int nHangars;
    private int nMedals;
    
    Loot(int supplies, int weapons,int shields, int hangars, int medals){
    this.nSupplies=supplies;
    this.nWeapons=weapons;
    this.nShields=shields;
    this.nHangars=hangars;
    this.nMedals=medals;
}
    
    public int getNSupplies(){
        return this.nSupplies;
    }
    
    public int getNWeapons(){
        return this.nWeapons;
    }
    
    public int getNShields(){
        return this.nShields;
    }
    
    public int getNHangars(){
        return this.nHangars;
    }
    
    public int getNMedals(){
        return this.nMedals;
    }
    
    LootToUI getUIversion(){
        return new LootToUI(this);
    }
    
    @Override
    public String toString(){
        String salida = "Suplementos: " + nSupplies + "\nNº de Armas: " + nWeapons + "\nNº Escudos: " + nShields + "\nNº Hangares: " + nHangars;
        salida = salida + "\nNº de Medallas: " + nMedals + "\n";
        
        return salida;        
    }
    
}
