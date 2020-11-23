/**
 *
 * @file decodeStegano.c
 *
 * @brief This file represents the -decodeStegano function of the program.
 *
 * @author Christos Kasoulides
 * @version 1.0
 * @since 20/11/20
 *
 */

#include "decodeStegano.h"
#include <stdlib.h>
#include <stdio.h>

static byte getBitMask(int noOfBits){
    switch (noOfBits){

        case 1:
            return 0b00000001;

        case 3:
            return 0b00000111;

        case 4:
            return 0b00001111;


        default:
            printf("\nThe number of bits entered is not within the limit of bits that can be encoded!\n");
            exit(EXIT_FAILURE);
    }
}

void decodeStegano(int noOfbits,IMAGE* newImage) {
    int cnt = 0;
    byte copy = getBitMask(noOfbits);

    for (int i = 0; i < newImage->iheader->biHeight; i++) {

        for (int j = 0; j < newImage->iheader->biWidth; j++) {

            byte maskR = ((newImage->data[cnt].r) & copy) << (8 - noOfbits);
            byte maskG = ((newImage->data[cnt].g) & copy) << (8 - noOfbits);
            byte maskB = ((newImage->data[cnt].b) & copy) << (8 - noOfbits);

            newImage->data[cnt].r = maskR;
            newImage->data[cnt].g = maskG;
            newImage->data[cnt].b = maskB;

            cnt++;
        }
       // cnt += (newImage->iheader->biWidth * 3) % 4;
    }
}


#ifdef DEBUGDS
int main(int argc, char **argv) {


    int noOfBits = atoi(argv[1]);


    char *coverImageName = argv[2];
    IMAGE *coverImage = readImage(coverImageName);

    decodeStegano(noOfBits,coverImage);

    saveImage(coverImage, "new-new-IMG_6865.bmp");

    printf("\nFinished decoding\n");

    return 0;

}
#endif
