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
#BinExp +
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadVal 10
li $8, 10

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
sw $9, 8($sp)
#BinExp *
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadVal 80
li $8, 80

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
mul $8,$6, $5

#AssignExp 
addu $9, $8, $0
# a = 1
#WriteVara
sw $9, 8($sp)
#BinExp /
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadVal 100
li $8, 100

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
div $8,$6, $5

#AssignExp 
addu $9, $8, $0
# a = 1
#WriteVara
sw $9, 8($sp)
#BinExp %
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

sw  $8, 0($sp)
addiu $sp, $sp, -4

#LoadVal 100
li $8, 100

sw  $8, 0($sp)
addiu $sp, $sp, -4

addiu $sp, $sp, +4
lw  $5, 0($sp)

addiu $sp, $sp, +4
lw  $6, 0($sp)

addu $5,$8, $0
div $6, $5
mfhi $8

#AssignExp 
addu $9, $8, $0
# a = 1
#WriteVara
sw $9, 8($sp)
#BinExp -
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

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
subu $8,$6, $5

#AssignExp 
addu $9, $8, $0
# a = 1
#WriteVara
sw $9, 8($sp)
#BinExp <<
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
addu $8,$9, $0

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
sll $8,$6, $5

#AssignExp 
addu $9, $8, $0
# a = 1
#WriteVara
sw $9, 8($sp)
#BinExp >>
#LoadID a
# a = 1
# stack = 2
#ReadVar name
lw $9, 8($sp)
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
sra $8,$6, $5

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

