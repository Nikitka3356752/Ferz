#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Написать программу, которая в качестве аргумента
 принимает размер произвольного массива, создает его,
заполняет случайными числами с плавающей точкой
 в интервале (0, 1) и выводит этот массив в консоль.*/
int main() {
    srand(time(0)); //изменение чесел в массиве
    int size;
    double m;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    float* array = (float*) malloc(size * sizeof(float)); // Выделение памяти для массива

    for (int i = 0; i < size; i++) {
        m=rand()%10;
        if (m<=3 & m>0){
            if (rand()%2==0){
                array[i]=m;
            }
            else array[i]=-m;
        }
        else if (m>=3 & m<=5){
            array[i]=m;
        }
          }
    printArray(array, size);
    free(array);
    return 0;
}
void printArray(float* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.*f ", 1, array[i]);
    }
    printf("\n");
}
