#include <stdio.h>
#include <stdlib.h>

void printArray(int**, int);

int main() {
	int i = 0, j = 0, n = 5;
	int **arr = (int**)malloc(n * sizeof(int*));

	// (3) Add your code to complete allocating and initializing the 2-D array here. The content should be all 0.
	for (i = 0; i < n; i++){
		*(arr + i) = (int*)malloc(n * sizeof(int*));
	}

	for (j = 0; j < n; j++){
		*(arr + j) = (int*)malloc(n * sizeof(int*));
	}

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			*(*(arr + i) + j) = 0;
		}
	}

    // This will print out your array
	printArray(arr, n);

    // (6) Add your code to make arr a diagonal matrix
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i == j){
				*(*(arr + i) + j) = j + 1; // If the first row index is equal to second row index then add one to the second row's index.
			}
		}
	}

	printArray(arr, n);
	// (7) Call printArray to print array
    
	return 0;
}

void printArray(int ** array, int size) {
	int i = 0;
	int j = 0;

	for (i = 0; i < size; i++){ 
		for (j = 0; j < size; j++){
			printf("%d ", *(*(array + i) + j));
		}
		printf("\n");
	}
	printf("\n");
    // (5) Implement your printArr here:

}
