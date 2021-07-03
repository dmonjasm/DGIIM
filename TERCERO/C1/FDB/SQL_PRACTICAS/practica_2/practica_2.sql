--Ejemplo 2.1
start introducir_datos;

--Ejemplo 2.2
INSERT INTO plantilla (dni,nombre,estadocivil,fechaalta)
    VALUES ('12345678','Pepe','soltero',SYSDATE);
INSERT INTO plantilla (dni,nombre,estadocivil,fechaalta)
    VALUES ('87654321','Juan','casado',SYSDATE);
INSERT INTO serjefe VALUES ('87654321','12345678');
INSERT INTO plantilla (dni, estadocivil) VALUES ('11223344','soltero');

--Ejercicio 2.1
SELECT * FROM plantilla;
SELECT dni FROM plantilla;
SELECT dni,nombre,estadocivil FROM plantilla;
SELECT * FROM prueba2;
SELECT cad1 FROM prueba2;

--Ejemplo 2.3
UPDATE plantilla
SET estadocivil = 'divorciado'
WHERE nombre='Juan';

--Ejercicio 2.2
UPDATE plantilla 
SET nombre = 'Luis'
WHERE dni = '12345678';

--Ejemlo 2.4
DELETE FROM prueba2;

--Ejercicio 2.3
DELETE FROM plantilla; --Se debe a que de plantilla se toma como clave externa el dni en la tabla ser jefe
DELETE FROM serjefe; --Tras ejecutar esto podríamos efectuar el borrado de tuplas en plantilla

--Ejemplo 2.5
UPDATE plantilla
SET fechaalta = fechaalta+1
WHERE nombre = 'Juan';

SELECT * FROM plantilla;

INSERT INTO plantilla 
    VALUES('11223355','Miguel','casado',TO_DATE('22/10/2005','dd/mm/yyyy'));
    
--Ejemplo 2.6
SELECT TO_CHAR(fechaalta,'dd-month-yyyy') FROM plantilla;

--Ejemplo 2.7
SELECT fechaalta FROM plantilla;

--Seccion 2.2
SELECT * FROM proyecto;
SELECT * FROM opc.ventas;

INSERT INTO ventas SELECT * FROM opc.ventas;

SELECT * FROM ventas;

COMMIT;

--Ejercicio 2.4
INSERT INTO ventas VALUES ('S3','P1','J1',150,'24/12/05');
SELECT * FROM ventas;
INSERT INTO ventas (codpro, codpj) VALUES ('S4','J2'); --La clave primaria de ventas es codpro,codpj,codpie luego no se puede meter codpie NULL
SELECT * FROM ventas;
INSERT INTO ventas VALUES('S5','P3','J6',400,TO_DATE('25/12/00')); --La clave J6 no existe en la tabla proyecto por tanto no se puede meter como calve externa
SELECT * FROM ventas;

--Ejercicio 2.5
UPDATE ventas
SET fecha = TO_DATE(2005,'YYYY')
WHERE codpro='S5';

SELECT * FROM ventas;

--Ejercicio 2.6
SELECT codpro, codpie, TO_CHAR(fecha,'"Dia" day, dd/mm/yy') FROM ventas;

--Seccion 2.3
SELECT table_name FROM user_tables;
ROLLBACK;

DROP TABLE equipos;

COMMIT;
EXIT;