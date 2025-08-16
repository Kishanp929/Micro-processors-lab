ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL DET
HERE: SJMP HERE
ORG 130H
// *****************
DET:
MOV A , 60H
MOV B , 63H
MUL AB
MOV R0 , B
MOV R1 , A

MOV A , 61H
MOV B , 62H

MUL AB

MOV R2 , B
MOV R3 , A

MOV A , R1
MOV B , R3

SUBB A , B

MOV R1 , A

MOV A  , R0
MOV B , R2
SUBB A , B

MOV R0 , A

MOV 70H , R0
MOV 71H , R1

RET
END