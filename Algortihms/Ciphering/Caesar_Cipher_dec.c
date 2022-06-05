#include <stdio.h>

int main()
{
    // Write C code here
    printf("CAESAR CIPHER DECODING\n");
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
            de_cc[i] = (char *)(122 - b);
        }
        else
        {
            de_cc[i] = (char *)(str2[i] - shift2);
        }
    }
    printf("The decoded string is:\n%s\n", de_cc);
}