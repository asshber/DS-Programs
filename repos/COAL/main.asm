TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc
.code
main PROC
mov eax, 44
call DumpRegs
exit
main ENDP
END main