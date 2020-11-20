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

void stringToImage(IMAGE* i, byte* text){

}

#ifdef DEBUGSTRINGTOIMAGE
int main(){
    readTextFile("strFile.txt");
    return 0;
}
#endif