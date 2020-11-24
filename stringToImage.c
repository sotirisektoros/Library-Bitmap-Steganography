/*<This file represents the -stringToImage function of the client.c >
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
 * @file stringToImage.c
 *
 * @brief This file represents the -stringToImage function of the program.
 *
 * @author Leonidas Lampiritis
 * @version 1.0
 * @since 19/11/20
 *
 */
#include "stringToImage.h"
#include "stdlib.h"
#include "stdio.h"
#include <string.h>


byte* readTextFile(char* filename){
    FILE *fp;
    //needs test if filename is .txt
    if((fp = fopen(filename,"rb")) == NULL){
        printf("Error opening file!");
        exit(1);
    }
    int size=1;
    byte* input=(byte*)calloc(1,sizeof(byte));
    int n=0;    // successfully read elements
    while(1){
        byte* buffer=(byte*)calloc(11,sizeof(byte));
        n= fread(buffer,sizeof(byte),10,fp);
        if(n==0){
            break;
        }
        size+=n;
        input=(byte*)realloc(input,size*sizeof(byte));
        strcat(input,buffer);
        if(n<10){
            break;
        }
        free(buffer);
    }
    return input;
}

static byte getBit(byte* text, int position){
    if (strlen(text)<=position/8){
        return 0;
    }
    byte c=(*(text+position/8) & (0x1 << (7-(position%8)))) >> (7-(position%8));
    return c;
}

/*void stringToImage(IMAGE* image, byte* text){
    byte padding=(image->iheader->biWidth*3)%4;
    for (byte i = 0; i < image->iheader->biWidth; i++) {
        for (byte j = 0; j < image->iheader->biHeight; j++) {
                ((image->data)+(j * image->iheader->biWidth + i + (j) * padding))->r=(128 * getBit(text, image->iheader->biHeight * i + j));
                ((image->data)+(j * image->iheader->biWidth + i + (j) * padding))->g=(128 * getBit(text, image->iheader->biHeight * i + j));
                ((image->data)+(j * image->iheader->biWidth + i + (j) * padding))->b=(128 * getBit(text, image->iheader->biHeight * i + j));
        }
    }
}*/
void stringToImage(IMAGE* image, byte* text){
    for (int i = 0; i < image->iheader->biWidth; i++) {
        for (int j = 0; j < image->iheader->biHeight; j++) {
            ((image->data)+((image->iheader->biHeight-j-1) * image->iheader->biWidth + i ))->r=(128 * getBit(text, image->iheader->biHeight * i + j));
            ((image->data)+((image->iheader->biHeight-j-1) * image->iheader->biWidth + i ))->g=(128 * getBit(text, image->iheader->biHeight * i + j));
            ((image->data)+((image->iheader->biHeight-j-1) * image->iheader->biWidth + i ))->b=(128 * getBit(text, image->iheader->biHeight * i + j));
        }
    }
}


#ifdef DEBUGSTRINGTOIMAGE
int main(){
    byte* text = readTextFile("strFile.txt");
    IMAGE* i=readImage("tux-pirate.bmp");
    stringToImage(i,text);
    saveImage(i,"/home/chris275/CLionProjects/EPL232_HW4/testStringToImage.bmp");
    return 0;
}
#endif