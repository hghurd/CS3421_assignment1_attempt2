//
// Created by hghurd on 23/09/22.
//

#include "memory.h"

static void create(int size);
static void reset();
static void dump(int *address, int count);
static void set(int *address, int count, int input[count]);

unsigned char* memory = NULL;

static void create(int size) {
    memory = malloc(sizeof (unsigned char) * size);
}

static void reset() {

}

static void dump(int *address, int count) {

}

static void set(int *address, int count, int input[count]) {

}

void memDoCycleWork(){

}

int main() {

    return 0;
}