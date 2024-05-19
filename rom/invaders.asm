00         NOP
00         NOP
00         NOP
C3 D4 18   JMP $18D4
00         NOP
00         NOP
F5         PUSH PSW
C5         PUSH B
D5         PUSH D
E5         PUSH H
C3 8C 00   JMP $008C
00         NOP
F5         PUSH PSW
C5         PUSH B
D5         PUSH D
E5         PUSH H
3E 80      MVI A,#0x80
34 72 20   STA $2072