# Enero 2020 #
## Tipo test ##
1) Un módulo de DRAM con chips en ambas caras no tiene porqué ser de doble rango (dual ranker). Verdadero.
   
2) Tanto las SRAM como las DRAM son volátiles pero las DRAM necesitan refresco. Verdadero.
    
    Las memorias DRAM requieren refresco dinámico de sus cargas mientras que las SRAM no.

3) Las primeras instrucciones que ejecuta un procesador en el arrangque proceden de las primeras direcciones de la DRAM. Falso

    Las primeras instruccinoes que ejecuta un procesador en el arranque proceden de la memoria ROM, que contiene el código de arranque básico del computador.

4) Los protocolos de comunicación serie pueden ser half-duplex. Verdadero.

    Basta ver el USB 2.0.

5) Con "almacenamiento permanente" queremos indicar que el dispositivo es de solo lectura y que el dato se va a quedar escrito en el dispositivo de forma permanente. Falso

    Se quiere indicar que el dispositivo no pierde la información al cortarse la alimentación.

6) Con un conector SATA de la placa base puedo conectar 4 discos mini SAS. Falso

    Las controladoras SAS aceptan conexiones SATA pero no al revés.

7) Jugando con las distintas configuraciones de un RAID se puede conseguir más fiabilidad o más disponibilidad pero no mayores prestaciones. Falso.

    RAID 0 proporciona mayores prestaciones.

8) sar es un monitor software por evento. Falso.

    Por lo general sar se programa para que tome muestras por periodos de tiempo.

9) La precisión de un sensor está relacionada con la dispersión de las medidas que realiza. Verdadero

    Es justo lo que mide.

10) Con "carga del sistema", el SO Linux se refiere al número de porcesoso en modo running, runnable o I/O blocked. Verdadero.

    Es justo a lo que se refiere.

11) La hipótesis inicial de un test t es que los rendimientos de ambas alternativas a analizar son estadísticamente diferentes. Falso

    La hipótesis nula supone que ambos rendimientos son equivalentes.

12) Cuando nos referimos al índice de prestaciones que se calcula según el benchmark SPEC CPU2017, el SPEC pico (peak) nunca puede ser menor que el SPEC base. Verdadero.

    No tiene sentido elegir unas opciones de compilación que empeoren el índice de prestaciones, pues entonces ya no serían óptimas, que son las opciones de compilación que se toman en el SPEC peak.

13) En los benchmarks TPC-C y TPC-H, el índice de prestaciones se calcula a partir de la meida geométrica de las ganancias en velocidad con respecto a una máquina de referencia. Falso.

    Esto se hace en SPEC y SYSMARK pero no en TPC.

14) Actuando sobre el elemento con mayor razón de visita nos garantizamos mejorar la productividad máxima de un servidor. Falso

    Esto es cierto si y sólo si actuamos sobre el cuello de botella. Podemos hacerlo sobre el de mayor razón de visita, pero si este no es el cuello de botella no afectará a la productividad máxima.

15) La razón media de visita de un dispositivo no tiene por qué ser un número entero. Verdadero.

16) En un servidor, si la demanda de servicio de un dispositivo es menor que la de otro, su utilización nunca podrá ser mayor que la de es otro dispositivo. Verdadero

    La ley de utilización nos dice que Ui=X0xDi, por tanto si Di>Dj entonces Ui>Uj, pues X0 es igual para ambos.

17) En un servidor modielado mediante una red de colas se cumple que Bi=(Ni-Qi)xT. Verdadero

    Si se despeja y sustituye adecuadamente se tiene que Ui=Bi/T, que es justo la definición de utilización del dispositivo i-ésimo.

18) Si el número total de ususarios en un servidor modelado mediante una red de colas cerrada interactiva es superior a NT*, entonces el servidor está saturado. Falso

    Si NT>NT*, lo único que se nos dice es que el tiempo de respuesta ya no puede ser el mínimo. El servidor está saturado si y sólo su su cuello de botella tiene una utilización de 1.

19) Es la media aritmética y no el índice SPEC el que nos ayuda a saber qué computadora ejecuta el conjunto total de programas de un benchmark en menos tiempo. Verdadero

    La media aritmética nos asegura que si un programa tiene una media menor para un mismo número de muestras, entonces la suma de las muestras es menor, es decir, la suma de los tiempos de ejecución de un programa cuya media sea menor es menor.

20) SAR, al igual que TOP, es un monitor software por evento. Falso

    Ambos son por muestreo, especialmente top, que se actualiza de forma interactiva (sar tiene la opción de hacerlo en segundo plano).

