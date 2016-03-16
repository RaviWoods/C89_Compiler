.text
.align 2
.globl  f
.ent  f
.type  f, @function
f:
sw  $4, 0($sp)
addiu $sp, $sp, -4
sw  $5, 0($sp)
addiu $sp, $sp, -4
sw  $6, 0($sp)
addiu $sp, $sp, -4
sw  $7, 0($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
j	$31
lw $8, 24($sp)
addu $2, $8, $0
nop

