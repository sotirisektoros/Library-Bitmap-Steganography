//
// Created by leoni on 17/11/2020.
//

#include "bmp.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

IMAGE* readImage(char* filename){
    FILE *fp;
    if((fp = fopen(filename,"rb")) == NULL){
        printf("Error opening file!");
        exit(1);
    }
    IMAGE* i=(IMAGE*)malloc(sizeof(IMAGE));
    i->fheader=(BITMAPFILEHEADER*)malloc(sizeof(BITMAPFILEHEADER));
    i->iheader=(BITMAPINFOHEADER*)malloc(sizeof(BITMAPINFOHEADER));
    byte* fh=(byte*)malloc(14*sizeof(byte));
    fscanf(fp,fh,14*sizeof(byte));
    i->fheader->bfOffBits= (*(fh)) & 0xFFFFFFFF;          *fh >> 32;
    i->fheader->bfReserved2= (*(fh)) & 0xFFFF;            *fh >> 16;
    i->fheader->bfReserved1= (*(fh)) & 0xFFFF;            *fh >> 16;
    i->fheader->bfSize=*(fh) & 0xFFFFFFFF;                *fh >> 32;
    i->fheader->bfType2=*(fh) & 0xF;                      *fh >> 4;
    i->fheader->bfType1=*(fh) & 0xF;                      *fh >> 4;
    free(fh);
    byte* ih=(byte*)malloc(40*sizeof(byte));
    fscanf(fp,ih,40*sizeof(byte));
    i->iheader->biClrImportant = (*(ih)) & 0xFFFFFFFF;    *ih >> 32;
    i->iheader->biClrUsed = (*(ih)) & 0xFFFFFFFF;         *ih >> 32;
    i->iheader->biYPelsPerMeter = (*(ih)) & 0xFFFFFFFF;   *ih >> 32;
    i->iheader->biXPelsPerMeter = (*(ih)) & 0xFFFFFFFF;   *ih >> 32;
    i->iheader->biSizeImage = (*(ih)) & 0xFFFFFFFF;       *ih >> 32;
    i->iheader->biCompression = (*(ih)) & 0xFFFFFFFF;     *ih >> 32;
    i->iheader->biBitCount = (*(ih)) & 0xFFFF;            *ih >> 16;
    i->iheader->biPlanes = (*(ih)) & 0xFFFF;              *ih >> 16;
    i->iheader->biHeight = (*(ih)) & 0xFFFFFFFF;          *ih >> 32;
    i->iheader->biWidth = (*(ih)) & 0xFFFFFFFF;           *ih >> 32;
    i->iheader->biSize = (*(ih)) & 0xFFFFFFFF;            *ih >> 32;
    free(ih);
    i->size=i->iheader->biHeight*i->iheader->biWidth;
    i->data = (PIXEL**)malloc(i->size*sizeof(PIXEL*));
    char* temp=(char*)malloc(3*sizeof(byte));
    for (int j = 0; j < i->size; ++j) {
        *(i->data+j)=(PIXEL*)malloc(sizeof(PIXEL));
        fscanf(fp,temp,3*sizeof(byte));
        (*(i->data+j))->b = *(temp) & 0xFF;               *temp >> 8;
        (*(i->data+j))->g = *(temp) & 0xFF;               *temp >> 8;
        (*(i->data+j))->r = *(temp) & 0xFF;               *temp >> 8;
    }
    free(temp);
    return i;
}

void saveImage(IMAGE* i, char* filename){




}

IMAGE* copyImage(IMAGE* i){


    IMAGE* copy =(IMAGE*)malloc(sizeof(IMAGE));


    copy->fheader=(BITMAPFILEHEADER*)malloc(sizeof(BITMAPFILEHEADER));
    copy->iheader=(BITMAPINFOHEADER*)malloc(sizeof(BITMAPINFOHEADER));

    //BITMAP_FILE_HEADER

    copy->fheader->bfOffBits = i->fheader->bfOffBits;
    copy->fheader->bfReserved2= i->fheader->bfReserved2;
    copy->fheader->bfReserved1= i->fheader->bfReserved2;
    copy->fheader->bfSize= i->fheader->bfSize;
    copy->fheader->bfType2= i->fheader->bfType2;
    copy->fheader->bfType1= i->fheader->bfType1;



    //BITMAP_INFO_HEADER

    copy->iheader->biClrImportant = i->iheader->biClrImportant;
    copy->iheader->biClrUsed = i->iheader->biClrUsed;
    copy->iheader->biYPelsPerMeter = i->iheader->biYPelsPerMeter;
    copy->iheader->biXPelsPerMeter = i->iheader->biXPelsPerMeter;
    copy->iheader->biSizeImage = i->iheader->biSizeImage;
    copy->iheader->biCompression = i->iheader->biCompression;
    copy->iheader->biBitCount = i->iheader->biBitCount;
    copy->iheader->biPlanes = i->iheader->biPlanes;
    copy->iheader->biHeight = i->iheader->biHeight;
    copy->iheader->biWidth = i->iheader->biWidth;
    copy->iheader->biSize = i->iheader->biSize;


    //BITMAP DATA

    copy->size=i->size;
    copy->data = (PIXEL**)malloc(copy->size*sizeof(PIXEL*));
    for (int j = 0; j < i->size; ++j) {
        *(copy->data+j)=(PIXEL*)malloc(sizeof(PIXEL));

        (*(copy->data+j))->b = (*(i->data+j))->b;
        (*(copy->data+j))->g = (*(i->data+j))->g;
        (*(copy->data+j))->r = (*(i->data+j))->r;
    }

    return copy;
}

