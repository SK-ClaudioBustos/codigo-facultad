--Crear Foreign Key

--cuando creamos la tabla
CREATE TABLE tableName (
    ID INT,
    SomeEntityID INT,
    FOREIGN KEY (SomeEntityID)REFERENCES SomeEntityTable(ID)ON DELETE CASCADE
);

--cuando ya creamos la tabla pero nos olvidamos de crear la FK, utilizamos alter
--con fk_name establecemos un nombre a la FK, luego es mas facil borrarla si es necesario
ALTER TABLE  tableName ADD
ADD CONSTRAINT fk_name
FOREIGN KEY (SomeEntityID) REFERENCES SomeEntityTable(ID) ON DELETE CASCADE;

--borrar FK
ALTER TABLE table_name
DROP CONSTRAINT fk_name;

--Crear Primary Key

--cuando creamos la tabla
CREATE TABLE tableName(
    ID INT,
    SomeEntityID INT,
    PRIMARY KEY (ID),
)

--cuando ya creamos la tabla pero nos olvidamos de crear la PK,generalmente se crea igual asignandose
--a al primer campo definido
ALTER TABLE NombreTabla ADD PRIMARY KEY (SID);