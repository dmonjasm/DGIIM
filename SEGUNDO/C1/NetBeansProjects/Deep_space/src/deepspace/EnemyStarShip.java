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
public class EnemyStarShip {
    private float ammoPower;
    private String name;
    private float shieldPower;
    private Damage damage;
    private Loot loot;
    
    public EnemyStarShip(String n, float a, float s, Loot l, Damage d){
        this.ammoPower=a;
        this.shieldPower=s;
        this.name=n;
        this.loot=l;
        this.damage=new Damage(d);
    }
    
    public EnemyStarShip(EnemyStarShip e){
        this.ammoPower=e.getAmmoPower();
        this.shieldPower=e.getShieldPower();
        this.name=e.getName();
        this.loot=e.getLoot();
        this.damage=e.getDamage();
    }
    
    public EnemyToUI getUIversion(){
        return new EnemyToUI(this);
    }
    
    public float fire(){
        return ammoPower;
    }
    
    public float getAmmoPower(){
        return ammoPower;
    }
    
    public Damage getDamage(){
        return damage;
    }
    
    public Loot getLoot(){
        return loot;
    }
    
    public String getName(){
        return name;
    }
    
    public float getShieldPower(){
        return shieldPower;
    }
    
    public float protection(){
        return shieldPower;
    }
    
    public ShotResult receiveShot(float shot){
        if(shieldPower < shot)
            return ShotResult.DONOTRESIST;
        
        else
            return ShotResult.RESIST;
    }    
}