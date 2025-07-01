


main:
	la	$t1, d		# print one byte across from d:
	lb	$t0, 1($t1)
	li	$v0, 1
	move	$a0, $t0
	syscall

	li	$v0, 0		# return;
	jr	$ra


    .data
a:	.space 4
b:	.word 42
c:	.space 1
d:	.byte 'a'
e:	.space 8
f:	.space 4 * 20