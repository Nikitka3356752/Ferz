%%
[0-9]+                {return atoi(yytext);}
" "                    ;
"\n"                   ;
.                    ;

%%
 
int main() {
    yylex();
    return 0;
}