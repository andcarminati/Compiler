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
	subl	$45, %esp

	push 	$0
	movl 	(%esp), %edx
	movl 	%edx, -4(%ebp)
	push 	$97
	movb 	(%esp), %dl
	movb 	%dl, -8(%ebp)
	pushl	 $.EVAR0
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl 	-4(%ebp)
//*pushing var reference*/
	pushl 	%ebp
	addl 	$-4, (%esp)
	pushl	 $.EVAR1
//*calling function*/
	call 	scanf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	pushl 	-8(%ebp)
	pushl 	-4(%ebp)
	pushl	 $.EVAR2
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	addl	$45, %esp

.END_start:
	movl 	%eax, %ebx


	movl	$1, %eax
	int	$0x80


/*end of procedure*/
.data

.EVAR0:
	.string "Digite um numero: \n"
.text
.data

.EVAR1:
	.string "%d"
.text
.data

.EVAR2:
	.string "numero: %d %c\n"
.text
//*End of assembly output*/
