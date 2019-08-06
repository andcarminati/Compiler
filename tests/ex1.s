/*C subset compiler*/
/*x86 assembly output code*/
/*File name assembly.s*/
	.text


/*start of procedure*/
.globl _start
	.type   _start, @function
_start:

	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$48, %esp

	push 	$2
	movl 	(%esp), %edx
	movl 	%edx, -4(%ebp)
	push 	$5
	movl 	(%esp), %edx
	movl 	%edx, -8(%ebp)
	pushl	 $.EVAR0
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl	 $.EVAR1
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl 	-4(%ebp)
	pushl 	-4(%ebp)
	popl 	%edx
	andl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF0

	pushl	 $.EVAR2
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	jmp 	.ENDELSE0
.ENDIF0:
	pushl	 $.EVAR3
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
.ENDELSE0:
	pushl	 $.EVAR4
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl 	-4(%ebp)
	pushl 	-8(%ebp)
	popl 	%edx
	cmpl 	%edx, (%esp)
	setl 	%dl
	movl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF1

	pushl	 $.EVAR5
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	jmp 	.ENDELSE1
.ENDIF1:
	pushl	 $.EVAR6
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
.ENDELSE1:
	pushl	 $.EVAR7
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl 	-4(%ebp)
	pushl 	-8(%ebp)
	popl 	%edx
	cmpl 	%edx, (%esp)
	setg 	%dl
	movl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF2

	pushl	 $.EVAR8
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	jmp 	.ENDELSE2
.ENDIF2:
	pushl	 $.EVAR9
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
.ENDELSE2:
	pushl	 $.EVAR10
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl 	-4(%ebp)
	pushl 	-8(%ebp)
	popl 	%edx
	cmpl 	%edx, (%esp)
	setle 	%dl
	movl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF3

	pushl	 $.EVAR11
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	jmp 	.ENDELSE3
.ENDIF3:
	pushl	 $.EVAR12
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
.ENDELSE3:
	pushl	 $.EVAR13
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl 	-4(%ebp)
	pushl 	-8(%ebp)
	popl 	%edx
	cmpl 	%edx, (%esp)
	setge 	%dl
	movl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF4

	pushl	 $.EVAR14
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	jmp 	.ENDELSE4
.ENDIF4:
	pushl	 $.EVAR15
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
.ENDELSE4:
	pushl	 $.EVAR16
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	push 	$2
	push 	$3
	movl 	(%esp), %edx
	addl 	$4, %esp
	addl 	%edx, (%esp)
	push 	$5
	popl 	%edx
	cmpl 	%edx, (%esp)
	sete 	%dl
	movl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF5

	pushl	 $.EVAR17
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	jmp 	.ENDELSE5
.ENDIF5:
	pushl	 $.EVAR18
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
.ENDELSE5:
	pushl	 $.EVAR19
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	push 	$10
	push 	$5
	movl 	(%esp), %edx
	addl 	$4, %esp
	subl 	%edx, (%esp)
	push 	$5
	popl 	%edx
	cmpl 	%edx, (%esp)
	sete 	%dl
	movl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF6

	pushl	 $.EVAR20
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	jmp 	.ENDELSE6
.ENDIF6:
	pushl	 $.EVAR21
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
.ENDELSE6:
	pushl	 $.EVAR22
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	push 	$2
	push 	$3
	movl 	(%esp), %eax
	addl 	$4, %esp
	imull 	(%esp)
	movl 	%eax, (%esp)
	push 	$6
	popl 	%edx
	cmpl 	%edx, (%esp)
	sete 	%dl
	movl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF7

	pushl	 $.EVAR23
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	jmp 	.ENDELSE7
.ENDIF7:
	pushl	 $.EVAR24
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
.ENDELSE7:
	addl	$48, %esp

.END_start:
	movl 	%eax, %ebx


	movl	$1, %eax
	int	$0x80


/*end of procedure*/
.data

.EVAR0:
	.string "Teste de operadores:\n"
.text
.data

.EVAR1:
	.string "& -> "
.text
.data

.EVAR2:
	.string "Certo\n"
.text
.data

.EVAR3:
	.string "Errado\n"
.text
.data

.EVAR4:
	.string "< -> "
.text
.data

.EVAR5:
	.string "Certo\n"
.text
.data

.EVAR6:
	.string "Errado\n"
.text
.data

.EVAR7:
	.string "> -> "
.text
.data

.EVAR8:
	.string "Errado\n"
.text
.data

.EVAR9:
	.string "Certo\n"
.text
.data

.EVAR10:
	.string "<= -> "
.text
.data

.EVAR11:
	.string "Certo\n"
.text
.data

.EVAR12:
	.string "Errado\n"
.text
.data

.EVAR13:
	.string ">= -> "
.text
.data

.EVAR14:
	.string "Errado\n"
.text
.data

.EVAR15:
	.string "Certo\n"
.text
.data

.EVAR16:
	.string "+ -> "
.text
.data

.EVAR17:
	.string "Certo\n"
.text
.data

.EVAR18:
	.string "Errado\n"
.text
.data

.EVAR19:
	.string "- -> "
.text
.data

.EVAR20:
	.string "Certo\n"
.text
.data

.EVAR21:
	.string "Errado\n"
.text
.data

.EVAR22:
	.string "* -> "
.text
.data

.EVAR23:
	.string "Certo\n"
.text
.data

.EVAR24:
	.string "Errado\n"
.text
//*End of assembly output*/
