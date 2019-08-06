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
	subl	$128, %esp

push 	$3
	movl 	(%esp), %edx
	movl 	%edx, -88(%ebp)
	push 	$77
//*array index*/
	pushl 	-88(%ebp)
//*= operation (var[] = exp)*/
	push 	$4
//*= operation (var[] = exp) ------*/
	movl 	(%esp), %eax
	addl 	$4, %esp
	imull 	(%esp)
	movl 	%eax, (%esp)
//*load var position*/
//*pushing var reference*/
	pushl 	%ebp
	addl 	$-4, (%esp)
	movl 	(%esp), %edx
	addl 	$4, %esp
	addl 	%edx, (%esp)
//*load pointer*/
	popl 	%edx
	movl 	(%esp), %ebx
	movl 	%ebx, (%edx)
	addl 	$4, %esp
	push 	$88
//*array index*/
	pushl 	-88(%ebp)
	push 	$3
	movl 	(%esp), %edx
	addl 	$4, %esp
	addl 	%edx, (%esp)
//*= operation (var[] = exp)*/
	push 	$4
//*= operation (var[] = exp) ------*/
	movl 	(%esp), %eax
	addl 	$4, %esp
	imull 	(%esp)
	movl 	%eax, (%esp)
//*load var position*/
//*pushing var reference*/
	pushl 	%ebp
	addl 	$-4, (%esp)
	movl 	(%esp), %edx
	addl 	$4, %esp
	addl 	%edx, (%esp)
//*load pointer*/
	popl 	%edx
	movl 	(%esp), %ebx
	movl 	%ebx, (%edx)
	addl 	$4, %esp
	pushl 	-88(%ebp)
	push 	$3
	movl 	(%esp), %edx
	addl 	$4, %esp
	addl 	%edx, (%esp)
	push 	$4
	movl 	(%esp), %eax
	addl 	$4, %esp
	imull 	(%esp)
	movl 	%eax, (%esp)
//*pushing var reference*/
	pushl 	%ebp
	addl 	$-4, (%esp)
	movl 	(%esp), %edx
	addl 	$4, %esp
	addl 	%edx, (%esp)
	popl 	%edx
	pushl 	(%edx)
	pushl 	-88(%ebp)
	push 	$4
	movl 	(%esp), %eax
	addl 	$4, %esp
	imull 	(%esp)
	movl 	%eax, (%esp)
//*pushing var reference*/
	pushl 	%ebp
	addl 	$-4, (%esp)
	movl 	(%esp), %edx
	addl 	$4, %esp
	addl 	%edx, (%esp)
	popl 	%edx
	pushl 	(%edx)
	pushl	 $.EVAR0
//*calling function*/
	call 	printf
	addl 	$4, %esp
//*push the return of function (is in eax) on stack*/
	pushl 	%eax
	addl 	$4, %esp
	addl	$128, %esp

.END_start:
	movl 	%eax, %ebx


	movl	$1, %eax
	int	$0x80


/*end of procedure*/
.data

.EVAR0:
	.string "Teste de variavel array i[i1] = %d, i[i1+3] = %d\n"
.text
//*End of assembly output*/
