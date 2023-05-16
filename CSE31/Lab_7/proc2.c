#include<stdio.h>

int sub(int a) {
    int b = 2;
    return a - b;   // 20 - 2 = 18
}

int sum(int n) {
    int m = 15;
    return n + sub(m + n); // 5 + sub(15 + 5), 5 + 18 = 23           
}

int main() {
    int x = 5, y = 10;

    y = y + x + sum(x);

    printf("%d\n", y);
    return 0;
}

// y = 10 + 5 + (23)
// 10 + 5 + 23
// 38   