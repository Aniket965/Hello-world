/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package watermeasure;

/**
 *
 * @author badhr
 */
public class ControlRoom {
    WaterLevelObserver[] lists = new WaterLevelObserver[10];
    int pos;
    int Value;
    public void addObserver(WaterLevelObserver waterLevelObserver){
        this.lists[pos++] = waterLevelObserver;
    }
    public void setWaterLevel(int Value){
        if(this.Value != Value){
            this.Value = Value;
            this.Notify();
        }
    }
    public void Notify(){
        for(int i = 0; i< pos ; i++){
            lists[i].display(Value);
        }
    }
    
}
