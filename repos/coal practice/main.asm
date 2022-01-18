TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc
.data
array byte "abcd"
dest byte 4 DUP(0)
.code
main PROC
mov eax,0h
neg eax
call dumpregs
exit
main ENDP
END main