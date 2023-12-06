#include <stdio.h>
#include <ctype.h> 

typedef struct {
    char* expression;
    size_t position;
} ExpressionConverter;

void E(ExpressionConverter* converter);
void T(ExpressionConverter* converter);
void EPrime(ExpressionConverter* converter);
void TPrime(ExpressionConverter* converter);
void F(ExpressionConverter* converter);

void ToPostfix(ExpressionConverter* converter) {
    E(converter);
    printf("\n");
}

void E(ExpressionConverter* converter) {
    T(converter);
    EPrime(converter);
}

void T(ExpressionConverter* converter) {
    F(converter);
    TPrime(converter);
}

void EPrime(ExpressionConverter* converter) {
    if (converter->expression[converter->position] == '+' || converter->expression[converter->position] == '-') {
        char op = converter->expression[converter->position];
        converter->position++;
        T(converter);
        EPrime(converter);
        printf("%c ", op);
    }
}

void TPrime(ExpressionConverter* converter) {
    if (converter->expression[converter->position] == '*' || converter->expression[converter->position] == '/') {
        char op = converter->expression[converter->position];
        converter->position++;
        F(converter);
        TPrime(converter);
        printf("%c ", op);
    }
}

void F(ExpressionConverter* converter) {
    if (isdigit(converter->expression[converter->position])) {
        printf("%c ", converter->expression[converter->position]);
        converter->position++;
    } else if (converter->expression[converter->position] == '(') {
        converter->position++;
        E(converter);
        if (converter->expression[converter->position] == ')') {
            converter->position++;
        } else {
            
        }
    } else {
        
    }
}

int main() {
    char infixExpression[100];
    printf("Введите инфиксиное выражение: ");
    scanf("%s", infixExpression);
    ExpressionConverter converter;
    converter.expression = infixExpression;
    converter.position = 0;
    ToPostfix(&converter);
    return 0;
}