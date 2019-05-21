# mark_description "Intel(R) C Intel(R) 64 Compiler for applications running on Intel(R) 64, Version 19.0.3.199 Build 20190206";
# mark_description "-S";
	.file "1_1.c"
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
        pushq     %r15                                          #4.1
        pushq     %rbx                                          #4.1
        subq      $112, %rsp                                    #4.1
        xorl      %esi, %esi                                    #4.1
        movl      $3, %edi                                      #4.1
        call      __intel_new_feature_proc_init                 #4.1
	.cfi_escape 0x10, 0x03, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0xf0, 0xff, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0f, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0xf8, 0xff, 0xff, 0xff, 0x22
                                # LOE r12 r13 r14
..B1.8:                         # Preds ..B1.1
                                # Execution count [1.00e+00]
        stmxcsr   (%rsp)                                        #4.1
        movl      $a.3.0.1, %edi                                #9.5
        orl       $32832, (%rsp)                                #4.1
        ldmxcsr   (%rsp)                                        #4.1
        movl      a.3.0.1(%rip), %r15d                          #8.7
..___tag_value_main.8:
#       unknown(int *)
        call      unknown                                       #9.5
..___tag_value_main.9:
                                # LOE r12 r13 r14 r15d
..B1.2:                         # Preds ..B1.8
                                # Execution count [1.00e+00]
        movl      a.3.0.1(%rip), %ebx                           #10.8
        cmpl      $5, %ebx                                      #10.11
        jne       ..B1.4        # Prob 0%                       #10.11
                                # LOE r12 r13 r14 ebx r15d
..B1.3:                         # Preds ..B1.2
                                # Execution count [1.00e+00]
        movl      $il0_peep_printf_format_0, %edi               #11.5
        call      puts                                          #11.5
                                # LOE r12 r13 r14 ebx r15d
..B1.4:                         # Preds ..B1.3 ..B1.2
                                # Execution count [1.00e+00]
        movl      $.L_2__STRING.1, %edi                         #13.5
        movl      %ebx, %esi                                    #13.5
        movl      %ebx, %edx                                    #13.5
        movl      %r15d, %ecx                                   #13.5
        xorl      %eax, %eax                                    #13.5
..___tag_value_main.10:
#       printf(const char *, ...)
        call      printf                                        #13.5
..___tag_value_main.11:
                                # LOE r12 r13 r14
..B1.5:                         # Preds ..B1.4
                                # Execution count [1.00e+00]
        movl      $1, %eax                                      #14.11
        addq      $112, %rsp                                    #14.11
	.cfi_restore 3
        popq      %rbx                                          #14.11
	.cfi_restore 15
        popq      %r15                                          #14.11
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
	.data
	.align 4
	.align 4
a.3.0.1:
	.long	5
	.section .rodata.str1.4, "aMS",@progbits,1
	.align 4
	.align 4
il0_peep_printf_format_0:
	.long	893205857
	.byte	0
	.data
# -- End  main
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
