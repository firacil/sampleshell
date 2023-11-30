#include "main.h"

void execmd(char **argv)
{
        pid_t pid = fork(); /* creating process and pid using fork so my process will going to have unique ID */

        if (pid == -1)
        {
                perror("fork");                 /* if pid fails */
                exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
                /*child process*/
                if (execvp(argv[0], argv) == -1) /* if pid is working i have to excute the command of argv[0] if it is not = -1 */
                {
                        perror("execvp");
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                /*parent waiting until child terminate*/
                int status;
                waitpid(pid, &status, 0);               /* parent waiting for child to terminate */

        }
}
