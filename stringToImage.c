//
// Created by leoni on 20/11/2020.
//

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

static byte getBit(byte* text, byte position){
    if (strlen(text)<=position/8){
        return 0;
    }
    byte c=(*(text+position/8) & (0x1 << (7-(position%8)))) >> (7-(position%8));
    return c;
}

void stringToImage(IMAGE* image, byte* text){
    byte padding=(image->iheader->biWidth*3)%4;
    for (byte i = 0; i < image->iheader->biWidth; i++) {
        for (byte j = 0; j < image->iheader->biHeight; j++) {
                ((image->data)+(j * image->iheader->biWidth + i + (j) * padding))->r=(128 * getBit(text, image->iheader->biHeight * i + j));
                ((image->data)+(j * image->iheader->biWidth + i + (j) * padding))->g=(128 * getBit(text, image->iheader->biHeight * i + j));
                ((image->data)+(j * image->iheader->biWidth + i + (j) * padding))->b=(128 * getBit(text, image->iheader->biHeight * i + j));
        }
    }
}


#ifdef DEBUGSTRINGTOIMAGE
int main(){
    readTextFile("strFile.txt");
    IMAGE* i=readImage("3x4.bmp");
    stringToImage(i,"AC");
    saveImage(i,"C:\\Users\\leoni\\Desktop\\testStringToImage.bmp");
    return 0;
}
#endif