#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Создать структуру для хранения данных о названии и цене товара. 
Считать из входного файла данные о товарах. Написать функцию для сортировки товаров по цене. 
Вывести отсортированные данные в выходной файл.*/

struct Product {
    char name[100];
    float price;
};


int main() {
    FILE *fileR, *fileS;
    fileR= fopen("t5.txt", "r");
    fileS = fopen("t5(sort).txt", "w");

    struct Product products[100];
    int count = 0;

    while (fscanf(fileR, "%s %f", products[count].name, &products[count].price) != EOF) {
        count++;
    }

    sortProductsByPrice(products, count);

    for (int i = 0; i < count; i++) {
        fprintf(fileS "%s %.2f\n", products[i].name, products[i].price);
    }

    fclose(fileS);
    fclose(fileR);

    return 0;
}
void sortProductsByPrice(struct Product products[], int count) {
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-i-1; j++) {
            if (products[j].price > products[j+1].price) {
                struct Product temp = products[j];
                products[j] = products[j+1];
                products[j+1] = temp;
            }
        }
    }
}
