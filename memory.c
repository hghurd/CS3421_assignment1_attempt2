//
// Created by hghurd on 23/09/22.
//

#include <string.h>
#include "memory.h"

static void create(unsigned char *dataPtr, int size);
static void reset(unsigned char *dataPtr, int size);
static void dump(unsigned int address, unsigned int count, unsigned char *dataPtr);
static void set(unsigned int address, unsigned int count, unsigned char *dataPtr, unsigned char input[count]);

static void create(unsigned char *dataPtr, int size) {
    dataPtr = malloc(sizeof (unsigned char) * size);
}

static void reset(unsigned char *dataPtr, int size) {
    memset(dataPtr, 0, size);
}

static void dump(unsigned int address, unsigned int count, unsigned char *dataPtr) {
    //Print out the top row of memDump
    printf("Addr ");
    for(int i = 0x0; i < 0x10; i++) {
        printf("%02X", i);
    }
    printf("\n");
    //Figure out a correct condition for the while-loop
    unsigned int temp = address;
    unsigned int i = 0;
    unsigned int mSigBit = address & 0xF0;
    while(temp < count){
        if (i == 0) {
            //print the y-axis label
            printf("0x%02X ", mSigBit);
            //increment by 0x10 for the next row
            mSigBit += 0x10;
        }
        //check if we're printing a value in dataPtr, or if we still need to print spaces
        //if we're still printing spaces, DO NOT increment temp
        //else print the data and a space
        //if data was printed, increment temp
        printf("%02X ", address & 0x0F);
        if (i == 15) {
            printf("\n");
        }
    }

}

static void set(unsigned int address, unsigned int count, unsigned char *dataPtr, unsigned char *input) {
    memcpy(dataPtr + address, input, count);
}

void memStartFetch(unsigned int address, unsigned int count, unsigned char *dataPtr, bool *memDonePtr){

}

int main() {

    return 0;
}