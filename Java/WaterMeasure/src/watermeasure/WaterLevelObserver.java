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
public interface WaterLevelObserver {
    public void display(int waterLevel); 

    @Override
    public boolean equals(Object obj);
}
