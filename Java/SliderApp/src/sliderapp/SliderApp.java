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
public class SliderApp {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        SliderControl sliderControl = new SliderControl();
        sliderControl.addSlider(new SliderWindow(sliderControl));
        sliderControl.addSlider(new SliderWindow(sliderControl));
        sliderControl.addSlider(new SliderWindow(sliderControl));
    }
    
}
