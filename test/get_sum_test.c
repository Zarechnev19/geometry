#include <ctest.h>
#include <get_sum.h>

CTEST(arithmetic_suite, simple_sum)
{
    const int a = 1;
    const int b = 1;
    const int result = get_sum(a, b);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}
