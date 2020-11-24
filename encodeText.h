

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
