#include "main.h"

/**
 * main - simple shell.
 * @ac: argument count.
 * @argv: array of strings.
 * Return: 0 @success.
 */
int main(int ac, char **argv)
{
        char *prompt = "$ "; /* My prompt to be printed */
        char *lineptr = NULL, *line_cp = NULL; /* this is ptr to char/ we can say string typed by user and copy of it, intally we will set it to NULL */
        size_t n = 0;/*  is used to keep track of the size of the buffer allocated for reading input using the getline function*/
        /* is assigned the return value of getline, which is the number of characters read, including the newline character at the end of the line(ifany).*/
        ssize_t nchar_read;
        const char *delim = " \n"; /* separator of strings, useful when tokenizing, man strtok */
        int ntok = 0;
/* above is used to keep track of the number of tokens (words) found during the tokenization process. It is incremented each time a new token is identified. */
        int i; /* it is used to iterate over the tokens obtained during the tokenization process and store them in the argv array. */
        char *token; /* is used to store the current token during the tokenization process. */

        (void)ac;

        while (1)
        {
                printf("%s", prompt); /* prompt printed */
                nchar_read = getline(&lineptr, &n, stdin); /* reading from user using getline function */

                if (nchar_read == -1)
                {
                        return (-1);                    /* we see that if no of char readed is failed it will terminate.*/
                }

                line_cp = malloc(sizeof(char) * nchar_read); /* allocating space for the copy of input from user using charachter readed (nchar_read);*/

                if (line_cp == NULL)
                {
                        perror("error allocating Memory");   /* if allocation is not successful print error */
                        return (-1);
                }

                strcpy(line_cp, lineptr);               /* after allocating memory for copy of input using charchter readed we can now copy th string to it*/

                /* remember the use of why we copy the input string because we are going to parse those input so we have to had the original one typed from user*/
                token = strtok(lineptr, delim);       /* parsing started, remember usage of strtok(not allowed in project we have to create our own coup*/

                while (token != NULL)
                {
                        ntok++;
                        token = strtok(NULL, delim); /* until any of input doesn't left it will tokenize or parse using this condition */
                }
                ntok++;

                /*allocting memory for each token*/
                argv = malloc(sizeof(char *) * ntok);

                /*started to put each token in argv
                  first tokenize and then i will give to argv using for loop and strcpy*/

                token = strtok(line_cp, delim);

                for (i = 0; token != NULL; i++)
                {
                        argv[i] = malloc(sizeof(char) * (strlen(token) + 1)); /*here i am allocating mem for each tokens counted.*/
                        strcpy(argv[i], token);

                        token = strtok(NULL, delim);
                }
                argv[i] = NULL;

                /* check for the first input and if it is "exit", exit the shell */
                if (strcmp(lineptr, "exit") == 0)
                {
                        myexit();  /* here am using(calling) my own function to exit the shell and you can build your own */
                }

                execmd(argv); /* here we are executing the commands */

                /*free those guys*/
                freetok(argv, ntok); /* here freetok, i am using(calling) my own function that free each token, you can buil Yours. */
                free(line_cp);
        }
        free(lineptr);
        return (0);
}

/* DONT FORGET: DON'T COPY ANY CODES OR FILES IN HERE FOR YOUR OWN SAFETY, JUST SEE HOW IT WORKS(THIS IS WHY I WRITE A COMMENT ALL THE PLACE */
/* DO HARD THINGS */
