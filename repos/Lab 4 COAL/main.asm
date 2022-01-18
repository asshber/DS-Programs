TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc
.data 
val1 SDWORD 8000d
.code
main PROC
mov eax,val1
add eax,1d
call DumpRegs
exit
main ENDP
END main