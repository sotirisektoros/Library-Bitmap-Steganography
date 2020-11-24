/*<This file represents the -decodeText function of the client.c >
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
 * @file decodeText.h
 *
 * @brief This file represents the -decodeText function of the program.
 *
 * @author Leonidas Lampiritis
 * @version 1.0
 * @since 24/11/20
 *
 */
#ifndef EPL232_HW4_DECODETEXT_H
#define EPL232_HW4_DECODETEXT_H
#include "bmp.h"

/**
 * This method takes an IMAGE* with encoded text, the number of characters
 * of the string that is encoded, and the systemkey value that was used in
 * the encoding process  and decodes the secret massage in a file using the
 * given filename
 * @param image  An IMAGE with encoded message
 * @param msLength The number of characters of the encoded text
 * @param systemkey the key that was used in encoding process
 * @param filename the name of a file to write the secret message
 */
void decodeText(IMAGE *image, int msLength, unsigned int systemkey, char *filename);


#endif //EPL232_HW4_DECODETEXT_H
