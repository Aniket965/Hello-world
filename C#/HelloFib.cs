using System;

namespace HelloHacktober{
    public class LetsGo{
        public static String Fibonacci(int n){
            if(n < 2){
                return "Hello World ";
            }
            else{
                return Fibonacci(n-1) + Fibonacci(n-2);
            }
        }
        public static void main(String[] args){
            Console.write(Fibonacci(1));
        }
    }
}