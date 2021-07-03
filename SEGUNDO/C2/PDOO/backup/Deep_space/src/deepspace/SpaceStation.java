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
        this.hangar = null;
        this.pendingDamage = null;
        
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
        int size = shieldBoosters.size();
        
        if(i >= 0 && i < size){
            ShieldBooster sb= shieldBoosters.remove(i);
            
            if(pendingDamage != null){
                pendingDamage.discardShieldBooster();
                
                this.cleanPendingDamage();
            }
        }
    }
    
    public void discardShieldBoosterInHangar(int i){
        if(this.hangar != null)
            this.hangar.removeShieldBooster(i);
    }
    
    public void discardWeapon(int i){
        int size = weapons.size();
        
        if( i >= 0 && i < size){
            Weapon w = weapons.remove(i);
            
            if(pendingDamage != null){
                pendingDamage.discardWeapon(w);
                
                this.cleanPendingDamage();
            }
        }
    }
    
    public void discardWeaponInHangar(int i){
        if(this.hangar != null)
            this.hangar.removeWeapon(i);
    }
    
    public float fire(){
        int size = weapons.size();
        int factor=1;
        
        for(int i=0; i < size; i++){
            Weapon w = weapons.get(i);
            factor *= w.useIt();
        }
        
        return (ammoPower*factor);
    }
    
    public float getAmmoPower(){
        return this.ammoPower;
    }
    
    public float getFuelUnits(){
        return this.fuelUnits;
    }
    
    public Hangar getHangar(){
        return this.hangar;
    }
    
    public String getName(){
        return this.name;
    }
    
    public int getNMedals(){
        return this.nMedals;
    }
    
    public Damage getPendingDamage(){
        return this.pendingDamage;
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
        this.fuelUnits-=(this.fuelUnits*this.getSpeed());
    }
    
    public float protection(){
        int size = shieldBoosters.size();
        int factor = 1;
        
        for(int i=0 ; i < size; i++){
            ShieldBooster s = shieldBoosters.get(i);
            factor *= s.useIt();
        }
        
        return (shieldPower*factor);
    }
    
    public void receiveHangar(Hangar h){
        if(this.hangar == null)
            this.hangar= h;
    }
    
    public boolean receiveShieldBooster(ShieldBooster s){
        if(this.hangar != null)
            return this.hangar.addShieldBooster(s);
        
        else
            return false;
    }
    
    public ShotResult receiveShot(float shot){
        float myProtection = this.protection();
        
        if(myProtection >= shot){
            this.shieldPower -= SHIELDLOSSPERUNITSHOT * shot;
            shieldPower = Math.max(0.0f, shieldPower);
            
            return ShotResult.RESIST;
        }
        
        else{
            shieldPower = 0.0f;
            return ShotResult.DONOTRESIST;
        }
        
    }
    
    public void receiveSupplies(SuppliesPackage s){
        this.ammoPower=s.getAmmoPower();
        this.fuelUnits=s.getFuelUnits();
        this.shieldPower=s.getShieldPower();
    }
    
    public boolean receiveWeapon(Weapon w){
        if(hangar != null){
            return this.hangar.addWeapon(w);
        }
        
        else
            return false;
    }
    
    public void setLoot(Loot loot){
        CardDealer dealer = CardDealer.getInstance();
        int h = loot.getNHangars();
        
        if(h > 0){
            this.hangar = dealer.nextHangar();
            this.receiveHangar(hangar);
        }
        
        int elements = loot.getNSupplies();
        
        for(int i=1; i < elements; i++){
            SuppliesPackage sup = dealer.nextSuppliesPackage();
            this.receiveSupplies(sup);
        }
        
        elements = loot.getNWeapons();
        
        for(int i = 0; i < elements; i++){
            Weapon weap = dealer.nextWeapon();
            this.receiveWeapon(weap);
        }
        
        elements = loot.getNShields();
        
        for(int i=1; i < elements; i++){
            ShieldBooster sh = dealer.nextShieldBooster();
            this.receiveShieldBooster(sh);
        }
        
        int medals = loot.getNMedals();
        
        this.nMedals += medals;
    }
    
    public void setPendingDamage(Damage d){
        this.pendingDamage=d.adjust(this.weapons, this.shieldBoosters);
        this.cleanPendingDamage();
    }
    
    public boolean validState(){
        if(this.pendingDamage == null || this.pendingDamage.hasNoEffect())
            return true;
        
        else
            return false;
    }
    
    public String toString(){
        String salida ="Combustible Máximo: " + MAXFUEL + "\nUnidades de Escudo Perdidas por Disparo: " + SHIELDLOSSPERUNITSHOT;
        salida = salida + "\nPotencia de fuego: " + ammoPower + "\nUnidades de Combustible: " + fuelUnits + "\nNombre: " + name;
        salida = salida + "\nNº de Medallas: " + nMedals + "\nPoder de Escudo: " + shieldPower;
        
        if(weapons != null){
            salida = salida + "\nArmas de la Estación: ";
            
            for(int i=0; i < weapons.size(); i++)
                salida = salida + weapons.get(i).toString();
            
        }
        
        if(shieldBoosters != null){
            salida = salida + "\nEscudos de la Estación: ";
            
            for(int i=0; i < shieldBoosters.size(); i++)
                salida = salida + shieldBoosters.get(i).toString();
        }
        
        if(pendingDamage != null)
            salida = salida + "\nDaño pendiente: " + pendingDamage;

        if(hangar != null)  
            salida = salida + "\nHangares de la Estación: " + hangar;
        
        return salida;
    }
}
