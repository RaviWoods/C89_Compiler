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
li $8, 10

addu $5,$8, $0
li $8, 7

addu $6,$8, $0
addu $8,$6, $5

addu $5,$8, $0
li $8, 1

addu $6,$8, $0
addu $8,$6, $5
addu $2, $8, $0
j  $31
nop

