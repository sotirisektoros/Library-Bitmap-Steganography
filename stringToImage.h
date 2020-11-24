//
// Created by leoni on 20/11/2020.
//


#ifndef EPL232_HW4_STRINGTOIMAGE_H
#define EPL232_HW4_STRINGTOIMAGE_H
#include "bmp.h"
/**
 * This method takes as argument a char* that repersents a txt filename
 * and returns a byte* that points to a string that represents the content
 * of the file
 * @param filename The filename of the txt file to be read
 * @return a String of the content of the txt file
 */
byte* readTextFile(char* filename);

/**
 * This method takes as argument an IMAGE* and a string byte*
 * and creates an IMAGE from the text
 * @param image The result of the the conversion of text to image
 * @param text The text to be converted to IMAGE
 */
void stringToImage(IMAGE* image, byte* text);

#endif //EPL232_HW4_STRINGTOIMAGE_H
