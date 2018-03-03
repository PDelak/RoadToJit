.386
.model flat
.code

public _foo
public _testParam
public _testParams
public _callFunction
public _passStruct

_foo PROC
	mov eax, 12
	ret
_foo ENDP

_testParam PROC
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8]
	mov esp, ebp
	pop ebp
	ret
_testParam ENDP

_testParams PROC
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8]
	add eax, [ebp + 12]
	mov esp, ebp
	pop ebp
	ret
_testParams ENDP


_callFunction PROC
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8]
	call eax
	xor eax, eax
	mov esp, ebp
	pop ebp
	ret
_callFunction ENDP

_passStruct PROC
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8]
	mov [eax], dword ptr 22
	add eax, 4
	mov [eax], dword ptr 23
	mov esp, ebp
	pop ebp
	ret
_passStruct ENDP


end