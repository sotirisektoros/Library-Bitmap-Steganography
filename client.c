

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


int main(int argc, char **argv) {

    char *option = argv[1];

    if (strcmp(option, "-list")) {

        if (argc == 2) { //arguments for -list from command line must be more than 1
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        for (int i = 2; i < argc; i++) {
            IMAGE *image = readImage(argv[i]);

            if (image != NULL) {
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

            if (image != NULL) {
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

        int noOfBits = atoi(argv[1]);


        char *coverImageName = argv[2];
        IMAGE *coverImage = readImage(coverImageName);

        char *secretImageName = argv[3];
        IMAGE *secretImage = readImage(secretImageName);

        if (coverImage != NULL && secretImage != NULL) {

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

        if (coverImage != NULL) {

            decodeStegano(noOfBits, coverImage);

            char *newExtension = "new-";
            strcat(newExtension, coverImageName);
            saveImage(coverImage, newExtension);
        }

    } else if (strcmp(option, "-encodeText")) {


    } else if (strcmp(option, "-decodeText")) {


    } else if (strcmp(option, "-stringToImage")) {

        if (argc != 4) { //arguments for -stringToImage from command line must be 2
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        byte *text = readTextFile(argv[3]);

        char *imageName = argv[2];
        IMAGE *image = readImage(imageName);

        if (image != NULL) {

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

        if (image != NULL) {
            ImageToString(image);
        }

    } else {
        printf("\nThe option you have entered in not included!\n");
        exit(EXIT_FAILURE);

    }



    return 0;


}

