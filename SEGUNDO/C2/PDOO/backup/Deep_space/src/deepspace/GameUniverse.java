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
        this.gameState = new GameStateController();
        this.turns = 0;
        this.dice = new Dice();
    }
    
    CombatResult combat(SpaceStation station, EnemyStarShip enemy){
        GameCharacter ch = dice.firstShot();
        boolean enemyWins;
        CombatResult combatResult;
        
        if(ch == GameCharacter.ENEMYSTARSHIP){
            float fire = enemy.fire();
            
            ShotResult result = station.receiveShot(fire);
            
            if(result == ShotResult.RESIST){
                fire = station.fire();
                
                result = enemy.receiveShot(fire);
                
                
                enemyWins = (result == ShotResult.RESIST);
            }
            
            else{
                enemyWins = true;
            }   
        }
        
        else{
            float fire = station.fire();
            ShotResult result = enemy.receiveShot(fire);
            enemyWins = (result == ShotResult.RESIST);
        }
        
        if(enemyWins){
            float s = station.getSpeed();
            
            boolean moves = dice.spaceStationMoves(s);
            
            if(!moves){
                Damage damage = enemy.getDamage();
                station.setPendingDamage(damage);
                combatResult = CombatResult.ENEMYWINS;
            }
            
            else{
                station.move();
                
                combatResult = CombatResult.STATIONESCAPES;
            }
            
        }
        
        else{
            Loot aLoot = enemy.getLoot();
            
            station.setLoot(aLoot);
            
            combatResult = CombatResult.STATIONWINS;
        }
        
        gameState.next(turns, spaceStations.size());
        
        return combatResult;
    }
    
    public CombatResult combat(){
        GameState state=gameState.getState();
        
        if(state == GameState.BEFORECOMBAT || state == GameState.INIT){
            return this.combat(currentStation, currentEnemy);
        }
        
        else
            return CombatResult.NOCOMBAT;
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
        GameState state = gameState.getState();
        
        if(state == GameState.CANNOTPLAY){
            spaceStations = new ArrayList<SpaceStation>();
            
            CardDealer dealer = CardDealer.getInstance();
            
            for(int i=0; i < names.size(); i++){
                SuppliesPackage supplies = dealer.nextSuppliesPackage();
                SpaceStation station = new SpaceStation(names.get(i), supplies);
                
                spaceStations.add(station);
                
                int nh = dice.initWithNHangar();
                int nw = dice.initWithWeapons();
                int ns = dice.initWithNShields();
                
                Loot lo = new Loot(0,nw,ns,nh,0);
                
                station.setLoot(lo);
            }
            
            currentStationIndex = dice.whoStarts(names.size());
            
            currentStation = spaceStations.get(currentStationIndex);
            
            currentEnemy = dealer.nextEnemy();
            
            gameState.next(turns, spaceStations.size());
        }
        
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
        boolean salida;
        GameState state = gameState.getState();
        
        if(state == GameState.AFTERCOMBAT){
            boolean stationState = currentStation.validState();
            
            if(stationState){
                currentStationIndex=(currentStationIndex + 1)%spaceStations.size();
                turns++;
                
                currentStation = spaceStations.get(currentStationIndex);
                currentStation.cleanUpMountedItems();
                
                CardDealer dealer = CardDealer.getInstance();
                
                currentEnemy = dealer.nextEnemy();
                
                gameState.next(turns, spaceStations.size());
                
                return true;
            }
            
            return false;
        }
        
        return false;
    }
    
    @Override
    public String toString(){
        String salida= "Medallas necesarias para ganar: " + WIN;
        salida = salida + "\nIndice Estación Actual: " + currentStationIndex + "\nTurnos: " + turns;
        
        if(gameState.getState() == GameState.AFTERCOMBAT)
            salida = salida + "\nEstado: AFTERCOMBAT";
        
        else if(gameState.getState() == GameState.BEFORECOMBAT)
            salida = salida + "\nEstado: BEFORECOMBAT";
        
        else if(gameState.getState() == GameState.CANNOTPLAY)
            salida = salida + "\nEstado: CANNOTPLAY";
        
        else
            salida = salida + "\nEstado: INIT";
        
        salida = salida + "\nEstación actual: " + currentStation.toString() + "\nLista de Estaciones Espaciales: \n";
        
        if(spaceStations != null){
            for(int i=0; i < spaceStations.size(); i++)
                salida = salida + spaceStations.get(i).toString();
        }
        
        salida = salida + "\nDice: " + dice.toString();
        salida = salida + "Nave Enemiga Actual: " + currentEnemy + "\n";
        
        return salida;        
    }
    
}
