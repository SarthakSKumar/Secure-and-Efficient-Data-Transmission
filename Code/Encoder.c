/*
Project Name: Secure and Efiicient Data Transmission
File Name: Encoder.c
Last Updated: 18/06/2022
Last Updated by: Sarthak S Kumar
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

char enc_str[50], file_data[1000];

void delay(int millis) {
    clock_t start_time = clock();
    while (clock() < start_time + millis)
        ;
}

void f_handle() {
    char filename[1];
    delay(500);
    printf("\n||||||||||||||||||||   ENTER THE NAME/LOCATION OF THE FILE TO BE ENCRYPTED    ||||||||||||||||||||\n\n");
    scanf("%s", &filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X  INVALID FILE  X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n");
        f_handle();
    }
    fgets(file_data, 1000, file);
    printf("%s", file_data);
}
int ceasar_cipher_enc(int flag) {
    int shift;
    char str[50];
    if (flag == 1) {
        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                  ENCRYPTION USING CAESAR CIPHER                                  \n");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("|||||||||||||||||||||||||||||             PROCESSING FILE          |||||||||||||||||||||||||||||||\n\n");
        strcpy(str, file_data);
        delay(200);

    } else {
        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                  ENCRYPTION USING CAESAR CIPHER                                  \n");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("|||||||||||||||||||||||||||||   INSERT THE STRING TO BE ENCRYPTED  |||||||||||||||||||||||||||||||\n\n");
        scanf(" %s", &str);
        delay(200);
    }

INVALID_SHIFT_VALUE:
    printf("                                ENTER THE SHIFT VALUE (0 - 255): ");
    scanf("%d", &shift);
    if (shift <= 0 && shift >= 255) {
        printf("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X  INVALID CHOICE  X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n");
        goto INVALID_SHIFT_VALUE;
    } else {
        delay(200);

        for (int i = 0; i < strlen(str); i++) {
            if (str[i] + shift > 122) {
                int a = 122 - str[i];
                int b = shift - a;
                enc_str[i] = (char)(97 + b);
            } else {
                enc_str[i] = (char)(str[i] + shift);
            }
        }
        delay(1000);
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STRING ENCRYPTED SUCCESSFULLY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
    return 0;
}

int cipher_select() {
    char choice, choice2;
    printf("                                    SELECT CIPHERING ALGORITHM                                    \n");
    delay(1000);
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("      [1] PLAYFAIR CIPHER      |         [2] CAESAR CIPHER         |         [0] EXIT             \n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                           YOUR CHOICE: ");
    scanf("%c", &choice);
    printf("%c", choice);
    if (choice == '0') {
        exit(0);
    }
    delay(1000);
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("      [1] FILE ENCRYPTION      |        [2] TEXT ENCRYPTION        |         [0] EXIT             \n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                           YOUR CHOICE: ");
    scanf(" %c", &choice2);
    if (choice2 == '0') {
        exit(0);
    }

    if (choice == '1' && choice2 == '1') {
        f_handle();
        // playfair
    } else if (choice == '2' && choice2 == '1') {
        delay(200);
        f_handle();
        ceasar_cipher_enc(1);
    } else if (choice == '1' && choice2 == '2') {
        delay(200);
        // playfair;
    } else if (choice == '2' && choice2 == '2') {
        delay(200);
        ceasar_cipher_enc(0);
    } else {
        printf("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X  INVALID CHOICE  X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n");
        cipher_select();
    }
}

int main() {
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
    printf("                          CSE SEM 2 PROJECT - LAST UPDATED ON 18-06-2022                          \n");
    printf("--------------------------------------------------------------------------------------------------\n\n");
    delay(1000);
    cipher_select();
}