//Original:/testcases/core/c_dsp32shift_expadj_h/c_dsp32shift_expadj_h.dsp
// Spec Reference: dsp32shift expadj rh
# mach: bfin

.include "testutils.inc"
	start




imm32 r0, 0x80000008;
imm32 r1, 0x80010008;
imm32 r2, 0x80020008;
imm32 r3, 0x80030008;
imm32 r4, 0x80040008;
imm32 r5, 0x80050008;
imm32 r6, 0x80060008;
imm32 r7, 0x80070008;
R1.L = EXPADJ( R1.H , R0.L );
R2.L = EXPADJ( R2.H , R0.L );
R3.L = EXPADJ( R3.H , R0.L );
R4.L = EXPADJ( R4.H , R0.L );
R5.L = EXPADJ( R5.H , R0.L );
R6.L = EXPADJ( R6.H , R0.L );
R7.L = EXPADJ( R7.H , R0.L );
R0.L = EXPADJ( R0.H , R0.L );
CHECKREG r0, 0x80000000;
CHECKREG r1, 0x80010000;
CHECKREG r2, 0x80020000;
CHECKREG r3, 0x80030000;
CHECKREG r4, 0x80040000;
CHECKREG r5, 0x80050000;
CHECKREG r6, 0x80060000;
CHECKREG r7, 0x80070000;

imm32 r0, 0x90010009;
imm32 r1, 0x00010009;
imm32 r2, 0x90020009;
imm32 r3, 0x90030009;
imm32 r4, 0x90040009;
imm32 r5, 0x90050009;
imm32 r6, 0x90060009;
imm32 r7, 0x90070009;
R0.L = EXPADJ( R0.H , R1.L );
R2.L = EXPADJ( R2.H , R1.L );
R3.L = EXPADJ( R3.H , R1.L );
R4.L = EXPADJ( R4.H , R1.L );
R5.L = EXPADJ( R5.H , R1.L );
R6.L = EXPADJ( R6.H , R1.L );
R7.L = EXPADJ( R7.H , R1.L );
R1.L = EXPADJ( R1.H , R1.L );
CHECKREG r0, 0x90010000;
CHECKREG r1, 0x00010009;
CHECKREG r2, 0x90020000;
CHECKREG r3, 0x90030000;
CHECKREG r4, 0x90040000;
CHECKREG r5, 0x90050000;
CHECKREG r6, 0x90060000;
CHECKREG r7, 0x90070000;


imm32 r0, 0xa001000a;
imm32 r1, 0xa001000a;
imm32 r2, 0xa002000a;
imm32 r3, 0xa003000a;
imm32 r4, 0xa004000a;
imm32 r5, 0xa005000a;
imm32 r6, 0xa006000a;
imm32 r7, 0xa007000a;
R0.L = EXPADJ( R0.H , R2.L );
R1.L = EXPADJ( R1.H , R2.L );
R3.L = EXPADJ( R3.H , R2.L );
R4.L = EXPADJ( R4.H , R2.L );
R5.L = EXPADJ( R5.H , R2.L );
R6.L = EXPADJ( R6.H , R2.L );
R7.L = EXPADJ( R7.H , R2.L );
R2.L = EXPADJ( R2.H , R2.L );
CHECKREG r0, 0xA0010000;
CHECKREG r1, 0xA0010000;
CHECKREG r2, 0xA0020000;
CHECKREG r3, 0xA0030000;
CHECKREG r4, 0xA0040000;
CHECKREG r5, 0xA0050000;
CHECKREG r6, 0xA0060000;
CHECKREG r7, 0xA0070000;

imm32 r0, 0xc001000c;
imm32 r1, 0xc001000c;
imm32 r2, 0xc002000c;
imm32 r3, 0xc003001c;
imm32 r4, 0xc004000c;
imm32 r5, 0xc005000c;
imm32 r6, 0xc006000c;
imm32 r7, 0xc007000c;
R0.L = EXPADJ( R0.H , R3.L );
R1.L = EXPADJ( R1.H , R3.L );
R2.L = EXPADJ( R2.H , R3.L );
R4.L = EXPADJ( R4.H , R3.L );
R5.L = EXPADJ( R5.H , R3.L );
R6.L = EXPADJ( R6.H , R3.L );
R7.L = EXPADJ( R7.H , R3.L );
R3.L = EXPADJ( R3.H , R3.L );
CHECKREG r0, 0xC0010001;
CHECKREG r1, 0xC0010001;
CHECKREG r2, 0xC0020001;
CHECKREG r3, 0xC0030001;
CHECKREG r4, 0xC0040001;
CHECKREG r5, 0xC0050001;
CHECKREG r6, 0xC0060001;
CHECKREG r7, 0xC0070001;

