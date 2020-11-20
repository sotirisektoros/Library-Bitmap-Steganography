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
