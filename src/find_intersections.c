#include <math.h>
#include <stdio.h>

int find_intersections(
        float first_rad,
        float second_rad,
        float first_x,
        float second_x,
        float first_y,
        float second_y)
{
    float circleDistance;

    circleDistance
            = sqrt(pow(first_x - second_x, 2) + pow(first_y - second_y, 2));

    return (circleDistance < first_rad + second_rad) ? 1 : 0;
}
