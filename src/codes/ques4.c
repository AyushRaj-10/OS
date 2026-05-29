#include <stdio.h>

int main()
{
    int bt[10], rem[10];
    int wt[10], tat[10];

    int n, tq;

    int temp = 0;

    float avgwt = 0;
    float avgtat = 0;

    printf("Enter number of processes: ");

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i+1);

        scanf("%d", &bt[i]);

        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");

    scanf("%d", &tq);

    int done;

    while(1)
    {
        done = 1;

        for(int i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                done = 0;

                if(rem[i] <= tq)
                {
                    temp += rem[i];

                    tat[i] = temp;

                    rem[i] = 0;
                }
                else
                {
                    rem[i] -= tq;

                    temp += tq;
                }
            }
        }

        if(done == 1)
            break;
    }

    for(int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];

        avgtat += tat[i];
    }

    printf("\nPROCESS\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
        i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
    avgwt / n);

    printf("\nAverage Turnaround Time = %.2f",
    avgtat / n);

    return 0;
}