import java.io.*;
import java.util.*;

public class BinaryToBase10 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int baseTen = scanner.nextInt();
        scanner.close();

        int count=0, maxOfOne=0, baseToBinary=0;

        while(baseTen>=1){
            int binary = baseTen%2;
            if(binary==1){
                count++;
                maxOfOne=count;
                if(maxOfOne>baseToBinary){
                    baseToBinary=maxOfOne;
                }
            } else if(binary==0){
                count=0;
            }
            baseTen=baseTen/2;
        }
        System.out.print(baseToBinary);
    }
}
