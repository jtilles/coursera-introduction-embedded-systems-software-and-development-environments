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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves data from source pointer to destination pointer
 * 
 * This function takes two byte pointers (one source and one destination) 
 * and a length of bytes to move from the source location to the
 * destination.
 * 
 * @param src Source Pointer, where the data currently resides
 * @param dst Destination Pointer, where the data should reside
 * @param length Length of data
 * @return uint8_t* returns pointer to the destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copys data from source pointer to destination pointer
 * 
 * This function takes two byte pointers (one source and one destination) 
 * and a length of bytes to copy from the source location to the
 * destination.
 * 
 * @param src Source Pointer, where the data currently resides
 * @param dst Destination Pointer, where the data should reside
 * @param length Length of data
 * @return uint8_t* returns pointer to the destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets memory in SRC pointer to VALUE
 * 
 * @param src Source Pointer, the data that should be changed
 * @param length Length of Data
 * @param value Value to set data to
 * @return uint8_t* source pointer
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets memory in SRC pointer to zero
 * 
 * This should take a pointer to a memory location, a length in bytes
 * and zero out all of the memory.
 * 
 * @param src Source Pointer, the data that should be set to 0
 * @param length Length of Data
 * @return uint8_t* source pointer
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief 
 * 
 * This should take a pointer to a memory location and a length in bytes
 * and reverse the order of all of the bytes.
 * 
 * @param src Pointer to memory location of bytes to reverse
 * @param length Length of Data
 * @return uint8_t* source pointer
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief This should take number of words to allocate in dynamic memory
 * 
 * @param length Length of Data
 * @return int32_t* A pointer to memory if successful, or a Null Pointer
 *                  if not successful
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free dynamic memory allocation pointed to by src
 * 
 * @param src Pointer to memory to free
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
