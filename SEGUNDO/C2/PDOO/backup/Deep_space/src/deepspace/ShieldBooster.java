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
public class ShieldBooster {
    private String name;
    private float boost;
    private int uses;
    
    ShieldBooster(String Name, float Boost, int Uses){
        name=Name;
        boost=Boost;
        uses=Uses;
    }
    
    ShieldBooster(ShieldBooster s){
        this(s.name,s.boost,s.uses);
    }

    public String getName() {
        return name;
    }

    public float getBoost() {
        return boost;
    }

    public int getUses() {
        return uses;
    }
    
    public float useIt(){
        if(this.uses > 0){
            uses--;
            return 0.0f;
        }
        
        else
            return 1.0f;
    }
    
    ShieldToUI getUIversion(){
        return new ShieldToUI(this);
    }
    
    @Override
    public String toString(){
        String salida = "Nombre: " + name + "\nBoost: " + boost + "\nUsos: " + uses + "\n";
        
        return salida;
    }
}
