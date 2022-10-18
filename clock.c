//
// Created by hghurd on 23/09/22.
//

#include "clock.h"
#include "cpu.h"
#include "memory.h"

static void reset(int currentTick);
static void tick(int currentTick, int tick);
static void dump(int currentTick);

static void reset(int currentTick) {
    currentTick = 0;
}

static void tick(int currentTick, int tick) {
    for (int i = currentTick; i < currentTick + tick; i++) {
        cpuDoCycleWork();
    }
}

static void dump(int currentTick) {
    //Print info to standard output
    printf("Clock: %d\n\n", currentTick);
}
