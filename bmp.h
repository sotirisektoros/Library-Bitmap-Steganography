//
// Created by leoni on 17/11/2020.
//

#ifndef EPL232_HW4_BMP_H
#define EPL232_HW4_BMP_H



typedef unsigned char byte; //%c
typedef unsigned short int word; //%hu
typedef unsigned int dword; //u


typedef struct bitmapfileheader{
    byte bfType1;   //Must always be set to 'BM' to declare that this is a .bmp file (i.e., bfType1=’B’ and bfType2=’M’. Based on these two fields you can identify if this is Bitmap file or not.
    byte bfType2;   //Must always be set to 'BM' to declare that this is a .bmp file (i.e., bfType1=’B’ and bfType2=’M’. Based on these two fields you can identify if this is Bitmap file or not.
    dword bfSize;   //Specifies the size of the file (including padding) in bytes
    word bfReserved1;   //Usually set to zero.
    word bfReserved2;   //Usually set to zero.
    dword bfOffBits;    //Specifies the offset from the beginning of the file to the bitmap data.
} __attribute__ ((__packed__)) BITMAPFILEHEADER;

typedef struct bitmapinfoheader{
    dword biSize;           //Specifies the size of the BITMAPINFOHEADER structure, in bytes.
    dword biWidth;          //Specifies the width of the image, in pixels.
    dword biHeight;         //Specifies the height of the image, in pixels.
    word biPlanes;          //Specifies the number of planes of the target device, usually set to zero.
    word biBitCount;        //Specifies the number of bits per pixel
    dword biCompression;    //Specifies the type of compression, usually set to zero (no compression). Need to provide an error if image is compressed.
    dword biSizeImage;      //Specifies the size of the image data, in bytes. If there is no compression, it is valid to set this member to zero.
    dword biXPelsPerMeter;  //Specifies the horizontal pixels per meter on the designated target device, usually set to zero.
    dword biYPelsPerMeter;  //Specifies the vertical pixels per meter on the designated target device, usually set to zero.
    dword biClrUsed;        //Specifies the number of colors used in the bitmap, if set to zero the number of colors is calculated using the biBitCount member.
    dword biClrImportant;   //Specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important.

} __attribute__ ((__packed__)) BITMAPINFOHEADER;

typedef struct pixel {
    byte r;
    byte g;
    byte b;
}__attribute__ ((__packed__)) PIXEL;

typedef struct image{
    BITMAPFILEHEADER* fheader;
    BITMAPINFOHEADER* iheader;
    dword size;
    PIXEL* data;
}__attribute__ ((__packed__)) IMAGE;

IMAGE* readImage(char* filename);

void saveImage(IMAGE* i, char* filename);

IMAGE* copyImage(IMAGE* i);

#endif //EPL232_HW4_BMP_H
