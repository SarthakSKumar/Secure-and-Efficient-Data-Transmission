/*
Project Name: Secure and Efiicient Data Transmission
File Name: Caesar_Cipher_enc.c
Last Updated: 05/06/2022
Last Updated by: Shreya Mandi
*/

#include <stdio.h>
#include <string.h>

int main()
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
