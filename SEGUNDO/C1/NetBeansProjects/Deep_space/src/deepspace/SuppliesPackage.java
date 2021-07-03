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
    
    public void to_String(){
        System.out.println("Munición: " + ammoPower + "\n");
        System.out.println("Combustible: " + fuelUnits + "\n");
        System.out.println("Escudo: " + shieldPower + "\n");
    }
}
