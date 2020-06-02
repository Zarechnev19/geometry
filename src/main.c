#include "check_data_strokes.h"
#include "get_count_strokes.h"
#include "get_data.h"
#include "print_rezult.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int countStr;
    char *p, bufer[255], fileName[] = "input.txt";
    FILE* input;
    countStr = get_count_strokes(fileName);
    int i, j, isValid, rezults[countStr];
    i = 0;
    isValid = 1;

    input = fopen(fileName, "r");
    p = fgets(bufer, 255, input);

    while (p != NULL) {
        rezults[i] = check_data_strokes(p);
        i++;
        p = fgets(bufer, 255, input);
    }
    fclose(input);
    input = fopen(fileName, "r");
    p = fgets(bufer, 255, input);

    i = 0;
    while (p != NULL) {
        if (rezults[i] == 1) {
            printf("Error: unknow figure \'");
            for (j = 0; p[j] != '('; j++)
                printf("%c", p[j]);
            printf("\'\n");
            isValid = 0;

        } else if (rezults[i] == 2) {
            printf("Error: invalid input format %s", p);
            isValid = 0;

        } else if (rezults[i] == 3) {
            printf("Error: unknow figure \'");
            for (j = 0; p[j] != '('; j++)
                printf("%c", p[j]);
            printf("\n");
            printf("Error: invalid input format %s", p);
            isValid = 0;
        }
        i++;
        p = fgets(bufer, 255, input);
    }
    fclose(input);

    if (isValid) {
        float coordsX[countStr], coordsY[countStr], rad[countStr];

        get_data(fileName, countStr, coordsX, coordsY, rad);
        print_rezult(countStr, coordsX, coordsY, rad);
    }

    return 0;
}
