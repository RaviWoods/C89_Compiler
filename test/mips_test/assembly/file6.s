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
#Declarator x
#LoadVal 10
li $8, 10

addu $9, $8, $0
#WriteNEWVarx
sw $9, 0($sp)
addiu $sp, $sp, -4

#return
#LoadID x
# x = 3
# stack = 3
#ReadVar name
lw $9, 4($sp)
addu $8,$9, $0
addu $2, $8, $0
j  $31
nop
#CompoundStat } 

