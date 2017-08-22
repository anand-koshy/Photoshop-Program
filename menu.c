/* File. menu.c
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


//Switch statement for handling user input
void userMenu() {
    //Stores input file
    char inputFile[50];
    //Stores output file
    char outputFile[50];
    int length;
    //Stores upper left row number
    int rowUp;
    //Stores upper left column number
    int columnUp;
    //Stores lower right row number
    int rowLower;
    //Stores lower right column number
    int columnLower;
    //Counter to keep track if a file has been successfully read
    int count = 0;
    //Stores brightness delta value
    double delta;

    //Struct for holding info related to current image
    header* headerInfo = malloc(sizeof(header));
    //Array of pixel structs for holding RGB values
    pixel* picture = malloc(sizeof(pixel));


    while (1) {

        char selection[50];

        menu_prompt();
        //Reads user menu input
        scanf("%s", selection);

        if (strlen(selection) == 1) {
            switch (selection[0]) {

            case 'r': //Read from file
                scanf("%s", inputFile);
                length = strlen(inputFile);
                inputFile[length] = '\0';
                read(inputFile);
                if (validFile(inputFile) == 0) {
                    break;
                }
                FILE* fp = fopen(inputFile, "r");
                if (readHeader(fp, headerInfo) == 0) {
                    break;
                }
                //Changes size of picture array to correspond to dimensions from the header
                picture = realloc(picture, sizeof(pixel) * headerInfo->columns * headerInfo->rows);
                readPixels(fp, picture, headerInfo);
                fclose(fp);
                count++;
                break;
            case 'w': //Write to file
                //Checks if a file has been read first
                if (count == 0) {
                    no_image();
                    break;
                }
                scanf("%s", outputFile);
                length = strlen(outputFile);
                outputFile[length] = '\0';
                write(outputFile);
                FILE* fpointer = fopen(outputFile, "w");
                writeHeader(fpointer, headerInfo);
                writePixels(fpointer, picture, headerInfo);
                fclose(fpointer);
                break;
            case 'c': //Crop
                //Checks if a file has been read first
                if (count == 0) {
                    no_image();
                    break;
                }
                scanf("%d %d %d %d", &columnUp, &rowUp, &columnLower, &rowLower);
                cropPrint(columnUp, rowUp, columnLower, rowLower);
                if (failedCrop(headerInfo, rowUp, columnUp, rowLower, columnLower) == 0) {
                    break;
                }
                picture = crop(headerInfo, picture, rowUp, columnUp, rowLower, columnLower);
                break;
            case 'i': //Inversion
                //Checks if a file has been read first
                if (count == 0) {
                    no_image();
                    break;
                }
                intensity();
                picture = inversion(headerInfo, picture);
                break;
            case 's':
                //Checks if a file has been read first
                if (count == 0) {
                    no_image();
                    break;
                }
                swapPrint();
                picture = swap(headerInfo, picture);
                break;
            case 'g': //Grayscale
                if (count == 0) {
                    no_image();
                    break;
                }
                grayscale();
                picture = grayScale(headerInfo, picture);
                break;
            case 'b': //Brightness
                //Checks if a file has been read first
                if (count == 0) {
                    no_image();
                    break;
                }
                scanf("%lf", &delta);
                brightnessPrint(delta);
                picture = brightness(headerInfo, picture, delta);
                break;
            case 'q': //Quit
                //Free headerInfo
                free(headerInfo);
                //Free pointer to picture array
                free(picture);
                quit();
                exit(1);
                break;
            default:
                invalid_input();
                break;

            }

        } else {
            invalid_input();
        }

    }

}
