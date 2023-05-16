#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays arr_even and arr_odd
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even;  // Dynamically allocated array with #elements = #even elements in arr (evenCount)
int *arr_odd;   // Dynamically allocated array with #elements = #odd elements in arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

void printArr(int *a, int size, char *prompt){
    if (prompt == str1){
        printf("%s", str1);
        if (arr[0] == '\0'){
            printf("%s", "empty");
        }
        for (int i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    else if (prompt == str2){
        printf("%s", str2);
        for (int i = 0; i < size; i++){
            printf("%d ", arr_even[i]);
        }
        if (arr_even[0] == '\0'){
            printf("%s", "empty");
        }
        printf("\n");
    }

    else if (prompt == str3){
        printf("%s", str3);
        for (int i = 0; i < size; i++){
            printf("%d ", arr_odd[i]);
        }
        if (arr_odd[0] == '\0'){
            printf("%s", "empty");
        }
    }
}

void arrCopy(){
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0 && arr[i] != 0){
            arr_even[evenCount] = arr[i];
            evenCount++;
        }
        
        else {
            arr_odd[oddCount] = arr[i];
            oddCount++;
        }
    }
}

int main(){
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &size);

    arr = (int*) malloc(size * sizeof(int));
    arr_even = (int*) malloc(evenCount * sizeof(int));
    arr_odd = (int*) malloc(oddCount * sizeof(int));

    for (int i = 0; i < size; i++){
        printf("Enter array element #%d: ", i+1);
        scanf("%d", &arr[i]);
    }


/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	// Print original array
    printArr(arr, size, str1);

	/// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}

// Dynamically allocate memory for arr (of appropriate size)
// Ask user to input content of arr and compute evenCount and oddCount
// Dynamically allocate memory for arr_even and arr_odd (of appropriate size)