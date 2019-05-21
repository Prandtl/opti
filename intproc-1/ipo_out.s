# mark_description "Intel(R) C Intel(R) 64 Compiler for applications running on Intel(R) 64, Version 19.0.3.199 Build 20190206";
# mark_description "-ipo-S";
	.file "ipo_out.c"
	.text
..TXTST0:
.L_2__routine_start_main_0:
# -- Begin  main
	.text
# mark_begin;
       .align    16,0x90
	.globl main
# --- main()
main:
..B1.1:                         # Preds ..B1.0
                                # Execution count [1.00e+00]
	.cfi_startproc
..___tag_value_main.1:
..L2:
                                                          #4.1
        pushq     %rbp                                          #4.1
	.cfi_def_cfa_offset 16
        movq      %rsp, %rbp                                    #4.1
	.cfi_def_cfa 6, 16
	.cfi_offset 6, -16
        andq      $-128, %rsp                                   #4.1
        subq      $128, %rsp                                    #4.1
        xorl      %esi, %esi                                    #4.1
        movl      $3, %edi                                      #4.1
        call      __intel_new_feature_proc_init                 #4.1
                                # LOE rbx r12 r13 r14 r15
..B1.6:                         # Preds ..B1.1
                                # Execution count [1.00e+00]
        stmxcsr   (%rsp)                                        #4.1
        movl      $il0_peep_printf_format_0, %edi               #11.5
        orl       $32832, (%rsp)                                #4.1
        ldmxcsr   (%rsp)                                        #4.1
        call      puts                                          #11.5
                                # LOE rbx r12 r13 r14 r15
..B1.2:                         # Preds ..B1.6
                                # Execution count [1.00e+00]
        movl      $5, %esi                                      #13.5
        movl      $.L_2__STRING.1, %edi                         #13.5
        movl      %esi, %edx                                    #13.5
        movl      %esi, %ecx                                    #13.5
        xorl      %eax, %eax                                    #13.5
..___tag_value_main.6:
#       printf(const char *, ...)
        call      printf                                        #13.5
..___tag_value_main.7:
                                # LOE rbx r12 r13 r14 r15
..B1.3:                         # Preds ..B1.2
                                # Execution count [1.00e+00]
        movl      $1, %eax                                      #14.11
        movq      %rbp, %rsp                                    #14.11
        popq      %rbp                                          #14.11
	.cfi_def_cfa 7, 8
	.cfi_restore 6
        ret                                                     #14.11
        .align    16,0x90
                                # LOE
	.cfi_endproc
# mark_end;
	.type	main,@function
	.size	main,.-main
..LNmain.0:
	.section .rodata.str1.4, "aMS",@progbits,1
	.align 4
	.align 4
il0_peep_printf_format_0:
	.long	893205857
	.byte	0
	.data
# -- End  main
	.text
.L_2__routine_start_unknown_1:
# -- Begin  unknown
	.text
# mark_begin;
       .align    16,0x90
	.globl unknown
# --- unknown(int *)
unknown:
# parameter 1: %rdi
..B2.1:                         # Preds ..B2.0
                                # Execution count [1.00e+00]
	.cfi_startproc
..___tag_value_unknown.11:
..L12:
                                                         #2.1
        ret                                                     #5.1
        .align    16,0x90
                                # LOE
	.cfi_endproc
# mark_end;
	.type	unknown,@function
	.size	unknown,.-unknown
..LNunknown.1:
	.data
# -- End  unknown
	.section .rodata.str1.4, "aMS",@progbits,1
	.space 3, 0x00 	# pad
	.align 4
.L_2__STRING.1:
	.long	622879781
	.long	1680154724
	.word	10
	.type	.L_2__STRING.1,@object
	.size	.L_2__STRING.1,10
	.data
	.section .note.GNU-stack, ""
# End
