//
// Created by leoni on 21/11/2020.
//

#include "ImageToString.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*void ImageToString(IMAGE* image, byte* text) {
    text = (byte *) calloc(image->size+1, sizeof(byte));
*//*    for (byte i = 0; i < image->size; i++) {
        *(text+i)=0;
    }*//*
    byte padding = (image->iheader->biWidth * 3) % 4;
    for (int i = 0; i < image->iheader->biWidth; i++) {
        for (int j = 0; j < image->iheader->biHeight; j++) {
            byte position=(image->iheader->biHeight * i + j);
            byte p=((image->data)+((image->iheader->biHeight-j-1) * image->iheader->biWidth + i + (j) * padding))->r;
            //printf("%d",p);
            if(p==128){
                byte c=*(text+position/8);
                byte mask=0x1<<(position%8);
                c|=mask;
                *(text+position/8)=c;
            }
*//*            else{
                *(text+position/8)&0x0<<(position%8);
            }*//*
        }
    }
    printf("%s", text);
    fflush(stdout);
}*/

void ImageToString(IMAGE *image) {
    FILE* fp;
    if((fp = fopen("outputText.txt","wb")) == NULL){
        printf("Error opening file!");
        exit(1);
    }
    int countBits=0;
    byte c='\0';
    for (int i = 0; i < image->iheader->biWidth; i++) {
        for (int j = 0; j < image->iheader->biHeight; j++) {
            byte p=((image->data)+((image->iheader->biHeight-j-1) * image->iheader->biWidth + i ))->r; //(j) * padding
            //printf("%d",p);
            if(p==128){
                c<<=1;
                c|=1;
                countBits++;
            }
            else{
                c<<=1;
                countBits++;
            }
            if (countBits==8){
                countBits=0;
                fputc(c,fp);
                c='\0';
            }
        }
    }
}

#ifdef DEBUGIMAGETOSTRING
int main(int argc, char**argv){
    IMAGE* i=readImage(argv[1]);
    ImageToString(i);
    return 0;
}
#endif