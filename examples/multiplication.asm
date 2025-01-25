; Calculates x * y
; https://theshamblog.com/programs-and-more-commands-for-the-ben-eater-8-bit-breadboard-computer/

LDA 14
SUB 12
JC 6
LDA 13
OUT
HLT
STA 14
LDA 13
ADD 15
STA 13
JMP 0
NOP
$1
; Product
NOP
; x
$2
; y
$2
