	.file	1 "tester.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.rdata
	.align	2
$LC1:
	.ascii	"Error (within MIPS program): received signal number %d\012"
	.ascii	"\000"
	.text
	.align	2
	.globl	signal_handler
	.set	nomips16
	.set	nomicromips
	.ent	signal_handler
	.type	signal_handler, @function
signal_handler:
	.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	16
	sw	$4,32($fp)
	lw	$5,32($fp)
	lui	$2,%hi($LC1)
	addiu	$4,$2,%lo($LC1)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$4,1			# 0x1
	lw	$2,%call16(exit)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,exit
1:	jalr	$25
	nop

	.set	macro
	.set	reorder
	.end	signal_handler
	.size	signal_handler, .-signal_handler
	.rdata
	.align	2
$LC2:
	.ascii	"DriverBegin (MIPS driver program starting)\012\000"
	.align	2
$LC3:
	.ascii	"%s%d, %d, %d\012\000"
	.align	2
$LC4:
	.ascii	"DriverFinished (MIPS driver program finishing)\012\000"
	.align	2
$LC0:
	.word	0
	.word	-1
	.word	-2
	.word	-7
	.word	-11
	.word	-255
	.word	-256
	.word	-257
	.word	-65535
	.word	-65536
	.word	-65537
	.word	-8388607
	.word	1
	.word	2
	.word	7
	.word	11
	.word	255
	.word	256
	.word	257
	.word	65535
	.word	65536
	.word	65537
	.word	8388607
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,152,$31		# vars= 112, regs= 2/0, args= 24, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-152
	sw	$31,148($sp)
	sw	$fp,144($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	24
	sw	$4,152($fp)
	sw	$5,156($fp)
	lui	$2,%hi(signal_handler)
	addiu	$5,$2,%lo(signal_handler)
	li	$4,2			# 0x2
	lw	$2,%call16(signal)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,signal
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lui	$2,%hi(signal_handler)
	addiu	$5,$2,%lo(signal_handler)
	li	$4,4			# 0x4
	lw	$2,%call16(signal)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,signal
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lui	$2,%hi(signal_handler)
	addiu	$5,$2,%lo(signal_handler)
	li	$4,11			# 0xb
	lw	$2,%call16(signal)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,signal
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lui	$2,%hi(signal_handler)
	addiu	$5,$2,%lo(signal_handler)
	li	$4,8			# 0x8
	lw	$2,%call16(signal)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,signal
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,43			# 0x2b
	li	$5,1			# 0x1
	lui	$2,%hi($LC2)
	addiu	$4,$2,%lo($LC2)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$4,$2
	lw	$2,%call16(fflush)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fflush
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lui	$2,%hi($LC0)
	addiu	$3,$fp,48
	addiu	$2,$2,%lo($LC0)
	li	$4,92			# 0x5c
	move	$6,$4
	move	$5,$2
	move	$4,$3
	lw	$2,%call16(memcpy)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,memcpy
1:	jalr	$25
	nop

	lw	$28,24($fp)
	li	$2,23			# 0x17
	sw	$2,40($fp)
	sw	$0,32($fp)
	b	$L3
	nop

$L6:
	sw	$0,36($fp)
	b	$L4
	nop

$L5:
	lw	$2,32($fp)
	sll	$2,$2,2
	addiu	$3,$fp,32
	addu	$2,$3,$2
	lw	$4,16($2)
	lw	$2,36($fp)
	sll	$2,$2,2
	addiu	$3,$fp,32
	addu	$2,$3,$2
	lw	$2,16($2)
	move	$5,$2
	lw	$2,%call16(f)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,f
1:	jalr	$25
	nop

	lw	$28,24($fp)
	sw	$2,44($fp)
	lw	$2,%got(stdout)($28)
	lw	$4,0($2)
	lw	$2,156($fp)
	addiu	$2,$2,4
	lw	$5,0($2)
	lw	$2,32($fp)
	sll	$2,$2,2
	addiu	$3,$fp,32
	addu	$2,$3,$2
	lw	$6,16($2)
	lw	$2,36($fp)
	sll	$2,$2,2
	addiu	$3,$fp,32
	addu	$2,$3,$2
	lw	$2,16($2)
	lw	$3,44($fp)
	sw	$3,20($sp)
	sw	$2,16($sp)
	move	$7,$6
	move	$6,$5
	lui	$2,%hi($LC3)
	addiu	$5,$2,%lo($LC3)
	lw	$2,%call16(fprintf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fprintf
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$4,$2
	lw	$2,%call16(fflush)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fflush
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lw	$2,36($fp)
	addiu	$2,$2,1
	sw	$2,36($fp)
$L4:
	lw	$3,36($fp)
	lw	$2,40($fp)
	slt	$2,$3,$2
	bne	$2,$0,$L5
	nop

	lw	$2,32($fp)
	addiu	$2,$2,1
	sw	$2,32($fp)
$L3:
	lw	$3,32($fp)
	lw	$2,40($fp)
	slt	$2,$3,$2
	bne	$2,$0,$L6
	nop

	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,47			# 0x2f
	li	$5,1			# 0x1
	lui	$2,%hi($LC4)
	addiu	$4,$2,%lo($LC4)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$4,$2
	lw	$2,%call16(fflush)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fflush
1:	jalr	$25
	nop

	lw	$28,24($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$31,148($sp)
	lw	$fp,144($sp)
	addiu	$sp,$sp,152
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 5.3.1-8) 5.3.1 20160205"
