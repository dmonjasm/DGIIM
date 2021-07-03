--Ejemplo 3.1
SELECT ciudad FROM proyecto; --Se aprecia que se admiten los duplicados

--Ejercicio 3.1
SELECT DISTINCT ciudad FROM proyecto; --La opción DISTINCT elimina los duplicados

--Ejemplo 3.2
SELECT * FROM proveedor;
SELECT codpro, nompro, status, ciudad FROM proveedor;

--Ejercicio 3.2
SELECT * FROM ventas;
SELECT codpro, codpie, codpj FROM ventas;
--No es necesrio usar DISTINCT pues las ternas codpro,codpie,codpj son la clave primaria de la tabla ventas, luego son únicas

SELECT DISTINCT codpro,codpie,codpj FROM ventas;
--Sin embargo, se puede apreciar que al usar DISTINCT no supone error

--Ejemplo 3.3
SELECT codpro FROM ventas
WHERE (codpj='J1');

--Ejercicio 3.3
SELECT  * FROM pieza;

SELECT codpie FROM pieza
WHERE (ciudad='Madrid')AND(color='Rojo' OR color='Gris');

--Ejercicio 3.4
SELECT * FROM ventas;

SELECT codpro, codpie, codpj FROM ventas
WHERE (cantidad <= 300) AND (cantidad >= 200);

--Ejemplo 3.4
SELECT nompro, ciudad FROM proveedor
WHERE ciudad LIKE 'L%';

--Ejercicio 3.5
SELECT nompie, codpie FROM pieza
WHERE nompie LIKE '%ornillo';

--Ejemplo 3.5
SELECT cantidad/12, round(cantidad/12,3), trunc(cantidad/12,3), floor(cantidad/12), ceil(cantidad/12)
FROM ventas WHERE (cantidad/12)>10;

--Ejemplo 3.6
SELECT codpro, nompro FROM proveedor
WHERE status IS NOT NULL;

--Ejemplo 3.7
SELECT table_name FROM ALL_TABLES WHERE TABLE_NAME LIKE '%ventas';

--Ejercicio 3.6
--Función UPPER(character_expression) devuelve una expresión de caracteres con datos de caracteres en minúsculas convertidos a mayúsuclas
SELECT TABLE_NAME FROM ALL_TABLES WHERE TABLE_NAME LIKE UPPER('%VENTAS');

--Funcion LOWER(character_expression) devuleve una expresión de caracteres después de convertir en minúculas los datos de caracteres en mayúsculas
SELECT LOWER(TABLE_NAME) FROM ALL_TABLES WHERE TABLE_NAME LIKE UPPER('%ventas');

--Ejemplo 3.8
SELECT DISTINCT ciudad FROM proveedor WHERE status>2
MINUS
SELECT DISTINCT ciudad FROM pieza WHERE codpie='P1';

--Ejercicio 3.7
SELECT DISTINCT ciudad FROM proveedor WHERE status>2
INTERSECT
SELECT DISTINCT ciudad FROM pieza WHERE codpie!='P1';

--Ejercicio 3.8
SELECT * FROM proyecto;
SELECT * FROM ventas;

SELECT codpj FROM ventas WHERE (codpro='S1') --Creo que esta condición no es estrictamente necesaria
MINUS
SELECT DISTINCT codpj FROM ventas WHERE (codpro!='S1');
--A todos los proyectos los provee un proveedor que no sea S1

--Ejercicio 3.9
SELECT ciudad FROM proveedor
UNION 
SELECT ciudad FROM proyecto
UNION
SELECT ciudad FROM pieza;

--Ejercicio 3.10
--UNION ALL no elimina las ciudades duplicadas
SELECT DISTINCT ciudad FROM(
SELECT ciudad FROM proveedor
UNION ALL
SELECT ciudad FROM proyecto
UNION ALL 
SELECT ciudad FROM pieza);

--Ejercicio 3.11
SELECT * FROM ventas, proveedor;
SELECT COUNT(*) FROM ventas, proveedor;

--Ejemplo 3.9
SELECT codpro, codpie, codpj
FROM proveedor,proyecto,pieza
WHERE proveedor.ciudad=proyecto.ciudad
AND proyecto.ciudad = pieza.ciudad;

