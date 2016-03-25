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
#UnaryExp -
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

subu $8,$0, $8
addu $2, $8, $0
j  $31
nop
#CompoundStat } 

