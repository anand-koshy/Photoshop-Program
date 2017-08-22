/* File. imageManip.c
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

//Checks user input and determines if the coordinates entered are valid
int failedCrop(header* headerInfo, int rowUp, int columnUp, int rowLower, int columnLower) {

    //Checks that the entered rows are within the original image
    if (rowUp > headerInfo->rows || rowLower > headerInfo->rows) {
        crop_failed();
        return 0;

    }

    //Checks that the entered columns are withing the original image
    if (columnUp > headerInfo->columns || columnLower > headerInfo->columns) {
        crop_failed();
        return 0;
    }

    //Checks that the coordinates are for the upper left and lower right
    //corners and not the upper right and lower left
    if (columnUp > columnLower || rowUp > rowLower) {
        crop_failed();
        return 0;
    }

    return 1;

}

//Functions for cropping image
pixel* crop(header* headerInfo, pixel* picture, int rowUp, int columnUp, int rowLower,
            int columnLower) {


    int newRow;//Stores the total rows for cropped image
    int newColumn;//Stores the total columns for the cropped image

    newRow = headerInfo->rows - rowUp - (headerInfo->rows - rowLower);
    newColumn = (headerInfo)->columns - columnUp - (headerInfo->columns - columnLower);

    //Temporary array of pixel structs for storing cropped image
    pixel* temp = malloc(sizeof(pixel) * newRow * newColumn);

    //Finds starting index in original array for the cropped image
    int startIndex = (headerInfo->columns * rowUp) + columnUp;
    //Determines the number of indices to skip after going through one row
    int increment = (headerInfo)->columns - newColumn;
    //Stores index for temp array
    int index = 0;

    for (int i = rowUp; i < rowLower; i++) {
        for (int j = columnUp; j < columnLower; j++) {
            temp[index] = picture[startIndex];
            index++;
            startIndex++;
        }
        startIndex = startIndex + increment;
    }


    free(picture);
    //Changes the dimensions stored in the struct to correspond
    //to the cropped image
    (headerInfo)->columns = newColumn;
    (headerInfo)->rows = newRow;

    //Returns the address of temp so the
    //the picture pointer now points to the cropped image
    //instead of the original
    return temp;

}

//Inverts intensity of image
pixel* inversion(header* headerInfo, pixel* picture) {

    int index = 0;
    for (int i = 0; i < headerInfo->rows; i++) {

        for (int j = 0; j < headerInfo->columns; j++) {
            picture[index].red = 255 - picture[index].red;
            picture[index].green = 255 - picture[index].green;
            picture[index].blue = 255 - picture[index].blue;
            index++;
        }

    }

    return picture;
}

//Swaps color channel of image
pixel* swap(header* headerInfo, pixel* picture)  {

    int index = 0;
    unsigned char tempRed = '0';
    unsigned char tempGreen = '0';
    unsigned char tempBlue = '0';

    for (int i = 0; i < headerInfo->rows; i++) {

        for (int j = 0; j < headerInfo->columns; j++) {

            tempRed = picture[index].red;
            tempGreen = picture[index].green;
            tempBlue = picture[index].blue;
            picture[index].red = tempGreen;
            picture[index].green = tempBlue;
            picture[index].blue = tempRed;

            index++;
        }
    }

    return picture;
}


//Converts image to grayscale
pixel* grayScale(header* headerInfo, pixel* picture) {

    unsigned char intensity = '0';

    int index = 0;

    for (int i = 0; i < headerInfo->rows; i++) {

        for (int j = 0; j < headerInfo->columns; j++) {

            intensity = ((.30) * picture[index].red) + ((.59) * picture[index].green) +
                        ((.11) * picture[index].blue);
            picture[index].red = intensity;
            picture[index].green = intensity;
            picture[index].blue = intensity;
            index++;

        }

    }

    return picture;

}

//Clamps saturation so it stays within 0 to 255 range
//when changing brightness
unsigned char clamp(double color) {

    unsigned char clampedColor;

    if (color > 255) {
        clampedColor = 255;
    } else if (color < 0) {
        clampedColor = 0;
    } else {
        clampedColor = (unsigned char)color;
    }
    return clampedColor;
}

//Adjusts brightness of image
pixel* brightness(header* headerInfo, pixel* picture, double delta) {

    int index = 0;
    double tempRed;
    double tempGreen;
    double tempBlue;

    for (int i = 0; i < headerInfo->rows; i++) {
        for (int j = 0; j < headerInfo->columns; j++) {

            tempRed = picture[index].red * delta;
            tempGreen = picture[index].green * delta;
            tempBlue = picture[index].blue * delta;

            tempRed = clamp(tempRed);
            tempBlue = clamp(tempBlue);
            tempGreen = clamp(tempGreen);

            picture[index].red = tempRed;
            picture[index].green = tempGreen;
            picture[index].blue = tempBlue;
            index++;

        }
    }
    return picture;

}




