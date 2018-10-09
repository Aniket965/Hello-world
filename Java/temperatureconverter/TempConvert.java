/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package temperatureconverter;

/**
 *
 * @author badhr
 */
public class TempConvert {

    private float farenheit;
    private double celsius;
    
    public void setfarenheit(float farenheit){
        this.farenheit = farenheit;
        System.out.println(this.farenheit);
    }
    public void setcelsius(float celsius){
        this.celsius = celsius;
    }
    public void ConvertToCel(){
        double num = 5.0/9.0;
        this.celsius = (num*(this.farenheit-32.00));
        System.out.println(num);
    }
    public float getfarenheit(){
        return this.farenheit;
    }
    public double getCelsius(){
        return this.celsius;
    }
}
