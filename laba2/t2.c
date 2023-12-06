#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Написать программу, которая генерирует массив из 
псевдослучайных целых чисел и записывает в 
файл в обратном порядке.
*/
int main(void){
    FILE *file = fopen("t2.txt","w"); srand(time(NULL));
    int a[10]={0};
    for (int i = 0;i<10;i++){
        a[i]=rand()%100;
        printf("%d\n",a[i]);
    }
    for (int i = 9;i>=0;i--){
        fprintf(file,"%d ",a[i]);
    }
    fclose(file);
    return 0;
}