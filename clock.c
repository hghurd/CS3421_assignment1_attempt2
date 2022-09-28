//
// Created by hghurd on 23/09/22.
//

#include "clock.h"
#include "cpu.h"
#include "memory.h"

static void reset();
static void tick(int tick);
static void dump();

static int currentTick;

static void reset() {
    currentTick = 0;
}

static void tick(int tick) {
    for (int i = currentTick; i < currentTick + tick; i++) {
        cpuDoCycleWork();
        memoryDoCycleWork();
    }
}

static void dump() {
    //Print info to a file
}

int main() {

    return 0;
}