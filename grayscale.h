//
// Created by leoni on 19/11/2020.
//

#ifndef EPL232_HW4_GRAYSCALE_H
#define EPL232_HW4_GRAYSCALE_H
#include "bmp.h"

void bmpToGrayscale(IMAGE* i);

static void PixelToLuminance(PIXEL* p);

#endif //EPL232_HW4_GRAYSCALE_H
