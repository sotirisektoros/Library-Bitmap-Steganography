//
// Created by leoni on 20/11/2020.
//


#ifndef EPL232_HW4_STRINGTOIMAGE_H
#define EPL232_HW4_STRINGTOIMAGE_H
#include "bmp.h"

byte* readTextFile(char* filename);

void stringToImage(IMAGE* i, byte* text);

#endif //EPL232_HW4_STRINGTOIMAGE_H