21) Si el índice SPEC para un conjunto dado de programas de un benchmark de una computadora es mayor que 1 es porque ejecuta todos los programas en menos tiempo que la máquina de referencia, es decir, la suma de los tiempos de ejecución de todos los programas del benchmarke s menor que si usamos la máquina de referencia. Falso

    El índice SPEC es la media geométrica de las ganacias respecto a la máquina de referencia. La media geométrica premia las mejores sustanciales y no se castigan los empeoramientos no sustanciales, es decir, puede tener todos los tiempos menos uno un poco peor que el de la máquina de referencia y el último mucho mejor, y con esto podría servir para que el índice SPEC fuese mayor que 1.

22) Tres soluciones para que nuestro servidor sea escalable.

    Podemos usar cloud computing+ virtualización. Podemos usar servidores modulares/clusters. Arquitecturas distribuidas/ arquitecturas por capas. Programación paralela. Storage Area Networks.

23) ¿En qué estados básicos puede encontrarse un proceso en un sistema tipo Unix?

    Puede estar ejecutándose, listo para ejecutar (runnable), interrumpido por E/S o durmiendo a la espera de la ocurrencia de un evento.

24) Con el comando *uptime*, ¿cuáles de ellos son los que computan para medir la carga del sistema?

    La carga del sistema los componen los que están en ejecución, los listos para ejecutar y los bloqueados por E/S.

25) Las principales medidas de prestaciones de un servidor se basan en latencias y anchos de banda. Verdadero

26) Todos los sistemas escalables son extensibles pero no a la inversa. Verdadero

    Un sistema escalable es aquel que puede aumentar sus caracterísiticas de forma **significativa**, mientras que el extensible puede aumentar sus características, pero no tiene porque poder hacerlo de forma significativa.

27) Xeon es una familia de microprocesadores de IBM especialmente dirigida a servidores. Falso

    Es de Intel.

28) La familia AMD Opteron X Series usa procesadores de ARM. Falso

    Esa es la familia AMD Opteron A Series, los X Series son los que se basan en APU y integran GPU y CPU en el mismo chip.

29) La celda básica de una SRAM es mayor que la de una DRAM. Verdadero?

30) El voltaje que usa un módulo DDR4 es menor que el de un módulo DDR3. Verdadero.

    Los módulos DDR4 trabajan con un voltaje entre 1,1 y 1,35V, mientras que DDR3 trabaja con 1.35-1.5V. (Cada versión reduce el voltaje).

31) Las latencias de las unidades de cinta suelen ser muy bajas ya que hay que rebobinar la cinta hasta que el cabezal se encuentre en la posición deseada. Falso.

    Las latencias son muy altas, no bajas.

32) AHCI es una interfaza para facilitar la conexión de SSD a través de PCIe. Falso

    Es una interfaz para facilitar la conexión con SATA, para PCIe se usa NVMe.

33) SAS es full-duplex. Verdadero

34) En el panel traseo de una placa base de un servidor, es habitual encontrar varios conectores de Ethernet. Verdadero

35) A través del System Panel se puede conectar el altavol del chasis a la placa base. Verdadero.

    Efectivamente el sistem panel tiene conectores para los botones de reset, speaker, power led (alimentación a la luz de encendido), PWRSW (power sw) botón de encendido, etc.

36) La pila que hay en la placa sirve, entre otras cosas, para tener el reloj en tiempo real de dicha placa actualizado. Verdadero

    Esa pila alimenta una RAM que contiene los parámetros de configuración de la placa, a parte de para mantener el reloj.

37) Existen servidores con fuentes de alimentación reemplazables en caliente (hot-swappable). Verdadero

    Aquellos con sistemas de alimentación redundantes.

38) El puente sur del chipset se encarga de la comunicación con la DRAM. Falso

    De eso se encarga el puente norte. El puente sur se encarga de las transferencias con el puente norte y el resto de periféricos de menores exigencias de velocidad.

39) En satuaración, el cuello de botella está al máximo de su productividad. Verdadero.

    En saturación la utilización está a 1, luego por la relación Utilización-Demanta X0=1/Db.

40) Si la suma de las utilizaciones de los distintos dispositivos que componen un sistema es mayor que 1, entonces el servidor está saturado. Falso

    No tiene porque, si ninguna de las utilizaciones es 1 entonces no está saturado.

41) La demanda media de servicio de un dispositivo en el seno de un servidor nunca debe ser menor a su tiempo de servicio mínimo. Falso

    Si la razón de visita es menor que 1 (puede serlo), entonces se dará que la demanda es menor que su tiempo medio de servicio.

