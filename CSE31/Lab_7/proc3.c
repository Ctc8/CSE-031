#include<stdio.h>

int bar(int a, int b, int c) {
    return (b - a) << (c);                  // p = (5 - 4) << 3 = 8
}                                           // q = (-1 - -2) << 4 = 16

int foo(int m, int n, int o) {
    int p = bar(m + o, n + o, m + n);       // p = bar(1 + 3, 2 + 3, 1 + 2) { (4, 5, 3) }
    int q = bar(m - o, n - m, n + n);       // q = bar(1 - 3, 2 - 3, 2 + 2) { (-2, -1, 4) }
    printf("p + q: %d\n", p + q);           
    return p + q;
}

int main() {
    int x = 1, y = 2, z = 3;
    
    z = x + y + z + foo(x, y, z);
    
    printf("z: %d\n", z);
    
    return 0;
}


// z = 1 + 2 + 3 + foo(1, 2, 3)