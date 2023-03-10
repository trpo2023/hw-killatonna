#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.14159265358979323846

int main()
{
    char object[50];
    char input[50];
    char x[20], y[20], radius[20];
    char circle[] = "circle";
    int i, index;
    double x_num, y_num, radius_num, area_num, perimetr_num;

    int bracket_open = 0, bracket_close = 0, comma_counter = 0;
    int error_bracket_open = 0, error_bracket_close = 0;

    for (int i = 0; i < 50; i++) {
        object[i] = '\0';
        input[i] = '\0';
    }

    fgets(input, sizeof(input), stdin);

    for (int j = 0; j < strlen(input); j++) {
        input[j] = tolower(input[j]);
    }

    for (int j = 0, m = 0; j < strlen(input); j++) {
        if ((input[j]) == ' ' && (input[j + 1] == ' '))
            continue;
        else {
            object[m] = input[j];
            m++;
        }
    }

    if (object[0] == 'c') {
        for (i = 0; isalpha(object[i]) != 0; i++) {
            if (object[i] != circle[i]) {
                for (int k = 0; k < i; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at column %d: expected 'circle'\n", i + 1);
                return 2;
            }
        }
        if (object[strlen(circle) + 1] != '(') {
            error_bracket_open = strlen(circle) + 1;
        }
        if (object[strlen(object)] != ')') {
            error_bracket_close = strlen(object);
        }

        for (int j = 0; j < strlen(object); j++) {
            if (object[j] == '(') {
                bracket_open++;
            }
            if (object[j] == ')') {
                bracket_close++;
            }

            if (object[j] == ',') {
                comma_counter++;
            }
        }
        if (bracket_open != 1) {
            for (int k = 0; k < error_bracket_open - 1; k++)
                printf(" ");
            printf("^\n");
            printf("Error at column %d: expected '('", error_bracket_open);
            return 1;
        }
        if (bracket_close != 1) {
            for (int k = 0; k < error_bracket_close - 1; k++)
                printf(" ");
            printf("^\n");
            printf("Error at column %d: expected ')'", error_bracket_close);
            return 1;
        }
        if (comma_counter != 1) {
            printf("Error: expected 'circle(x y, r)'\n");
            return 5;
        }

        for (int j = 0; object[i] != ' '; j++) {
            if (object[i] == ')') {
                printf("Error: expected 'circle(x y, r)'\n");
                return 5;
            }
            for (i = i + 1; object[i] != ' '; i++, j++) {
                x[j] = object[i];
            }
            index = j;
        }

        x_num = atof(x);

        int indexX = index;
        for (int j = 0, point = 0, minus = 0; j < index; j++) {
            if (x[0] == '.') {
                for (int k = 0; k < strlen(circle) + 1; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %ld: expected '<double>'\n",
                       strlen(circle) + 2);
                return 3;
            }
            if (x[j] == '.')
                point++;
            if (x[j] == '-')
                minus++;
            if (isalpha(x[j]) != 0) {
                for (int k = 0; k < i - 1; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (point > 1 || minus > 1) {
                for (int k = 0; k < i - 1; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
        }

        for (int j = 0; object[i] != ','; j++) {
            if (object[i] == ')') {
                printf("Error: expected 'circle(x y, r)'\n");
                return 5;
            }
            for (i = i + 1; object[i] != ','; i++, j++) {
                y[j] = object[i];
            }
            index = j;
        }

        y_num = atof(y);

        for (int j = 0, point = 0, minus = 0; j < index; j++) {
            if (y[0] == '.') {
                for (int k = 0; k < strlen(circle) + indexX + 2; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %ld: expected '<double>'\n",
                       strlen(circle) + indexX + 3);
                return 3;
            }
            if (y[j] == '.')
                point++;
            if (y[j] == '-')
                minus++;
            if (isalpha(y[j]) != 0) {
                for (int k = 0; k < i - 1; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (point > 1 || minus > 1) {
                for (int k = 0; k < i - 1; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
        }
        int indexY = index;

        for (int j = 0; object[i] != ')'; j++) {
            for (i = i + 2; object[i] != ')'; i++, j++) {
                radius[j] = object[i];
            }
            index = j;
        }

        radius_num = atof(radius);
        for (int j = 0, point = 0, minus = 0; j < index; j++) {
            if (radius[0] == '.') {
                for (int k = 0; k < strlen(circle) + indexX + indexY + 4; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %ld: expected '<double>'\n",
                       strlen(circle) + indexX + indexY + 5);
                return 3;
            }
            if (radius[j] == '.')
                point++;
            if (radius[j] == '-') {
                for (int k = 0; k < i - strlen(radius) + 2; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %d: expected positive number\n", i);
                return 3;
            }
            if (isalpha(radius[j]) != 0) {
                for (int k = 0; k < i - 1; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (point > 1 || minus > 1) {
                for (int k = 0; k < i - 1; k++)
                    printf(" ");
                printf("^\n");
                printf("Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
        }

        if (i + 1 != strlen(object) - 1) {
            printf("Error at column %d: unexpected token", i);
            return 4;
        }
        printf("%s", object);
        area_num = pi * radius_num * radius_num;
        perimetr_num = 2 * pi * radius_num;
        printf("x = %f\ny = %f\nradius = %f\nArea = %f\nPerimert = %f\n", x_num, y_num, radius_num, area_num, perimetr_num);
    }

    else {
        printf("\nError at column 0: expected 'circle'");
        return 5;
    }
}
