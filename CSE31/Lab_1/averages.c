#include <stdio.h>

int sumOfDigits(int n){
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int main(){
    int n;

    float totalEVEN = 0; //total
    float totalODD = 0;

    int countEVEN = 0; //counter
    int countODD = 0; 

    int i = 1; //iterator

    while (n != 0){
        if ((i % 10 == 1) && (i % 100 != 11)){
            printf("Enter the %dst value: ", i);
            scanf("%d", &n);
            i++;
        }
        else if ((i % 10 == 2) && (i % 100 != 12)){
            printf("Enter the %dnd value: ", i);
            scanf("%d", &n);
            i++;
        }
        else if ((i % 10 == 3) && (i % 100 != 13)){
            printf("Enter the %drd value: ", i);
            scanf("%d", &n);
            i++;
        }
        else {
            printf("Enter the %dth value: ", i);
            scanf("%d", &n);
            i++;
        }

        if (sumOfDigits(n) % 2 == 0){
            if (n == 0){
                continue;
            }
            totalEVEN = totalEVEN + n;
            countEVEN++;
        }
        else {
            totalODD = totalODD + n;
            countODD++;
        }
    }  
    
    totalEVEN = totalEVEN / countEVEN;
    totalODD = totalODD / countODD;

    if (countEVEN != 0){
        printf("Average of inputs whose digits sum up to an even number: %.2f\n", totalEVEN);
    }
    if (countODD != 0){
        printf("Average of inputs whose digits sum up to an odd number: %.2f\n", totalODD);
    }
    else if (countEVEN == 0){
        printf("There is no average to compute.\n");
    }
    else if (countODD == 0){
        printf("There is no average to compute.\n");
    }

    return 0;
}


