/*
Project Name: Secure and Efiicient Data Transmission
File Name: Caesar_Cipher_enc.c
Last Updated: 05/06/2022
Last Updated by: Shreya Mandi
*/

//CAESAR CIPHER ENCODING
#include <stdio.h>
#include <string.h>
char whitespace(char str[50]);

int main()
{
    printf("CAESER CIPHER ENCODING\n");
    printf("Enter the string and the shift.\n");
    int shift;
    char en_cc[50];
    char str[50];
    gets(&str);
    scanf("%d",&shift);
    
    
    int i, len = 0,j;  
    len = sizeof(str)/sizeof(str[0]);  
    for(i = 0; i < len; i++){  
        if(str[i] == ' '){  
            for(j=i;j<len;j++)  
        {  
            str[j]=str[j+1];  
        }  
        len--;  
        }  
    }  
    //printf("String after removing all the white spaces : %s", str);
    
    
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]+shift>122)
        {
            int a=122-str[i];
            int b=shift-a;
            en_cc[i]=(char)(97+b);
        }
        else
        {
            en_cc[i]=(char)(str[i]+shift);
        }
    }
    printf("The encoded string is:\n%s\n",en_cc);

    return 0;
}

/*void whitespace_count()
{
    char str[50]=data.str;
    for(int i=0; i<strlen(str); i++)
    {
        char a=str[i];
        char *p1=&a;
        char b=" ";
        char *p2=&b;

        if(strcmp(*p1,*p2))
        {
            stuff.arr[0+count]=i;
            count++;
        }
        else
        {
            data.str[i]=str[i];
        }
    }
}*/