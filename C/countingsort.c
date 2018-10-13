#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int max(int* arr, int len) {
	int out = arr[0];
	for (int i = 0; i < len; i++)
		if (arr[i] > out)
			out = arr[i];
	return out;
}

void sort(int* inputs, int* outputs, size_t length) {
	// this is the size of the array of counts
	int greatest = max(inputs, length);	// find the greatest number in the array

	// allocate the array of counts
	int* counts = calloc(greatest + 1, sizeof(int));

	// count numbers in input array
	for (int i = 0; i < length; i++) {
		counts[inputs[i]]++;
	}

	int counter = 0;	// keep track of where we are in output array

	// loop through all the counts
	for (int i = 0; i < (greatest + 1); i++) {	// for every count in array
		for (int j = 0; j < counts[i]; j++) {	// loop that many times
			outputs[counter++] = i;	// add the integer being counted to the output array
		}
	}
	free(counts);
}

int main(int argc, char** argv) {
	int *inputs, *outputs;
	size_t length = argc - 1;	// number of integers to sort
	inputs = malloc(sizeof(int) * (argc - 1));
	outputs = malloc(sizeof(int) * (argc - 1));

	for (int i = 1; i < argc; i++) {
		inputs[i - 1] = atoi(argv[i]);	// assign arguments to array
	}

	sort(inputs, outputs, length);

	for (size_t i = 0; i < (length); i++) {
		printf("%d ", outputs[i]);	// print space separated sorted numbers
	}
	printf("\n");

	free(inputs);
	free(outputs);

	return 0;
}
