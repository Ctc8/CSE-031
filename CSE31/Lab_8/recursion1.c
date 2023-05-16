
#include<stdio.h>

int recursion(int m) {
    if(m == -1)                     // 1) If number is -1 return 3
        return 3;
    else if(m <= -2) {              // 2) If number is less than or equal to -2 enter this block
        if (m < -2)                 // 3) If number is less than -2 return 2
            return 2;               
        else
            return 1;               // 4) If number is -2 return 1
    }
    else 
        return recursion(m - 3) + m + recursion(m - 2);  
}                                                            

int main() {
    int x;
    printf("Please enter a number: ");
	scanf("%d", &x);
    printf("%d\n", recursion(x));
    return 0;
}
