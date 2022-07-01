/*Project Name: Secure and Efiicient Data Transmission
File Name: Decoder.c
Last Updated: 18/06/2022
Last Updated by: Sarthak S Kumar
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define EXTENSION ".ef"

char dec_str[50], file_data[1000], filename[1];

void huffman_decode(char str[]) {
}

void delay(int millis) {
    clock_t start_time = clock();
    while (clock() < start_time + millis)
        ;
}

void decrypt(char str2[]) {
    FILE *file = fopen("Decrypted", "w");
    fprintf(file, "%s", str2);
}

void f_handle() {
    delay(500);
    printf("\n||||||||||||||||||||   ENTER THE NAME/LOCATION OF THE FILE TO DECRYPTED    ||||||||||||||||||||\n\n");
    scanf("%s", &filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X  INVALID FILE  X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n");
        f_handle();
    }
    int i = 0;
    while (fgets(file_data, sizeof(file_data), file)) {
        i++;
        if (i == 60) {
            break;
        }
    }

    fclose(file);
}
int ceasar_cipher_dec(int flag) {
    int shift;
    char str[50];
    if (flag == 1) {
        printf("\n--------------------------------     DECODING USING HUFFMAN    -----------------------------------\n");
        huffman_decode(file_data);
        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                   DECRYPTION USING CAESAR CIPHER                                   \n");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("|||||||||||||||||||||||||||||             PROCESSING FILE          |||||||||||||||||||||||||||||||\n\n");
        strcpy(str, file_data);
        delay(200);

    } else {
        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                  DECRYPTION USING CAESAR CIPHER                                  \n");
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("|||||||||||||||||||||||||||||   INSERT THE STRING TO BE DECRYPTED  |||||||||||||||||||||||||||||||\n\n");
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
        char dec_str[50];
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] - shift < 97) {
                int a = str[i] - 97;
                int b = shift - a;
                dec_str[i] = (char)(122 - b);
            } else {
                dec_str[i] = (char)(str[i] - shift);
            }
        }
    }
    delay(2000);
    decrypt(file_data);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  DATA DECRYPTED SUCCESSFULLY  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int cipher_select() {
    char choice, choice2;
    printf("                                     SELECT CIPHERING ALGORITHM                                    \n");
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
    printf("      [1] FILE DECRYPTION      |        [2] TEXT DECRYPTION        |         [0] EXIT             \n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                           YOUR CHOICE: ");
    scanf(" %c", &choice2);
    if (choice2 == '0') {
        exit(0);
    }

    if (choice == '1' && choice2 == '1') {
        // f_handle();
        //  playfair
    } else if (choice == '2' && choice2 == '1') {
        delay(200);
        f_handle();
        ceasar_cipher_dec(1);
    } else if (choice == '1' && choice2 == '2') {
        delay(200);
        // playfair;
    } else if (choice == '2' && choice2 == '2') {
        delay(200);
        ceasar_cipher_dec(0);
    } else {
        printf("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X  INVALID CHOICE  X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n");
        cipher_select();
    }
}

int main() {
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("        SECURE AND EFFICIENT DATA TRANSMISSION USING CIPHERING AND COMPRESSION ALGORITHMS         \n");
    printf("--------------------------------------------------------------------------------------------------\n\n");

    printf("###### ###### ###### ###### ###### ###### ######    #    #  ######  ######  #    #  #       ######\n");
    printf("#    # #      #      #    # #    # #      #    #    ##  ##  #    #  #    #  #    #  #       #\n");
    printf("#    # ###### #      #    # #    # ###### #####     # ## #  #    #  #    #  #    #  #       ######\n");
    printf("#    # #      #      #    # #    # #      #    #    #    #  #    #  #    #  #    #  #       #     \n");
    printf("#####  ###### ###### ###### #####  ###### #    #    #    #  ######  #####   ######  ######  ######\n\n");

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                          CSE SEM 2 PROJECT - LAST UPDATED ON 18-06-2022                          \n");
    printf("--------------------------------------------------------------------------------------------------\n\n");
    cipher_select();
}
