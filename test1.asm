.8086
data segment
tt db 01000110b
data ends

code segment

main proc far
assume cs:code,ds:data
mov ax,data
mov ds,ax
mov al ,tt
mov cl,4
rol al,cl
and al,0fh
add al,30h
cmp al,3ah
call display
add al,7h
call display
mov al,tt
and al,0fh
add al,30h
cmp al,3ah
call display
add al,7h
;call display
display proc near
mov dl,al
mov ah,2
int 21h
ret
display endp
main endp
code ends