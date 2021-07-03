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
    
    public Hangar(int capacity){
        this.maxElements=capacity;
    }
    
    public Hangar(Hangar h){
        this.maxElements=h.getMaxElements();
        this.shieldBoosters=(ArrayList<ShieldBooster>) h.getShieldBoosters().clone();
        this.weapons=(ArrayList<Weapon>) h.getWeapons().clone();
    }
    
    public HangarToUI getUIversion(){
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
    
}
