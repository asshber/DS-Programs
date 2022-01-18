TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc
.code
main PROC
mov eax, 50h
mov ebx, 25h
call DumpRegs
exit
main ENDP
END main