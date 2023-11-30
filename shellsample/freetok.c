#include "main.h"

void freetok(char **tok, int numtok)
{
        int i; /* loop until my tokens end */

        for (i = 0; i < numtok; i++)
        {
                free(tok[i]); /* free each token */
        }
        free(tok);
}
