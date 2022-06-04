%{
/*#include <math.h> */ 
#include "y.tab.h"
#include "sym.h"
%}
 
%%
([0-9]+|([0-9]*\.[0-9]+)([eE][+-]?[0-9]+)?) {
    yylval.dval = atof(yytext);
    return NUMBER;
    }

[ \t] ; /* ignore whitespace */

PI {
    yylval.dval = 3.14159;
    return CONS;
    }

PHI {
    yylval.dval = 1.61803;
    return CONS;
    }

[A-Za-z][A-Za-z0-9]* {
    /* return symbol pointer */
    yylval.symptr = sym_lookup(yytext);
    return NAME;
    }

\? { 
    return SYM_INV;
    }

"$" { return 0; }
\n |
. { return yytext[0]; };
%%
int yywrap() { return 1; }
