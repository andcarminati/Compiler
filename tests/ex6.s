/*C subset compiler*/
/*x86 assembly output code*/
/*File name assembly.s*/
	.text
.globl var
	.data
	.align 4
var:
	.long 0
	.text


/*start of procedure*/
.globl _start
	.type   _start, @function
_start:

	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$40, %esp

	push 	$25
//*= operation (var = exp)*/
	pushl 	$var
	popl 	%edx
	movl 	(%esp), %ebx
	movl 	%ebx, (%edx)
	addl 	$4, %esp
	pushl 	var
	pushl	 $.EVAR0
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	addl	$40, %esp

.END_start:
	movl 	%eax, %ebx


	movl	$1, %eax
	int	$0x80


/*end of procedure*/
.data

.EVAR0:
	.string "teste %d\n"
.text
//*End of assembly output*/
