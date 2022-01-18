TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc
.data
val1 DWORD ?
char1 BYTE "Value in Hex: ",0
char2 BYTE "Value in Dec: ",0
char3 BYTE "Value in Binary: ",0
.code
main PROC
call ReadDEC
mov edx,OFFSET char1
call WriteString
call Writehex
call DumpRegs
mov edx,OFFSET char2
call WriteString
call WriteDec
call DumpRegs
mov edx,OFFSET char3
call WriteString
call WriteBin
call DumpRegs
exit
main ENDP
END main