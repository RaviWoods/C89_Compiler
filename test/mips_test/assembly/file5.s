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
li $9, 10
sw  $9, 0($sp)
addiu $sp, $sp, +4

sw  $9, 0($sp)
lw $9, 8($sp)
lw $9, 8($sp)
sw $9, 0($sp)
addiu $sp, $sp, -4
sw  $9, 0($sp)
addiu $sp, $sp, -4
addu $2, $9, $0
j  $31
nop

