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
public class GameUniverse {
    static private int WIN=10;
    private int currentStationIndex;
    private int turns;
    private GameStateController gameState;
    private SpaceStation currentStation;
    private ArrayList<SpaceStation> spaceStations;
    private Dice dice;
    private EnemyStarShip currentEnemy;
    
    public GameUniverse(){
        
    }
    
    public CombatResult combat(SpaceStation station, EnemyStarShip enemy){
        throw new UnsupportedOperationException();   
    }
    
    public CombatResult combat(){
        throw new UnsupportedOperationException();
    }
    
    public void discardHangar(){
        if(this.gameState.getState()==GameState.INIT || this.gameState.getState()==GameState.AFTERCOMBAT)
            this.currentStation.discardHangar();
    }
    
    public void discardShieldBooster(int i){
        if(this.gameState.getState()==GameState.INIT || this.gameState.getState()==GameState.AFTERCOMBAT)
            this.currentStation.discardShieldBooster(i);
    }
    
    public void discardShieldBoosterInHangar(int i){
        if(this.gameState.getState()==GameState.INIT || this.gameState.getState()==GameState.AFTERCOMBAT)
            this.currentStation.discardShieldBoosterInHangar(i);
    }
    
    public void discardWeapon(int i){
        if(this.gameState.getState()==GameState.INIT || this.gameState.getState()==GameState.AFTERCOMBAT)
            this.currentStation.discardWeapon(i);
    }
    
    public void discardWeaponInHangar(int i){
        if(this.gameState.getState()==GameState.INIT || this.gameState.getState()==GameState.AFTERCOMBAT)
            this.currentStation.discardWeaponInHangar(i);      
    }
    
    public GameState getState(){
        return this.gameState.getState();
    }
    
    public GameUniverseToUI getUIversion(){
        return new GameUniverseToUI(this.currentStation, this.currentEnemy);
    }
    
    public boolean haveAWinner(){
        if(this.currentStation.getNMedals() == WIN)
            return true;
        
        else
            return false;
    }
    
    public void init(ArrayList<String> names){
        throw new UnsupportedOperationException();
    }
    
    public void mountShieldBooster(int i){
        if(this.gameState.getState()==GameState.INIT || this.gameState.getState()==GameState.AFTERCOMBAT)
            this.currentStation.mountShieldBooster(i);
    }
    
    public void mountWeapon(int i){
        if(this.gameState.getState()==GameState.INIT || this.gameState.getState()==GameState.AFTERCOMBAT)
            this.currentStation.mountWeapon(i);
    }
    
    public boolean nextTurn(){
        throw new UnsupportedOperationException();
    }
    
}
