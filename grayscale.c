//
// Created by leoni on 19/11/2020.
//

#include "grayscale.h"
#include <math.h>

void bmpToGrayscale(IMAGE* i){
    int line=i->iheader->biWidth;
    int counter=0;
    int padding=(i->iheader->biWidth*3)%4;
    for (int j = 0; j < i->size; ++j) {
        if(counter<line){
            PixelToLuminance(&i->data[j]);
        }
        else{
            counter=0;
            j+=padding;
        }
    }
}

static void PixelToLuminance (PIXEL* p){
    byte luminance = round(0.299*p->r+0.587*p->g+0.114*p->b);
    p->r=luminance;
    p->g=luminance;
    p->b=luminance;
}

#ifdef DEBUGGRAYSCALE
int main(int argc,char** argv){
    char* filename=argv[1];//full path
    IMAGE* i = readImage(filename);
    bmpToGrayscale(i);
    saveImage(i,"grayscale.bmp");
}
#endif