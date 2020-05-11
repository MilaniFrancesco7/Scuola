-- Francesco Milani
-- 5AI
-- 040320
--
-- Esercizio Esame 2013 

-- Creazione tabelle

CREATE TABLE Passeggero(
	Documento int(11) NOT NULL AUTO_INCREMENT,
	Nome varchar(14) NOT NULL,
	Cognome varchar(14) NOT NULL,
	Nazionalita varchar(14) NOT NULL,
	PRIMARY KEY (Documento)
);

CREATE TABLE Viaggio(
	Codice int(11) NOT NULL AUTO_INCREMENT, 
	Aeroporto_Part varchar(20) NOT NULL,
	Aeroporto_Dest varchar(20) NOT NULL,
	motivo varchar(20) NOT NULL,
	Codice_Passeggero int(11) NOT NULL,
	PRIMARY KEY (Codice),
	FOREIGN KEY (Codice_Passeggero) REFERENCES Passeggero(Documento)
);

CREATE TABLE Categoria(
	Codice int(11) NOT NULL AUTO_INCREMENT,
	Nome varchar(30) NOT NULL,
	PRIMARY KEY (Codice)
);

CREATE TABLE Merce(
	Codice int(11) NOT NULL AUTO_INCREMENT,
	Descrizione varchar(30) NOT NULL,
	Quantita int(11) NOT NULL,
	Codice_Passeggero int(11) NOT NULL,
	Codice_Categoria int(11) NOT NULL,
	PRIMARY KEY (Codice),
	FOREIGN KEY (Codice_Passeggero) REFERENCES Passeggero(Documento),
	FOREIGN KEY (Codice_Categoria) REFERENCES Categoria(Codice)
);

CREATE TABLE Punto_Controllo(
	Codice int(11) NOT NULL AUTO_INCREMENT,
	Posizione varchar(20) NOT NULL,
	PRIMARY KEY (Codice)
);

CREATE TABLE Addetto(
	Codice int(11) NOT NULL AUTO_INCREMENT,
	Nome varchar(20),
	Cognome varchar(20),
	PRIMARY KEY (Codice)
);

CREATE TABLE Controllo(
	Codice int(11) NOT NULL AUTO_INCREMENT,
	Data_In date NOT NULL,
	Ora_In time NOT NULL,
	Data_Fin date NOT NULL,
	Ora_Fin time NOT NULL,
	Esito varchar(20) NOT NULL,
	Dazio int(11) NOT NULL,
	Codice_Merce int(11) NOT NULL,
	Codice_Punto int(11) NOT NULL,
	Codice_Addetto int(11) NOT NULL,
	Note varchar(30) NOT NULL,
	Contestazione int(2) NOT NULL,
	PRIMARY KEY (Codice),
	FOREIGN KEY (Codice_Merce) REFERENCES Merce(Codice),
	FOREIGN KEY (Codice_Punto) REFERENCES Punto_Controllo(Codice),
	FOREIGN KEY (Codice_Addetto) REFERENCES Addetto(Codice)
);


-- Inserimento dati

INSERT INTO Passeggero(Nome,Cognome,Nazionalita) VALUES
("Francesco","Milani","Italia"),
("Filippo","Inzaghi","Italia"),
("Simon","Kjaer","Danimarca"),
("Rafael","Leao","Portogallo"),
("Zlatan","Ibrahimovic","Svezia"),
("Lucas","Paqueta","Brasile"),
("Hakan","Calhanoglu","Turchia"),
("Theo","Hernandez","Francia"),
("Mateo","Musacchio","Argentina"),
("Samuel","Castillejo","Spagna");

INSERT INTO Viaggio(Aeroporto_Part,Aeroporto_Dest,motivo,Codice_Passeggero) VALUES
("Venezia","Bergamo","Lavoro",1),
("Milano","Barcellona","Lavoro",2),
("Siviglia","Londra","Trasferimento",3),
("Lisbona","Parigi","Turismo",4),
("Manchester","Los Angeles","Trasferimento",5),
("Roma","Monaco","Lavoro",6),
("Istanbul","Milano","Turismo",7),
("Madrid","Milano","Lavoro",8),
("Berlino","Lecce","Turismo",9),
("Napoli","Torino","Trasferimento",10);

INSERT INTO Categoria(Nome) VALUES
("Abbigliamento"),
("Alimentari"),
("Dispositivi Elettronici"),
("Animali"),
("Medicinali");

INSERT INTO Merce(Descrizione,Quantita,Codice_Passeggero,Codice_Categoria) VALUES
("Scarpe",3,1,1),
("Pasta",4,2,2),
("Laptop",1,3,3),
("Cane",1,4,4),
("Tachipirina",7,5,5),
("Felpa",5,6,1),
("Carne",9,7,2),
("Smartphone",1,8,3),
("Gatto",1,9,4),
("Aerius",10,10,5);

INSERT INTO Punto_Controllo(Posizione) VALUES
("Nord"),
("Sud"),
("Ovest"),
("Est");

