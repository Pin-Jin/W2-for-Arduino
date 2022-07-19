	.text
	.align	2
	.globl	entry
	.ent	entry
entry:
   .set noreorder

  ##
  # Hardware requres this:
  ##
    nop                         # 0x0		//0
    lui	$gp, 0x0000		# 0x4 	//4, gp for the user program
    ori	$gp, $gp, 0		# 0x8	//8
    addiu 	$sp, $sp, -12		# 0xc	//12
    sw 	$31, 8($sp)		# 0x10	//16
    sw 	$fp, 4($sp)			# 0x14	//20
    move 	$fp, $sp			# 0x18	//24
    nop				# 0x1c 	//28
    nop				# 0x20	//32
    j main	                 		# 0x24  	//36
    nop				# 0x28	//40
    nop				# 0x2c	//44				 
    lui	$gp, 0x0000		# 0x30 	//48, gp for the user program
    ori	$gp, $gp, 0		# 0x34
    addiu 	$sp, $sp, -12
    sw 	$31, 8($sp)
    sw 	$fp, 4($sp)
    move 	$fp, $sp     
    jal 	user_interrupt	
    nop	 
    move 	$sp,$fp
    lw	$31, 8($sp)
    lw	$fp, 4($sp)
    addiu	$sp, $sp, 12
    lui	$gp, 0x0100		#gp for the loader
    ori	$gp, $gp, 0x8000
    jr 	$31
    nop                          
        .end    entry

























































































































