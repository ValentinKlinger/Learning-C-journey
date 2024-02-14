#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <regex.h>
#include <regex.h>

#define TEXT_SIZE 142


void switchPointers(char **ptr0, char **ptr1, char **ptr2) {
    char *temp = *ptr0;
    *ptr0 = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void check_2_line(char* _1ptr, char* _2ptr, int *sum) {
    for (int i = 0; i < TEXT_SIZE; i++) {
        int fst_digit = i;
        int snd_digit = -1;
        
        while (isdigit(*(_1ptr + i))) {
            
            if (i >= (TEXT_SIZE - 1)) {
                snd_digit = i;
                break;
            }
            snd_digit = i;
            i++;
        }

        if (snd_digit != -1) {
            int fst_range;
            int snd_range;

            if (fst_digit == 0) {
                fst_range = fst_digit;
                snd_range = snd_digit + 1;
            }
            else if (snd_digit == (TEXT_SIZE - 3)) {
                fst_range = fst_digit -1;
                snd_range = snd_digit;
            }
            else {
                fst_range = fst_digit - 1;
                snd_range = snd_digit + 1;
            }

            int num = 0;
            for (int j = fst_digit; j <= snd_digit; j++) {
                num = num * 10 + (*(_1ptr + j) - '0');
            }
            
            
            if (*(_1ptr + fst_range) != '.' && !isdigit(*(_1ptr + fst_range))) {
                *sum += num;
                continue;
            }
            else if (*(_1ptr + snd_range) != '.' && !isdigit(*(_1ptr + snd_range))) {
                *sum += num;
                continue;
            }

            for (int j = fst_range; j <= snd_range; j++) {

                if (*(_2ptr + j) != '.' && !isdigit(*(_2ptr + j))) {
                    *sum += num;
                    continue;
                }               
            }
        }
    }
}

void check_line(char* ptr0, char* ptr1, char* ptr2, int *sum) {
    for (int i = 0; i < TEXT_SIZE; i++) {
        int fst_digit = i;
        int snd_digit = -1;
        
        while (isdigit(*(ptr1 + i))) {
            
            if (i >= (TEXT_SIZE - 1)) {
                snd_digit = i;
                break;
            }
            snd_digit = i;
            i++;
            


        }
        if (snd_digit != -1) {
            int fst_range;
            int snd_range;

            if (fst_digit == 0) {
                fst_range = fst_digit;
                snd_range = snd_digit + 1;
            }
            else if (snd_digit == (TEXT_SIZE - 3)) {
                fst_range = fst_digit -1;
                snd_range = snd_digit;
            }
            else {
                fst_range = fst_digit - 1;
                snd_range = snd_digit + 1;
            }

            int num = 0;
            for (int j = fst_digit; j <= snd_digit; j++) {
                num = num * 10 + (*(ptr1 + j) - '0');
            }
            
            if (*(ptr1 + fst_range) != '.' && !isdigit(*(ptr1 + fst_range))) {
                *sum += num;

                continue;
            }
            else if (*(ptr1 + snd_range) != '.' && !isdigit(*(ptr1 + snd_range))) {
                *sum += num;
                continue;
                
            }

            for (int j = fst_range; j <= snd_range; j++) {
                if (*(ptr0 + j) != '.' && !isdigit(*(ptr0 + j))) {
                    *sum += num;
                    continue;
                }

                else if (*(ptr2 + j) != '.' && !isdigit(*(ptr2 + j))) {
                    *sum += num;
                    continue;
                }                
            }      
        }
    }
}

int main() {
    FILE* fptr;
    char line_0[TEXT_SIZE];
    char line_1[TEXT_SIZE];
    char line_2[TEXT_SIZE];
    char *ptr0 = line_0;
    char *ptr1 = line_1;
    char *ptr2 = line_2;
    int sum_numbers = 0;

    fptr = fopen("puzzle_input.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    fgets(ptr1, sizeof(line_1), fptr);
    fgets(ptr2, sizeof(line_2), fptr);

    check_2_line(ptr1, ptr2, &sum_numbers);

    switchPointers(&ptr0, &ptr1, &ptr2);

    while (fgets(ptr2, TEXT_SIZE, fptr))
    {


        check_line(ptr0, ptr1, ptr2, &sum_numbers);


        switchPointers(&ptr0, &ptr1, &ptr2);
    }
    
    
    check_2_line(ptr1, ptr0, &sum_numbers);
    printf("%d", sum_numbers);
    return 0;
}
