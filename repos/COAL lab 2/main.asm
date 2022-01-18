TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc
.code
main PROC
mov eax,10d
mov esi,05ADh
sub esi,eax
add esi,65o
add esi,65d
sub esi,11110111b
add esi,150d
mov eax,esi
call DumpRegs
exit
main ENDP
END main