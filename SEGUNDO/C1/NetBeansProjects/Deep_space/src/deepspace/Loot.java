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
    
    public LootToUI getUIversion(){
        return new LootToUI(this);
    }
    
    @Override
    public String toString(){
        System.out.println("Nº Suplementos: "+ nSupplies + "\n");
        System.out.println("Nº Armas: " + nWeapons + "\n");
        System.out.println("Nº Escudos: " + nShields + "\n");
        System.out.println("Nº Hangares: " + nHangars + "\n");
        System.out.println("Nº Medallas: " + nMedals + "\n");
        
        return "";
    }
    
}
