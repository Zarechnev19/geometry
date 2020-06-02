#include <check_data_strokes.h>
#include <ctest.h>

CTEST(data_suite, figure_invalid_name)
{
    char str[] = "circlewwww(10 1, 2)";
    const int result = check_data_strokes(str);
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, figure_invalid_name_one_uppercase_letter)
{
    char str[] = "ciRcle(10 1, 2)";
    const int result = check_data_strokes(str);
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, figure_invalid_name_all_uppercase_letters)
{
    char str[] = "CIRLCE(10 1, 2)";
    const int result = check_data_strokes(str);
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, figure_invalid_name_invalid_character)
{
    char str[] = "circ/le(10 1, 2)";
    const int result = check_data_strokes(str);
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, input_format_extra_brackets)
{
    char str[] = "circle((1.5 1.5, 234))";
    const int result = check_data_strokes(str);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, input_format_extra_commas)
{
    char str[] = "circle(1.5 1.5, ,2)";
    const int result = check_data_strokes(str);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, input_format_extra_spaces)
{
    char str[] = "circle((1.5  1.5,  234))";
    const int result = check_data_strokes(str);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, input_format_no_x_coord)
{
    char str[] = "circle( 1.5, 234)";
    const int result = check_data_strokes(str);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, input_format_no_y_coord)
{
    char str[] = "circle(1.5 , 234)";
    const int result = check_data_strokes(str);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, input_format_no_radius)
{
    char str[] = "circle(1.5 1.5, )";
    const int result = check_data_strokes(str);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, input_format_no_input)
{
    char str[] = "circle()";
    const int result = check_data_strokes(str);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, invalid_input_format_and_name)
{
    char str[] = "circsele((1.5 1.5, 24))";
    const int result = check_data_strokes(str);
    const int expected = 3;

    ASSERT_EQUAL(expected, result);
}

CTEST(data_suite, invalid_input_format_minus_radius)
{
    char str[] = "circle(1.5 1.5, -24)";
    const int result = check_data_strokes(str);
    const int expected = 2;

    ASSERT_EQUAL(expected, result);
}
