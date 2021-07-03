DROP TABLE Faltas;
DROP TABLE Encuentros;
DROP TABLE Jugadores;
DROP TABLE Equipos;

CREATE TABLE Equipos(
    codE VARCHAR2(3) CONSTRAINT condE_primaria PRIMARY KEY CONSTRAINT codE_nonulo NOT NULL,
    nombreE VARCHAR2(30) CONSTRAINT nombreE_nonulo NOT NULL,
    localidad VARCHAR2(30) CONSTRAINT localidad_nonulo NOT NULL,
    entrenador VARCHAR2(30) CONSTRAINT entreandor_nonulo NOT NULL,
    fecha_crea DATE CONSTRAINT fecha_crea_nonulo NOT NULL);
    
CREATE TABLE Jugadores(
    codJ VARCHAR2(4) CONSTRAINT codJ_primaria PRIMARY KEY,
    codE CONSTRAINT codE_externa REFERENCES Equipos(codE) CONSTRAINT codE_nonulo_jugadores NOT NULL,
    nombreJ VARCHAR2(30) CONSTRAINT nombreJ_nonulo NOT NULL);
    
CREATE TABLE Encuentros(
    ELocal CONSTRAINT ELocal_externa REFERENCES Equipos(codE),
    EVisitante CONSTRAINT EVisitante_externa REFERENCES Equipos(codE),
    fecha date,
    PLocal INT DEFAULT 0 CONSTRAINT PLocal_mayor_igual_0 CHECK (PLocal >= 0),
    PVisitante INT DEFAULT 0 CONSTRAINT PVisitante_mayor_igual_0 CHECK( PVisitante >= 0),
    PRIMARY KEY(ELocal,EVisitante));
    
CREATE TABLE Faltas(
    codJ CONSTRAINT codJ_externa REFERENCES Jugadores(codJ),
    ELocal VARCHAR2(3),
    EVisitante VARCHAR2(3),
    num INT DEFAULT 0 CONSTRAINT num_mayor_igual_0 CHECK(0<=num and num<=5),
    FOREIGN KEY(Elocal,EVisitante) REFERENCES Encuentros(ELocal,EVisitante),
    PRIMARY KEY(codJ, ELocal, EVisitante));
 
SELECT TABLE_NAME FROM user_tables;   
DESCRIBE Equipos;
DESCRIBE Jugadores;
DESCRIBE Encuentros;
DESCRIBE Faltas;
COMMIT;
EXIT;