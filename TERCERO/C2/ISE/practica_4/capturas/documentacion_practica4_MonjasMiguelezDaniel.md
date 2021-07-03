# Practica 4: Documentación #
## Ejercicio 1 ##
### Instalación de Phoronix Ubuntu ###
Si bien Phoronix Test Suite está disponible en los repositarios predeterminados de Ubuntu, y por tanto podríamos instalarlo fácilmente con

<code>
sudo apt-get install phoronix -test -suite
</code>

, los paquetes en los repositorios son probablemente muy viejos. por lo tanto, es aconsejable obtener la última versión de la página de descarga oficial. En el momento de realización de esta práctica, la versión estable es la 10.2.2, por tanto ejecutaremos

<code>
wget http://phoronix-test-suite.com/releases/repo/pts.debian/files/phoronix-test-suite_10.2.2_all.deb
</code>

Y tras esto realizaremos la instalación utilizando

<code>
sudo dpkg -i phoronix-test-suite_10.2.0_all.deb
</code>

Tras lo anterior utilizaremos el comando 

<code>
sudo apt -f install
</code>

, para resolver cualquier problema de dependencias.

![Phoronix Instalado](./phoronix_instalado.png)

Para comprobar que hemos instalado Phoronix con éxito podemos utilizar el comando

<code>
phoronix-test-suite help
</code>

, y tras aceptar la licencia de uso nos mostrará una lista de los comandos disponibles.

### Instalación Phoronix CentOS ###
El único requerimento obligatorio para Phoronix Test Suite es PHP CLI, luego lo instalamos con el comando

<code>
sudo yum install php-cli wget
</code>

También debemos instalar wget, para tras esto descargarnos el paquete desde la página.

Tras esto procedemos a descargarnos el paquete de instalación desde la páquina de Phoronix Test Suite, con el comando 

<code>
wget https://phoronix-test-suite.com/releases/phoronix-test-suite-10.2.2.tar.gz
</code>

Ahora lo descomprimimos con 

<code>
tar -xzvf phoronix-test-suite-10.2.2.tar.gz
</code>

y tras esto nos metemos en la carpeta y ejecutamos en el instalador, con los comando 

<code>
cd phoronix-test-suite

sudo ./install-sh
</code>

Una vez hecho esto podemos comprobar que está correctamente instalado con 

<code>
phoronix-test-suite help
</code>

En el caso de que nos ponga que se requiere alguna extensión de PHP para el funcionamiento hacemos

<code>
sudo yum install php-extensión
</code>

Tras instalar todas las dependencias que se nos exigen volvemos a probar el comando anterior y debería funcionar.

### Benchmarking ###
**compress-7zip**

En primer lugar se ha elegido un benchmark de procesador denominado `7-Zip Compression`, el cual tiene un tiempo medio de ejecución de un minuto y medio, y cuya única dependencia es el compilador de C/C++. Para correr el test ejecutamos el comando

<code>
phoronix-test-suite benchmark compress-7zip
</code>

Una vez terminada la ejecución de los Benchmark, como es un benchmark que calcula la velocidad de compresión del procesador, nos muestra el número de compresiones realizadas en las tres ejecuciones que se han realizado.

### UbuntuServer ###
Por su lado UbuntuServer nos ha proporcionado los siguientes datos

![compress-7zipUbuntu_1](./compress_ubuntu.png)
![compress-7zipUbuntu_2](./compress_ubuntu_2.png)

Vemos que en la mejor de las ejecuciones obtiene una puntuación de 3613, mientras que en la peor obtiene una puntuación de 3027.

Además si cogemos la carpeta que contiene los resultados del test y la movemos a la carpeta `/var/www/html/` entonces podremos consultar en el navegador la siguiente información


![info_navegaodr_1](./sysinfo_ubuntu.png)

![info_navegaodr_2](./results_overview_ubuntu.png)

![info_navegaodr_1](./test_results_ubuntu.png)

Podemos ver que en todas las ejecuciones realizadas, la media de UbuntuServer son 3314 puntos

