#include <stdio.h>

int frame[3];

void display()
{
    printf("Frames: ");

    for(int i = 0; i < 3; i++)
    {
        printf("%d ", frame[i]);
    }

    printf("\n");
}

int main()
{
    int pages[12] = {2,3,2,1,5,2,4,5,3,2,5,2};

    int fs[3];
    int pf = 0;



    for(int i = 0; i < 3; i++)
    {
        frame[i] = -1;
    }



    for(int j = 0; j < 12; j++)
    {
        int found = 0;

        printf("\nChecking page %d\n", pages[j]);



        for(int i = 0; i < 3; i++)
        {
            if(frame[i] == pages[j])
            {
                found = 1;

                printf("Page Hit\n");

                break;
            }
        }


        if(found == 0)
        {
            printf("Page Fault\n");

            int empty = 0;


            for(int i = 0; i < 3; i++)
            {
                if(frame[i] == -1)
                {
                    frame[i] = pages[j];

                    empty = 1;

                    printf("Inserted into empty frame\n");

                    break;
                }
            }


            if(empty == 0)
            {


                for(int i = 0; i < 3; i++)
                {
                    fs[i] = 0;
                }

                int index = 0;


                for(int k = j-1, l = 1;
                    l <= 2;
                    l++, k--)
                {
                    for(int i = 0; i < 3; i++)
                    {
                        if(frame[i] == pages[k])
                        {
                            fs[i] = 1;
                        }
                    }
                }


                for(int i = 0; i < 3; i++)
                {
                    if(fs[i] == 0)
                    {
                        index = i;
                    }
                }

                printf("Replacing %d with %d\n",
                frame[index], pages[j]);

                frame[index] = pages[j];
            }

            pf++;
        }

        display();
    }

    printf("\nTotal Page Faults = %d\n", pf);

    return 0;
}