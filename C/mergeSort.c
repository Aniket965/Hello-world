#include <stdio.h>

void mergeSort(int input[], int size)
{
	if (size == 0 || size == 1)
		return;
	int start = 0, end = size - 1, mid;
	mid = (start + end) / 2;
	mergeSort(input, mid + 1);
	mergeSort(input + mid + 1, end - mid);
	int output[1000];
	int k = 0;
	for (int i = 0, j = mid + 1; !((i == mid + 1) && (j == end + 1));)
	{
		if (((j == end + 1) || (input[i] <= input[j])) && (i != mid + 1))
		{
			output[k] = input[i];
			i++;
			k++;
		}
		else if (((i == mid + 1) || (input[j]<input[i])) && (j != end + 1))
		{
			output[k] = input[j];
			j++;
			k++;
		}
	}
	for (int l = 0; l<size; l++)
		input[l] = output[l];


}

int main() {
	int input[1000], length;
	scanf("%d",&length);
	for (int i = 0; i < length; i++)
		scanf("%d",&input[i];
	mergeSort(input, length);
	for (int i = 0; i < length; i++) {
		printf("%d", input[i]);
	}
}