Por otro lado, como configuré zabbix para que monitorizase el uso del procesador podemos ver cual es el uso del mismo


![zabbix_compress](./zabbix_ubuntu.png)

Si nos fijamos en los datos comprendidos entre la `16:05` y las `16:18` vemos que se ve un aumento significativo del uso de la CPU, como cabría esperar durante el tiempo de ejecución del Benchmark.

Aclarar que las horas no coinciden, porque la máquina virtual tiene una hora incorrecta configurada, sin embargo, los minutos si coinciden. También se observa que no pasa en ningún momento la utilización del 90%, luego zabbix no nos va a monitorizar ningún problema, pues el umbral que impone zabbix es el 90% de utilización de la CPU.

### CentOS ###
Por su parte CentOS nos ha proporcionado los siguientes datos

![compress-7zipCentOS_1](./compress_centOS.png)
![compress-7zipCentOS_2](./compress_CentOS_2.png)

Vemos que la mejor de las ejecuciones da 3995 puntos y la peor da 3559 puntos. Además repitiendo el proceso de mover la carpeta de resultados podemos observar que

![info_navegaodr_3](./sysinfo_centos.png)

![info_navegaodr_4](./result_overview_centos.png)

![info_navegaodr_5](./test_results_centos.png)

Podemos ver que la media de las ejecuciones de CentOS son 3784 puntos

Por otro lado, Zabbix nos muestra lo siguiente en cuanto a utilización de la CPU.

![zabbix_compress_CentOS](./zabbix_centos.png)

Si nos fijamos en la franja horaria entre las `16:04` y las `16:17`, que son la hora de inicio y finalización del test, vemos un pico en la uitlización del mismo. Esta vez podemos observar que aunque la utilización de la CPU ha crecido bastante al empezar el test no ha pasado del 66%, mucho menos en comparación con la utilización de la CPU obtenida en Ubuntu.

### Conclusiones ###
Vemos que el resultado obtenido por UbuntuServer es peor que el obtenido por CentOS, a pesar de que la utilización del procesador ha sido mayor (el mejor resultado obtenido por CentOS es un 10.57% mejor que el mejor resultado obtenido por UbuntuServer, siendo la media de CentOS un 14.18% mejor que la media de UbuntuServer). Esto se puede deber entre otras cosas a que como ambas máquinas tienen asignado un único núcleo y, sin embargo, UbuntuServer tiene más funciones que atender, pues es el encargado de monitorizar con Zabbix, la carga extra se deba a la carga de trabajo que pueda suponer Zabbix y la correspondiente monitorización que mantiene. También podemos observar que en comparación con otros resultados a este mismo test obtenidos por procesadores dedicados a servidores nuestro resultado es muy bajo. 

Por ejemplo, fijándonos en el resultado obtenido por un AMD EPYC vemos que su resultado es de 298812, es decir, casi 70 veces mejor que el mejor de nuestros resultados.


**cryptsetup**

Se trata de un benchmark que mide el rendimiento en criptografía del sistema. Es un test cuya única dependencia es tener instalado cryptsetup y tiene una duración media de dos minutos y medio. Además se trata de un test de sistema en contraposición al test de procesador que ya hemos realizado.

### UbuntuServer ###
UbuntuServer nos ha dado por la terminal los siguientes resultados

![terminal_cryptsetup_1](./cryptsetup_UbuntuServer_1.png)

![terminal_cryptsetup_2](./cryptsetup_UbuntuServer_2.png)

Se puede apreciar que la media son `316.8 MiB/s` y la posición en la clasificación.

Por otro lado en la interfaz web se nos muestra

![sysinfo_web](./sysinfo_ubuntu_crypt.png)

![sysinfo_web](./result_overview_ubuntu_crypt.png)
![sysinfo_web](./test_result_ubuntu_crypt.png)
![sysinfo_web](./test_result_ubuntu_crypt_2.png)
![sysinfo_web](./test_result_ubuntu_crypt_3.png)
![sysinfo_web](./test_result_ubuntu_crypt_4.png)
![sysinfo_web](./test_result_ubuntu_crypt_5.png)

