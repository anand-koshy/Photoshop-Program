/* File. print.c
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
#include "print.h"



void menu_prompt() {
    printf(
        "Main menu:\n"
        "r <filename> - read image from <filename>\n"
        "w <filename> - write image to <filename>\n"
        "c <x1> <y1> <x2> <y2> - crop image to the box with the given corners\n"
        "i - invert intensities\n"
        "s - swap color channels\n"
        "g - convert to grayscale\n"
        "b <amt> - change brightness (up or down) by the given amount\n"
        "q - quit\n"
        "\n"
        "Enter your choice:\n");

}

void invalid_input() {
    printf("Error: unknown command\n");
}

void invalid_file(char inputFile[]) {
    printf("Error: file %s not found\n", inputFile);
}

void no_image() {
    printf("Error: there is no current image\n");
}

void crop_failed() {
    printf("Error: cropping failed, image unchanged\n");
}

void not_ppm() {
    printf("Not a ppm fil\n");
}

void read(char inputFile[]) {
    printf("Reading from %s...\n", inputFile);
}

void write(char outputFile[]) {
    printf("Writing to %s...\n", outputFile);
}

void grayscale() {
    printf("Converting to grayscale...\n");
}

void brightnessPrint(double delta) {
    printf("Adjusting brightness by %lf...\n", delta);
}

void intensity() {
    printf("Inverting intensity...\n");
}

void cropPrint(int columnUp, int rowUp, int columnLower, int rowLower) {
    printf("Cropping region from (%d, %d) to (%d, %d)...\n", columnUp, rowUp, columnLower, rowLower);

}

void swapPrint() {
    printf("Swapping color channels...\n");
}

void quit() {
    printf("Goodbye!\n");
}



