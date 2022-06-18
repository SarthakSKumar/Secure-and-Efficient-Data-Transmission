#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

void delay(int millis)
{
    clock_t start_time = clock();
    while (clock() < start_time + millis)
        ;
}
int ceasar_cipher_enc()
{
    printf("CAESER CIPHER ENCODING\n");
    printf("Enter the string and the shift.\n");
    int shift;
    char str[50];
    char en_cc[50];
    scanf("%s", &str);
    scanf("%d", &shift);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] + shift > 122)
        {
            int a = 122 - str[i];
            int b = shift - a;
            en_cc[i] = (char)(97 + b);
        }
        else
        {
            en_cc[i] = (char)(str[i] + shift);
        }
    }
    printf("The encoded string is:\n%s\n", en_cc);

    return 0;
}

int cipher_select()
{
    int choice = 0;
    printf("                                    SELECT CIPHERING ALGORITHM                                    \n");
    delay(1000);
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("   [1] PLAYFAIR CIPHER         |         [2] CAESAR CIPHER         |         [0] EXIT             \n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                           YOUR CHOICE: ");
    scanf("%c", &choice);
    delay(200);
    if (choice == '1')
    {
        printf("lol");
    }
    else if (choice == '2')
    {
        ceasar_cipher_enc();
    }
    else if (choice == '0')
    {
        printf("close");
    }
    else
    {
        printf("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X  INVALID CHOICE  X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n");
        cipher_select();
    }
}

int main()
{
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("        SECURE AND EFFICIENT DATA TRANSMISSION USING CIPHERING AND COMPRESSION ALGORITHMS         \n");
    printf("--------------------------------------------------------------------------------------------------\n\n");
    delay(1000);
    printf("###### #    # ###### ###### ###### ###### ######    #    #  ######  ######  #    #  #       ######\n");
    printf("#      ##   # #      #    # #    # #      #    #    ##  ##  #    #  #    #  #    #  #       #\n");
    printf("###### # #  # #      #    # #    # ###### #####     # ## #  #    #  #    #  #    #  #       ######\n");
    printf("#      #   ## #      #    # #    # #      #    #    #    #  #    #  #    #  #    #  #       #     \n");
    printf("###### #    # ###### ###### #####  ###### #    #    #    #  ######  #####   ######  ######  ######\n\n");

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                          CSE SEM 2 PROJECT - LAST UPDATED ON 02-02-2022                          \n");
    printf("--------------------------------------------------------------------------------------------------\n\n");
    delay(1000);
    cipher_select();
}