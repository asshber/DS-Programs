include irvine32.inc
include macros.inc
.stack 100h
.model small
.data
.code
main proc
mWrite "Enter any Character: "
call ReadChar
call WriteChar
call Crlf
call WriteBin
mWrite "The Binary ASCII Value of the given character is: "
mov ebx,eax
shl eax,24
mov ecx,8
L1:
shl eax,1
mov edx,eax
mov eax,0
adc al,0
call WriteDec
mov eax,edx
loop L1
mov eax,ebx
mov ecx,16
mov ebx,0
L2:
shr al,1
adc ebx,0
loop L2
mov eax,ebx
call Crlf
mWrite "The Number of 1 bits is: "
call WriteDec
exit
main endp
end main
