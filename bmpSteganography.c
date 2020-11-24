/*<This file represents the client>
Copyright (C) <2020>  <ckasou01>

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
 * @file bmpSteganography.c
 *
 * @brief This file represents the client.
 *
 * @author Christos Kasoulides
 * @version 1.0
 * @since 24/11/20
 *
 */

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

    if (strcmp(option, "-list") == 0) {

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

    } else if (strcmp(option, "-grayscale") == 0) {

        if (argc != 5) { //arguments for -grayscale from command line must be 3
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        for (int i = 2; i < argc; i++) {
            IMAGE *image = readImage(argv[i]);

            if (image != NULL) { //if image is NULL the image is ignored
                bmpToGrayscale(image);


                char* newExtension = (char*)calloc(1,4+sizeof(argv[i])+1);
                strcat(newExtension, "new-");
                strcat(newExtension, argv[i]);
                saveImage(image, newExtension);
                free(newExtension);
            }
        }


    } else if (strcmp(option, "-encodeStegano") == 0) {

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

            char* newExtension = (char*)calloc(1,4+sizeof(coverImageName)+1);
            strcat(newExtension, "new-");
            strcat(newExtension, coverImageName);
            saveImage(coverImage, newExtension);
            free(newExtension);
        }

    } else if (strcmp(option, "-decodeStegano") == 0) {

        if (argc != 4) { //arguments for -decodeStegano from command line must be 2
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);
        }

        int noOfBits = atoi(argv[2]);


        char *coverImageName = argv[3];
        IMAGE *coverImage = readImage(coverImageName);

        if (coverImage != NULL) { //if cover image is NULL the image is ignored

            decodeStegano(noOfBits, coverImage);

            char* newExtension = (char*)calloc(1,4+sizeof(coverImageName)+1);
            strcat(newExtension, "new-");
            strcat(newExtension, coverImageName);
            saveImage(coverImage, newExtension);
            free(newExtension);
        }

    } else if (strcmp(option, "-encodeText") == 0) {

        if (argc != 4) { //arguments for -encodeText from command line must be 2
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        byte *text = readTextFile(argv[3]);

        char *imageName = argv[2];
        IMAGE *image = readImage(imageName);

        if (image != NULL) { //if image is NULL the image is ignored

            encodeText(image, text,SYSTEMKEY);

            char* newExtension = (char*)calloc(1,4+sizeof(imageName)+1);
            strcat(newExtension, "new-");
            strcat(newExtension, imageName);
            saveImage(image, newExtension);
            free(newExtension);
        }





    } else if (strcmp(option, "-decodeText") == 0) {

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

            char* newExtension = (char*)calloc(1,4+sizeof(imageName)+1);
            strcat(newExtension, "new-");
            strcat(newExtension, imageName);
            saveImage(image, newExtension);
            free(newExtension);
        }


    } else if (strcmp(option, "-stringToImage") == 0) {

        if (argc != 4) { //arguments for -stringToImage from command line must be 2
            printf("\nWrong number of arguments.\n");
            exit(EXIT_FAILURE);

        }

        byte *text = readTextFile(argv[3]);

        char *imageName = argv[2];
        IMAGE *image = readImage(imageName);

        if (image != NULL) { //if image is NULL the image is ignored

            stringToImage(image, text);

            char* newExtension = (char*)calloc(1,4+sizeof(imageName)+1);
            strcat(newExtension, "new-");
            strcat(newExtension, imageName);
            saveImage(image, newExtension);
            free(newExtension);
        }

    } else if (strcmp(option, "-imageToString") == 0) {

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
        printf("\nThe instruction you have entered in not included!\n");
        exit(EXIT_FAILURE);

    }



    return 0;


}


