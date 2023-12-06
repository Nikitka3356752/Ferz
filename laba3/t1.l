%{
#include <stdio.h>
%}

%%
[0-9]+  {printf("number/n");}
[a-zA-Zа-яА-Я]+ {printf("word/n");}
[\+\-\*\/]+ {printf("operator/n");}
[a-zA-Zа-яА-Я][a-zA-Zа-яА-Я0-9]* {printf("word with number/n");}
%%
int yywrap() {return 1;}