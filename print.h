/* File: print.h
 * Homework 6, 600.120 Spring 2017
 *
 * Anand Koshy
 * akoshy1
 * akoshy1@jhu.edu
 * 4 April 2017
 */

#include <stdio.h>
#ifndef PRINT_H_
#define PRINT_H_

void menu_prompt();
void invalid_input();
void invalid_file(char inputFile[]);
void no_image();
void crop_failed();
void not_ppm();
void read(char inputFile[]);
void write(char outputFile[]);
void grayscale();
void brightnessPrint(double delta);
void intensity();
void cropPrint(int columnUp, int rowUp, int columnLower, int rowLower);
void swapPrint();
void quit();


#endif //PRINT_H_
