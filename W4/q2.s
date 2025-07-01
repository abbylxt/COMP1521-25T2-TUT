# int flag[4][3] = flag
# max_rows = 4
# max_col = 3
# &flag[0][0] = &flag
# &flag[0][2] = &flag + 2
# &flag[1][0] = &flag + 3
# &flag[1][2] = &flag + 3 + 2
# &flag[2][2] = &flag + 3 + 3 + 2 = &flag + 2 * 3 + 2
# &flag[row][col] = &flag + (max_col * row + col) * size_of_elements

.data
flag:	
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

.text
# CONSTANTS
FLAG_ROWS = 6
FLAG_COLS = 12
SIZE_OF_FLAG = 1

main:
main_prologue:
	# set up your function
	# everything you push
main_body:
	# $t0 = row, $t1 = col
main_loop_rows_init:
	li	$t0, 0		# int row = 0;

main_loop_rows_cond:
	bge	$t0, FLAG_ROWS, main_loop_rows_end 

main_loop_cols_init:
	li	$t1, 0		# int col = 0;

main_loop_cols:
	bge	$t1, FLAG_COLS, main_loop_cols_end

	# &flag[row][col] = &flag + (max_col * row + col) * size_of_elements
	mul	$t3, FLAG_COLS, $t0
	add	$t3, $t3, $t1
	mul	$t3, $t3, SIZE_OF_FLAG
	# la	$t2, flag
	# add	$t2, $t2, $t3
	# lb	$a0, ($t2)
	lb	$a0, flag($t3)

	# printf("%c", flag[row][col]);
	li	$v0, 11
	syscall

	addi	$t1, 1
	b	main_loop_cols

main_loop_cols_end:
	li	$a0, '\n'
	li	$v0, 11
	syscall

	addi	$t0, 1
	b	main_loop_rows_cond

main_loop_rows_end:

main_epilogue:
	# everything you pop
	li	$v0, 0
	jr	$ra
