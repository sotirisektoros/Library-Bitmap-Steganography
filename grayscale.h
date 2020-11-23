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
