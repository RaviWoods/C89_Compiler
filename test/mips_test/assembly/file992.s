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
#Declarator y
#BinExp ^
#BinExp +
#LoadVal 1
li $8, 1

sw  $8, 0($sp)
addiu $sp, $sp, -4

#BinExp *
#LoadVal 2
li $8, 2

sw  $8, 0($sp)
addiu $sp, $sp, -4

#BinExp *
#LoadVal 3
li $8, 3

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadVal 4
li $8, 4

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

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
mul $8,$6, $5

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
addu $8,$6, $5

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
xor $8,$6, $5

addu $9, $8, $0
#WriteNEWVary
sw $9, 0($sp)
addiu $sp, $sp, -4

#Declarator x
#BinExp &
#BinExp >
#BinExp +
#LoadVal 1
li $8, 1

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadVal 2
li $8, 2

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
addu $8,$6, $5

sw  $8, 0($sp)
addiu $sp, $sp, -4

#BinExp <=
#LoadVal 3
li $8, 3

sw  $8, 0($sp)
addiu $sp, $sp, -4

#BinExp *
#LoadID a
# a = 1
# stack = 5
#ReadVar name
lw $9, 20($sp)
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

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
sle $8,$6, $5

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
slt $8,$5, $6

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadID y
# y = 3
# stack = 4
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
and $8,$6, $5

addu $9, $8, $0
#WriteNEWVarx
sw $9, 0($sp)
addiu $sp, $sp, -4

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

