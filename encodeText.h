/*<This file represents the -encodeText function of the client.c >
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
 * @file encodeText.h
 *
 * @brief This file represents the -encodeText function of the program.
 *
 * @author Leonidas Lampiritis
 * @version 1.0
 * @since 24/11/20
 *
 */

#ifndef EPL232_HW4_ENCODETEXT_H
#define EPL232_HW4_ENCODETEXT_H

#include "bmp.h"



/**
 * This method encodes a secret message (char* text) into the IMAGE* i
 * using the systemkey
 * @param i
 * @param text the text to tb encoded
 * @param systemkey The secret key of the encoding process
 */
void encodeText(IMAGE* i,char* text,unsigned int systemkey);

/**
 * This method takes as argument one string filename and returns
 * a char* that points to the content of the file
 * @param filename the name of the file to be read
 * @return char* that points to the content of the file
 */
char* readTextFromFile(char* filename);



#endif //EPL232_HW4_ENCODETEXT_H
