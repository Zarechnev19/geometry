#include <stdio.h>
#include <string.h>

int check_data_strokes(char* str)
{
    char stroke[10] = "circle(";
    int i, flag, countSpaces, countCommas, countLeftBrackets,
            countRightBrackets, countValues, isValid;
    flag = 0;
    countSpaces = 0;
    countCommas = 0;
    countLeftBrackets = 0;
    countRightBrackets = 0;
    countValues = 0;
    isValid = 1;

    for (i = 0; str[i]; i++) {
        if (str[i] == ' ')
            countSpaces++;
        if (str[i] == ',')
            countCommas++;
        if (str[i] == '(')
            countLeftBrackets++;
        if (str[i] == ')')
            countRightBrackets++;
    }

    // Проверка на правильность написания названия фигуры
    // и правильность введённых данных
    if (strncmp(str, stroke, 7) != 0
        && (countSpaces != 2 || countCommas != 1 || countLeftBrackets > 1
            || countLeftBrackets == 0 || countRightBrackets > 1
            || countRightBrackets == 0))
        flag = 3;
    else if (
            countSpaces != 2 || countCommas != 1 || countLeftBrackets > 1
            || countLeftBrackets == 0 || countRightBrackets > 1
            || countRightBrackets == 0)
        flag = 2;
    else if (strncmp(str, stroke, 7) != 0)
        flag = 1;

    // Проверка на отсутствие значений и правильность введенного радиуса
    if (flag == 0) {
        i = 0;
        while (str[i] != '(')
            i++;
        while (str[i] != ')') {
            if (str[i] == '-' && countValues == 2) {
                flag = 2;
                break;
            }
            while (str[i] == '1' || str[i] == '2' || str[i] == '3'
                   || str[i] == '4' || str[i] == '5' || str[i] == '6'
                   || str[i] == '7' || str[i] == '8' || str[i] == '9'
                   || str[i] == '0')
                i++;
            if (str[i] == ' ' && str[i - 1] != ',' && str[i - 1] != '(')
                countValues++;
            if (str[i] == ',' && countValues == 1 && str[i - 1] != ' ')
                countValues++;
            if (str[i] == ')' && countValues == 2) {
                countValues++;
                i--;
            }
            if (str[i] == ')')
                i--;

            if (str[i] == '.') {
                i++;
                if (str[i] == ' ') {
                    flag = 2;
                    isValid = 0;
                }
                while (str[i] != ' ') {
                    if (str[i] == ')') {
                        i--;
                        break;
                    }

                    if (str[i] != '1' && str[i] != '2' && str[i] != '3'
                        && str[i] != '4' && str[i] != '5' && str[i] != '6'
                        && str[i] != '7' && str[i] != '8' && str[i] != '9'
                        && str[i] != '0') {
                        if (str[i] == ',' || str[i] == ')')
                            break;
                        flag = 2;
                        isValid = 0;
                        break;
                    }
                    i++;
                }

                if (flag != 2)
                    countValues++;
                if (str[i] == ')')
                    i--;
            }
            if (isValid == 0)
                break;
            i++;
        }
        // Проверка на количество введённых значений
        if (countValues != 3)
            flag = 2;
    }

    return flag;
}