--Ejemplo 3.10
SELECT codpro, codpie, codpj
FROM proveedor, proyecto, pieza
WHERE proveedor.ciudad='Londres' AND proyecto.ciudad='Londres' 
AND pieza.ciudad='Londres';

--Ejercicio 3.12
SELECT codpro, codpie, codpj
FROM proveedor, proyecto, pieza
WHERE proveedor.ciudad=proyecto.ciudad AND proyecto.ciudad=pieza.ciudad
INTERSECT
SELECT codpro, codpie, codpj
FROM ventas;

--Ejemplo 3.11
SELECT codpro, codpie, codpj
FROM proveedor S, proyecto Y, pieza P
WHERE S.ciudad=Y.ciudad AND Y.ciudad=P.ciudad;

--Ejercicio 3.13
SELECT DISTINCT S.codpro, Y.codpro
FROM proveedor S, proveedor Y
WHERE S.ciudad!=Y.ciudad;

--Ejercicio 3.14
SELECT codpie
FROM pieza
MINUS
SELECT S.codpie
FROM pieza S, pieza Y
WHERE S.peso < Y.peso;

--Ejemplo 3.12
SELECT nompro, cantidad 
FROM proveedor NATURAL JOIN (SELECT * FROM ventas WHERE cantidad>800);

SELECT nompro, cantidad
FROM proveedor s, (SELECT * FROM ventas WHERE cantidad>800) v
WHERE s.codpro = v.codpro; 
--La segunda forma equivale a la reunión natural hecho con selección y proyección

SELECT nompro, cantidad
FROM proveedor s JOIN(SELECT * FROM ventas WHERE cantidad>800) v ON (s.codpro=v.codpro);

--Ejercicio 3.15
SELECT codpie
FROM ventas NATURAL JOIN(SELECT DISTINCT codpro FROM proveedor WHERE proveedor.ciudad='Madrid');

--Ejercicio 3.16
SELECT codpie, ciudad
FROM ventas
NATURAL JOIN(SELECT codpro, codpj, s.ciudad 
FROM proveedor s, proyecto y
WHERE s.ciudad=y.ciudad);

SELECT DISTINCT codpie, ciudad FROM ventas NATURAL JOIN proveedor NATURAL JOIN proyecto;

--Ejemplo 3.13
SELECT nompro
FROM proveedor 
ORDER BY nompro;

--Ejercicio 3.17
SELECT nompro
FROM proveedor;

--Ejercicio 3.18
SELECT *
FROM ventas
ORDER BY cantidad, fecha DESC;

--Ejemplo 3.14
SELECT codpie
FROM ventas
WHERE codpro IN 
    (SELECT codpro FROM proveedor WHERE ciudad='Londres');

--Ejercicio 3.19
SELECT DISTINCT codpie
FROM ventas 
WHERE codpro = ANY(SELECT codpro FROM proveedor WHERE ciudad='Madrid');

SELECT DISTINCT codpie
FROM ventas 
WHERE codpro IN(SELECT codpro FROM proveedor WHERE ciudad='Madrid');
    
--Ejercicio 3.20
SELECT codpj
FROM proyecto 
WHERE ciudad IN (SELECT ciudad FROM pieza);

--Ejercicio 3.21
--solución usando IN
SELECT DISTINCT codpj
FROM proyecto
MINUS
SELECT DISTINCT codpj
FROM ventas
WHERE (codpie IN(SELECT codpie FROM pieza WHERE color='Rojo')) 
AND (codpro IN(SELECT codpro FROM proveedor WHERE ciudad='Londres'));


--solución no usando MINUS
SELECT DISTINCT codpj
FROM proyecto
WHERE codpj NOT IN(SELECT DISTINCT codpj
FROM ventas
WHERE (codpie IN(SELECT codpie FROM pieza WHERE color='Rojo')) 
AND (codpro IN(SELECT codpro FROM proveedor WHERE ciudad='Londres')));


--Solución usando not exists
SELECT DISTINCT codpj
FROM proyecto
WHERE NOT EXISTS(
SELECT DISTINCT codpj
FROM ventas
WHERE (codpie IN(SELECT codpie FROM pieza WHERE color='Rojo')) 
AND (codpro IN(SELECT codpro FROM proveedor WHERE ciudad='Londres'))
AND ventas.codpj=proyecto.codpj);

