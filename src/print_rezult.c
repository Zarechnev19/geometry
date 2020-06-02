#include "find_intersections.h"
#include "get_area.h"
#include "get_perimeter.h"
#include <math.h>
#include <stdio.h>

void print_rezult(int countStr, float coordsX[], float coordsY[], float rad[])
{
    int i, j;

    for (i = 0; i < countStr; i++) {
        printf("%d circle(%.2f %.2f, %.2f) \n",
               i + 1,
               coordsX[i],
               coordsY[i],
               rad[i]);
        printf("   perimetr = %.2f\n   area = %.2f\n   intersects:\n",
               get_perimeter(rad[i]),
               get_area(rad[i]));

        for (j = 0; j < countStr; j++) {
            if (j == i)
                continue;

            if (find_intersections(
                        rad[i],
                        rad[j],
                        coordsX[i],
                        coordsX[j],
                        coordsY[i],
                        coordsY[j]))
                printf("    %d. circle\n", j + 1);
        }
        printf("\n");
    }
}
