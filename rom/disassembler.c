#include <stdio.h>
#include <stdlib.h>

int Disassemble8080Op(unsigned char *codebuffer, int PC) {
    unsigned char *code = &codebuffer[PC];
    int opbyte = 1;
    printf("%04x ", PC);
    switch (*code) {
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI      B,#$%02x%02x", code[2], code[1]); opbyte = 3; break;
        case 0x02: printf("STX      B"); break;
        case 0x03: printf("INX      B"); break;
        case 0x04: printf("INR      B"); break;
        case 0x05: printf("DCR      B"); break;
        case 0x06: printf("MVI      B,#$%02x", code[1]); opbyte = 2; break;
        case 0x07: printf("RLC      B"); break;
        case 0x09: printf("DAD      B"); break;
        case 0x0A: printf("LDAX     B"); break;
        case 0x0B: printf("DCX      B"); break;
        case 0x0C: printf("INR      C"); break;
        case 0x0D: printf("DCX      C"); break;
        case 0x0E: printf("MVI      C,#$%02x", code[1]); opbyte = 2; break;
        case 0x0F: printf("RRC"); break;
        case 0x11: printf("LXI      D,#$%02x%02x", code[2], code[1]); opbyte = 3; break;
        case 0x12: printf("STAX     D"); break;
        case 0x13: printf("INX      D"); break;
        case 0x14: printf("INR      D"); break;
        case 0x15: printf("DCR      D"); break;
        case 0x16: printf("MVI      D,#$%02x", code[1]); opbyte = 2; break;
        case 0x17: printf("RAL"); break;
        case 0x19: printf("DAD      D"); break;
        case 0x1A: printf("LDAX     D"); break;
        case 0x1B: printf("DCX      D"); break;
        case 0x1C: printf("INR      E"); break;
        case 0x1D: printf("DCR      E"); break;
        case 0x1E: printf("MVI      E,#$%02x", code[1]); opbyte = 2; break;
        case 0x1F: printf("RAR"); break;
        case 0x21: printf("LXI      H,#$%02x%02x", code[2], code[1]); opbyte = 3; break;
        case 0x22: printf("SHLD     H,#$%02x%02x", code[2], code[1]); opbyte = 3; break;
        case 0x23: printf("INX      H"); break;
        case 0x24: printf("INR      H"); break;
        case 0x25: printf("DCR      H"); break;
        case 0x26: printf("MVI      H,#$%02x", code[1]); opbyte = 2; break;
        case 0x27: printf("DAA"); break;
        case 0x29: printf("DAD      H"); break;
    }

    printf("\n");
    return opbyte;
}

int main(int argc, char**argv) {
    FILE *ROM= fopen(argv[1], "rb");
    if (ROM == NULL) {
        printf("error: Couldn't open %s\n", argv[1]);
        exit(1);
    }

    // Get the file size and read it into a memory buffer
    fseek(ROM, 0L, SEEK_END);
    const int file_size = ftell(ROM);
    fseek(ROM, 0L, SEEK_SET);

    unsigned char *buffer = malloc(file_size);

    fread(buffer, file_size, 1, ROM);
    fclose(ROM);

    int PC = 0;

    while (PC < file_size) {
        PC += Disassemble8080Op(buffer, PC);
    }

    return 0;
}