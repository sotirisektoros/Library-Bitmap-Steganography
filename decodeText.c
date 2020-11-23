//
// Created by leoni on 22/11/2020.
//

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