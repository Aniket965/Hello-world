import java.util.Scanner;

class MergeCount{
int inv1 = 0;

void merge(int arr[], int l,int m, int r){
int n1 = m - l + 1;
int n2 = r - m;
int leftArray[] = new int [n1];
int rightArray[] = new int [n2];

for(int i=0; i<n1; i++){
leftArray[i] = arr[l+i];
}
for(int j=0; j<n2; j++){
rightArray[j] = arr[m+1+j];
}

int i=0, j=0;

int k = l;
while(i<n1 && j<n2){
if(leftArray[i] <= rightArray[j]){
arr[k] = leftArray[i];
i++;
}
else{
arr[k] = rightArray[j];
j++;
inv1 += (n1-i);
}
k++;
}

while(i < n1){
arr[k] = leftArray[i];
i++;
k++;
}

while(j < n2){
arr[k] = rightArray[j];
j++;
k++;
}
}

void sort(int arr[], int leftIndex, int rightIndex){
if(leftIndex < rightIndex){
int middleIndex = (leftIndex+rightIndex)/2;
sort(arr,leftIndex,middleIndex);
sort(arr,middleIndex + 1, rightIndex);
merge(arr, leftIndex, middleIndex, rightIndex);
}
}
}
class Main{
public static void main(String arg[]){


Scanner sc = new Scanner(System.in);

int t;
t = sc.nextInt();
for(;t>0;t--){
int n;
n = sc.nextInt();

int[] arr = new int[1000];
int i;
for(i=0;i<n;i++){
arr[i] = sc.nextInt();
}
MergeCount sorter = new MergeCount();
sorter.sort(arr,0,i - 1);
System.out.print(sorter.inv1);
System.out.println();
}
}
}
