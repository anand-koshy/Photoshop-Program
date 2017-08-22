/* File: ppmIO.h
 * Homework 6, 600.120 Spring 2017
 *
 * Anand Koshy
 * akoshy1
 * akoshy1@jhu.edu
 * 4 April 2017
 */

#include <stdio.h>
#ifndef PPMIO_H_
#define PPMIO_H_

//Struct for storing RGB values of each pixel
//for one index in the array
typedef struct pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;

} pixel;

//Struct for storing image type, rows,
//columns, and color range for current image
typedef struct header {
    char file[15];
    int rows;
    int columns;
    int colorRange;
} header;

int validFile(char inputFile[]);
int readHeader(FILE* fp, header* headerInfo);
int readPixels(FILE* fp, pixel* picture, header* headerInfo);
int writeHeader(FILE* fp, header* headerInfo);
int writePixels(FILE* fp, pixel* picture, header* headerInfo);



#endif //PPMIO_H_
