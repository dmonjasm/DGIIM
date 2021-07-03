# suma.s del GuiÃ³n 1
# 1.- aÃ±adiÃ©ndole convenciÃ³n cdecl
# 2.- aÃ±adiÃ©ndole printf() y cambiando syscall por exit()
# 3.- extrayendo suma a mÃ³dulo C para linkar
#	gcc -m32 -O1 -g -c suma_03_SC_c.c
#	as --32      -g    suma_03_SC_s.s -o suma_03_SC_s.o
#	ld -m elf_i386     suma_03_SC_c.o    suma_03_SC_s.o -o suma_03_SC \
#		-lc   -dynamic-linker /lib/ld-linux.so.2
# 4.- dejando sÃ³lo los datos, que el resto lo haga suma() en mÃ³dulo C
#				mismas instrucciones que versiÃ³n _03_

.section .data
lista:		.int 1,2,10,  1,2,0b10,  1,2,0x10
longlista:	.int (.-lista)/4
resultado:	.int -1
formato:	.ascii	"resultado = %d = %0x hex\n\0"
				# formato para printf() libC
.global lista, longlista, resultado, formato

.section .text
main:	.global main

	jmp suma
