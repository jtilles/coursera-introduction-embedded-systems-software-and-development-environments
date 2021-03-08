/******************************************************************************
 * Copyright (C) 2021 by Josh Illes
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain the copyright found in 
 * the LICENSE file.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 *
 ******************************************************************************
 *
 * @file data.c
 * @brief File contains functions that perform ASCII-to-INT and INT-to-ASCII
 *
 * @author Josh Illes
 * @date Thu Mar 04 2021
 *
 *****************************************************************************/


#include <stdio.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    /* Since the min/max value of data is ±2147483648, we need a max array size of
     * 12, 1 for sign, 10 for digits, 1 for null terminator */
    uint8_t arraySize = 12;
    uint8_t tempArray[arraySize];
    uint8_t isNegativeFlag = 0;
    uint8_t strLength = 0;

    // Case where number is zero;
    if (data == 0){
        *ptr='0';
        *(ptr+1)=0;
        return 2;
    }

    // case of a negative number
    if (data<0){
        data = data*-1;
        isNegativeFlag = 1;
    }
    // Null character
    tempArray[strLength] = 0x0;
    strLength++;

    // Peel off each character
    while (data >= 1){
        uint8_t myChar = data%base;
        // printf("data%%base: %d\n", myChar);
        
        // If char is 0-9
        if(myChar>=0 && myChar<=9){
            tempArray[strLength] = myChar + 0x30;
        }

        // If char is A-F
        if(myChar>=10 && myChar<=15){
            tempArray[strLength] = myChar + 0x37;
        }

        data = data/base;
        strLength++;
    }

    // Add negative sign if negative number
    if(isNegativeFlag){
        tempArray[strLength] = '-';
        strLength++;
    }

    // Since string number is assembled in reverse, flip it for the string.
    for(uint8_t i=0 ; i<strLength; i++){
        *(ptr+i)=tempArray[strLength-1-i];
    }


    return strLength;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    uint8_t isNegativeFlag = 0;
    uint32_t myNumber=0;
    uint8_t *charPtr = ptr;

    if(*charPtr == '-'){
        isNegativeFlag = 1;
        digits--;
        charPtr++;
    }

    // While not Null Character, add values
    uint8_t i = 0;
    do {
        uint32_t multiplier = pow(base,(digits-2-i));
        uint8_t digit = *(charPtr+i);
        if(digit<='F' && digit>='A'){
            digit-=0x37;
        }
        else if(digit<='9' && digit>='0'){
            digit-=0x30;
        }
        // printf("Adding %d to myNumber\n", multiplier*digit);
        myNumber+= multiplier*digit;
        i++;
    } while(*(charPtr+i-1) != 0);

    if(isNegativeFlag){
        myNumber*=-1;
    }
    
    return myNumber;
}