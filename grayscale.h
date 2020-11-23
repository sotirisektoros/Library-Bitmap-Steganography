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
 * @file grayscale.h
 *
 * @brief This file represents the -grayscale function of the program.
 *
 * @author Leonidas Lampiritis
 * @version 1.0
 * @since 19/11/20
 *
 */

#ifndef EPL232_HW4_GRAYSCALE_H
#define EPL232_HW4_GRAYSCALE_H
#include "bmp.h"


/**
 * This method takes as argument an PIXEL pointer (PIXEL*) and
 * convert add a grayscale filter to the given PIXEL.
 * @param p PIXEL pointer (PIXEL*) that points to a PIXEL
 */
void PixelToLuminance (PIXEL* p);

/**
 * This method takes as argument an IMAGE pointer (IMAGE*) and
 * convert add a grayscale filter to the given bmp IMAGE.
 * @param i IMAGE pointer (IMAGE*) that points to a bmp IMAGE
 */
void bmpToGrayscale(IMAGE* i);



#endif //EPL232_HW4_GRAYSCALE_H
