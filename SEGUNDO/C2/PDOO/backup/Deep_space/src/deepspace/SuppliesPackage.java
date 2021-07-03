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
public class SuppliesPackage {
    private float ammoPower;
    private float fuelUnits;
    private float shieldPower;
    
    SuppliesPackage(float ammopower, float fuelunits, float shieldpower){
        ammoPower=ammopower;
        fuelUnits=fuelunits;
        shieldPower=shieldpower;
    }
    
    SuppliesPackage(SuppliesPackage s){
        this(s.ammoPower,s.fuelUnits,s.shieldPower);
    }

    public float getAmmoPower() {
        return ammoPower;
    }

    public float getFuelUnits() {
        return fuelUnits;
    }

    public float getShieldPower() {
        return shieldPower;
    } 
    
    public String to_String(){
        String salida = "Potencia de fuego: " + ammoPower + "\nUnidades de combustible: " + fuelUnits + "\nPoder de escudo: " + shieldPower + "\n";
        
        return salida;        
    }
}
