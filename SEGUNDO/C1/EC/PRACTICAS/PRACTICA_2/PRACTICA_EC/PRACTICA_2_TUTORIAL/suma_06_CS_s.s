# suma.s del GuiÃ³n 1
# 1.- aÃ±adiÃ©ndole convenciÃ³n cdecl
# 2.- aÃ±adiÃ©ndole printf() y cambiando syscall por exit()
# 3.- extrayendo suma a mÃ³dulo C para linkar
# 4.- dejando sÃ³lo los datos, que el resto lo haga suma() en mÃ³dulo C
# 5.- entero en C
# 6.- volviendo a sacar la suma a ensamblador
#	gcc -m32 -O1 -g    suma_06_CS_c.c    suma_06_CS_s.s -o suma_06_CS
#
#	gcc -m32 -O1 -g -c suma_06_CS_c.c
#	as  --32     -g    suma_06_CS_s.s -o suma_06_CS_s.o
#	gcc -m32           suma_06_CS_c.o    suma_06_CS_s.o -o suma_06_CS
#
#	LDIR=`gcc -print-file-name=`
#	ld -m elf_i386     suma_06_CS_c.o    suma_06_CS_s.o -o suma_06_CS \
#		-dynamic-linker /lib/ld-linux.so.2				\
#		/usr/lib32/crt1.o /usr/lib32/crti.o /usr/lib32/crtn.o	\
#		$LDIR/32/crtbegin.o   $LDIR/32/crtend.o		-lc

.section .text
suma:	.global suma
	push %ebp
	mov  %esp, %ebp

	push %ebx
	mov  8(%ebp), %ebx
	mov 12(%ebp), %ecx

	mov $0, %eax
	mov $0, %edx
bucle:
	add (%ebx,%edx,4), %eax
	inc       %edx
	cmp  %edx,%ecx
	jne bucle

	pop %ebx
	pop %ebp
	ret


