#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*Написать программу, вычисляющую значение выражения, 
записанного в постфиксной (обратной польской) записи, 
считываемого из входного файла. */

int MAXSIZE = 10;
int stack[10];
int cnt1 = -1;

int isempty(){
   if(cnt1 == -1)
      return 1;
   else
      return 0;
}

int isfull(){
   if(cnt1 == MAXSIZE)
      return 1;
   else
      return 0;
}

char pop(){
   int data;
   if(!isempty()) {
      data = stack[cnt1];
      cnt1 -= 1;
      return data;
   } else {
      printf("Стак пустой.\n");
   }
}

char push(int data){
    if (!isfull()) {
        cnt1 += 1;
        stack[cnt1] = data;
    } 
    else {
        printf("Стак переполнен.\n");
   }
}

int main(){
    FILE *file = fopen("t7.txt","r");
    char ch;

    while ((ch = getc(file)) != EOF) {
        if (isdigit(ch)) {
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int a = pop();
            int b = pop();
            int result;

            switch (ch) {
                case '+':
                    result = b + a;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '*':
                    result = b * a;
                    break;
                case '/':
                    result = b / a;
                    break;
            }

            push(result);
        }
    }
    printf("result: %d\n",pop());
    fclose(file);
}