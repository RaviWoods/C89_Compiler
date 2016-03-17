.text
.align 2
.globl  f
.end  f
.type  f, @function
f:
sw  $4, $sp
addiu $sp, $sp, -4
sw  $5, $sp
addiu $sp, $sp, -4
sw  $6, $sp
addiu $sp, $sp, -4
sw  $7, $sp
addiu $sp, $sp, -4
lw $8, 8($sp)
addiu $2, $8, $0
j	$31
nop

