//
// Created by hghurd on 23/09/22.
//

#include "cpu.h"

struct CPU {
    unsigned char regs[8];
    unsigned char PC;
};

struct CPU cpu;

static void reset();
static void setReg(char* reg, unsigned char byte);
static void dump();

static void reset() {
    for (int i = 0; i < 8; i++) {
        cpu.regs[i] = 0;
    }
}

static void setReg(char* reg, unsigned char byte) {
    int index = (int) ('A' - reg[1]);
    cpu.regs[index] = byte;
}

static void dump() {
    //print out all the information in the registers and PC
    printf("PC: %02X\n", cpu.PC);
    for (int i = 0; i < 8; i++) {
        printf("R%C: %02X\n", ((char) i + 'A'), cpu.regs[i]);
    }
}

void cpuDoCycleWork() {
    //Shift everything in registers one register down
    for (int i = 8; i > 0; i--) {
        cpu.regs[i] = cpu.regs[i - 1];
    }
    //increment program counter
    cpu.PC++;
}

int main() {

    return 0;
}