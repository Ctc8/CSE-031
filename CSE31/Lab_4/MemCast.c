#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i = 0; i < 4; i++)
        four_ints[i] = 2;

	printf("%x\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	for(i = 0; i < 4; i++)
        four_c[i] = 'A' + i; // ASCII value of 'A' is 65 or 0x41 in Hex.
    
    // Add your code for the exercises here:
	printf("%x\n", four_ints[0]);
	printf("Number 3: %x\n", four_ints[0]); // 3.
	printf("Number 4: %x\n", four_ints[1]); // 4.
	

	// for (i = 0; i < 4; i++){			// 5.
	// 	printf("%c ", four_ints[i]);
	// }

	// for (i = 0; i < 4; i++){
	// 	printf("%c", four_c[i]);
	// }


	printf("Number 6: ");
	for (i = 0; i < 4; i++){			// 6.
		printf("%c ", four_ints[i]);
	}
	printf("\n");

	printf("Number 8: ");
	for (i = 0; i < 4; i++){
		printf("%c ", four_c[i]);
	}
	printf("\n");
	
	return 0;
}