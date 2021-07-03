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
public class Damage {
    private int nShields;
    private int nWeapons;
    private ArrayList<WeaponType> weapons;
    
    public Damage(int w, int s){
        this.nShields=s;
        this.nWeapons=w;
    }
    
    public Damage(ArrayList<WeaponType> wl, int s){
        this.nShields=s;
        this.nWeapons=-1;
        this.weapons=(ArrayList<WeaponType>) wl.clone();
    }
    
    public Damage(Damage d){
        this.nShields=d.getNShields();
        this.nWeapons=d.getNWeapons();
        this.weapons=(ArrayList<WeaponType>) d.getWeapons().clone();
    }
    
    public DamageToUI getUIversion(){
        return new DamageToUI(this);
    }
    
    private int arrayContainsType(ArrayList<Weapon> w, WeaponType t){
        boolean encontrado=false;
        int posicion=0;
        
        for(int i = 0; i < w.size() && !encontrado; i++){
            if(w.get(i).getType() == t){
                encontrado=true;
                posicion=i;
            }
                
        }
        
        if(!encontrado)
            posicion=-1;
        
        return posicion;
    }
    
    public Damage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s){
        if(weapons.isEmpty()){
            nShields=Math.min(nShields,s.size());
            nWeapons=Math.min(nWeapons, w.size());
            
            return new Damage(nWeapons,nShields);
        }
        
        else{
            nShields=Math.min(nShields, s.size());
            
            int lasers_1=0, lasers_2=0;
            int plasmas_1=0, plasmas_2=0;
            int misiles_1=0,misiles_2=0;
            
            for(int i=0; i < w.size(); i++){
                if(w.get(i).getType() == WeaponType.LASER)
                    lasers_1++;
                
                else if(w.get(i).getType() == WeaponType.PLASMA)
                    plasmas_1++;
                
                else
                    misiles_1++;
            }
            
            for(int i=0; i < weapons.size(); i++){
                if(weapons.get(i) == WeaponType.LASER)
                    lasers_2++;
                
                else if(weapons.get(i) == WeaponType.PLASMA)
                    plasmas_2++;
                
                else
                    misiles_2++;
            }
            
            lasers_1=Math.min(lasers_1, lasers_2);
            plasmas_1=Math.min(plasmas_1, plasmas_2);
            misiles_1=Math.min(misiles_1, misiles_2);
            
            ArrayList<WeaponType> array_tipos = new ArrayList<WeaponType>();
            
            for(int i=0; i < (lasers_1+plasmas_1+misiles_1); i++){
                if(lasers_1 > 0){
                    array_tipos.add(WeaponType.LASER);
                    lasers_1--;
                }
                
                else if(plasmas_1 > 0){
                    array_tipos.add(WeaponType.PLASMA);
                    plasmas_1--;
                }
                
                else
                    array_tipos.add(WeaponType.MISSILE);     
            }
            
            return new Damage((ArrayList<WeaponType>) array_tipos.clone(), nShields);  
        }
    }
    
    public void discardWeapon(Weapon w){
        if(weapons.size() != 0){
            for(int i=0; i < weapons.size(); i++){
                if(weapons.get(i) == w.getType())
                    weapons.remove(i);
                    
            }
        }
        
        else if(nWeapons - 1 >= 0)
            nWeapons--;
    }
    
    public void discardShieldBooster(){
        if(nShields - 1 >= 0)
            nShields--;
    }
    
    public boolean hasNoEffect(){
        if((nShields == 0 && nWeapons==0) && weapons.isEmpty())
            return true;
        
        else
            return false;
    }
    
    public int getNShields(){
        return this.nShields;
    }
    
    public int getNWeapons(){
        return this.nWeapons;
    }
    
    public final ArrayList<WeaponType> getWeapons(){
        return this.weapons;
    }
}
