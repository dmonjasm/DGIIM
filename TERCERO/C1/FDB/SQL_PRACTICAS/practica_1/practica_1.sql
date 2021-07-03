set pause on;
set pause '.....Pulsa una tecla para continuar.....';
CREATE TABLE prueba1(
    cad char(3),
    n int,
    x float);
DESCRIBE PRUEBA1;
DESCRIBE PRUEBA2;

CREATE TABLE plantilla(
    dni varchar2(9),
    nombre varchar2(15),
    estadocivil varchar2(10)
        CHECK(estadocivil IN ('soltero', 'casado', 'divorciado', 'viudo')),
    fechaalta DATE,
    PRIMARY KEY(dni));
DESCRIBE plantilla;


CREATE TABLE serjefe(
    dnijefe REFERENCES plantilla(dni),
    dnitrabajador REFERENCES plantilla(dni),
    PRIMARY KEY(dnitrabajador));
DESCRIBE serjefe;

DROP TABLE PRUEBA1;
DESCRIBE PRUEBA1;

ALTER TABLE plantilla ADD fechabaja date;
DESCRIBE plantilla;

@proveedor;

start pieza;

start proyecto;

start ventas;

select table_name from user_tables;

COMMIT;
EXIT;
