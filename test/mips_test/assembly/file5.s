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
#LoadVal 10
li $8, 10

#AssignExp 
addu $9, $8, $0
# a = 1
#WriteVara
sw $9, 8($sp)
#return
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0
addu $2, $8, $0
j  $31
nop
#CompoundStat } 

