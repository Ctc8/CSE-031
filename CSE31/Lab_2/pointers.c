#include <stdio.h>

int main(){
    int x = 3;
    int y = 5;
    int *px; //initialize pointer
    int *py; //initialize pointer
    px = &x; //px points to x
    py = &y; //py points to y
    int arr[10];

    printf("Address of x: %p\n", &x);
    printf("Address of y: %p\n", &y);
    printf("Value of x: %p\n", &x);
    printf("Value of y: %p\n", &y);

    printf("%d\n", arr[0]);

    for (char i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){ 
        printf("%d, ", *(arr + i));
    }

    return 0;
}