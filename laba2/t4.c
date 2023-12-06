#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Написать программу, которая в качестве аргумента принимает размер 
произвольного массива, создает его, заполняет случайными числами 
с плавающей точкой в интервале (arg1, arg2), где arg1 и arg2 - также аргументы,
 вводимые при запуске программы, и выводит массив в консоль. 
Далее программа записывает массив в файл в отсортированном виде.*/
int main() {
    srand(time(0)); //изменение чесел в массиве
    int size,ar1,ar2;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    printf("Введите нижнюю границу: ");
    scanf("%d", &ar1);
    printf("Введите верхнюю границу: ");
    scanf("%d", &ar2);
    while (ar1>=ar2){
        printf("Введите нижнюю границу: ");
        scanf("%d", &ar1);
        printf("Введите верхнюю границу: ");
        scanf("%d", &ar2);
    }
    float* array = (float*) malloc(size * sizeof(float)); // Выделение памяти для массива

    for (int i = 0; i < size; i++) {
        array[i] = (float) randomizr(ar1,ar2);
    }
    printArray(array, size);
    free(array);
    return 0;
}

void printArray(float* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}

double randomizr(double ar1, double ar2){
    int c = 0, m, z;
    m = rand()%10;
    m/=10;
    while (c!=1){
        z = (double)rand();
        if (z>=ar1 & z<ar2){
            return m+z;
            c++;
        }
    }
}