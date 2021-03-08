# Final Assesment

## Goals
1. Incorporate a c-program application into your Make and GCC build system
1. Write c-program functions that manipulate memory
1. Execute and test your application by simulating it on the host machine


## Use
### Normal
Invoke make to build and run all files with:
```
make run
```
### COURSE1
To run the unit test specified in `course1.c` you can define the make variable `COURSE1` as true:
```
make run COURSE1=true
```
### VERBOSE
To run the unit test specified in `course1.c` with extra debugging information you can define the make variable `VERBOSE` as true:
``` 
make run VERBOSE=true COURSE1=true
```
### Clean
To make *clean* or *clobber* (delete all generated files), issue the following command:
```
make clean
```


## Roadmap
### Previous Files

- [x] Copy and paste source files and functions from Week1 & Week2
- [x] Compile time switch for main function.  

    *Your main function will be very simple. You will just need to call a function that is defined in the course1.c source file. However, you need to use a compile time switch to wrap this function to call. This way we can have a simple main() function that can switch which course deliverable we wish to call by specifying the -DCOURSE1 compile time switch.*

```c
    #ifdef COURSE1
    course1();
    #endif
```

- [x] Modify `print_array()` function so you can enable/disable print with a compile time switch.  Compile time switch should be enabled with **VERBOSE** flag  (`-DVERBOSE`).
- [x] Modify *printf* to use the **PRINTF** macro defined in `platform.h`

---
### Memory Functions
- [x] Memory Move Function:
    ```
    uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);
    ```

    1. This function takes two byte pointers (one source and one destination) and a length of bytes to move from the source location to the destination.
    2. The behavior should handle overlap of source and destination. Copy should occur, with no data corruption.
    3. All operations need to be performed using pointer arithmetic, not array indexing
    4. Should return a pointer to the destination (dst).

- [x] Memory Copy Function:
    ```
    uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);
    ```

    1. This function takes two byte pointers (one source and one destination) and a length of bytes to copy from the source location to the destination.
    2. The behavior is undefined if there is overlap of source and destination. Copy should still occur, but will likely corrupt your data.
    3. All operations need to be performed using pointer arithmetic, not array indexing
    4. Should return a pointer to the destination (dst).

- [x] Memory Set Function:
    ```
    uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);
    ```
    1. This should take a pointer to a source memory location, a length in bytes and set all locations of that memory to a given value.
    2. All operations need to be performed using pointer arithmetic, not array indexing
    3. Should return a pointer to the source (src).
    4. You should NOT reuse the set_all() function

- [x] Memory Zero Function:
    ```
    uint8_t * my_memzero(uint8_t * src, size_t length);
    ```
    1. This should take a pointer to a memory location, a length in bytes and zero out all of the memory.
    2. All operations need to be performed using pointer arithmetic, not array indexing
    3. Should return a pointer to the source (src).
    4. You should NOT reuse the clear_all() function

- [x] Reverse order of bytes Function:
    ```
    uint8_t * my_reverse(uint8_t * src, size_t length);
    ```
    1. This should take a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.
    2. All operations need to be performed using pointer arithmetic, not array indexing
    3. Should return a pointer to the source.

- [x] Reserve Word in Memory Function:
    ```
    int32_t * reserve_words(size_t length);
    ```
    1. This should take number of words to allocate in dynamic memory
    2. All operations need to be performed using pointer arithmetic, not array indexing
    3. Should return a pointer to memory if successful, or a Null Pointer if not successful

- [x] Free Words Function
    ```
    void free_words(int32_t * src);
    ```
    1. Should free a dynamic memory allocation by providing the pointer src to the function
    2. All operations need to be performed using pointer arithmetic, not array indexing

---
### data.c/data.h Requirements

- [x] Integer to ASCII function:
    ```
    uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
    ```
  1. Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
  2. All operations need to be performed using pointer arithmetic, not array indexing
  3. The number you wish to convert is passed in as a signed 32-bit integer.
  4. You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).
  5. Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
  6. The signed 32-bit number will have a maximum string size (Hint: Think base 2).
  7. You must place a null terminator at the end of the converted c-string
  8. Function should return the length of the converted data (including a negative sign). Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
  9. This function needs to handle signed data.
  10. You may not use any string functions or libraries

- [x] ASCII to Integer function:
    ```
    int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
    ```
  1. ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.
   1. All operations need to be performed using pointer arithmetic, not array indexing
   2. The character string to convert is passed in as a uint8_t * pointer (ptr).
   3. The number of digits in your character set is passed in as a uint8_t integer (digits).
   4. You should be able to support bases 2 to 16.
   5. The converted 32-bit signed integer should be returned.
   6. This function needs to handle signed data.
   7. You may not use any string functions or libraries
