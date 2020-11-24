/*<This file represents the -list function of the client.c >
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
 * @file list.c
 *
 * @brief This file represents the -list function of the program.
 *
 * @author Christos Kasoulides
 * @version 1.0
 * @since 19/11/20
 *
 */
#include "list.h"
#include <stdio.h>


void list(IMAGE *i){
    printf("\nBITMAP_FILE_HEADER\n");
    printf("==================\n");

    printf("bfType: %c%c\n",i->fheader->bfType1,i->fheader->bfType2);
    printf("bfSize: %u\n",i->fheader->bfSize);
    printf("bfReserved1: %hu\n",i->fheader->bfReserved1);
    printf("bfReserved2: %hu\n",i->fheader->bfReserved2);
    printf("bfOffBits: %u\n",i->fheader->bfOffBits);

    printf("\nBITMAP_INFO_HEADER\n");
    printf("==================\n");

    printf("biSize: %u\n",i->iheader->biSize);
    printf("biWidth: %u\n",i->iheader->biWidth);
    printf("biHeight: %u\n",i->iheader->biHeight);
    printf("biPlanes: %hu\n",i->iheader->biPlanes);
    printf("biBitCount: %hu\n",i->iheader->biBitCount);
    printf("biCompression: %u\n",i->iheader->biCompression);
    printf("biSizeImage: %u\n",i->iheader->biSizeImage);
    printf("biXPelsPerMeter: %u\n",i->iheader->biXPelsPerMeter);
    printf("biYPelsPerMeter: %u\n",i->iheader->biYPelsPerMeter);
    printf("biClrUsed: %u\n",i->iheader->biClrUsed);
    printf("biClrImportant: %u\n",i->iheader->biClrImportant);

    printf("***************************************************************************\n");


}

#ifdef DEBUGLIST
int main(int argc,char** argv){


    for(int j = 1; j < argc; j++){
        char* filename=argv[j];
        IMAGE* i = readImage(filename);
        list(i);
    }


return 0;

}
#endif




