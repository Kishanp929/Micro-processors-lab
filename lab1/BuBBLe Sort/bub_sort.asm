ORG 0H
LJMP MAIN
ORG 100H
MAIN:
ACALL SORT
HERE: SJMP HERE
ORG 130H
// *****************
SORT:
MOV R2 , #08
MOV R0 , #70H
MOV R1 , #60H
kishan :

MOV A, @R1
MOV @R0,A
INC R0
INC R1
DJNZ R2 , kishan 
MOV A, @R1
MOV @R0,A

MOV R0 , #70H
MOV R1 , #71H
MOV R3 , #07H
MOV R4 , #07H



Here3 :
Here2 :

MOV A , @R0
MOV B , @R1
SUBB A , B
JC LOL 

MOV A, @R1
MOV B,@R0
MOV @R0,A
MOV @R1,B

INC R0
INC R1
JNC kis 
LOL :
INC R0
INC R1
kis:
DJNZ R3 , Here2
 
MOV R0 , #70H
MOV R1 , #71H
MOV R3 , #07H
DJNZ R4 , Here3




RET
END