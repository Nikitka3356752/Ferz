#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Написать программу, которая генерирует массив из 
псевдослучайных целых чисел и выводит его в консоль.*/
int main(){
    srand(time(0));
    int a[10]={0};
    for (int i = 0;i<10;i++){
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }
}