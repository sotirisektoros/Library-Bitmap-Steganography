//
// Created by chris275 on 22/11/20.
//

#include "encodeText.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

static byte getBit(char *m, int n) {
    byte u;

    if (n <= 8 * strlen(m)) {
        u = (*(m + n / 8) & (0x1 << (7 - (n % 8)))) >> (7 - (n % 8));
        return u;
    } else
        return 0;

}


static int *createPermutationFunction(int N, unsigned int systemkey) {

    srand(systemkey);

    int *permutation = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++) { //initializing permutation
        permutation[i] = i;
    }

    for (int k = 0; k < N; k++) { //mixing up permutation
        int i = abs(rand() % N);
        int j = abs(rand() % N);

        int temp = permutation[i];
        permutation[i] = permutation[j];
        permutation[j] = temp;


    }

    return permutation;
}


void encodeText(IMAGE *image, char *text, unsigned int systemkey) {
    int o = 0;
    for (int i = 0; i < (1 + strlen(text)) * 8; i++) {
        byte b = getBit(text, i);
        o = (createPermutationFunction(strlen(text)+1, systemkey)[i/8]);

        switch (o % 3) {
            case 0:
                image->data[o / 3].r = ((image->data[o / 3].r >> 1) << 1); //delete last bit of text[o] R byte
                image->data[o / 3].r = image->data[o / 3].r | b; //insert b in last bit of text[o] R byte
                break;
            case 1:
                image->data[o / 3].g = ((image->data[o / 3].g >> 1) << 1); //delete last bit of text[o] G byte
                image->data[o / 3].g = image->data[o / 3].g | b; //insert b in last bit of text[o] G byte
                break;
            default:
                image->data[o / 3].b = ((image->data[o / 3].b >> 1) << 1); //delete last bit of text[o] B byte
                image->data[o / 3].b = image->data[o / 3].b | b; //insert b in last bit of text[o] B byte
                break;
        }


    }

}

char *readTextFromFile(char *filename) {

    FILE *fp;
    //needs test if filename is .txt
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    int size = 1;
    char *input = (char *) calloc(1, sizeof(char));
    int n = 0;    // successfully read elements
    while (1) {
        char *buffer = (char *) calloc(11, sizeof(char));
        n = fread(buffer, sizeof(char), 10, fp);
        if (n == 0) {
            break;
        }
        size += n;
        input = (char *) realloc(input, size * sizeof(char));
        strcat(input, buffer);
        if (n < 10) {
            break;
        }
        free(buffer);
    }
    return input;
}


#ifdef DEBUGET
int main(int argc, char **argv) {


    IMAGE *i = readImage(argv[1]);
    char *text = readTextFromFile(argv[2]);


    int systemkey = 123;

    encodeText(i, text, systemkey);

    saveImage(i, "encodeTextTesting.bmp");

    return 0;

}
#endif



