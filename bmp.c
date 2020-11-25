/*<This file represents the implementation of .bmp files.>
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
 * @file bmp.c
 *
 * @brief This file represents the implementation of.bmp files.
 *
 * @author Christos Kasoulides
 * @version 1.0
 * @since 24/11/20
 *
 */

#include "bmp.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


IMAGE* readImage(char* filename){

    FILE *fp;
    if((fp = fopen(filename,"rb")) == NULL){
        printf("\nError opening file!\n");
        exit(1);
    }
    IMAGE* i=(IMAGE*)malloc(sizeof(IMAGE));

    i->fheader=(BITMAPFILEHEADER*)malloc(sizeof(BITMAPFILEHEADER));
    i->iheader=(BITMAPINFOHEADER*)malloc(sizeof(BITMAPINFOHEADER));

    //BITMAP_FILE_HEADER
    fread(i->fheader,sizeof(BITMAPFILEHEADER),1,fp);

    //BITMAP_INFO_HEADER
    fread(i->iheader,sizeof(BITMAPINFOHEADER),1,fp);
    if (i->fheader->bfType1!='B' || i->fheader->bfType2!='M'){
        printf("\nFile %s is not .bmp image.\n",filename);      //check if file is BMP type
        return NULL;
    }
    if (i->iheader->biCompression!=0){
        printf("\nFile %s is compressed.\n",filename);          //check if file is compressed
        return NULL;
    }
    if (i->iheader->biBitCount!=24){
        printf("\nBits per PIXEL are not 24.\n");                // check if bits pe PIXEL are 24-bits
        return NULL;
    }

    i->size = (i->iheader->biWidth * i->iheader->biHeight);

    i->data = (PIXEL*)malloc(i->size*sizeof(PIXEL));
    //BITMAP DATA
    int counter=0;
    int padding=4-(i->iheader->biWidth*3)%4;

    for (int j = 0; j < i->size; ++j) {
        if(counter==i->iheader->biWidth*3){
            counter=0;
            if(padding!=4){
                for (int k = 0; k < padding; ++k) {
                    fgetc(fp);
                }
            }
        }
        i->data[j].r=fgetc(fp);
        i->data[j].g=fgetc(fp);
        i->data[j].b=fgetc(fp);
        counter+=3;
    }

    fclose(fp);

    return i;
}

void saveImage(IMAGE* i, char* filename){


    FILE *fp;
    if((fp = fopen(filename,"wb")) == NULL){
        printf("Error opening file!");
        exit(1);
    }


    //BITMAP_FILE_HEADER
    fwrite(i->fheader,sizeof(BITMAPFILEHEADER),1,fp);

    //BITMAP_INFO_HEADER
    fwrite(i->iheader,sizeof(BITMAPINFOHEADER),1,fp);

    //BITMAP DATA
    int counter=0;
    int padding=4-(i->iheader->biWidth*3)%4;

    for (int j = 0; j < i->size; ++j) {
        if(counter==i->iheader->biWidth*3){
            counter=0;
            if(padding!=4){
                for (int k = 0; k < padding; ++k) {
                    fputc('0',fp);
                }
            }
        }
        fputc(i->data[j].r,fp);
        fputc(i->data[j].g,fp);
        fputc(i->data[j].b,fp);
        counter+=3;
    }

    fclose(fp);
}

#ifdef DEBUGBMP
int main(int argc,char** argv){
    char* filename=argv[1];//full path
    IMAGE* i = readImage(filename);
    printf("%c\n%c\n%hu\n%u\n",i->fheader->bfType1,i->fheader->bfType2,i->fheader->bfSize,i->fheader->bfOffBits);
    printf("%u\n%u\n%hu",i->iheader->biHeight,i->iheader->biWidth,i->iheader->biBitCount);


    saveImage(i,"4x3new.bmp");

    printf("FINISH");

return 0;

}
#endif