--Ejercicio 3.15
SELECT codpro
FROM proveedor
WHERE EXISTS (SELECT * FROM ventas
                WHERE ventas.codpro = proveedor.codpro
                AND ventas.codpie='P1');
                
--Ejemplo 3.16
SELECT codpro
FROM proveedor
WHERE status =(SELECT status FROM proveedor WHERE codpro='S3');

--Ejemplo 3.17
SELECT codpie
FROM pieza
WHERE peso > ANY
    (SELECT peso FROM pieza WHERE nompie LIKE 'Tornillo%');
    
--Ejercicio 3.22
SELECT codpie
FROM pieza
WHERE peso > ANY
    (SELECT peso FROM pieza WHERE nompie = 'Tornillo');
    
--Ejercicio 3.23
SELECT codpie
FROM pieza
WHERE peso >= ALL(SELECT peso FROM pieza);
    
--Ejemplo 3.18
(SELECT codpro FROM ventas)
MINUS
(SELECT codpro
    FROM (
            (SELECT v.codpro, p.codpie FROM
                (SELECT DISTINCT codpro FROM ventas) v,
                (SELECT codpie FROM pieza) p
            )
            MINUS
            (SELECT codpro, codpie FROM ventas)
            )
);

--Ejemplo 3.18.2
SELECT codpro
FROM proveedor
WHERE NOT EXISTS(
    (SELECT * FROM pieza
    WHERE NOT EXISTS (SELECT * FROM ventas
                        WHERE pieza.codpie = ventas.codpie
                                AND proveedor.codpro=ventas.codpro)));
                                
--Ejemplo 3.18.3                           
SELECT codpro 
FROM proveedor
WHERE NOT EXISTS(
(SELECT DISTINCT codpie FROM pieza)
MINUS
(SELECT DISTINCT codpie FROM ventas WHERE proveedor.codpro=ventas.codpro));

--Ejercicio 3.24
(SELECT DISTINCT codpie FROM ventas)--Proyección de codpie sobre ventas
MINUS --Quitamos a las piezas que están en ventas aquellas que no han sido proporcionadas a algún proyecto con base en Londres
(SELECT codpie FROM
    (SELECT DISTINCT * FROM                     --Seleccion las parejas pieza, donde la pieza está en ventas y proyecto donde el proyecto tiene sede en Londres
    (SELECT DISTINCT codpie FROM ventas) v,
    (SELECT codpj FROM proyecto WHERE ciudad='Londres') y
    MINUS       --Tras el minus nos quedan las parejas pieza que esta en ventas proyecto que esta en Londres donde esa pareja no está en ventas.
    SELECT DISTINCT codpie, codpj FROM ventas));--Selecciona las parejas pieza proyecto de ventas
    
SELECT DISTINCT codpie 
FROM ventas V1
WHERE NOT EXISTS(
(SELECT DISTINCT codpro FROM proyecto WHERE ciudad='Londres')
MINUS
(SELECT DISTINCT codpro FROM ventas V2 WHERE V1.codpie=V2.codpie));

--Ejercicio 3.25
(SELECT DISTINCT codpro FROM ventas)
MINUS
(SELECT DISTINCT codpro FROM
    (SELECT p.codpro, q.codpie  FROM
        (SELECT DISTINCT codpro FROM ventas) p,
        (SELECT codpie FROM pieza  s JOIN (SELECT * FROM proyecto) v ON (s.ciudad=v.ciudad))q
    MINUS
    (SELECT codpro, codpie FROM ventas)));
    
SELECT DISTINCT codpro
FROM ventas v1
WHERE NOT EXISTS(
(SELECT DISTINCT codpie FROM pieza,proyecto WHERE pieza.ciudad=proyecto.ciudad)
MINUS
(SELECT DISTINCT codpie FROM ventas v2 WHERE v1.codpro=v2.codpro));

--Ejemplo 3.19
SELECT MAX(cantidad), MIN(cantidad), SUM(cantidad) FROM ventas;

SELECT MAX(DISTINCT cantidad), MIN(DISTINCT cantidad), SUM(DISTINCT cantidad) FROM ventas;

--Ejercicio 3.26
SELECT COUNT(*) FROM ventas WHERE cantidad > 1000;

--Ejercicio 3.27
SELECT MAX(peso) FROM pieza;

