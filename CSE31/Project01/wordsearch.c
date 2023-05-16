#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;

int** path;
void toUpper(char* word);
int recursiveSearch(char** arr, char* word, int i, int j, int l);
void firstLetterSearch(char** arr, char* word);
void formatPath();

int found = 0;

// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
} 

// ---------------------------------------------------------------------- //

void printPuzzle(char** arr) { // Prints original puzzle
    for (int i = 0; i < bSize; i++){
        for (int j = 0; j < bSize; j++){
            printf("%c ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");

}

void searchPuzzle(char** arr, char* word) {
    toUpper(word); // Uppercase conversion

    path = (int**)malloc(bSize * sizeof(int*)); // Allocate memory for path
	for (int i = 0; i < bSize; i++){
		*(path + i) = (int*)malloc(bSize * sizeof(int));
    	for (int j = 0; j < bSize; j++){
		    *(*(path + i) + j) = 0; // Set path to 0's
	    }
    }

    firstLetterSearch(arr, word);

    if (found == 0){
        printf("Word not found! \n");
    }
    else {
        printf("Word found! \n");
        printf("Printing the search path: \n");
        formatPath();
    }
}

void toUpper(char* word){ 
    int i = 0;
    while (*(word + i) != '\0'){
        if (*(word + i) >= 'a' && *(word + i) <= 'z'){
            *(word + i) = *(word + i) - 32;
        }
        i++;
    }
}

void firstLetterSearch(char** arr, char* word){
    for (int i = 0; i < bSize; i++){
        for (int j = 0; j < bSize; j++){
            if (*(word + 0) == *(*(arr + i) + j)){ // Check if first index of word is equal to puzzle[i][j] (row & column)
                recursiveSearch(arr, word, i, j, 1);
                found++;
            }
        }
    }
}

int recursiveSearch(char** arr, char* word, int i, int j, int l){
    if (*(word + l) == '\0'){ // Checking last letter in word and when to stop
        *(*(path + i) + j) = *(*(path + i) + j) * 10; // Multiple occurences of letter
        *(*(path + i) + j) = *(*(path + i) + j) + l; // Incrementing the next letter to search in word                         
        found++;
        return 1; // Return false if cannot find first letter
    }

    for (int dI = -1; dI <= 1; dI++){ // Check around the first letter
        for (int dJ = -1; dJ <= 1; dJ++){ // If out of range
            if ((dI == 0) && (dJ == 0)){
                continue;
            }
            if (dI + i < 0 || dI + i >= bSize){
                continue;
            }
            if (dJ + j < 0 || dJ + j >= bSize){
                continue;
            }
            if (*(word + l) == *(*(arr + i + dI) + j + dJ)){
                if (recursiveSearch(arr, word, i + dI, j + dJ, l + 1)){
                    *(*(path + i) + j) = *(*(path + i) + j) * 10; // Multiple occurences of letter
                    *(*(path + i) + j) = *(*(path + i) + j) + l;  // Incrementing the next letter to search in word
                    return 1;
                }
            }
        }
    }
    return 0;
}

void formatPath(){ 
    for (int i = 0; i < bSize; i++){ 
		for (int j = 0; j < bSize; j++){
            if (*(*(path + i) + j) < 10){
                printf("%d       ", *(*(path + i) + j));
            }
            else if (*(*(path + i) + j) >= 10 && *(*(path + i) + j) < 100){
                printf("%d      ", *(*(path + i) + j));
            }
            else if (*(*(path + i) + j) >= 100 && *(*(path + i) + j) < 1000){
                printf("%d     ", *(*(path + i) + j));
            }
            else if (*(*(path + i) + j) >= 1000 && *(*(path + i) + j) < 10000){
                printf("%d    ", *(*(path + i) + j));
            }
            else if(*(*(path + i) + j) >= 10000 && *(*(path + i) + j) < 100000){
                printf("%d   ", *(*(path + i) + j));
            }
            else{
                printf("%d", *(*(path + i) + j));
            }
		}
		printf("\n");
	}
}

// 1. Convert the word that you want to find into all uppercase letters (i.e. HelLo -> HELLO)
// 2. Replace all the letters in the puzzle into 0's 
// 3. Make a helper function to find nearby letters in the word
// 4. Once you find a letter, call the helper function again to search surrounding indexes
// 5. Find the first letter by looking at the 8 possible letters around the first letter
// 6. Keep calling that function to find all possible letters
// 7. If there are multiple letters in the same spot, use exponents to keep track of the search path
// Implement: Word not found! / Word found! tracker