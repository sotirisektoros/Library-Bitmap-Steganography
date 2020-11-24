/*<This file represents the -stringToImage function of the client.c >
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
 * @file stringToImage.h
 *
 * @brief This file represents the -stringToImage function of the program.
 *
 * @author Leonidas Lampiritis
 * @version 1.0
 * @since 19/11/20
 *
 */


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
