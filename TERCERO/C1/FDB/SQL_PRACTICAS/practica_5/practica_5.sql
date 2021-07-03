SELECT TABLE_NAME,NUM_ROWS, AVG_SPACE FROM USER_TABLES;

--Ejercicio 5.1
DESCRIBE USER_TABLES;

SELECT * FROM USER_INDEXES;

--Ejercicio 5.2
CREATE TABLE acceso (testigo NUMBER);

INSERT INTO acceso VALUES(1);
INSERT INTO acceso VALUES(2);

GRANT SELECT ON acceso TO usuario_derecha;

SELECT * FROM usuario_izquierda.acceso;

REVOKE SELECT ON acceso FROM usuario_derecha;

GRANT SELECT ON acceso TO usuario_derecha WITH GRANT OPTION;

GRANT SELECT ON usuario_izquierda.acceso TO usuario_derecha;

SELECT * FROM usuario_izquierda.acceso;
SELECT * FROM usuario_izquierda_del_usuario_izquierda.acceso;

REVOKE SELECT ON acceso FROM usuario_derecha;
SELECT * FROM usuario_izquierda.acceso;
SELECT * FROM usuario_izquierda_del_usuario_izquierda.acceso;
COMMIT;
EXIT;