INSERT INTO Addetto(Nome,Cognome) VALUES
("Paolo","Maldini"),
("Zvonimir","Boban"),
("Ivan","Gazidis"),
("Stefano","Pioli");

INSERT INTO Controllo(Data_In,Ora_In,Data_Fin,Ora_Fin,Esito,Dazio,Codice_Merce,Codice_Punto,Codice_Addetto,Note,Contestazione) VALUES
('2012-01-20','12:55:00','2012-01-20','13:10:00',"Nessuna segnalazione",0,1,1,1,"",0),
('2012-01-20','13:10:00','2012-01-20','14:10:00',"Merce respinta",200,2,2,2,"Alimento vietato",1),
('2012-01-20','15:55:00','2012-01-20','16:10:00',"Fermo passeggero",1000,3,3,3,"Informazioni rubate",1),
('2012-01-21','12:55:00','2012-01-21','13:10:00',"Nessuna segnalazione",0,4,1,1,"",0),
('2012-01-21','13:55:00','2012-01-21','14:10:00',"Fermo passeggero",500000,5,1,1,"Sostanze stupefacenti",1),
('2012-01-21','14:55:00','2012-01-21','15:10:00',"Merce respinta",3000,6,2,2,"Materiali vietati",1),
('2012-01-21','15:55:00','2012-01-21','16:10:00',"Nessuna segnalazione",0,7,3,3,"",0),
('2012-01-22','12:55:00','2012-01-22','13:10:00',"Nessuna segnalazione",0,8,4,4,"",0),
('2012-01-22','13:55:00','2012-01-22','14:10:00',"Fermo passeggero",1000000,9,1,1,"Sostanze stupefacenti",1),
('2012-01-23','12:55:00','2012-01-23','13:10:00',"Merce respinta",70000,10,2,2,"Sostanze vietate",1),
('2012-01-23','13:55:00','2012-01-23','14:10:00',"Nessuna segnalazione",0,1,2,2,"",0),
('2012-01-23','14:55:00','2012-01-23','15:10:00',"Nessuna segnalazione",0,1,3,3,"",0),
('2012-01-23','15:55:00','2012-01-23','16:10:00',"Fermo passeggero",10000,1,4,4,"Sostanze stupefacenti",1),
('2012-01-24','12:55:00','2012-01-24','13:10:00',"Nessuna segnalazione",0,4,2,2,"",0),
('2012-01-24','13:55:00','2012-01-24','14:10:00',"Nessuna segnalazione",0,4,3,3,"",0),
('2012-01-24','14:55:00','2012-01-24','15:10:00',"Merce respinta",0,4,4,4,"Materiali vietati",1);




------------- QUERY RICHIESTE ---------------
/*
1. 	SELECT Passeggero.*,Punto_Controllo.Codice AS Codice.Controllo, Punto_Controllo.Posizione
   	FROM Passeggero
   	INNER JOIN Merce
   	ON Merce.Codice_Passeggero=Passeggero.Documento
   	INNER JOIN Controllo
   	ON Controllo.Codice_Merce=Merce.Codice
	INNER JOIN Punto_Controllo
	ON Punto_Controllo.Codice=Controllo.Codice_Punto
	ORDER BY Passeggero.Documento;

2.	SELECT Punto_Controllo.*, SUM(Controllo.Dazio) AS Totale_Dazio
	FROM Punto_Controllo
	INNER JOIN Controllo
	ON Punto_Controllo.Codice=Controllo.Codice_Punto
	GROUP BY Punto_Controllo.Codice

3.	SELECT Categoria.Nome, COUNT(Controllo.Codice_Merce) AS Totale_Merce
	FROM Categoria
	INNER JOIN Merce
	ON Merce.Codice_Categoria=Categoria.Codice
	INNER JOIN Controllo
	ON Controllo.Codice_Merce=Merce.Codice
	WHERE Controllo.Dazio>0
	GROUP BY Merce.Codice_Categoria;

4.	SELECT Addetto.Nome, Addetto.Cognome, COUNT(Controllo.Contestazione) AS Totale_Contestazioni
	FROM Addetto
	INNER JOIN Controllo
	ON Controllo.Codice_Addetto=Addetto.Codice
	WHERE Controllo.Contestazione=1
	GROUP BY Addetto.Codice;

5. 	SELECT Punto_Controllo.*, AVG(TIMESTAMPDIFF(minute, Controllo.Ora_In, Controllo.Ora_Fin)) AS Durata_Media
	FROM Punto_Controllo
	INNER JOIN Controllo
	ON Controllo.Codice_Punto=Punto_Controllo.Codice
	GROUP BY Punto_Controllo.Codice;

6.	SELECT Passeggero.*
	FROM Passeggero
	INNER JOIN Merce
	ON Merce.Codice_Passeggero=Passeggero.Documento
	INNER JOIN Controllo
	ON Controllo.Codice_Merce=Merce.Codice
	WHERE Controllo.Esito="Fermo Passeggero"
	ORDER BY Passeggero.Nazionalità, Passeggero.Cognome, Passeggero.Nome;
*/