#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
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
bool isOperator(char symbol) {
  if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
    return true;
  return false;
}

// Получение приоритета оператора
int getPriority(char symbol) {
  if (symbol == '*' || symbol == '/')
    return 2;
  else if (symbol == '+' || symbol == '-')
    return 1;
  else
    return 0;
}

// Преобразование инфиксной записи в постфиксную
void infixToPostfix(char infix[], char postfix[]) {
  int i, j;
  char symbol, item;
  push('(');
  strcat(infix,")");
  i = 0;
  j = 0;
  symbol = infix[i];
  while (symbol != '\0') {
    if (symbol == '(')
      push(symbol);
    else if (isdigit(symbol) || symbol == '.')
      postfix[j++] = symbol;
    else if (isOperator(symbol)) {
      item = pop(&stack);
      while (isOperator(item) && getPriority(item) >= getPriority(symbol)) {
        postfix[j++] = item;
        item = pop();
      }
      push(item);
      push(symbol);
    } else if (symbol == ')') {
      item = pop();
      while (item != '(') {
        postfix[j++] = item;
        item = pop();
      }
    }
    i++;
    symbol = infix[i];
  }
  postfix[j] = '\0';
}

int main() {
  char infix[10],postfix[10];
  printf("Введите инфиксное выражение: ");
  gets(infix);
  infixToPostfix(infix, postfix);
  printf("Постфиксное выражение: %s\n", postfix);
  return 0;
}
