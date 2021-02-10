/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include <stdint.h>
#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90,};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  // Create Struct
  stat Array;

  // Initialize Struct
  Array.numArray = test;
  Array.arrayLength = SIZE;
  Array.max = 0;
  Array.min = 0xFF;
  Array.mean = 0;
  Array.median = 0;

  print_array(Array);
  print_statistics(Array);
  sort_array(Array);
  Array.min = find_min(Array.numArray, Array.arrayLength);
  Array.max = find_max(Array.numArray, Array.arrayLength);
  print_array(Array);
  print_statistics(Array);
}

void print_statistics(stat ArrayStats){
  printf("Array Min: %u\n", ArrayStats.min);
  printf("Array Max: %u\n", ArrayStats.max);
  printf("Array Mean: %u\n", ArrayStats.mean);
  printf("Array Median: %u\n", ArrayStats.median);
  printf("Array Size: %u\n", ArrayStats.arrayLength);
}

void print_array(stat ArrayStats){
  // Loop through and print the array
  for(uint8_t i=0; i<ArrayStats.arrayLength; i++){
    printf("array[%u]: %u\n", i, *(ArrayStats.numArray + sizeof(char)*i));
  }
  printf("\n");
  return;
}

void sort_array(stat ArrayStats){
  uint8_t i, j = 0;
  uint8_t temp;
  // Sort Array
  for(i=0; i<ArrayStats.arrayLength; i++){
    for(j=i+1; j<ArrayStats.arrayLength; j++){
      if(ArrayStats.numArray[i]<ArrayStats.numArray[j]){
        temp = ArrayStats.numArray[i];
        ArrayStats.numArray[i]=ArrayStats.numArray[j];
        ArrayStats.numArray[j]=temp;
      }
    }
  }
}

uint8_t find_min(uint8_t *arrayPtr, uint8_t arrayLength){
  uint8_t minValue=0xFF;

  for (uint8_t i=0; i<arrayLength; i++){
    if (arrayPtr[i] < minValue){
      minValue = arrayPtr[i];
    }
  }

  return minValue;
}

uint8_t find_max(uint8_t *arrayPtr, uint8_t arrayLength){
  uint8_t maxValue=0;

  for (uint8_t i=0; i<arrayLength; i++){
    if (arrayPtr[i] > maxValue){
      maxValue = arrayPtr[i];
    }
  }

  return maxValue;
}