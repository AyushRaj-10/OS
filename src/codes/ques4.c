#include <stdio.h>

int main()
{
    int bt[10], rem[10], n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    int tq;

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int done;

    while(1)
    {
        done = 1;

        for(int i=0;i<n;i++)
        {
            if(rem[i] > 0)
            {
                done = 0;

                if(rem[i] > tq)
                {
                    rem[i] -= tq;
                }
                else
                {
                    rem[i] = 0;
                }
            }
        }

        if(done == 1)
            break;
    }

    printf("Processes completed\n");

    return 0;
}