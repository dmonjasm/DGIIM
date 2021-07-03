--Ejemplo 4.1
CREATE VIEW VentasParis (codpro,codpie,codpj,cantidad,fecha) AS
    SELECT codpro, codpie, codpj, cantidad, fecha
    FROM ventas
    WHERE (codpro, codpie,codpj) IN 
        (SELECT codpro,codpie,codpj
        FROM proveedor, pieza,proyecto
        WHERE proveedor.ciudad='Paris' AND
            pieza.ciudad='Paris' AND
            proyecto.ciudad='Paris');
            
--Con la siguiente sentencia se puede ver que nuestra vista est� en las vistas del sistema
SELECT * FROM ALL_VIEWS
WHERE view_name='VENTASPARIS'
ORDER BY 2 DESC;

--No aparece nada pues s�lo hay una tupla en nuestra vista, y el proyecto es J3
SELECT DISTINCT codpro 
FROM VentasParis
WHERE codpj='J4';

--Ejemplo 4.2
CREATE VIEW PiezaLondres AS
    SELECT codpie,nompie,color,peso FROM pieza
    WHERE pieza.ciudad='Londres';
    
INSERT INTO PiezaLondres
    VALUES('P9','Pieza 9', 'rojo', 90);
    
--Comando para eliminar vistas DROP VIEW <nombre_vista>
--Para cambiar la definici�n se usa CREATE OR REPLACE VIEW ... <VISTA>

DROP VIEW VentasParis;

--Ejercicio 4.1
DESCRIBE proveedor;
CREATE VIEW ProveedoresLondresErroneo AS
    SELECT codpro,nompro, status,ciudad
    FROM proveedor
    WHERE proveedor.ciudad='Londres';

    
INSERT INTO ProveedoresLondresErroneo   --Aqu� se permite esta inserci�n lo cual no deber�a, pues esta tupla no estar� en la vista
    VALUES ('S7','Jos� Suarez',3,'Granada');
    
DELETE FROM Proveedor WHERE codpro='S7';
    

SELECT * FROM Proveedor;

--La opci�n WITCH CHECK OPTION en el CREATE VIEW indica que se proh�be cualquier camibo en la tabla o vista que produjese filas que no 
--sean incluidas en la subconsulta.

CREATE VIEW ProveedoresLondresCorrecto AS
    SELECT codpro, nompro, status,ciudad
    FROM proveedor
    WHERE proveedor.ciudad='Londres'
WITH CHECK OPTION;

INSERT INTO ProveedoresLondresCorrecto  --Esta sentencia da error, pues esta tupla no entra en la vista ya que la ciudad del proveedor no es Londres
    VALUES ('S7','Jos� Suarez',3,'Granada');
    
--Ejercicio 4.2
CREATE VIEW ProveedorNombreCiudad AS
    SELECT nompro,ciudad 
    FROM proveedor;
    
SELECT * FROM ProveedorNombreCiudad;

INSERT INTO ProveedorNombreCiudad --No se permite realizar ninguna inserci�n, pues en estas no se incluyen clave primaria
    VALUES ('Jos� Suarez', 'Granada'); --por tanto no ser�an diferenciables en la tabla base
    
DELETE FROM ProveedorNombreCiudad WHERE nompro='Jos� Suarez';

UPDATE ProveedorNombreCiudad 
SET ciudad='Segovia' 
WHERE nompro='Maria Reyes';

--Se pueden realizar borrado y actualizaci�n de tuplas, siempre y cuando sea con los atributos de los que dispone la vista

--Ejercicio 4.3
CREATE VIEW CodProNomProCodPJ AS
    SELECT v.codpro,p.nompro,v.codpj
    FROM ventas v,proveedor p,pieza q
    WHERE q.color='Gris' AND p.codpro=v.codpro AND q.codpie=v.codpie;
    
SELECT * FROM CodProNomProCodPJ;

INSERT INTO CodProNomProCodPJ  --Esta sentencia no funciona porque la vista es la reuni�n natural de tres tablas, luego no se puede actualizar 
    VALUES ('S10','Pepe Villuela','J10'); --Habr�a que actualizar varias tablas base pero no se sabe cuales pues la vista se crea sobre la tabla que es la 
    --Reuni�n natural de todas ellas, que se crea en el momento para hacer la vista.
    
COMMIT;
EXIT;