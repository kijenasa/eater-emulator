; https://theshamblog.com/programs-and-more-commands-for-the-ben-eater-8-bit-breadboard-computer/
LDI 1
STA 14
LDI 0
STA 15
OUT
LDA 14
ADD 15
STA 14
OUT
LDA 15
ADD 14
JC 13
JMP 3
HLT
