/*<This file represents the -grayscale function of the client.c >
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
 * @file grayscale.c
 *
 * @brief This file represents the -grayscale function of the program.
 *
 * @author Leonidas Lampiritis
 * @version 1.0
 * @since 19/11/20
 *
 */
#include "grayscale.h"
#include <math.h>

/*
void PixelToLuminance (PIXEL* p){
    byte luminance = round(0.299*p->r+0.587*p->g+0.114*p->b);
    p->r=luminance;
    p->g=luminance;
    p->b=luminance;
}
*/

void bmpToGrayscale(IMAGE* i){
    for (int j = 0; j < i->size; ++j) {
       // PixelToLuminance(&i->data[j]);
    }
}


#ifdef DEBUGGRAYSCALE
int main(int argc,char** argv){
    char* filename=argv[1];//full path
    IMAGE* i = readImage(filename);
    bmpToGrayscale(i);
    saveImage(i,"grayscale.bmp");
}
#endif