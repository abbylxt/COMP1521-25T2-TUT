main:
main_prologue:
	begin				# open stack frame
	push	$ra			# save the value of $ra onto stack

main_body:
					# sum4(11, 13, 17, 19);
					# load arguments into $a registers to prep for function call
	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19

	jal	sum4			# jump to function and link current location in $ra
					# return value from sum4 is in $v0
	move	$t0, $v0		# result = $t0

	li	$v0, 1			# printf("%d", sum4(11, 13, 17, 19));
	move	$a0, $t0
	syscall
	
	li	$v0, 11			# printf("\n");
	li	$a0, '\n'
	syscall

main_epilogue:
	pop	$ra

	li	$v0, 0			# return 0;
	jr	$ra


sum4:
	# we know that this function was called with the below by convention
	# li	$a0, a
	# li	$a1, b
	# li	$a2, c
	# li	$a3, d
sum4_prologue:
	begin 				# open stack frame
	push	$ra			# save the value of $ra onto stack
	push	$s0			# save the value of $s0 onto stack
	push	$s1			# save the value of $s1 onto stack
	push	$s2			# save the value of $s2 onto stack

sum4_body:
					# int c = $s1, int d = $s2
	move	$s1, $a2		# save the values of $a2, $a3 --> $s1, $s2
	move	$s2, $a3		# this is because we have a function call before we need to use them

					# arguments already in $a0, $a1
	jal	sum2			# sum2(a, b)
	move	$s0, $v0		# int res1 = $s0

	move	$a0, $s1		# set up arguments into $a0, $a1
	move	$a1, $s2
	jal	sum2			# sum2(c, d)
	move	$t1, $v0		# int res2 = $s0

	move	$a0, $s0		# set up arguments into $a0, $a1
	move	$a1, $t1
	jal	sum2			# sum2 (res1, res2)
					# move	$v0, $v0

sum4_epilogue:
	pop	$s2			# save the top element of stack to $s2
	pop	$s1			# save the top element of stack to $s1
	pop	$s0			# save the top element of stack to $s0
	pop	$ra			# save the top element of stack to $ra
	end				# close stack frame

	jr	$ra			# return to return address

sum2:
sum2_prologue:
sum2_body:
	add	$v0, $a0, $a1		# return x + y;

sum2_epilogue:
	jr	$ra

