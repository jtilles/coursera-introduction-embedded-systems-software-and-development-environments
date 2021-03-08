/******************************************************************************
 * Copyright (C) 2021 by @author
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Josh Illes is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Functions for providing statics on an array of numbers, 
 *   and general practice in the "C" language
 *
 *
 * @author Joshua Illes
 * @date 2021-02-09
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

typedef struct stats{
    uint8_t *numArray;
    uint8_t arrayLength;
    uint8_t median;
    uint8_t mean;
    uint8_t max;
    uint8_t min;
} stat;

/**
 * @brief Print out all the statistics related to the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * 
 * @return Void()
 */
void print_statistics(uint8_t *arrayPtr, uint8_t arrayLength);


/**
 * @brief Prints the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * 
 * @return Void()
 */
void print_array(uint8_t *arrayPtr, uint8_t arrayLength);

/**
 * @brief Sorts the array inplace from largest (index 0) to smallest (index n-1)
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 */
void sort_array(uint8_t *arrayPtr, uint8_t arrayLength);

/**
 * @brief Given an array pointer and length of array, returns the minimum value in the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return uint8_t minimum value in array
 */
uint8_t find_min(uint8_t *arrayPtr, uint8_t arrayLength);

/**
 * @brief Given an array pointer and length of array, returns the maximum value in the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return uint8_t maximum value in array
 */
uint8_t find_max(uint8_t *arrayPtr, uint8_t arrayLength);

/**
 * @brief Given an array pointer and length of array, returns the average value of the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return uint8_t average value in array
 */
uint8_t find_mean(uint8_t *arrayPtr, uint8_t arrayLength);

/**
 * @brief Given an array pointer and length of array, returns the median value of the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return uint8_t median value in array
 */
uint8_t find_median(uint8_t *arrayPtr, uint8_t arrayLength);


#endif /* __STATS_H__ */
