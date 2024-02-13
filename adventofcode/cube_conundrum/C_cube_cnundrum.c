#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>

#define MAX_MATCHES 5 // Max num corespondences
#define TEXT_SIZE 152 // Max len line
#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14


void find_values_re(const char* line, char* pattern, int* numcount, int arr[]) {

    regex_t regex;
    regmatch_t matches[MAX_MATCHES];
    char buffer[TEXT_SIZE];
    int reti;
    int space;

    if (pattern == "[0-9]+ red") {
        space = 4;
    }
    else if (pattern == "[0-9]+ blue") {
        space = 5;
    }
    else if (pattern == "[0-9]+ green") {
        space = 6;
    }

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(EXIT_FAILURE);
    }
    int counter = 0;
    while (1) {
        
        reti = regexec( &regex, line, MAX_MATCHES, matches, 0);
        if (reti == REG_NOMATCH) {
            break;
        } 

        else if (reti) {
            fprintf(stderr, "Metching error\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < MAX_MATCHES; i++) {
            if (matches[i].rm_so == -1) {
                break;
            }

            strncpy(buffer, line + matches[i].rm_so, matches[i].rm_eo - matches[i].rm_so - space);
            buffer[matches[i].rm_eo - matches[i].rm_so - space] = '\0';
            int number = atoi(buffer);
            arr[counter] = number;
            counter++;
        }
        line += matches[0].rm_eo;
    }
    *numcount = counter;
}


int main () {
    FILE* fptr;
    char line[TEXT_SIZE];
    char* pattern_red = "[0-9]+ red";
    char* pattern_blue = "[0-9]+ blue";
    char* pattern_green = "[0-9]+ green";
    int sum_ID = 0;
    int num_l = 0;
    bool cont = true;
    int comter;

    fptr = fopen("puzzle_input.txt", "r");

    while (fgets(line, sizeof(line), fptr)) {
        num_l++;
        cont = true;

        comter = 0;
        int values_red[MAX_MATCHES];
        find_values_re(line, pattern_red, &comter, values_red);

        for (int i = 0; i < comter; i++) {
            if (values_red[i] > MAX_RED) {
                cont = false;
            }

        }
        if (!cont) {
            continue;
        }

        comter = 0;
        int values_blue[MAX_MATCHES];
        find_values_re(line, pattern_blue, &comter, values_blue);

        for (int i = 0; i < comter; i++) {
            if (values_blue[i] > MAX_BLUE) {
                cont = false;
            }
        }

        if (!cont) {
            continue;
        }

        comter = 0;
        int values_green[MAX_MATCHES];
        find_values_re(line, pattern_green, &comter, values_green);

        for (int i = 0; i < comter; i++) {
            if (values_green[i] > MAX_GREEN) {
                cont = false;
            }
        }
        if (!cont) {
            continue;
        }

        sum_ID += num_l;
    }
    printf("%d", sum_ID);
    return 0;
}