#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int i = 0;
	int j = 0;
	int k = 0;
	int product = 0;
	int ** resultantMat;
	resultantMat = (int**)malloc(size * sizeof(int*));

	for (i = 0; i < size; i++){
		*(resultantMat + i) = (int*)malloc(size * sizeof(int));
	}

	for (i = 0; i < size; i++){ // Traverse row of first matrix
		for (j = 0; j < size; j++){ // Traverse column of second matrix
			for (k = 0; k < size; k++){ // Keep track of multiplying rows by columns
				product = product + *(*(a + i) + k) * *(*(b + k) + j); // Row number of matrix A multiplied by column number of matrix B
			}
			*(*(resultantMat + i) + j) = product; // Store the indexing [i][j] of resultant matrix with the product found above
			product = 0; // Reset product
		}
	}
	return resultantMat;
	
}

void printArray(int **arr, int n) {
	// (2) Implement your printArray function here
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
	printf("\n");

}

int main() {
	int n = 3;
	int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices). 
	int i = 0;
	int j = 0;
	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));

	for (i = 0; i < n; i++){ // Allocate memory for matA
		*(matA + i) = (int*)malloc(n * sizeof(int*));
	}

	for (i = 0; i < n; i++){ // Allocate memory for matB
		*(matB + i) = (int*)malloc(n * sizeof(int*));
	}
	
	/* ================================================= */

	for (i = 0; i < n; i++){ 
		for (j = 0; j < n; j++){
			*(*(matA + i) + j) = ((n - i) * (n - j));
		}
	}

	for (i = 0; i < n; i++){ 
		for (j = 0; j < n; j++){
			*(*(matB + i) + j) = ((n + i) * (n + j));
		}
	}


	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printArray(matB, n);
	
	// (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	
	// (6) Call printArray to print out resulting array here.
	printArray(matC, n);

    return 0;
}