Donde nos da información del sistema, una vista general de los resultados obtennidos y un gráfico con los resultados obtenidos para cada tipo de encriptación. Además podemos ver la carga extra que se ha puesto sobre la CPU en zabbix.

![sysinfo_web](./zabbix_ubuntu_crypt.png)

Donde una vez más se puede observar que hay un pico de utilización de la CPU, pero de nuevo no se ha llegado al umbral necesario para que zabbix nos lance un aviso

### CentOS ###
Por su parte CentOS nos muestra por la terminal lo siguiente

![Terminal_centos](./cryptsetup_CentOS_2.png)

![Terminal_centos_2](./cryptsetup_CentOS_3.png)

, donde se puede apreciar que la media obtenida es `323.8 MiB/s`, quedando en un percentil más alto que UbuntuServer, aunque se debe destacar que se han realizado tres ejecuciones más que en UbuntuServer. Por su parte la interfaz web nos muestra lo siguiente

![sysinfo_web](./sysinfo_centos_crypt.png)

![sysinfo_web](./result_overview_centos_crypt.png)
![sysinfo_web](./test_result_centos_crypt.png)
![sysinfo_web](./test_result_centos_crypt_2.png)
![sysinfo_web](./test_result_centos_crypt_3.png)
![sysinfo_web](./test_result_centos_crypt_4.png)
![sysinfo_web](./test_result_centos_crypt_5.png)

, donde nos muestra la información del sistema sobre el que se ha realizado el Benchmark, una vista general de los resultado y los resultados obtenidos de forma particular para cada una de las encriptaciones disponibles.

Por otro lado, zabbix nos muestra

![sysinfo_web](./zabbix_centos_crypt.png)

Nos muestra que tras un pico del 100% que tiene debido a la instalación de dependencias que se ha realizado, tras esto parte de una utilización cercana al 0%, que tras empezar el test sube rápidamente hasta una utilización entrono al 60%, muy similar a la obtenida en el test anterior.

### Conclusiones ###
De nuevo CentOS nos proporciona unos resultados un poquito mejor que el obtenido por UbuntuServer (entorno al 2.21%), con una utilización de la CPU menor. De nuevo se considera que esa utilización de CPU mayor en UbuntuServer se debe a la tarea por parte de zabbix de monitorizar tanto a si mismo como a CentOS. 

## Ejercicio 2 ##
Una vez he instalado la aplicación `iseP4JMeter` en la máquina virtual e instalado JMeter en mi ordenador abro la aplicación y defino dos variables de usuario

![Jmeter-1](./JMeter_1.png)

Tras esto añado un `HTTP Authorization Manager` que lo denomino Acceso ETSII API y le añado los siguiente parámetros

![Jmeter-2](./JMeter_2.png)

Con esto tenemos guardados en dos variables la IP del servidor y el puerto. También tenemos que en los mensajes HTTP, en la cabecera, se ha especificado `Content-Type: application/x-www-form-urlencode` y además se ha definido la autenticación básica para acceder a la API de la ETSII.

Ahora añado al test plan dos grupos de hebras, uno que denominaremos Alumnos y otro que denominaremos Administradores, dejando de momento los parámetros que traen por defecto.

Al grupo Alunos, le hacemos `Add->Config Element->CSV Data Set Config` al cual denominaremos **Credenciales Alumnos** y cuyos campos rellenaremos como sigue

![Jmeter-4](./JMeter_4.png)

Es especialmente importante cambiar el campo de ignorar primera línea a true, pues la primera línea tiene escrito login y password, lo cual nos dará un error.

Tras esto creamos un `HTTP Request` en el grupo Alumnos haciendo `Add->Sampler->HTTP Request`, y la denominamos Login Alumno. Como más adelante crearemos varias peticiones HTTP todas dirigidas al mismo host y al mismo puerto vamos a crear en el test plan un `HTTP Request Defaults` el cual rellenamos así

