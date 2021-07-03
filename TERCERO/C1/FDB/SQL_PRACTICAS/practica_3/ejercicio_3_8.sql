SELECT codpj FROM ventas WHERE codpro='S1'
MINUS
SELECT DISTINCT codpj FROM ventas WHERE (codpro!='S1');

SELECT * FROM ventas;

COMMIT;
EXIT;