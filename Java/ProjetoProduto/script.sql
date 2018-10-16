CREATE TABLE categoria(
	idcategoria SERIAL,
	desccategoria VARCHAR(200),
	CONSTRAINT pkcategoria PRIMARY KEY (idcategoria)
	);

CREATE TABLE produto(
	idprod SERIAL,
	descprod VARCHAR(200),
	valor NUMERIC(9,2),
	marca VARCHAR(200),
	idcategoria INTEGER NOT NULL,
	CONSTRAINT pkprod PRIMARY KEY (idprod),
	CONSTRAINT fkcategoria FOREIGN KEY (idcategoria) REFERENCES categoria
	);

INSERT INTO categoria VALUES (DEFAULT, 'CATEGORIA 1');
INSERT INTO categoria VALUES (DEFAULT, 'CATEGORIA 2');
INSERT INTO categoria VALUES (DEFAULT, 'CATEGORIA 3');
INSERT INTO categoria VALUES (DEFAULT, 'CATEGORIA 4');
INSERT INTO categoria VALUES (DEFAULT, 'CATEGORIA 5');


INSERT INTO produto VALUES (DEFAULT, 'PRODUTO 1', 100.00, 'MARCA', 5);
INSERT INTO produto VALUES (DEFAULT, 'PRODUTO 2', 500.00, 'MARCA', 4);
INSERT INTO produto VALUES (DEFAULT, 'PRODUTO 3', 200.00, 'MARCA', 3);
INSERT INTO produto VALUES (DEFAULT, 'PRODUTO 4', 300.00, 'MARCA', 2);
INSERT INTO produto VALUES (DEFAULT, 'PRODUTO 5', 1000.00,'MARCA', 1);


SELECT * FROM produto JOIN categoria USING (idcategoria) ORDER BY idprod;



SELECT * FROM  categoria order by idcategoria;
