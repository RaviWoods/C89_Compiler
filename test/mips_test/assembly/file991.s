.text
.align 2
.globl  f
.ent  f
.type  f, @function
f:
#WriteNEWParam
sw  $4, 0($sp)
addiu $sp, $sp, -4
#WriteNEWParam
sw  $5, 0($sp)
addiu $sp, $sp, -4
#CompoundStat { 
#return
#BinExp ==
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadID b
# b = 2
# stack = 3
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
seq $8,$6, $5
addu $2, $8, $0
j  $31
nop
#CompoundStat } 

