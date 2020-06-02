#include <ctest.h>
#include <find_intersections.h>

CTEST(intersections_suite, intersect)
{
    float first_rad = 1.5;
    float second_rad = 6.5;
    float first_x = 10;
    float second_x = 3;
    float first_y = 1;
    float second_y = 0;
    const int result = find_intersections(
            first_rad, second_rad, first_x, second_x, first_y, second_y);
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(intersections_suite, not_intersect)
{
    float first_rad = 1.5;
    float second_rad = 2.5;
    float first_x = 10;
    float second_x = 2;
    float first_y = 1;
    float second_y = 2;
    const int result = find_intersections(
            first_rad, second_rad, first_x, second_x, first_y, second_y);
    const int expected = 0;

    ASSERT_EQUAL(expected, result);
}
