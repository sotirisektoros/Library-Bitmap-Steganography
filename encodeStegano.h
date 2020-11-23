/*<This file represents the -encodeStegano function of the client.c >
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
 * @file encodeStegano.h
 *
 * @brief This file represents the -encodeStegano function of the program.
 *
 * @author Christos Kasoulides
 * @version 1.0
 * @since 20/11/20
 *
 */

#ifndef EPL232_HW4_ENCODESTEGANO_H
#define EPL232_HW4_ENCODESTEGANO_H

#include "bmp.h"

/**
 * This function encodes the secret image inside the cover image based on the given number of bits.
 *
 * @param noOfbits is an integer representing the given number of bits
 * @param cover is an IMAGE representing the given cover image
 * @param secret is an IMAGE representing the given secret image
 *
 * @return void
 */
void encodeStegano(int noOfbits, IMAGE* cover, IMAGE* secret);

#endif //EPL232_HW4_ENCODESTEGANO_H
