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
public class SpaceStation {
    static private float MAXFUEL=100;
    static private float SHIELDLOSSPERUNITSHOT=0.1f;
    private float ammoPower;
    private float fuelUnits;
    private String name;
    private int nMedals;
    private float shieldPower;
    private ArrayList<Weapon> weapons;
    private ArrayList<ShieldBooster> shieldBoosters;
    private Damage pendingDamage;
    private Hangar hangar;
    
    private void assignFuelValue(float f){
        if(f > MAXFUEL)
            fuelUnits=MAXFUEL;
        
        else
            fuelUnits=f;
    }
    
    private void cleanPendingDamage(){
        if(pendingDamage.hasNoEffect())
            pendingDamage=null;
    }
    
    SpaceStation(String n, SuppliesPackage supplies){
        this.name=n;
        this.ammoPower=supplies.getAmmoPower();
        this.fuelUnits=supplies.getFuelUnits();
        this.shieldPower=supplies.getShieldPower();
        this.nMedals=0;
        this.shieldBoosters=new ArrayList<ShieldBooster>();
        this.weapons=new ArrayList<Weapon>();
        
    }
    
    public void cleanUpMountedItems(){
        int i=0;
        
        while (i < this.weapons.size()){
            if(this.weapons.get(i).getUses() == 0)
                this.weapons.remove(i);
            
            else
                i++;
        }
        
        i=0;
        
        while (i < this.shieldBoosters.size()){
            if(this.shieldBoosters.get(i).getUses() == 0)
                this.shieldBoosters.remove(i);
            
            else
                i++;
        }
    }
    
    public void discardHangar(){
        this.hangar=null;
    }
    
    public void discardShieldBooster(int i){
        throw new UnsupportedOperationException();
    }
    
    public void discardShieldBoosterInHangar(int i){
        if(this.hangar != null)
            this.hangar.removeShieldBooster(i);
    }
    
    public void discardWeapon(int i){
        throw new UnsupportedOperationException();
    }
    
    public void discardWeaponInHangar(int i){
        if(this.hangar != null)
            this.hangar.removeWeapon(i);
    }
    
    public float fire(){
        throw new UnsupportedOperationException();
    }
    
    public float getAmmoPower(){
        return this.ammoPower;
    }
    
    public float getFuelUnits(){
        return this.fuelUnits;
    }
    
    public Hangar getHangar(){
        return new Hangar(this.hangar);
    }
    
    public String getName(){
        return this.name;
    }
    
    public int getNMedals(){
        return this.nMedals;
    }
    
    public Damage getPendingDamage(){
        return new Damage(this.pendingDamage);
    }
    
    public ArrayList<ShieldBooster> getShieldBoosters(){
        return (ArrayList<ShieldBooster>) this.shieldBoosters.clone();
    }
    
    public float getShieldPower(){
        return this.shieldPower;
    }
    
    public float getSpeed(){
        return (this.fuelUnits/MAXFUEL);
    }
    
    public SpaceStationToUI getUIversion(){
        return new SpaceStationToUI(this);
    }
    
    public ArrayList<Weapon> getWeapons(){
        return (ArrayList<Weapon>) this.weapons.clone();
    }
    
    public void mountShieldBooster(int i){
        if(this.hangar != null){
            ShieldBooster escudo=hangar.removeShieldBooster(i);
            
            if(escudo != null)
                this.shieldBoosters.add(escudo);
        }
            
    }
    public void mountWeapon(int i){
        if(this.hangar != null){
            Weapon arma=hangar.removeWeapon(i);
            
            if(arma != null)
                this.weapons.add(arma);
        }
            
    }
    
    public void move(){
        this.fuelUnits=(this.fuelUnits*this.getSpeed());
    }
    
    public float protection(){
        throw new UnsupportedOperationException();
    }
    
    public void receiveHangar(Hangar h){
        if(this.hangar != null)
            this.hangar= h;
    }
    
    public boolean receiveShieldBooster(ShieldBooster s){
        if(this.hangar != null)
            return this.hangar.addShieldBooster(s);
        
        else
            return false;
    }
    
    public ShotResult receiveShot(float shot){
        throw new UnsupportedOperationException();
    }
    
    public void receiveSupplies(SuppliesPackage s){
        this.ammoPower=s.getAmmoPower();
        this.fuelUnits=s.getFuelUnits();
        this.shieldPower=s.getShieldPower();
    }
    
    public boolean receiveWeapon(Weapon w){
        if(hangar != null){
            return hangar.addWeapon(w);
        }
        
        else
            return false;
    }
    
    public void setLoot(Loot loot){
        throw new UnsupportedOperationException();
    }
    
    public void setPendingDamage(Damage d){
        this.pendingDamage=d.adjust(this.weapons, this.shieldBoosters);
    }
    
    public boolean validState(){
        if(this.pendingDamage == null || this.pendingDamage.hasNoEffect())
            return true;
        
        else
            return false;
    }
}
