import java.util.Scanner;

class StrassenMult{
int[][] mult(int[][] A, int[][] B){

int n = A.length;
int[][] C = new int[n][n];

if(n==1){
C[0][0] = A[0][0]*B[0][0];
}

else{
int[][] A11 = new int[n/2][n/2];
int[][] A12 = new int[n/2][n/2];
int[][] A21 = new int[n/2][n/2];
int[][] A22 = new int[n/2][n/2];
int[][] B11 = new int[n/2][n/2];
int[][] B12 = new int[n/2][n/2];
int[][] B21 = new int[n/2][n/2];
int[][] B22 = new int[n/2][n/2];

divide(A,A11,0,0);
divide(A,A12,0,n/2);
divide(A,A21,n/2,0);
divide(A,A22,n/2,n/2);
divide(B,B11,0,0);
divide(B,B12,0,n/2);
divide(B,B21,n/2,0);
divide(B,B22,n/2,n/2);

int[][] P1 = mult(add(A11,A22), add(B11,B22));
int[][] P2 = mult(add(A21,A22), B11);
int[][] P3 = mult(A11,sub(B12,B22));
int[][] P4 = mult(A22,sub(B21,B11));
int[][] P5 = mult(add(A11,A12), B22);
int[][] P6 = mult(sub(A21,A11), add(B11,B12));
int[][] P7 = mult(sub(A12,A22), add(B21,B22));

int[][] C11 = add(sub(add(P1,P4),P5),P7);
int[][] C12 = add(P3,P5);
int[][] C21 = add(P2,P4);
int[][] C22 = add(sub(add(P1,P3),P2),P6);

conquer(C11,C,0,0);
conquer(C12,C,0,n/2);
conquer(C21,C,n/2,0);
conquer(C22,C,n/2,n/2);

}
return C;
}

void divide(int[][] P, int[][] R, int i, int j){
for(int k=0,l=i; k<R.length; k++,l++){
for(int m=0,n=j; m<R.length; m++,n++){
R[k][m] = P[l][n];
}
}
}

int[][] sub(int[][] A, int[][] B){
int n = A.length;
int[][] R = new int[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
R[i][j] = A[i][j] - B[i][j];
}
}
return R;
}

int[][] add(int[][] A, int[][] B){
int n = A.length;
int[][] R = new int[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
R[i][j] = A[i][j] + B[i][j];
}
}
return R;
}

void conquer(int[][] R, int[][] C, int i, int j){
for(int k=0,l=i; k<R.length; k++,l++){
for(int m=0,n=j; m<R.length; m++,n++){
C[l][n] = R[k][m];
}
}
}

int nextPowerOf2(int n){
int count = 0;
if (n > 0 && (n & (n - 1)) == 0)
return n;
while(n != 0)
{
n >>= 1;
count += 1;
}
return 1 << count;
}
}

class Main{

public static void main(String[] args){
Scanner sc = new Scanner(System.in);

int t=0;
t = sc.nextInt();
for(;t>0;t--){

StrassenMult sm = new StrassenMult();
int n = sc.nextInt();

int p = sm.nextPowerOf2(n);

int[][] A = new int[p][p];
for(int i=0; i<n;i++){
for(int j=0; j<n;j++){
A[i][j] = sc.nextInt();
}
}

int[][] B = new int[p][p];
for(int i=0; i<n;i++){
for(int j=0; j<n;j++){
B[i][j] = sc.nextInt();
}
}



int[][] C  = sm.mult(A,B);

for(int i=0; i<n;i++){
for(int j=0; j<n;j++){
System.out.print(C[i][j]+ " ");
}
System.out.println();
}
}
}
}
