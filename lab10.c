#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>

float area_triangle(float a, float b, float c);
void draw_triangle(int a);
void name(int a);

int main() {
    int choice2;
    float a, b, c;
    setlocale(LC_ALL, "RUS");

    printf("Введите длины сторон треугольника:\n");
    printf("Сторона A: ");
    scanf("%f", &a);
    printf("Сторона B: ");
    scanf("%f", &b);
    printf("Сторона C: ");
    scanf("%f", &c);

    printf("\nВыберите действие:\n");
    printf("1. Вычислить площадь треугольника\n");
    printf("2. Нарисовать треугольник\n");
    printf("3. Описание треугольника\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice2);

    switch (choice2) {
    case 1:
        printf("Площадь треугольника: %.2f\n", area_triangle(a, b, c));
        break;
    case 2:
        draw_triangle((int)a); 
        break;
    case 3:
        name(3); 
        break;
    default:
        printf("Некорректный выбор!\n");
    }

    return 0;
}

float area_triangle(float a, float b, float c) {
    float p = (a + b + c) / 2;
    float area = sqrt(p * (p - a) * (p - b) * (p - c));
    return area;
}

void draw_triangle(int a) {
    printf("\n");
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a - i; j++) {
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

void name(int a) {
    if (a == 3) {
        printf("Треугольник - это геометрическая фигура, состоящая из трех сторон и трех углов.\n");
        printf("Площадь вычисляется по формуле Герона.\n");
    }
    else {
        printf("Фигура с кодом %d не распознана.\n", a);
    }
}
