/*<This file represents the -decodeText function of the client.c >
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
 * @file decodeText.c
 *
 * @brief This file represents the -decodeText function of the program.
 *
 * @author Leonidas Lampiritis
 * @version 1.0
 * @since 24/11/20
 *
 */
#include "decodeText.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


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

void decodeText(IMAGE *image, int msLength, unsigned int systemkey, char *filename) {
    FILE* fp;
    if((fp = fopen(filename,"wb")) == NULL){
        printf("Error opening file!");
        exit(1);
    }
    int o = 0;
    int countBits=0;
    byte b='\0';

    int* temp = (createPermutationFunction(image->fheader->bfSize-54, systemkey));

    for (int i = 0; i < (1 + msLength) * 8; i++) {
        o = temp[i];
        switch (o % 3) {
            case 0:
                b |= (image->data[o / 3].r & 0x1);
                countBits++;
                break;
            case 1:
                b |= (image->data[o / 3].g & 0x1);
                countBits++;
                break;
            default:
                b |= (image->data[o / 3].b & 0x1);
                countBits++;
                break;
        }
        if(countBits==8){
            countBits=0;
            fputc(b,fp);
            b = '\0';
        }
        b<<=1;

    }
    free(temp);
}

#ifdef DEBUGDT
int main(int argc, char **argv) {
    int msLength=atoi(argv[2]);

    IMAGE *i = readImage(argv[1]);

    int systemkey = 123;
    decodeText(i, msLength, systemkey, "test.txt");

    return 0;
}
#endif