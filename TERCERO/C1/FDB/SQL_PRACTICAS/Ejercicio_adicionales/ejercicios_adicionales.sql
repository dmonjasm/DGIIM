--Ejercicio 1
--a
SELECT codpro
FROM ventas
WHERE codpie='P1' AND fecha>=(SYSDATE-365)
GROUP BY codpro
HAVING SUM(cantidad) = (SELECT MAX(SUM(cantidad)) 
                        FROM ventas
                        WHERE codpie='P1' AND fecha>=(SYSDATE-365)
                        GROUP BY codpro,cantidad);
                        
--b
SELECT DISTINCT v1.codpie
FROM ventas v1, (SELECT * FROM ventas NATURAL JOIN(pieza) WHERE color='Blanco') v2
WHERE v1.codpie=v2.codpie AND v1.codpro!= v2.codpro
GROUP BY v1.codpro, v1.codpie
HAVING COUNT(*)>=2;

--C
SELECT codpj
FROM ventas
WHERE TRUNC(fecha,'yyyy')=TO_DATE('2000','yyyy')
GROUP BY codpj
HAVING AVG(cantidad)>150;

--d
SELECT codpro
FROM ventas NATURAL JOIN(proyecto)
WHERE TO_CHAR(fecha,'mm/yyyy')='01/2020' AND ciudad='Londres'
GROUP BY codpro
HAVING SUM(cantidad) >= (SELECT MAX(SUM(cantidad))
                         FROM ventas NATURAL JOIN(proyecto)
                         WHERE TO_CHAR(fecha,'mm/yyyy')='01/2020' AND ciudad='Londres'
                         GROUP BY codpro);








SELECT *
FROM ventas NATURAL JOIN(proyecto)
ORDER BY fecha DESC;
