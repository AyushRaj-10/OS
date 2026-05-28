#include <stdio.h>

int full = 0, empty = 3, item = 0, mutex = 1;

void producer()
{
    if(mutex == 1 && empty != 0)
    {
        full++;
        item++;
        empty--;

        printf("Produced item %d\n", item);
    }
    else
    {
        printf("Buffer Full\n");
    }
}

void consumer()
{
    if(mutex == 1 && full != 0)
    {
        printf("Consumed item %d\n", item);

        full--;
        item--;
        empty++;
    }
    else
    {
        printf("Buffer Empty\n");
    }
}

int main()
{
    producer();
    consumer();
    consumer();

    return 0;
}