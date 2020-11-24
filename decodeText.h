//
// Created by leoni on 22/11/2020.
//

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