42) Si ejecutamos la línea sar -d de un servidor con sar instalado, iremos obteniendo la información sobre las transferencias de cada disco del servidor de forma interactiva. Falso

    Los resultados no los mostrará, sino que los mandará al fichero de muestreo correspondiente.

43) C0 es un valor medio calculado durante el periodo de monitorización T. Falso

    C0 es un valor exacto (concretamente se refiere al número de peticiones completadas), que se toma contando las peticiones completadas durante el periodo de monitorización.

44) Si el servidor A es un 50% más rápido que el servidor B en ejecutar un determinado programa benchmark, entonces podemos decir igualmente que el servidor B es un 50% más lento que el servidor A en ejecutar dicho benchmark. Falso

    Si tB/tA=1.5, entonces  tA/tB=1/1.5, es decir, tB es un 33,33% más lento que tA.

45) Las memorias ECC se usan para aumentar la disponibilidad del servidor. Falso.

    Se usan para aumentar la fiablidad del servidor.

46) La frecuencia de reloj de las CPU sigue todavía incrementándose de forma exponencial con los años. Falso.

    Hace años que se prefiere aumentar el número de cores a la frecuencia, pues no es fácil disipar el calor producida por las frecuencias tan altas.

47) Las DRAM, a diferencia de las SRAM, necesitan refresco. Verdadero

49) El VRM, entre otras cosas, convierte la corriente alterna en corriente continua. Falso

    Eso lo hace la fuente de alimentación. El VRM se encarga de adapatar el voltaje obtenido de la fuente de alimentación al que necesita cada componente.

50) Las unidades de estado sólido son capaces de alcanzar anchos de banda superiores a los que el protocolo SATA-3 puede proporcionar. Verdadero.

    De ahí que ahora la nuevas unidades de estado sólido usen M.2
    
51) Time skew es un protocolo de comunicación paralelo. Falso.

    Time skew se refiere a la desviación producida en dispositivos de medida del tiempo. En los circuitos integrados se refiere a que la señar de reloj no llega a todos los componentes a la vez. En redes de computadoreas se puede referir a las diferencias de tiempo entre distintas computadoras.

52) Es el propio procesador de muchas placas base actuales el que realiza la función de puente norte en el chipset. Verdadero

    Actualmente es común que el puenter norte y el puente sur contenga estas funciones.

53) Es muy importante en las pacas de servidores que los conectores de audio y video del panel trasero sean de altas prestaciones. Falso.

    De hecho si nos enseñan un panel trasero con conectores de audio y vídeo de altas prestaciones podemos asumir que es un placa de PC de sobremesa más que una de servidor.

54) "sar" es un monitor de actividad software por muestreo. Verdadero.

55) Si el servidor A es el doble de rápido que el servidor B para todos los programas de un benchmark cuyo rendimiento se calcula según el criterio SPEC, entonces ese índice SPEC del servidor A será mayor que el del servidor B, independientemente de la máquina de referencia elegida. Verdadero.

    Es claro que si es el doble de rápido en todos los programas entonces la ganancia con respecto a la máquina de referencia será mayor en todos los programas, y por tanto también el índice SPEC.

56) El conjunto de instrucciones que ejecutan el auto-test de arranque (Power On self-test) se encuentran almacenadas en las primeras direcciones de la DRAM. Falso

    La DRAM es no volátil. Se encuentran en la ROM.

57) Una red de colas abierta se puede considerar un caso particular de red de colas cerrada si hacemos que Z=0. Falso.

    Si Z=0 es una red cerrada de tipo Batch o por lotes.

58) Si aplicamos la ley de Little a los usuarios en reflexión de una red de colas cerrada interactiva, podemos relacionar el número medio de usuarios en reflexión con la productividad media del servidor y el tiempo medio de reflexión de dichos usuarios. Verdadero.

    NT=X0x(R0+Z)

59) Si un servidor web ha recibido una media de 10 visitas por segundo, entonces la razón media de visita del servidor es 10 tr/s. Falso.

    El propio servidor no tiene razón media de visita, solo los dispositivos.

60) Si añadimos una segunda CPU a nuestro servidor, idéntica a la ya existente, es razonable suponer que la razón media de visita de la primera CPU se va a dividir en dos. Verdadero.

61) W​i​ =N​i​*S​i es una ley operacional válida para servidores modelados mediante una red de colas abierta en equilibrio de flujo. Falso.

    Se trata la hipótesis de la independencia en la llegada de los trabajos, que no una ley operacional.

