.386
DATA SEGMENT USE16
    MESG DB 'hello world','$'
DATA ENDS

CODE SEGMENT USE16                  ;
          ASSUME CS:CODE,DS:DATA    ;
    start:
          MOV    AX,DATA            ;
          MOV    DS,AX              ;
          LEA    DX,MESG            ;
          MOV    AH,09H             ;
          INT    21h                ;
CODE ENDS

END start;