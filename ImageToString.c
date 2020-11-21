//
// Created by leoni on 21/11/2020.
//

#include "ImageToString.h"
#include <stdlib.h>
#include <stdio.h>

void ImageToString(IMAGE* image, byte* text) {
    text = (byte *) calloc(image->size+1, sizeof(byte));
/*    for (byte i = 0; i < image->size; i++) {
        *(text+i)=0;
    }*/
    byte padding = (image->iheader->biWidth * 3) % 4;
    for (byte i = 0; i < image->iheader->biWidth; i++) {
        for (byte j = 0; j < image->iheader->biHeight; j++) {
            byte position=(image->iheader->biHeight * i + j);
            byte p=((image->data)+(j * image->iheader->biWidth + i + (j) * padding))->r;
            printf("%d",p);
            if(((image->data)+(j * image->iheader->biWidth + i + (j) * padding))->r==128){
                *(text+position/8)&(0x1<<(position%8));
            }
/*            else{
                *(text+position/8)&0x0<<(position%8);
            }*/
        }
    }
    printf("%s", text);
}

//#ifdef DEBUGIMAGETOSTRING
int main(){
    byte* text;
    IMAGE* i=readImage("C:\\Users\\leoni\\Desktop\\testStringToImage.bmp");
    ImageToString(i,text);
    return 0;
}
//#endif