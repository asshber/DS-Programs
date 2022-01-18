INCLUDE Irvine32.inc
.data
arrayb BYTE "*"
val1 DWORD 2
val2 WORD 05h
.code
main PROC
call ReadInt
mov esi,eax
mov eax,0
mov al,arrayb
mov edx,0
mov dx,05h
call Gotoxy
call writechar
call crlf
mov ecx,esi
l1:
add val2,0FFh
mov dx,val2
call Gotoxy
mov ebx,ecx
mov ecx,val1
l2:
call writechar
loop l2
inc val1
mov ecx,ebx
call crlf
loop l1

exit
main ENDP
END main