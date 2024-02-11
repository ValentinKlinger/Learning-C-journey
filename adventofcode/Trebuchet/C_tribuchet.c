#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE* fptr;
    char line[100];
    int sum = 0;

    fptr = fopen("puzzle_input.txt", "r");

    // Read each line from the file.
    while (fgets(line, sizeof(line), fptr)) {
        int fst_num = -1, snd_num = -1;
        for (int i = 0; line[i] != '\0'; i++) {

            // Check if is an integer.
            if (isdigit(line[i])) {
                // info : line[i] give the ascii code.
                fst_num = line[i] - '0';
                break;
            }
        }

        for (int i = strlen(line) -1; i != -1; i--) {
            // printf("%c\t", line[i]);
            if (isdigit(line[i])) {
                
                snd_num = line[i] - '0';
                
                break;
            }
        
        }
        sum += fst_num * 10 + snd_num;
    }

    fclose(fptr);
    printf("%d", sum);
    return 0;
}