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


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bmplib.h"

PRIVATE int *createPermutationFunction(int N, unsigned int systemkey) {

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
    int decodeText(char *imageFile, int msgLength, unsigned int systemkey, char *textFile) {
    FILE* fp;
    if((fp = fopen(textFile,"wb")) == NULL){
        printf("Error opening file!");
        exit(1);
    }
    int o = 0;
    int countBits=0;
    byte b='\0';
    BMP* image= readImage(imageFile);
   
    int* temp = (createPermutationFunction(image->fileHeader.bfSize-54, systemkey));

    for (int i = 0; i < (1 + msgLength) * 8; i++) {
        o = temp[i];
        for (int j = 0; j < image->infoHeader.biWidth; j++) {
        switch (o % 3) {
            case 0:
                b |= (image->pixels[o / 3].red & 0x1);
                countBits++;
                break;
            case 1:
                b |= (image->pixels[o / 3].green & 0x1);
                countBits++;
                break;
            default:
                b |= (image->pixels[o / 3].blue & 0x1);
                countBits++;
                break;
        }
        }
        if(countBits==8){
            countBits=0;
            fputc(b,fp);
            b = '\0';
        }
        b<<=1;

    }
    free(temp);
    free(image);
    free(fp);
    return EXIT_SUCCESS;
}


#ifdef DEBUGDT
int main(int argc, char **argv) {
    int msLength=atoi(argv[2]);

    char *imageFile = argv[1];

    int systemkey = 123;
    int a=decodeText(imageFile, msLength, systemkey, "test.txt");

    return 0;
}
#endif
