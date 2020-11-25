/*<This file represents the -encodeText function of the client.c >
Copyright (C) <2020>  <llampi01>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Υou should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
/**
 *
 * @file encodeText.c
 *
 * @brief This file represents the -encodeText function of the program.
 *
 * @author Leonidas Lampiritis
 * @version 1.0
 * @since 24/11/20
 *
 */
#include "encodeText.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



static byte getBit(char *m, int n) {
    byte u;

    if (n <= 8 * strlen(m)) {
        u = (*(m + n / 8) & (0x1 << (7 - (n % 8)))) >> (7 - (n % 8));
        return u;
    } else
        return 0;

}


static int* createPermutationFunction(int N, unsigned int systemkey) {

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

    int* temp = (createPermutationFunction(image->fheader->bfSize-54, systemkey));

    byte b;
    for (int i = 0; i < (1 + strlen(text)) * 8; i++) {
        b = getBit(text, i);
        o = temp[i];

        switch (o % 3) {
            case 0:
                image->data[o / 3].r = ((image->data[o / 3].r >> 0x1) << 0x1); //delete last bit of text[o] R byte
                image->data[o / 3].r = image->data[o / 3].r | b; //insert b in last bit of text[o] R byte
                break;
            case 1:
                image->data[o / 3].g = ((image->data[o / 3].g >> 0x1) << 0x1); //delete last bit of text[o] G byte
                image->data[o / 3].g = image->data[o / 3].g | b; //insert b in last bit of text[o] G byte
                break;
            default:
                image->data[o / 3].b = ((image->data[o / 3].b >> 0x1) << 0x1); //delete last bit of text[o] B byte
                image->data[o / 3].b = image->data[o / 3].b | b; //insert b in last bit of text[o] B byte
                break;
        }


    }
    free(temp);
    free(text);

}

char *readTextFromFile(char *filename) {

    FILE *fp;

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
            free(buffer);
            break;
        }
        size += n;
        input = (char *) realloc(input, size * sizeof(char));
        strcat(input, buffer);
        if (n < 10) {
            free(buffer);
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



