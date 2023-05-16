#include <stdio.h>
#include <stdbool.h>

int main(){

    int numOfLines;
    int typoLine;

    printf("Enter the number of repetitions for the punishment phrase: ");
    scanf("%d", &numOfLines);

    while (numOfLines < 0 || numOfLines == 0){
        printf("You entered an invalid value for the number of repetitions!\n");
        printf("Enter the number of repetitions for the punishment phrase again: ");
        scanf("%d", &numOfLines);
    }

    if (numOfLines > 0){
        printf("Enter the line where you wish to introduce the typo: ");
        scanf("%d", &typoLine);
    }

    if (typoLine < 0 || typoLine == 0){
        
        while (typoLine < 0 || typoLine == 0){
            printf("You entered an invalid value for the typo placement!\n");
            printf("Enter the line where you wish to introduce the typo again: ");
            scanf("%d", &typoLine);
        }
    }

    while (typoLine > numOfLines){ // If number of typo line reqest is greater than the actual number of lines
        printf("You entered an invalid value for the typo placement!\n");
        printf("Enter the line where you wish to introduce the typo again: ");
        scanf("%d", &typoLine);
    }

    for (int i = 0; i < numOfLines; i++){
        if (i == (typoLine - 1)){
            printf("Cading in C is fun end intreseting!\n");
        }
        else {
            printf("Coding in C is fun and interesting!\n");
        }
    }

    return 0;
}