.486
.model flat, stdcall
option casemap :none

	include    \masm32\include\msvcrt.inc
	includelib \masm32\lib\msvcrt.lib
.data
	typchar db '%c', 0
	typnum db '%d', 0
	output dd 0
	_pi dd 0
	_näù‘ dd 0
	_c dd 0
	_i dd 0
	_j dd 0
	_r dd 0
	_x dd 0
	_y dd 0
.code
_start:
	push 0
	pop _pi
	push 97
	pop _c
	push 1
	push 2
	pop ecx
	pop eax
	add eax, ecx
	push eax
	push 3
	push 4
	pop ecx
	pop eax
	imul eax, ecx
	push eax
	push 5
	pop ecx
	pop eax
	cdq
	xor edx, edx
	idiv ecx
	push eax
	push 6
	pop ecx
	pop eax
	cdq
	xor edx, edx
	idiv ecx
	push edx
	pop ecx
	pop eax
	sub eax, ecx
	push eax
	push 7
	pop ecx
	pop eax
	and eax, ecx
	push eax
	push 8
	push 9
	push 1
	pop ebx
	pop eax
	mov cl, bl
	sar eax, cl
	push eax
	pop ecx
	pop eax
	xor eax, ecx
	push eax
	pop ecx
	pop eax
	or eax, ecx
	push eax
	pop output
	invoke crt_printf, addr typnum, output
	push 0
	pop _i
@0:
	push _i
	push 10
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jge @2
	inc edx
@2:
	push edx
	pop eax
	cmp eax, 0
	je @1
	push _c
	pop eax
	push eax
	inc eax
	push eax
	pop _c
	push 97
	pop ecx
	pop eax
	sub eax, ecx
	push eax
	pop output
	invoke crt_printf, addr typnum, output
	push _i
	push 1
	pop ecx
	pop eax
	add eax, ecx
	push eax
	pop _i
	jmp @0
@1:
@3:
	push _nR˜˜
	push 0
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jl @5
	inc edx
@5:
	push edx
	pop eax
	cmp eax, 0
	je @4
	push _nR˜˜
	push 10
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jl @6
	inc edx
@6:
	push edx
	push _n
	push 100
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jge @7
	inc edx
@7:
	push edx
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, 0
	je @8
	cmp ecx, 0
	je @8
	inc edx
@8:
	push edx
	pop eax
	cmp eax, 0
	je @9
	push 1
	pop output
	invoke crt_printf, addr typnum, output
	jmp @10
@9:
	push _n
	push 0
	push 1
	pop ecx
	pop eax
	sub eax, ecx
	push eax
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jg @11
	inc edx
@11:
	push edx
	push _n
	push 4
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jle @12
	inc edx
@12:
	push edx
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, 0
	jne @13
	cmp ecx, 0
	jne @13
	jmp @14
@13:
	inc edx
@14:
	push edx
	pop eax
	cmp eax, 0
	je @15
	push 0
	pop _r
	jmp @16
@15:
	push 1
	pop _r
@17:
	push _n
	push 0
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jle @19
	inc edx
@19:
	push edx
	pop eax
	cmp eax, 0
	je @18
	push _r
	push 3
	pop ebx
	pop eax
	mov cl, bl
	sal eax, cl
	push eax
	push _r
	push 1
	pop ebx
	pop eax
	mov cl, bl
	sal eax, cl
	push eax
	pop ecx
	pop eax
	add eax, ecx
	push eax
	pop _r
	push _n
	pop eax
	push eax
	dec eax
	push eax
	pop _n
	jmp @17
@18:
@16:
@10:
	push 0
	pop _pi
	push 0
	push _r
	pop ecx
	pop eax
	sub eax, ecx
	push eax
	pop _i
@20:
	push _i
	push _r
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jge @22
	inc edx
@22:
	push edx
	pop eax
	cmp eax, 0
	je @21
	push 0
	push _r
	pop ecx
	pop eax
	sub eax, ecx
	push eax
	pop _j
@23:
	push _j
	push _r
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jge @25
	inc edx
@25:
	push edx
	pop eax
	cmp eax, 0
	je @24
	push _i
	push 2
	pop ecx
	pop eax
	imul eax, ecx
	push eax
	push 1
	pop ecx
	pop eax
	add eax, ecx
	push eax
	pop _x
	push _j
	push 2
	pop ecx
	pop eax
	imul eax, ecx
	push eax
	push 1
	pop ecx
	pop eax
	add eax, ecx
	push eax
	pop _y
	push _x
	push _x
	pop ecx
	pop eax
	imul eax, ecx
	push eax
	push _y
	push _y
	pop ecx
	pop eax
	imul eax, ecx
	push eax
	pop ecx
	pop eax
	add eax, ecx
	push eax
	push 4
	push _r
	pop ecx
	pop eax
	imul eax, ecx
	push eax
	push _r
	pop ecx
	pop eax
	imul eax, ecx
	push eax
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jge @26
	inc edx
@26:
	push edx
	pop eax
	cmp eax, 0
	je @27
	push _pi
	push 1
	pop ecx
	pop eax
	add eax, ecx
	push eax
	pop _pi
@27:
	push _j
	push 1
	pop ecx
	pop eax
	add eax, ecx
	push eax
	pop _j
	jmp @23
@24:
	push _i
	push 1
	pop ecx
	pop eax
	add eax, ecx
	push eax
	pop _i
	jmp @20
@21:
	push _r
	push 1
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jl @28
	inc edx
@28:
	push edx
	pop eax
	cmp eax, 0
	je @29
	push _r
	push 2
	pop ecx
	pop eax
	xor edx, edx
	cmp eax, ecx
	jl @30
	inc edx
@30:
	push edx
	pop eax
	cmp eax, 0
	je @31
	push _pi
	push _r
	pop ecx
	pop eax
	cdq
	xor edx, edx
	idiv ecx
	push eax
	pop output
	invoke crt_printf, addr typnum, output
	jmp @32
@31:
	push 3
	pop output
	invoke crt_printf, addr typnum, output
@32:
@29:
	jmp @3
@4:
	invoke crt__exit, 0
end _start
