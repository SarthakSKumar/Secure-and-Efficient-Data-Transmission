/*
Project Name: Secure and Efiicient Data Transmission
File Name: Caesar_Cipher_dec.c
Last Updated: 10/06/2022
Last Updated by: Shreya Mandi
*/
#include <stdio.h>
#include <string.h>

int main()
{
    printf("PLAYFAIR CIPHER DECODING\n");
    printf("Enter the string.\n");
    char str[50];
    char en_cc[50];
    scanf("%s", &str);
    char key[5][5] = {"playf", "irbcd", "eghkm", "noqst", "uvwxz"};
    printf("Key:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        for (int j = 0; j < 5; j++)
        {
            printf("%c", key[i][j]);
        }
        printf("\n");
    }
    printf("Decrypted text:\n");
    int i, j, r2 = 0, c2 = 0, r1 = 0, c1 = 0;
    // printf("%d",strlen(str));

    for (int k = 0; k < strlen(str) - 1; k += 2)
    {
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (key[i][j] == str[k])
                {
                    r1 = i;
                    c1 = j;
                }
                if (key[i][j] == str[k + 1])
                {
                    r2 = i;
                    c2 = j;
                }
            }
        }
        // printf("%d%d",r1,c1);
        // printf("%d%d",r2,c2);
        if (r1 == r2)
        {
            if (c1 == 0)
            {
                c1 = 4;
                c2 = c2 - 1;
                printf("%c%c", key[r1][c1], key[r2][c2]);
            }
            else if (c2 == 0)
            {
                c2 = 4;
                c1 = c1 - 1;
                printf("%c%c", key[r1][c1], key[r2][c2]);
            }
            else
            {
                c1 = c1 - 1;
                c2 = c2 - 1;
                printf("%c%c", key[r1][c1], key[r2][c2]);
            }
        }
        else if (c1 == c2)
        {
            if (r1 == 0)
            {
                r1 = 4;
                r2 = r2 - 1;
                printf("%c%c", key[r1][c1], key[r2][c2]);
            }
            else if (r2 == 0)
            {
                r2 = 4;
                r1 = r1 - 1;
                printf("%c%c", key[r1][c1], key[r2][c2]);
            }
            else
            {
                r1 = r1 - 1;
                r2 = r2 - 1;
                printf("%c%c", key[r1][c1], key[r2][c2]);
            }
        }
        else
        {
            char temp;
            temp = c1;
            c1 = c2;
            c2 = temp;
            printf("%c%c", key[r1][c1], key[r2][c2]);
        }
    }
    return 0;
}
