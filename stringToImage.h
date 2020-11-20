//
// Created by leoni on 20/11/2020.
//


#ifndef EPL232_HW4_STRINGTOIMAGE_H
#define EPL232_HW4_STRINGTOIMAGE_H
#include "bmp.h"

byte* readTextFile(char* filename);

void stringToImage(IMAGE* image, byte* text);

byte getBit(byte* text, byte position);

#endif //EPL232_HW4_STRINGTOIMAGE_H
