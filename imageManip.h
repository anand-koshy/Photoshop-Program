/* File: imageManip.h
 * Homework 6, 600.120 Spring 2017
 *
 * Anand Koshy
 * akoshy1
 * akoshy1@jhu.edu
 * 4 April 2017
 */

#include <stdio.h>
#include "menu.h"
#include "ppmIO.h"

#ifndef IMAGEMANIP_H_
#define IMAGEMANIP_H_

int failedCrop(header* headerInfo, int rowUp, int columnUp, int rowLower, int columnLower);
pixel* crop(header* headerInfo, pixel* picture, int rowUp, int columnUp, int rowLower,
            int columnLower);
pixel* inversion(header* headerInfo, pixel* picture);
pixel* swap(header* headerInfo, pixel* picture);
pixel* grayScale(header* headerInfo, pixel* picture);
unsigned char clamp(double color);
pixel* brightness(header* headerInfo, pixel* picture, double delta);



#endif //IMAGEMANIP_H_