--Ejercicio 3.28
SELECT codpie FROM pieza WHERE peso=(SELECT MAX(peso) FROM pieza);

--Ejercicio 3.29
SELECT codpie, MAX(peso) FROM pieza;
--No la resuelve la consulta.

--Ejercicio 3.30
SELECT DISTINCT codpro 
FROM proveedor 
WHERE (SELECT COUNT(*) FROM ventas WHERE ventas.codpro = proveedor.codpro) > 3;

--Ejemplo 3.20
SELECT codpro, COUNT(*), MAX(cantidad)
FROM ventas
GROUP BY (codpro);

--Ejercicio 3.31
SELECT AVG(cantidad),nompie
FROM
(SELECT codpie, nompie, cantidad
FROM ventas NATURAL JOIN (pieza))
GROUP BY(codpie,nompie);

--Ejercicio 3.32
SELECT codpro,AVG(cantidad)
FROM ventas
WHERE codpie='P1'
GROUP BY(codpro);

--Ejemplo 3.21
SELECT codpro, AVG(cantidad)
FROM ventas
GROUP BY (codpro)
HAVING COUNT(*) > 3;

--Ejemplo 3.22
SELECT codpro,codpie, AVG(cantidad)
FROM ventas
WHERE codpie='P1'
GROUP BY(codpro, codpie)
HAVING COUNT(*) BETWEEN 2 AND 10;

--Ejemplo 3.23
SELECT v.codpro, v.codpj, j.nompj, AVG(v.cantidad)
FROM ventas v, proyecto j
WHERE v.codpj = j.codpj
GROUP BY (v.codpj, j.nompj, v.codpro);

--Ejercicio 3.33
SELECT codpie, codpj, SUM(cantidad) FROM ventas GROUP BY (codpie,codpj) ORDER BY codpie, codpj;

--Ejercicio 3.34
--Es correcta ya que se hace el producto cartesiano de ventas por proyecto y se toma solo las filas donde los codpj coinciden
--con esto se amplía la información de forma que en cada tupla aparece también el nompj
--de aquí se agrupan en función de las tuplas codpj,codpro,nompj, luego cada una de estas agrupaciones serían todas las ventas de un proveedor
--a un proyecto con nombre nompj independientemente de la pieza que se haya vendido
--y finalmente de cada una de estas agrupaciones se toma el codpro, codpj, nompj y la media de las cantidades de todas las tuplas de la agrupación.
--Como solo pide nompj y cantidad se podría quitar el codpro y codpj
SELECT  v.codpro,j.nompj, AVG(v.cantidad)
FROM ventas v, proyecto j
WHERE v.codpj = j.codpj
GROUP BY (v.codpj, j.nompj, v.codpro);

--Otra forma de escribirlo sería esta que es más simple pero son equivalentes
SELECT codpro, nompj, AVG(cantidad)
FROM ventas NATURAL JOIN(SELECT codpj, nompj FROM proyecto)
GROUP BY(codpro,codpj,nompj);

--Ejercicio 3.35
SELECT nompro, SUM(cantidad)
FROM ventas NATURAL JOIN(proveedor)
GROUP BY nompro,codpro
HAVING SUM(cantidad)>1000;


--Ejemplo 3.24
SELECT codpro, SUM(cantidad)
FROM ventas
GROUP BY codpro 
HAVING SUM(cantidad) = (SELECT MAX(SUM(V1.cantidad))
                        FROM ventas V1
                        GROUP BY V1.codpro);
                        
--Ejercicio 3.36
SELECT codpie
FROM ventas
GROUP BY codpie
HAVING SUM(cantidad)= (SELECT MAX(SUM(v1.cantidad)) FROM ventas v1 GROUP BY codpie);

--Alternativa
SELECT codpie
FROM ventas
GROUP BY codpie
HAVING SUM(cantidad)>= ALL(SELECT SUM(v1.cantidad) FROM ventas v1 GROUP BY codpie);

--Ejemplo 3.25
SELECT TO_CHAR(fecha,'DD-MM-YYYY')
FROM ventas;

--Ejemplo 3.26
SELECT * FROM ventas
WHERE fecha BETWEEN 
TO_DATE('01/01/2012','DD/MM/YYYY')  AND
TO_DATE('31/12/2012','DD/MM/YYYY');


