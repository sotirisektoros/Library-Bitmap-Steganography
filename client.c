/*


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "list.h"
#include "grayscale.h"
#include "encodeStegano.h"
#include "decodeStegano.h"
#include "encodeText.h"
#include "decodeText.h"
#include "stringToImage.h"
#include "ImageToString.h"

#define SYSTEMKEY 123


int main(int argc, char **argv) {

    printf("\n<client.c>  Copyright (C) <2020>  <ckasou01 , llampi01>\n"
           "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
           "This is free software, and you are welcome to redistribute it\n"
           "under certain conditions; type `show c' for details.\n");


    char *option = argv[1];

    if (strcmp(option, "-list")) {

        if (argc == 2) { //arguments for -list from command line must be more than 1
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        for (int i = 2; i < argc; i++) {
            IMAGE *image = readImage(argv[i]);

            if (image != NULL) { //if image is NULL the image is ignored
                list(image);
            }
        }

    } else if (strcmp(option, "-grayscale")) {

        if (argc != 5) { //arguments for -grayscale from command line must be 3
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        for (int i = 2; i < argc; i++) {
            IMAGE *image = readImage(argv[i]);

            if (image != NULL) { //if image is NULL the image is ignored
                char *newExtension = "new-";
                bmpToGrayscale(image);
                strcat(newExtension, argv[i]);
                saveImage(image, newExtension);
            }
        }


    } else if (strcmp(option, "-encodeStegano")) {

        if (argc != 5) { //arguments for -encodeStegano from command line must be 3
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        int noOfBits = atoi(argv[2]);


        char *coverImageName = argv[3];
        IMAGE *coverImage = readImage(coverImageName);

        char *secretImageName = argv[4];
        IMAGE *secretImage = readImage(secretImageName);

        if (coverImage != NULL || secretImage != NULL) { //if coverImage or secretImage is NULL the images are ignored

            encodeStegano(noOfBits, coverImage, secretImage);

            char *newExtension = "new-";
            strcat(newExtension, coverImageName);
            saveImage(coverImage, newExtension);
        }

    } else if (strcmp(option, "-decodeStegano")) {

        if (argc != 4) { //arguments for -decodeStegano from command line must be 2
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);
        }

        int noOfBits = atoi(argv[1]);


        char *coverImageName = argv[2];
        IMAGE *coverImage = readImage(coverImageName);

        if (coverImage != NULL) { //if cover image is NULL the image is ignored

            decodeStegano(noOfBits, coverImage);

            char *newExtension = "new-";
            strcat(newExtension, coverImageName);
            saveImage(coverImage, newExtension);
        }

    } else if (strcmp(option, "-encodeText")) {

        if (argc != 4) { //arguments for -encodeText from command line must be 2
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        byte *text = readTextFile(argv[3]);

        char *imageName = argv[2];
        IMAGE *image = readImage(imageName);

        if (image != NULL) { //if image is NULL the image is ignored

            encodeText(image, text,SYSTEMKEY);

            char *newExtension = "new-";
            strcat(newExtension, imageName);
            saveImage(image, newExtension);
        }





    } else if (strcmp(option, "-decodeText")) {

        if (argc != 5) { //arguments for -decodeText from command line must be 3
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        char *imageName = argv[2];
        IMAGE *image = readImage(imageName);

        int msLength = atoi(argv[3]);

        char* filename = argv[4];


        if (image != NULL) { //if image is NULL the image is ignored



            decodeText(image,msLength,SYSTEMKEY,filename);

            char *newExtension = "new-";
            strcat(newExtension, imageName);
            saveImage(image, newExtension);
        }


    } else if (strcmp(option, "-stringToImage")) {

        if (argc != 4) { //arguments for -stringToImage from command line must be 2
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        byte *text = readTextFile(argv[3]);

        char *imageName = argv[2];
        IMAGE *image = readImage(imageName);

        if (image != NULL) { //if image is NULL the image is ignored

            stringToImage(image, text);

            char *newExtension = "new-";
            strcat(newExtension, imageName);
            saveImage(image, newExtension);
        }

    } else if (strcmp(option, "-imageToString")) {

        if (argc != 3) { //arguments for -ImageToString from command line must be 1
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        char *imageName = argv[2];
        IMAGE *image = readImage(imageName);

        if (image != NULL) { //if image is NULL the image is ignored
            ImageToString(image);
        }

    } else {
        printf("\nThe option you have entered in not included!\n");
        exit(EXIT_FAILURE);

    }



    return 0;


}

*/
