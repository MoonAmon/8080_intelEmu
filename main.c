#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct ConditionCodes {
    uint8_t Z:1;
    uint8_t S:1;
    uint8_t P:1;
    uint8_t CY:1;
    uint8_t AC:1;
    uint8_t PAD:3;
} ConditionCodes;

typedef struct State8080 {
    uint8_t A;
    uint8_t B;
    uint8_t C;
    uint8_t D;
    uint8_t E;
    uint8_t H;
    uint8_t L;
    uint16_t SP;
    uint16_t PC;
    uint8_t *memory;
    struct ConditionCodes CC;
    uint8_t int_enable;
} State8080;

void UnimplementedInstruction(State8080* state) {
    // PC will have advanced one, so undo that
    printf("Erro: Unimplemendted instruction\n");
    exit(1);
}

int Emulate8080p(State8080* state) {
    unsigned char *opcode = &state->memory[state->PC];

    switch (*opcode) {
        case 0x00:
            // NOP
            break;

        case 0x01:
            // LXI B, data16
            state->C = opcode[1];
            state->B = opcode[2];
            state->PC += 2;
            break;

        case  0x02:
            break;

    }

}


int main(void) {
    printf("Hello, World!\n");
    return 0;
}
