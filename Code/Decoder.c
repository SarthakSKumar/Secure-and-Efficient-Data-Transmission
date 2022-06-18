#include "stdio.h"
#include "stdlib.h"

int main()
{
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("        SECURE AND EFFICIENT DATA TRANSMISSION USING CIPHERING AND COMPRESSION ALGORITHMS         \n");
    printf("--------------------------------------------------------------------------------------------------\n\n");

    printf("###### ###### ###### ###### ###### ###### ######    #    #  ######  ######  #    #  #       ######\n");
    printf("#    # #      #      #    # #    # #      #    #    ##  ##  #    #  #    #  #    #  #       #\n");
    printf("#    # ###### #      #    # #    # ###### #####     # ## #  #    #  #    #  #    #  #       ######\n");
    printf("#    # #      #      #    # #    # #      #    #    #    #  #    #  #    #  #    #  #       #     \n");
    printf("#####  ###### ###### ###### #####  ###### #    #    #    #  ######  #####   ######  ######  ######\n\n");

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                          CSE SEM 2 PROJECT - LAST UPDATED ON 02-02-2022                          \n");
    printf("--------------------------------------------------------------------------------------------------\n\n");
}

int cipher_select()
{
    int choice;
    printf("SELECT CIPHERING ALGORITHM\n");
    printf("1 PLAYFAIR CIPHER 2 CAESAR CIPHER\n");
    printf("YOUR CHOICE: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        ceasar_cipher_enc();
    }
    else if (choice == 2)
    {
        playfair_cipher_enc();
    }
    else
    {
        printf("INVALID CHOICE\n");
        cipher_select();
    }
}

int ceasar_cipher_dec()
{
    printf("CAESAR CIPHER DECODING ALGORITHM\n");
    printf("Enter the string and the shift.\n");
    int shift2;
    char str2[50];
    char de_cc[50];
    scanf("%s", &str2);
    scanf("%d", &shift2);
    for (int i = 0; i < strlen(str2); i++)
    {
        if (str2[i] - shift2 < 97)
        {
            int a = str2[i] - 97;
            int b = shift2 - a;
            de_cc[i] = (char)(122 - b);
        }
        else
        {
            de_cc[i] = (char)(str2[i] - shift2);
        }
    }
    printf("The decoded string is:\n%s\n", de_cc);
}