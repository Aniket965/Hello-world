import java.util.*;

class rand{
int getRandomIntegerBetweenRange(int min, int max){
int x = (int)(Math.random()*((max-min)+1))+min;
return x;
}
}

class Main{
public static void main(String arg[]){
rand r = new rand();
char[] A = new char[5];
int[][] b = new int[3][2];

b[0][0]=48;
b[0][1]=57;
b[1][0]=65;
b[1][1]=90;
b[2][0]=97;
b[2][1]=122;

for(int i=0;i<5;i++){
int k = r.getRandomIntegerBetweenRange(0,2);
A[i]=((char)(r.getRandomIntegerBetweenRange(b[k][0],b[k][1])));
}
System.out.print(A);
System.out.println();

int count=0;
String a;
Scanner sc = new Scanner(System.in);

String c = new String(A);
//System.out.print(c);
a = sc.nextLine();
/*for(int i=0;i<5;i++){
if(A[i]==((c[i]).charAt[0])){
count++;
}
}*/

if(c.equals(a)){
System.out.print("matched");
System.out.println();
}
else{
System.out.print("not matched");
System.out.println();
}
}
}
