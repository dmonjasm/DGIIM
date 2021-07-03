/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepspace;

import deepspace.WeaponType;

/**
 *
 * @author daniel
 */
public class Weapon {
    private String name;
    private WeaponType type;
    private int uses;
    
    Weapon(String Name, WeaponType Type, int Uses){
        this.name = Name;
        this.type = Type;
        this.uses = Uses;
    }
    
    Weapon(Weapon s){
        this(s.name, s.type,s.uses);
    }

    public WeaponType getType() {
        return type;
    }

    public int getUses() {
        return uses;
    }
    
    public float power(){
        return type.getPower();
    }
    
    public float useIt(){
        if(uses > 0){
            uses--;
            return 0.0f;
        }
        
        else
            return 1.0f;
    }
    
    public WeaponToUI getUIversion(){
        return new WeaponToUI(this);
    }
    
    @Override
    public String toString(){
        System.out.println("Nombre: " + name + "\n");
        
        if(type == WeaponType.LASER)
            System.out.println("Tipo: LASER\n");
        
        else if(type == WeaponType.MISSILE)
            System.out.println("Tipo: MISSILE\n");
        else
            System.out.println("Tipo: PLASMA\n");
        
        System.out.println("Usos: " + uses + "\n");
        
        return "";
    }   
}
