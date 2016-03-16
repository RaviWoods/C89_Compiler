	.text
	.align	2
	.globl	f
	.ent	f
	.type	f, @function
f:
	li	$2,42			# 0x2a
	j	$31
	nop