![Jmeter-5](./JMeter_5.png)

Con esto tendremos que todas las peticiones HTTP irán dirigidas a la dirección contenida en la variables HOST y al puerto contenido en la variable PORT.

Siguiendo con Login Alumno, lo rellenamos como sigue,

![Jmeter-6](./JMeter_6.png)

, donde nuestra HTTP Request tendrá dos parámetros, login y password, cuyos valores son obtenidos del archivos de credenciales alumnos.csv. Además vemos que en path vamos a hacer login.

Ahora veamos para extraer el Token que nos devuelve la API al HTTP Request le añadimos un `Regular Expression Extractor`, para ello hacemos sobre Login Alumno `Add->Post Processors->Regular Expression Extractor`, al cual denominaremos Token Devuelto y rellenaremos sus campos como sigue

![Jmeter-7](./JMeter_7.png)

, donde hemos indicado que se almacene en la variable `token_alumno` el valor de lo que devuelva la API, la expresión regular indica que se coja todo y el template que se cojan todos los subgrupos.

Para comprobar si de momento funciona todo bien le añadimos al grupo Alumnos un Listener View Results Tree, para ello hacemos sobre Alumno `Add->Listener->View Results Tree` y le damos a ejecutar el test. 

![Jmeter-8](./JMeter_8.png)

Si nos da error depuramos viendo que ha podido fallar. Por ejemplo, mi primer login ha dado error porquen no había indicado el path en login alumno.

Ahora hacemos otra petición HTTP, esta vez para recoger los datos del alumno concreto y lo denominaremos Recuperar Datos Alumnos, y lo rellenamos como sigue

![Jmeter-9](./JMeter_9.png)

Sin embargo, si ahora probamos el test nos dará error

![Jmeter-10](./JMeter_10.png)

, esto se debe a que no hemos pasado en la cabecer el token que nos ha devuelto en el login, para añadirlo sobre la petición HTTP Recuperar Datos Alumnos añado un HTTP Header Manager y lo rellenamos como sigue

![Jmeter-11](./JMeter_11.png)

Y ahora si probamos de nuevo el test ya debería funcionar.

![Jmeter-12](./JMeter_12.png)

Efectivamente. Por último añadimos la espera que nos indica el enunciado añadiendo a alumnos un timer haciendo `Add->Timer->Gaussian Random Timer` que denominamos espera.

Para el grupo de administradores repetimos el proceso, cambiando el archivo de credenciales.

![Jmeter-13](./JMeter_13.png)

![Jmeter-14](./JMeter_14.png)

![Jmeter-15](./JMeter_15.png)

Con esto ya podemos probar si el login es correcto

![Jmeter-16](./JMeter_16.png)

Al principio me había dado error, pues la cabecera del HTTP Request había puesto GET, en lugar de POST. Llegados a este punto es donde varía de alumnos. En lugar de crear un nuevo HTTP Request, creamos un Acceso Log Samples, para ello en administradores hacemos `Add->Sampler->Access Log Sampler` que rellenamos como sigue

![Jmeter-17](./JMeter_17.png)

, y al igual que hicimos con Recuperar Datos Alumnos tenemos que hacer un HTTP Header Manager al que le pasamos el token que nos devuelve la API al identificarnos como administradores. Y lo rellenamos como sigue

![Jmeter-18](./JMeter_18.png)

Una vez hecho esto ya tendríamos nuestro test listo para ejecutar. Antes de ejecutar al test le añadimos test listenerse `Add->Listener->Summary Report`, `Add->Listener->View Results in Table` y `Add->Listener->Aggregate Report` (podemos añadir también un View Results Tree, pero aconsejo desactivarlo, pues con muchas peticiones ralentiza bastante), con los cuales comprobaremos que nuestro test es correcto. Además en alumnos y en administradores vamos a actualizar los parámetros Number of Threads y Ramp-up period, a 500 y 5 respectivamente, de forma que nuestro test mandará 100 peticiones por segundo durante cinco segundos de alumnos y análogo con administradores. Con esto podemos ejecutar nuestro test.

