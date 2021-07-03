--Daniel Monjas Miguélez
--Ejercicio 3.57
--Primer intento, bastante ineficiente
--En este archivo se proporcionan tres soluciones, la incial, con intersección y con solo un IN
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