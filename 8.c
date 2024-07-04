#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f[50] = {0};
    int allocatedBlockCount, startingBlockIndex, lenghtRequired, flag;

    printf("Enter how many blocks already allocated: ");
    scanf("%d", &allocatedBlockCount);

    printf("Enter blocks already allocated: ");
    for (int i = 0; i < allocatedBlockCount; i++)
    {
        int a;
        scanf("%d", &a);
        if (a >= 0 && a < 50)
        {
            f[a] = 1;
        }
        else
        {
            printf("Invalid block index %d. Please enter a value between 0 and 49.\n", a);
        }
    }

    flag = 1;
    while (flag == 1)
    {
        printf("Enter index starting block and length: ");
        scanf("%d%d", &startingBlockIndex, &lenghtRequired);

        if (startingBlockIndex < 0 || startingBlockIndex >= 50 || lenghtRequired <= 0 || startingBlockIndex + lenghtRequired > 50)
        {
            printf("Invalid starting block or length. Please enter valid values.\n");
            continue;
        }

        int k = lenghtRequired;
        int success = 1;

        if (f[startingBlockIndex] == 0)
        {
            for (int j = startingBlockIndex; j < startingBlockIndex + k; j++)
            {
                if (f[j] == 0)
                {
                    f[j] = 1;
                    printf("%d-------->%d\n", j, f[j]);
                }
                else
                {
                    printf("%d Block is already allocated \n", j);
                    success = 0;
                }
            }
        }
        else
        {
            printf("%d starting block is already allocated \n", startingBlockIndex);
            success = 0;
        }

        if (success)
        {
            printf("Blocks allocated successfully.\n");
        }

        printf("Do you want to enter more file(Yes - 1/No - 0): ");
        scanf("%d", &flag);
    }

    return 0;
}