--Ejercicio 3.27
SELECT * FROM ventas
WHERE fecha BETWEEN 
'01/01/2012' AND '31/12/2012';

--Ejemplo 3.27
(SELECT DISTINCT codpie FROM pieza)
MINUS
(SELECT DISTINCT codpie FROM ventas
WHERE TO_NUMBER(TO_CHAR(fecha,'YYYY'))>2001);

SELECT p.codpie FROM pieza p WHERE NOT EXISTS
(SELECT * FROM ventas v WHERE TO_NUMBER(TO_CHAR(v.fecha,'YYYY'))>2001 AND v.codpie=p.codpie);

--Ejemplo 3.28
SELECT TO_CHAR(fecha,'YYYY'), SUM(cantidad)
FROM ventas
GROUP BY TO_CHAR(fecha,'YYYY');

--Ejercicio 3.38
SELECT AVG(cantidad), TO_CHAR(fecha,'MM')
FROM ventas
GROUP BY TO_CHAR(fecha,'MM');

--Ejemplo 3.29
SELECT *
FROM ALL_USERS;

DESCRIBE ALL_USERS;

--Ejemplo 3.30
DESCRIBE DICTIONARY;

SELECT * FROM DICTIONARY
WHERE table_name LIKE '%INDEX%';

--Ejercicio 3.39


--Ejercicio 3.40
SELECT * FROM DICTIONARY;

DESCRIBE USER_TABLES;

SELECT table_name,OWNER FROM USER_TABLES;
                        
--Ejercicio 3.41
SELECT * FROM DICTIONARY;
DESCRIBE USER_OBJECTS;

SELECT object_name, object_type FROM USER_OBJECTS;

--Ejercicio 3.42
SELECT codpro
FROM ventas
GROUP BY codpro
HAVING SUM(cantidad) > (SELECT SUM(cantidad) FROM ventas WHERE codpro='S1');

--Ejercicio 3.43
SELECT codpro, SUM(cantidad)
FROM ventas
GROUP BY codpro 
HAVING SUM(cantidad) = (SELECT MAX(SUM(cantidad)) FROM ventas v GROUP BY v.codpro);

--Variación, Diseñese una consulta que muestre los productores cuyo sumatorio de ventas es el mayor o el segundo mayor
SELECT codpro, SUM(cantidad)      
FROM ventas
GROUP BY codpro 
HAVING SUM(cantidad) >= ALL((SELECT DISTINCT SUM(cantidad) FROM ventas v1 GROUP BY v1.codpro)
                        MINUS
                        (SELECT MAX(SUM(cantidad)) FROM ventas v2 GROUP BY v2.codpro))
ORDER BY 2 DESC;    --El 2 significa que se ordena en función de la segunda columna

SELECT codpro, SUM(cantidad)
FROM ventas
GROUP BY codpro;
                        
--Ejercicio 3.44
SELECT codpro 
FROM proveedor p
WHERE NOT EXISTS(
    SELECT ciudad 
    FROM ventas v1 NATURAL JOIN(proyecto)
    WHERE  v1.codpro='S3'
    MINUS
    SELECT ciudad 
    FROM ventas v2 NATURAL JOIN(proyecto)
    WHERE v2.codpro=p.codpro) AND codpro<>'S3';
    
--Ejercicio 3.45
SELECT codpro, COUNT(*)
FROM ventas 
GROUP BY  codpro
HAVING COUNT(*)>=10;

--Ejercicio 3.46
SELECT DISTINCT codpro
FROM ventas v
WHERE NOT EXISTS(
    SELECT codpie 
    FROM ventas v1
    WHERE v1.codpro='S1'
    MINUS
    SELECT codpie
    FROM ventas v2
    WHERE v2.codpro=v.codpro);
    
--Ejercicio 3.47
SELECT DISTINCT SUM(cantidad)
FROM ventas v
WHERE NOT EXISTS(
    SELECT codpie 
    FROM ventas v1
    WHERE v1.codpro='S1'
    MINUS
    SELECT codpie
    FROM ventas v2
    WHERE v2.codpro=v.codpro)
GROUP BY codpro;

--Ejercicio 3.48
SELECT codpj
FROM proyecto
WHERE NOT EXISTS(
    SELECT codpro
    FROM ventas
    WHERE codpie='P3'
    MINUS
    SELECT codpro
    FROM ventas v1
    WHERE proyecto.codpj= v1.codpj);

