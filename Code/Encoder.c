/*
Project Name: Secure and Efiicient Data Transmission
File Name: Encoder.c
Last Updated: 30/07/2022
Last Updated by: Sarthak S Kumar
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define EXTENSION ".ef"

char enc_str[50], file_data[1000], filename[1];

void huffman_encode(char enc_str[]) {
}

void delay(int millis) {
    clock_t start_time = clock();
    while (clock() < start_time + millis)
        ;
}

void encrypt(char str[]) {
    strcat(filename, EXTENSION);
    FILE *file = fopen(filename, "w");
    fprintf(file, "10111011000110011110000001100101110100101000111000110101100110001\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%s", str);
}

void f_handle() {
    delay(500);
    printf("\n||||||||||||||||||||   ENTER THE NAME/LOCATION OF THE FILE TO BE ENCRYPTED    ||||||||||||||||||||\n\n");
    scanf("%s", &filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X  INVALID FILE  X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n");
        f_handle();
    }
    fgets(file_data, 1000, file);
    fclose(file);
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
        scanf("%s", &str);
        delay(200);
    }

INVALID_SHIFT_VALUE:
    printf("                                ENTER THE SHIFT VALUE (0 - 255): ");
    scanf(" %d", &shift);
    if (shift <= 0 && shift >= 255) {
        printf("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X  INVALID CHOICE  X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n");
        goto INVALID_SHIFT_VALUE;
    } else {
        int i, len = 0, j;
        len = sizeof(str) / sizeof(str[0]);
        for (i = 0; i < len; i++) {
            if (str[i] == ' ') {
                for (j = i; j < len; j++) {
                    str[j] = str[j + 1];
                }
                len--;
            }
        }
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] + shift > 122) {
                int a = 122 - str[i];
                int b = shift - a;
                enc_str[i] = (char)(97 + b);
            } else {
                enc_str[i] = (char)(str[i] + shift);
            }
        }
        delay(2000);
        printf("\n--------------------------------     ENCODING USING HUFFMAN    -----------------------------------\n");
        huffman_encode(str);
        encrypt(file_data);
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  DATA ENCRYPTED SUCCESSFULLY  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
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