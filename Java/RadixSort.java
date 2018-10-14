import java.util.*;

public class RadixSort{
    public int[] array;

    public RadixSort(int[] array){
        this.array = array;
    }

    public void sort(int d){ 
        int n = array.length;
        int output[] = new int[n]; 
        int counter[] = new int[10];
        int position = 1;
        for(int j = 0; j < d; j++){                     
            for(int i = 0; i < 10; i++){
                counter[i] = 0;
            }        
                
            for(int i = 0; i < n; i++){            
                counter[ ( array[i] / position ) %10 ]++;
            }
            
            for (int i = 1; i < 10; i++){
                counter[i] = counter[i] + counter[i - 1];   
            }
            
            for(int i = n - 1; i >= 0; i--){
                output[ counter[ (array[i] / position) % 10 ] - 1 ] = array[i];
                counter[ ( array[i] / position ) % 10]--;
            }

            for(int i = 0; i < n; i++){
                int temp = array[i];
                array[i] = output[i];
                output[i] = temp;
            }

            position = position * 10;
        }  
    }

    public String toString(){
        String result = "[ ";
        for(int i = 0; i < this.array.length; i++){
            result = result + this.array[i] + "; ";
        }
        return result + "]" ;
    }
    
    public static void main(String args[]){
        int array[] = new int[10];
        Random random = new Random();
        for(int i = 0; i < 10; i++){
            array[i] = random.nextInt(100);
        }         

        RadixSort orderedArray = new RadixSort(array);
        System.out.println("Array:" + orderedArray.toString());
        orderedArray.sort(2);
 
        System.out.println("Sorted Array: " + orderedArray.toString());
    }
}