imm32 r0, 0xb0000008;
imm32 r1, 0xb0010008;
imm32 r2, 0xb0020008;
imm32 r3, 0xb0030008;
imm32 r4, 0xb0040008;
imm32 r5, 0xb0050008;
imm32 r6, 0xb0060008;
imm32 r7, 0xb0070008;
R0.L = EXPADJ( R1.H , R4.L );
R1.L = EXPADJ( R2.H , R4.L );
R2.L = EXPADJ( R3.H , R4.L );
R3.L = EXPADJ( R4.H , R4.L );
R5.L = EXPADJ( R5.H , R4.L );
R6.L = EXPADJ( R6.H , R4.L );
R7.L = EXPADJ( R7.H , R4.L );
R4.L = EXPADJ( R0.H , R4.L );
CHECKREG r0, 0xB0000000;
CHECKREG r1, 0xB0010000;
CHECKREG r2, 0xB0020000;
CHECKREG r3, 0xB0030000;
CHECKREG r4, 0xB0040000;
CHECKREG r5, 0xB0050000;
CHECKREG r6, 0xB0060000;
CHECKREG r7, 0xB0070000;

imm32 r0, 0xc0010009;
imm32 r1, 0xc0010009;
imm32 r2, 0xc0020009;
imm32 r3, 0xc0030009;
imm32 r4, 0xc0040009;
imm32 r5, 0xc0050009;
imm32 r6, 0xc0060009;
imm32 r7, 0xc0070009;
R0.L = EXPADJ( R0.H , R5.L );
R1.L = EXPADJ( R2.H , R5.L );
R2.L = EXPADJ( R3.H , R5.L );
R3.L = EXPADJ( R4.H , R5.L );
R4.L = EXPADJ( R5.H , R5.L );
R6.L = EXPADJ( R6.H , R5.L );
R7.L = EXPADJ( R7.H , R5.L );
R5.L = EXPADJ( R1.H , R5.L );
CHECKREG r0, 0xC0010001;
CHECKREG r1, 0xC0010001;
CHECKREG r2, 0xC0020001;
CHECKREG r3, 0xC0030001;
CHECKREG r4, 0xC0040001;
CHECKREG r5, 0xC0050001;
CHECKREG r6, 0xC0060001;
CHECKREG r7, 0xC0070001;


imm32 r0, 0xe001000a;
imm32 r1, 0xe001000a;
imm32 r2, 0xe002000a;
imm32 r3, 0xe003000a;
imm32 r4, 0xe004000a;
imm32 r5, 0xe005000a;
imm32 r6, 0xe006000a;
imm32 r7, 0xe007000a;
R0.L = EXPADJ( R0.H , R6.L );
R1.L = EXPADJ( R1.H , R6.L );
R2.L = EXPADJ( R3.H , R6.L );
R3.L = EXPADJ( R4.H , R6.L );
R4.L = EXPADJ( R5.H , R6.L );
R5.L = EXPADJ( R6.H , R6.L );
R6.L = EXPADJ( R7.H , R6.L );
R7.L = EXPADJ( R2.H , R6.L );
CHECKREG r0, 0xE0010002;
CHECKREG r1, 0xE0010002;
CHECKREG r2, 0xE0020002;
CHECKREG r3, 0xE0030002;
CHECKREG r4, 0xE0040002;
CHECKREG r5, 0xE0050002;
CHECKREG r6, 0xE0060002;
CHECKREG r7, 0xE0070002;

imm32 r0, 0xd001000c;
imm32 r1, 0xd001000c;
imm32 r2, 0xd002000c;
imm32 r3, 0xd003001c;
imm32 r4, 0xd004000c;
imm32 r5, 0xd005000c;
imm32 r6, 0xd006000c;
imm32 r7, 0xd007000c;
R0.L = EXPADJ( R0.H , R7.L );
R1.L = EXPADJ( R1.H , R7.L );
R2.L = EXPADJ( R2.H , R7.L );
R3.L = EXPADJ( R4.H , R7.L );
R4.L = EXPADJ( R5.H , R7.L );
R5.L = EXPADJ( R6.H , R7.L );
R6.L = EXPADJ( R7.H , R7.L );
R7.L = EXPADJ( R3.H , R7.L );
CHECKREG r0, 0xD0010001;
CHECKREG r1, 0xD0010001;
CHECKREG r2, 0xD0020001;
CHECKREG r3, 0xD0030001;
CHECKREG r4, 0xD0040001;
CHECKREG r5, 0xD0050001;
CHECKREG r6, 0xD0060001;
CHECKREG r7, 0xD0070001;


pass
