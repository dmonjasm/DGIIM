.section .data		#DANIEL MONJAS MIGUÉLEZ DGIIM 2º
lista:
	.int 0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001	#Declaramos 32 enteros de 4 bytes
	.int 0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001
	.int 0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001
	.int 0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001

longlista:
	.int	(.-lista)/4	#Se almacena en la variable longlista la longitud de la lista

resultado:
	.quad -1

.section .text
_start: .global _start

	mov $lista, %ebx	#Se mueve la direccion inicial de lista al registro %ebx
	mov longlista, %ecx	#Se mueve el valor de la variable longlista al registro %ecx
	call suma		#Se llama a la funcion suma
	mov %eax, resultado	#Se mueve el contenido de %eax(resultado de la suma de los 32 enteros) a la variable resultado
	mov %edx, resultado+4	#Se mueve el acarreo total de la suma a la siguiente posicion de memoria del resultado
	mov $1, %eax		#Se establece a 1 %eax
	mov $0, %ebx		#Se establece a 0 %ebx
	int $0x80		#Se llama a exit()


suma:
	push %esi		#Se almacena en la pila el valor del registro %esi que será el contador del bucle for
	mov $0, %eax		#Se establece a 0 el acumulador
	mov $0, %esi		#Se establece a 0 el contador
	mov $0, %edx		#Se establece a 0 el registro que llevará la extensión de %eax durante el bucle
	mov $0, %edi		#Se establece a 0 el que será el acumulador de acarreos
	mov $0,	%ebp		#Se establece a 0 el registro que contendra los valores de la lista con la extension de signo

bucle:
	mov (%ebx, %esi, 4),%eax
	cdq
	add %eax, %ebp			#Se suman los registros %eax+(4*%esi+%ebx) y se almacena en %eax
	adc %edx, %edi			#Se cuman las cifras mas significativas y el acarreo y se guardan en el acumulador de acarreos
	inc %esi			#Se incrementa el valor del contador %esi
	cmp %esi, %ecx			#Se compara si %esi y %ecx son iguales o no
	jne bucle			#Si no son iguales se vuelve a ejecutar el bucle
	
	mov %ebp, %eax
	mov %edi, %edx
	pop %esi			#Si son iguales se reestablece el valor de %esi
	ret				#Se ejecuta el return
