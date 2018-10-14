package fizzbuzz;

/**
 *
 * @author Guillermo Garrido
 */
public class FizzBuzz {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
 
       for (int x = 0; x <= 100; x++)
       {
           //x is divisible by both 3 and 5
           if ((x % 3) == 0 && (x % 5) == 0) 
           {
               System.out.println("FizzBuzz");
           }
           //x is divisible by 3
           else if ((x % 3) == 0)
           {
               System.out.println("Fizz");
           }
           //x is divisble by 5
           else if ((x % 5) == 0 )
           {
               System.out.println("Buzz");
           }
           //x is divisible by neither 3 nor 5
           else 
           {
               System.out.println(x);
           }
       }
    }
    
}


/** Sample Output:

FizzBuzz
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
16
17
Fizz
19
Buzz
Fizz
22
23
Fizz
Buzz
26
Fizz
28
29
FizzBuzz
31
32
Fizz
34
Buzz
Fizz
37
38
Fizz
Buzz
41
Fizz
43
44
FizzBuzz
46
47
Fizz
49
Buzz
Fizz
52
53
Fizz
Buzz
56
Fizz
58
59
FizzBuzz
61
62
Fizz
64
Buzz
Fizz
67
68
Fizz
Buzz
71
Fizz
73
74
FizzBuzz
76
77
Fizz
79
Buzz
Fizz
82
83
Fizz
Buzz
86
Fizz
88
89
FizzBuzz
91
92
Fizz
94
Buzz
Fizz
97
98
Fizz
Buzz

*/
