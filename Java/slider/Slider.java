/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package slider;

/**
 *
 * @author badhr
 */
public class Slider {

    /**
     * @param args the command line arguments
     */
    private SlideChanger[] slide = new SlideChanger[10];
    private int pos;
    public void addSlider(SlideChanger slideChanger){
        slide[pos++] = slideChanger;
    }
    public void changeSlider(int val){
        for(int i = 0; i<pos; i++){
            slide[i].ChangeSlider(val);
        }
    }
    
}
