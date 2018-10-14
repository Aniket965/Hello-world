package HelloWorld;

public class Hello {

    public static void main(String[] args) {
        System.out.println("Hello world");

        System.out.println("Hey there is pratikpalashikar ");
        System.out.println("0.0 Here's your gift 0.0 ");
         pattern(7); 

         System.out.println("")
         System.out.println("Hello World!");
         System.out.println("This is Nasif Nuha from Sri Lanka");
         pattern(7);
        
        System.out.println("")
         System.out.println("Hello World!");
         System.out.println("This is Uvaish Zafri from india");
         pattern(7);
        
         System.out.println("")
         System.out.println("Hello World!");

    }




    
    
     static void pattern(int n) 
    { 
        int i, j; 
  
        // This is upper half of pattern 
        for (i = 1; i <= n; i++) { 
            for (j = 1; j <= (2 * n); j++) { 
                  
                // Left part of pattern 
                if (i < j) 
                    System.out.print(" "); 
                else
                    System.out.print("*"); 
  
                // Right part of pattern 
                if (i <= ((2 * n) - j)) 
                    System.out.print(" "); 
                else
                    System.out.print("*"); 
            } 
              
            System.out.println(""); 
        } 
  
        // This is lower half of pattern 
        for (i = 1; i <= n; i++) { 
            for (j = 1; j <= (2 * n); j++) { 
                  
                // Left part of pattern 
                if (i > (n - j + 1)) 
                    System.out.print(" "); 
                else
                    System.out.print("*"); 
  
                // Right part of pattern 
                if ((i + n) > j) 
                    System.out.print(" "); 
                else
                    System.out.print("*"); 
            } 
              
            System.out.println(""); 
        } 
    } 
    
}
