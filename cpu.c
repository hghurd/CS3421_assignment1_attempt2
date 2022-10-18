//
// Created by hghurd on 23/09/22.
//

#include <stdbool.h>
#include "cpu.h"
#include "memory.h"

static void reset();
static void setReg(char* reg, unsigned char byte);
static void dump();

struct CPU {
    unsigned char regs[8];
    unsigned char PC;
};

struct CPU cpu;
unsigned char fetchByte;
bool fetchDone;

static void reset() {
    for (int i = 0; i < 8; i++) {
        cpu.regs[i] = 0;
    }
}

static void setReg(char *reg, unsigned char byte) {
    int index = (int) (reg[1] - 'A');
    cpu.regs[index] = byte;
}

static void dump() {
    //print out all the information in the registers and PC
    printf("PC: %02X\n", cpu.PC);
    for (int i = 0; i < 8; i++) {
        printf("R%C: %02X\n\n", ((char) i + 'A'), cpu.regs[i]);
    }
}

void cpuDoCycleWork() {
    //Shift everything in registers one register down
    for (int i = 1; i < 8; i++) {
        cpu.regs[i] = cpu.regs[i - 1];
    }
    //Set RA to 0
    cpu.regs[0] = 0;

    //Does this go here???
    memStartFetch(cpu.PC, 1, &fetchByte, &fetchDone);

    //increment program counter
    cpu.PC++;
}

int main() {

    return 0;
}