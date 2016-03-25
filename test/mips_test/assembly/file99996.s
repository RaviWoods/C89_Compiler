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
#LoadVal 5
li $8, 5

addu $9, $8, $0
#WriteNEWVarx
sw $9, 0($sp)
addiu $sp, $sp, -4

#CompoundStat { 
#Declarator x
#LoadVal 10
li $8, 10

addu $9, $8, $0
#WriteNEWVarx
sw $9, 0($sp)
addiu $sp, $sp, -4

#BinExp +
#LoadID x
# x = 4
# stack = 4
#ReadVar name
lw $9, 4($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadVal 1
li $8, 1

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
addu $8,$6, $5

#AssignExp 
addu $9, $8, $0
# x = 4
#WriteVarx
sw $9, 4($sp)
#return
#LoadID x
# x = 4
# stack = 4
#ReadVar name
lw $9, 4($sp)
addu $8,$9, $0
addu $2, $8, $0
j  $31
nop
#CompoundStat } 
#CompoundStat } 

