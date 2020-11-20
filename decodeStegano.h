/**
 *
 * @file decodeStegano.h
 *
 * @brief This file represents the -decodeStegano function of the program.
 *
 * @author Christos Kasoulides
 * @version 1.0
 * @since 20/11/20
 *
 */
#ifndef EPL232_HW4_DECODESTEGANO_H
#define EPL232_HW4_DECODESTEGANO_H
#include "bmp.h"

/**
 * This function decodes a given images based on the given number of bits.
 *
 * @param noOfbits is an integer representing the given number of bits
 * @param newImage is an IMAGE representing the given image
 *
 * @return void
 */
void decodeStegano(int noOfbits,IMAGE* newImage);

#endif //EPL232_HW4_DECODESTEGANO_H
