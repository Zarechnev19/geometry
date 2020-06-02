#include <ctest.h>
#include <get_area.h>

CTEST(perimetr_suite, area_test)
{
    const float PI = 3.14;
    const float result = get_area(1.2);
    const float expected = PI * 1.2 * 1.2;

    ASSERT_DBL_NEAR(expected, result);
}
