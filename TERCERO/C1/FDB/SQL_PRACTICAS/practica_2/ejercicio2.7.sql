start ejercicio1.8.sql;

INSERT INTO Equipos (codE,nombreE,localidad,entrenador,fecha_crea)
    VALUES('001','FBD1','Segovia','Pepe1',SYSDATE);
INSERT INTO Equipos (codE,nombreE,localidad,entrenador,fecha_crea)
    VALUES('002','FBD2','Segovia','Pepe2',SYSDATE);
INSERT INTO Equipos (codE,nombreE,localidad,entrenador,fecha_crea)
    VALUES('003','FBD3','Segovia','Pepe3',SYSDATE);
INSERT INTO Equipos (codE,nombreE,localidad,entrenador,fecha_crea)
    VALUES('004','FBD4','Segovia','Pepe4',SYSDATE);
    
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('001','001','Fernando1');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('002','001','Fernando2');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('003','001','Fernando3');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('004','001','Fernando4');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('005','001','Fernando5');
    
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('006','002','Fernando1');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('007','002','Fernando2');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('008','002','Fernando3');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('009','002','Fernando4');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('010','002','Fernando5');
    
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('011','003','Fernando1');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('012','003','Fernando2');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('013','003','Fernando3');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('014','003','Fernando4');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('015','003','Fernando5');
    
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('016','004','Fernando1');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('017','004','Fernando2');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('018','004','Fernando3');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('019','004','Fernando4');
INSERT INTO Jugadores(codJ,codE,nombreJ)
    VALUES('020','004','Fernando5');
    
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('001','002',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('001','003',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('001','004',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('002','001',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('002','003',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('002','004',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('003','001',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('003','002',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('003','004',SYSDATE);
INSERT INTO Encuentros(ELocal,EVisitante,fecha)
    VALUES('004','001',SYSDATE);
    
UPDATE Encuentros
SET PLocal = 10, PVisitante=0
WHERE(ELocal='001');

UPDATE Encuentros
SET PLocal = 0, PVisitante=10
WHERE(EVisitante='001');

UPDATE Encuentros
SET PLocal = 10, PVisitante=0
WHERE(EVisitante!='001' AND ELocal!='001');

SELECT * FROM Encuentros;

COMMIT;
EXIT;



    
    
