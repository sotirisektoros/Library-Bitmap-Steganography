
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


    //if((i->iheader->biWidth*3)%4 == 0){
    i->size = (i->iheader->biWidth * i->iheader->biHeight);
    //}else
        //i->size = (i->iheader->biWidth * i->iheader->biHeight) + i->iheader->biHeight*((i->iheader->biWidth*3)%4);

    i->data = (PIXEL*)malloc(i->size*sizeof(PIXEL));
    //BITMAP DATA
    // fread(i->data,sizeof(PIXEL),i->size,fp);
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
    //fwrite(i->data,sizeof(PIXEL),i->size,fp);
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
