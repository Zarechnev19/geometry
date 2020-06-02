#include <ctest.h>
#include <get_sum.h>

CTEST(arithmetic_suite, simple_sum)
{
    const int a = 2;
    const int b = 4;
    const int result = get_sum(a, b);
    const int expected = 6;

    ASSERT_EQUAL(expected, result);
}
