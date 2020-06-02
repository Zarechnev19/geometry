#include <ctest.h>
#include <get_perimeter.h>

CTEST(perimetr_suite, perimetr_test)
{
    const float PI = 3.14;
    const float result = get_perimeter(2.3);
    const float expected = 2 * PI * 2.3;

    ASSERT_DBL_NEAR(expected, result);
}
