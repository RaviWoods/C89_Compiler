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

#Declarator y
#LoadVal 2
li $8, 2

addu $9, $8, $0
#WriteNEWVary
sw $9, 0($sp)
addiu $sp, $sp, -4

#BinExp +
#LoadID a
# a = 1
# stack = 4
#ReadVar name
lw $9, 16($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadID x
# x = 3
# stack = 5
#ReadVar name
lw $9, 12($sp)
addu $8,$9, $0

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
# a = 1
#WriteVara
sw $9, 16($sp)
#BinExp +
#LoadID a
# a = 1
# stack = 4
#ReadVar name
lw $9, 16($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#BinExp <<
#BinExp *
#LoadID y
# y = 4
# stack = 5
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadID b
# b = 2
# stack = 6
#ReadVar name
lw $9, 20($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
mul $8,$6, $5

sw  $8, 0($sp)
addiu $sp, $sp, -4

#BinExp %
#LoadVal 200
li $8, 200

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadVal 5
li $8, 5

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
div $6, $5
mfhi $8

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
sll $8,$6, $5

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
# a = 1
#WriteVara
sw $9, 16($sp)
#return
#BinExp +
#LoadID a
# a = 1
# stack = 4
#ReadVar name
lw $9, 16($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadID b
# b = 2
# stack = 5
#ReadVar name
lw $9, 16($sp)
addu $8,$9, $0

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
# a = 1
#WriteVara
sw $9, 16($sp)
addu $2, $8, $0
j  $31
nop
#CompoundStat } 

