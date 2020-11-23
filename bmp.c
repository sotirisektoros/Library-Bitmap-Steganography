
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

    //BITMAP_FILE_HEADER
    fread(i->fheader,sizeof(BITMAPFILEHEADER),1,fp);

    //BITMAP_INFO_HEADER
    fread(i->iheader,sizeof(BITMAPINFOHEADER),1,fp);
    if (i->fheader->bfType1!='B' || i->fheader->bfType2!='M'){
        printf("\nFile %s is not .bmp image.\n",filename);      //check if file is BMP type
    }
    if (i->iheader->biCompression!=0){
        printf("\nFile %s is compressed.\n,filename");          //check if file is compressed
    }
    if (i->iheader->biBitCount!=24){
        printf("\nBits per PIXEL is not 24.\n");                // check if bits pe PIXEL are 24-bits
    }


    if((i->iheader->biWidth*3)%4 == 0){
        i->size = (i->iheader->biWidth * i->iheader->biHeight);
    }else
        i->size = (i->iheader->biWidth * i->iheader->biHeight) + i->iheader->biHeight*((i->iheader->biWidth*3)%4);

    i->data = (PIXEL*)malloc(i->size*sizeof(PIXEL));
    //BITMAP DATA
    fread(i->data,sizeof(PIXEL),i->size,fp);


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
    fwrite(i->data,sizeof(PIXEL),i->size,fp);


    fclose(fp);



}

IMAGE* copyImage(IMAGE* i){


    IMAGE* copy =(IMAGE*)malloc(sizeof(IMAGE));


    copy->fheader=(BITMAPFILEHEADER*)malloc(sizeof(BITMAPFILEHEADER));
    copy->iheader=(BITMAPINFOHEADER*)malloc(sizeof(BITMAPINFOHEADER));

    //BITMAP_FILE_HEADER  memcpy(copy->fheader,i->fheader,sizeof(BITMAPFILEHEADER))

    copy->fheader->bfOffBits = i->fheader->bfOffBits;
    copy->fheader->bfReserved2= i->fheader->bfReserved2;
    copy->fheader->bfReserved1= i->fheader->bfReserved2;
    copy->fheader->bfSize= i->fheader->bfSize;
    copy->fheader->bfType2= i->fheader->bfType2;
    copy->fheader->bfType1= i->fheader->bfType1;



    //BITMAP_INFO_HEADER  memcpy(copy->iheader,i->iheader,sizeof(BITMAPINFOHEADER))

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
    copy->data = (PIXEL*)malloc(copy->size*sizeof(PIXEL));
    for (int j = 0; j < copy->size; ++j) {
        copy->data[j]=i->data[j];  // or use memcpy(&copy->data[j],&i->data[j]
    }
   /** copy->data = (PIXEL**)malloc(copy->size*sizeof(PIXEL*));
    for (int j = 0; j < i->size; ++j) {
        *(copy->data+j)=(PIXEL*)malloc(sizeof(PIXEL));

        (*(copy->data+j))->b = (*(i->data+j))->b;
        (*(copy->data+j))->g = (*(i->data+j))->g;
        (*(copy->data+j))->r = (*(i->data+j))->r;
    }*/

    return copy;
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
