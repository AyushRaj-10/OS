#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void performOperation(char op, int a, int b)
{
    int result;

    switch(op)
    {
        case '+':
            result = a + b;
            break;

        case '-':
            result = a - b;
            break;

        case '*':
            result = a * b;
            break;

        case '/':
            if(b == 0)
            {
                printf("Division by zero not possible\n");
                exit(1);
            }

            result = a / b;
            break;

        default:
            printf("Invalid Operator\n");
            exit(1);
    }

    printf("Result = %d\n", result);

    exit(result);
}

int main()
{
    char op;
    int a, b, status;

    printf("Enter operator (+,-,*,/): ");
    scanf(" %c", &op);

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    pid_t pid = fork();

    if(pid < 0)
    {
        printf("Fork Failed\n");
    }

    else if(pid == 0)
    {
        // Child Process

        performOperation(op, a, b);
    }

    else
    {
        // Parent Process

        waitpid(pid, &status, 0);

        if(WIFEXITED(status))
        {
            printf("Child exited with result %d\n",
            WEXITSTATUS(status));
        }
    }

    return 0;
}