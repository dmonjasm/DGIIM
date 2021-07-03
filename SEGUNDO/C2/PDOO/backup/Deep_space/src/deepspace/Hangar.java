/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepspace;

import java.util.ArrayList;

/**
 *
 * @author daniel
 */
public class Hangar {
    private int maxElements;
    private ArrayList<ShieldBooster> shieldBoosters;
    private ArrayList<Weapon> weapons;
    
    Hangar(int capacity){
        this.maxElements=capacity;
        this.shieldBoosters = new ArrayList<ShieldBooster>();
        this.weapons = new ArrayList<Weapon>();
    }
    
    Hangar(Hangar h){
        this.maxElements=h.getMaxElements();
        this.shieldBoosters = new ArrayList<ShieldBooster>();
        this.weapons = new ArrayList<Weapon>();
        
    }
    
    HangarToUI getUIversion(){
        return new HangarToUI(this);
    }
    
    private boolean spaceAvailable(){
        boolean salida;
        
        if((shieldBoosters.size() + weapons.size()) < maxElements)
            salida=true;
        
        else
            salida=false;
        
        return salida;
    }
    
    public boolean addWeapon(Weapon w){
        boolean salida;
        
        if(this.spaceAvailable()){
            weapons.add(w);
            salida=true;
        }
        
        else
            salida=false;
        
        return salida;
    }
    
    public boolean addShieldBooster(ShieldBooster s){
        boolean salida;
        
        if(this.spaceAvailable()){
            shieldBoosters.add(s);
            salida=true;
        }
        
        else
            salida = false;
        
        return salida;
    }
    
    public int getMaxElements(){
        return this.maxElements;
    }
    
    public final ArrayList<ShieldBooster> getShieldBoosters(){
        return this.shieldBoosters;
    }
    
    public final ArrayList<Weapon> getWeapons(){
        return this.weapons;
    }
    
    public ShieldBooster removeShieldBooster(int s){
        ShieldBooster salida;
        
        if( !shieldBoosters.isEmpty() && s < shieldBoosters.size())
            salida=shieldBoosters.remove(s);
        
        
        else
            salida=null; 
        
        return salida;
    }
    
    public Weapon removeWeapon(int w){
        Weapon salida;
        
        if( !weapons.isEmpty() && w < weapons.size())
            salida=weapons.remove(w);
        
        else
            salida=null;
        
        return salida;   
    }
    
    @Override
    public String toString(){
        String salida = "Capacidad: " + maxElements;
        
        if(shieldBoosters != null){
            salida = salida + "\nEscudos: \n";
            for(int i=0; i < shieldBoosters.size(); i++)
                salida= salida + shieldBoosters.get(i).toString();
        }
        
        if(weapons != null){
            salida = salida + "\nArmas: \n";
            for(int i=0; i < weapons.size(); i++)
                salida = salida + weapons.get(i).toString();         
        }
        
        return salida;                
    }
    
}
