--Ejemplo 6.1
CREATE INDEX indice_proveedores ON proveedor(nompro);

--Ejemplo 6.2
SELECT * FROM user_indexes WHERE index_name LIKE 'INDICE_PROVEEDORES';

DROP INDEX indice_proveedores;

--Ejemplo Indice Inverso

CREATE INDEX indice_proveedores_inverso ON proveedor(nompro) REVERSE;

DROP INDEX indice_proveedores_inverso;

--Índices BITMAP

CREATE TABLE Prueba_bit (color Varchar2(10));

/*BEGIN 
    FOR i IN 1..50000 LOOP
        INSERT INTO Prueba_bit (
        SELECT decode(round(dbms_random.value(1,4)),1,'Rojo',2,'Verde',
        3,'Amarillo',4,'Azul') FROM dual);
        END LOOP;
END;*/

CREATE INDEX Prueba_IDX ON Prueba_Bit(color);

SELECT count(*) FROM Prueba_Bit
WHERE color='Amarrillo' OR color='Azul';

DROP INDEX Prueba_IDX;

DROP TABLE Prueba_bit;

--Tablas Organizadas por Índice (IOT)
CREATE TABLE Prueba_IOT (id NUMBER PRIMARY KEY) ORGANIZATION INDEX;

START carga_prueba_iot.sql;

SELECT id FROM Prueba_IOT;

DROP TABLE Prueba_IOT;


--Cluster
--Ejemplo 6.3
CREATE CLUSTER cluster_codpro(codpro VARCHAR2(3));

DROP CLUSTER cluster_codpro;

CREATE TABLE proveedor2(
    codpro VARCHAR2(3) PRIMARY KEY,
    nompro VARCHAR2(30) NOT NULL,
    status NUMBER(2) CHECK(status>=1 AND status <=10),
    ciudad VARCHAR2(15))
    CLUSTER cluster_codpro(codpro);
    
DROP TABLE proveedor2;

CREATE TABLE ventas2(
    codpro VARCHAR(3) REFERENCES proveedor2(codpro),
    codpie REFERENCES pieza(codpie),
    codpj REFERENCES proyecto(codpj),
    cantidad NUMBER(4),
    fecha DATE,
    PRIMARY KEY (codpro,codpie,codpj))
    CLUSTER cluster_codpro(codpro);
    
DROP TABLE ventas2;
    
CREATE INDEX indice_cluster ON CLUSTER cluster_codpro;

DROP INDEX indice_cluster;

--Ejercicio 6.1
INSERT INTO proveedor2 SELECT * FROM proveedor;
INSERT INTO ventas2 SELECT * FROM ventas;

--Ejercicio 6.2
SELECT * FROM ventas2 NATURAL JOIN(proveedor2) WHERE codpro='S1';

--Ejercicio 6.3
SELECT * FROM DICTIONARY;
SELECT * FROM USER_TABLES;
SELECT * FROM USER_CLUSTERS;
SELECT * FROM USER_INDEXES;

--Cluster hash
CREATE CLUSTER cluster_codpro_hash(codpro VARCHAR2(3)) SIZE 610 HASHKEYS 50;

CREATE TABLE proveedor3(
    codpro VARCHAR2(3) PRIMARY KEY,
    nompro VARCHAR2(30) NOT NULL,
    status NUMBER(2) CHECK(status>=1 AND status <=10),
    ciudad VARCHAR2(15))
    CLUSTER cluster_codpro_hash(codpro);
    
DROP TABLE proveedor3;

CREATE TABLE ventas3(
    codpro VARCHAR(3) REFERENCES proveedor2(codpro),
    codpie REFERENCES pieza(codpie),
    codpj REFERENCES proyecto(codpj),
    cantidad NUMBER(4),
    fecha DATE,
    PRIMARY KEY (codpro,codpie,codpj))
    CLUSTER cluster_codpro_hash(codpro);
    
DROP TABLE ventas3;

--Cluster hash de una sola tabla
--Ejemplo 6.6
CREATE CLUSTER cluster_codpro_single_hash(codpro VARCHAR2(3)) SIZE 50 SINGLE TABLE HASHKEYS 100;

CREATE TABLE proveedor_hash(
    codpro VARCHAR2(3) PRIMARY KEY,
    nompro VARCHAR2(30) NOT NULL,
    status NUMBER(2) CHECK(status>=1 AND status <=10),
    ciudad VARCHAR2(15))
    CLUSTER cluster_codpro_single_hash(codpro);



COMMIT;
EXIT;
