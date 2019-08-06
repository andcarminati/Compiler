/*C subset compiler*/
/*x86 assembly output code*/
/*File name assembly.s*/
	.text


/*start of procedure*/
.globl fatorial
	.type   fatorial, @function
fatorial:

	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp

	pushl 	8(%ebp)
	push 	$0
	popl 	%edx
	cmpl 	%edx, (%esp)
	setle 	%dl
	movl 	%edx, (%esp)
	addl 	$4, %esp
	cmpl 	$0, -4(%esp)
	je 	.ENDIF0

	push 	$1
	movl 	(%esp), %eax
	jmp 	.ENDfatorial
	jmp 	.ENDELSE0
.ENDIF0:
	pushl 	8(%ebp)
	pushl	 $.EVAR0
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl 	8(%ebp)
	pushl 	8(%ebp)
	push 	$1
	movl 	(%esp), %edx
	addl 	$4, %esp
	subl 	%edx, (%esp)
//*calling function*/
	call 	fatorial
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	movl 	(%esp), %eax
	addl 	$4, %esp
	imull 	(%esp)
	movl 	%eax, (%esp)
	movl 	(%esp), %eax
	jmp 	.ENDfatorial
.ENDELSE0:

.ENDfatorial:
	leave
	ret
/*end of procedure*/


/*start of procedure*/
.globl _start
	.type   _start, @function
_start:

	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$44, %esp

	push 	$5
//*calling function*/
	call 	fatorial
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	movl 	(%esp), %edx
	movl 	%edx, -4(%ebp)
	pushl 	-4(%ebp)
	pushl	 $.EVAR1
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	addl	$44, %esp

.END_start:
	movl 	%eax, %ebx


	movl	$1, %eax
	int	$0x80


/*end of procedure*/
.data

.EVAR0:
	.string "%d\n"
.text
.data

.EVAR1:
	.string "Fatorial de 5 => %d\n"
.text
//*End of assembly output*/
