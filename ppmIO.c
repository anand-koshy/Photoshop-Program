/* File. ppmIO.c
 * Homework 6, 600.120 Spring 2017
 *
 * Anand Koshy
 * akoshy1
 * akoshy1@jhu.edu
 * 4 April 2017
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "print.h"
#include "ppmIO.h"
#include "menu.h"
#include "imageManip.h"

//Checks if the input file exists
int validFile(char inputFile[]) {

    FILE* fp = fopen(inputFile, "r");

    if (fp == NULL) {
        invalid_file(inputFile);
        return 0;
    }

    fclose(fp);
    return 1;
}

//Reads the header from input file
//and determines if it's a ppm file
//Also stores columns, rows, and columns
//in appropriate variables
int readHeader(FILE* fp, header* headerInfo) {

    char a;

    fscanf(fp, "%s", headerInfo->file);

    if ((strcmp("P6", headerInfo->file))) {
        not_ppm();
        return 0;
    }

    while (isspace(a = fgetc(fp))) {
        while ((a = fgetc(fp)) == '#') {
            while ((a = fgetc(fp)) != '\n') {
            }
        }
        ungetc(a, fp);
    }
    ungetc(a, fp);

    fscanf(fp, " %d %d %d", &headerInfo->columns, &headerInfo->rows, &headerInfo->colorRange);

    a = fgetc(fp);

    return 1;
}


//Reads pixels from input file and stores in picture array
int readPixels(FILE* fp, pixel* picture, header* headerInfo) {

    return fread(picture, 3 * sizeof(unsigned char), headerInfo->columns * headerInfo->rows, fp);

    //return 1;
}

//Writes header info to appropriate output fileo
int writeHeader(FILE* fp, header* headerInfo) {

    fprintf(fp, "%s\n", headerInfo->file);
    fprintf(fp, "%d %d\n", headerInfo->columns, headerInfo->rows);
    fprintf(fp, "%d\n", headerInfo->colorRange);

    return 1;

}

//Writes pixels of updated image to output file
int writePixels(FILE* fp, pixel* picture, header* headerInfo) {

    fwrite(picture, 3 * sizeof(unsigned char), headerInfo->columns * headerInfo->rows, fp);
    fprintf(fp, "\n");

    return 1;
}