![Jmeter-19](./JMeter_19.png)

![Jmeter-20](./JMeter_20.png)

![Jmeter-21](./JMeter_21.png)

En el Summary Report se puede apreciar que se han realizado 500 peticiones de Login Alumno, Login Administradores, Recuperar Datos y luego un http://dir_ip que se corresponde con Acceso Administradores. También se aprecia que el porcentaje de error en las cuatro filas es 0 así como el total.

Si vamos a View Results in Table vemos que de nuevo nos muestra status en verde en todas las peticiones aunque solo se vean unas pocas en la imagen

en cuanto al Agregate Report podemos apreciar lo mismo, que el error obtenido es 0 y otras información como los KB/sec recibidos y enviados, etc.

Recalcar que se ha eliminado el HTTP Header Manager Basic-Auth Api que se ven en varias imágenes, pues el único parámetro que incluia era `Content-Type: application/x-www-form-urlencoded`, que es el por defecto en JMeter, y porque este generaba error en Acceso Administradores.

Por último veamos como estresa nuestra aplicación (aumentaré un poco el número de peticiones y segundos), para ello vamos en el navegador a la siguiente dirección

<code>
http://192.168.56.105:3000/status
</code>

![Jmeter-22](./JMeter_22.png)

Para esta prueba he establecido un test en el que acceden 100 usuarios de cada tipo (admin y alumnos) cada segundo durante 50 segundos. Vemos que la utilización de la CPU se encuentra entorno al 75%, luego nuestro servidor podría servir unas pocas más peticiones por segundo. También se ve que el status code por lo general es del tipo 2xx, es decir, de ejecución correcta.

Con esto se concluye el ejercicio 2.

## Ejercicio Opcional. Ejecutar un test de Phoronix usando Docker en nuestro ordenador anfitrión ##
En primer lugar tenemos que instalar Docker en nuestra máquina, para ello se recomienda seguir los pasos de <https://help.wnpower.com/hc/es/articles/360048910771-C%C3%B3mo-instalar-Docker-en-tu-servidor-con-Ubuntu>

Tras esto procedemos a descargar una imagen de Docker llamada phoronix/pts con el comando 

<code>
docker pull phoronix/pts
</code>

![opcional](./opcional1_1.png)

Una vez instalado lanzamos el docker con el comando

<code>
sudo docker run -it phoronix/pts
</code>

Con esto llegaremos a una pantalla similar a esta

![opcional](./opcional1_2.png)

Y dese aquí ejecutamos el comando

<code>
benchmark compress-7zip
</code>

, que se corresponde con un test de procesador ejecutado en el ejercicio 1. Abrimos el monitor del sistema para comprobar la utilización del procesador durante la ejecución del test.

![opcional](./opcional_1_3.png)
![opcional](./opcional_1_4.png)
![opcional](./opcional_1_5.png)

![opcional](./opcional1_resultados.png)
![opcional](./opcional1_resultados_2.png)

En las tres imágenes del monitor del sistema se ve que las ocho hebras de mi portátil se encuentran en valores cercanos o iguales al 100% de utilización. Al inicio de las segunda y tercera imágenes se ven dos grandes surcos de utilización de la CPU, uno en cada una de las imágenes, esto se debe a al finalización de las ejecuciones de una de la pruebas y el comienzo de la siguiente.

Si nos fijamos estrictamente en las puntuaciones obtenidas, mi ordenador ha obtenido unas puntuaciones muy superiores a las que nos han proporcionado ambas máquinas virtuales, en particular el mejor resultado por mi ordenador es 3.85 veces mejor que el obtenido en el mejor resultado de la máquina UbuntuServer, y 3.48 veces mejor que el mejor resultado obtenido por la máquina CentOS.
 
El resultado era algo evidente, pues mi portátil utiliza los 8 núcleos en lugar de el núcleo único que utilizan las máquinas virtuales.

