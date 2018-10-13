/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sliderapp;

/**
 *
 * @author badhr
 */
public class SliderControl {
    private SliderObserver[] observer = new SliderObserver[10];
    private int pos,value;
    public void addSlider(SliderObserver observer){
        this.observer[pos++] = observer;
    }
    public void Notify(int value){
        if(this.value != value){
            this.value = value;
            this.setValue(value);
        }
    }
    public void setValue(int value){
        for(int i = 0; i<pos; i++){
            observer[i].update(value);
        }
    }
}