--Ejercicio 3.49
SELECT AVG(cantidad), codpro
FROM ventas
WHERE codpie='P3'
GROUP BY codpro;

--Ejercicio 3.50
SELECT * FROM DICTIONARY;

DESCRIBE USER_INDEXES;

SELECT index_name, table_name FROM USER_INDEXES;

--Ejercicio 3.53
SELECT DISTINCT codpro
FROM ventas NATURAL JOIN(pieza)
WHERE color='Rojo';

--Ejercicio 3.54
SELECT codpro
FROM proveedor p 
WHERE NOT EXISTS(
    SELECT codpie
    FROM pieza
    WHERE color='Rojo'
    MINUS
    SELECT codpie
    FROM ventas v WHERE p.codpro=v.codpro);
    
--Ejercicio 3.55
SELECT codpro
FROM ventas p
WHERE NOT EXISTS(
    SELECT *
    FROM ventas NATURAL JOIN(pieza)
    WHERE color!='Rojo' AND p.codpro=ventas.codpro);
    
--Ejercicio 3.56
SELECT codpro
FROM ventas NATURAL JOIN(pieza)
WHERE color='Rojo'
GROUP BY codpro
HAVING COUNT(*)>1;

--Ejercicio 3.57
--Primer intento, bastante ineficiente
SELECT DISTINCT codpro
FROM ventas
WHERE codpro IN(
                SELECT codpro
                FROM proveedor p 
                WHERE NOT EXISTS(
                    SELECT codpie
                    FROM pieza
                    WHERE color='Rojo'
                    MINUS
                    SELECT codpie
                    FROM ventas v WHERE p.codpro=v.codpro))
AND codpro IN(SELECT DISTINCT codpro
                FROM ventas v1
                WHERE NOT EXISTS(
                    SELECT *
                    FROM ventas v2
                    WHERE v1.codpro=v2.codpro AND cantidad <= 10));

--Este método sería el mismo que el anterior cambiando el AND por una intersección de los proveedores que venden todas la piezas rojas
--y además todas su ventas son mayores o iguales que 10
SELECT DISTINCT codpro
FROM ventas
WHERE codpro IN(
                (SELECT codpro
                FROM proveedor p 
                WHERE NOT EXISTS(
                    SELECT codpie
                    FROM pieza
                    WHERE color='Rojo'
                    MINUS
                    SELECT codpie
                    FROM ventas v WHERE p.codpro=v.codpro))
                INTERSECT
                SELECT DISTINCT codpro
                FROM ventas v1
                WHERE NOT EXISTS(
                    SELECT *
                    FROM ventas v2
                    WHERE v1.codpro=v2.codpro AND cantidad <= 10));

--Aquí en lugar de hacer como al principio que codpro se comprueba en dos conjuntos se sustituye el segundo conjunto y la condición de 
--su correspondiente WHERE se incluye como una condición más en el WHERE más exterior
SELECT DISTINCT codpro
FROM ventas v1
WHERE codpro IN(
                SELECT codpro
                FROM proveedor p 
                WHERE NOT EXISTS(
                    SELECT codpie
                    FROM pieza
                    WHERE color='Rojo'
                    MINUS
                    SELECT codpie
                    FROM ventas v WHERE p.codpro=v.codpro))
AND
            NOT EXISTS(
            SELECT *
            FROM ventas v2
            WHERE v1.codpro=v2.codpro AND cantidad <= 10);
            
--Ejercicio 3.59
SELECT codpie
FROM ventas
WHERE codpie NOT IN(
    SELECT codpie
    FROM ventas
    WHERE TO_CHAR(fecha,'mm/yyyy') = '05/2014')
AND TO_CHAR(fecha,'mm/yyyy')='08/2009'
GROUP BY codpie
HAVING SUM(cantidad)=(
                        SELECT MAX(SUM(cantidad))
                        FROM ventas
                        WHERE codpie NOT IN(
                            SELECT codpie
                            FROM ventas
                            WHERE TO_CHAR(fecha,'mm/yyyy') = '09/2009')
                        AND TO_CHAR(fecha,'mm/yyyy')='08/2009'
                        GROUP BY codpie);



                           
COMMIT;
EXIT;
