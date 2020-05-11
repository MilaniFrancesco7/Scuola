 # Comandi MySQL

### Accedere al database
- mysql -h contabile.fermi.intra -u s01244 -p
- bae2deiX
 
### Far vedere i database presenti
- show databases; 	

### Utilizzare un database
- use "Nomedatabase"; 	

### Mostra le tabelle presenti nel database
- show tables; 					

### Mostrare tutto da una tabella		
- select * from "nometabella";

### Mostrare qualcosa tramite attributo
- select * from "nometaballa" where "attributo";

#### Select con altri aggettivi
- select * from "nometabella" where "attributo" LIKE B___Y (con spazi, quindi contato)
- LIKE B%Y (non contato)

### importare un file SQL in MySQL

- mysql> source file.sql
- mysql> .\ file.sql

### Crea una tabella

- mysql> create table employee (Name char(20),Dept char(20),jobTitle char(20));

### Vedi la tabella appena creata

- mysql> DESCRIBE employee;  -> Stessa cosa di " show columns from employee; "

        +----------+----------+------+-----+---------+-------+
        | Field    | Type     | Null | Key | Default | Extra |
        +----------+----------+------+-----+---------+-------+
        | Name     | char(20) | YES  |     | NULL    |       |
        | Dept     | char(20) | YES  |     | NULL    |       |
        | jobTitle | char(20) | YES  |     | NULL    |       |
        +----------+----------+------+-----+---------+-------+
        3 rows in set (0.03 sec)

### Mostra le tabelle
- mysql> show tables;
        +-------------------+
        | Tables_in_bedrock |
        +-------------------+
        | employee          |
        +-------------------+

### Aggiungi dati

- mysql> INSERT INTO employee VALUES ('Fred Flinstone','Quarry Worker','Rock Digger');

### Eliminare la tabella

- mysql> DROP TABLE employee

### Aggiornare una riga
- mysql> update employee set jobTitle='Neightbor' were NAME="Fred Flinstone";


### Creazione tabella 

CREATE TABLE insurances(    //Non mettere mai accenti, buona norma usare nomi singolari

### Modifica tabella
- ALTER TABLE employee ADD EmpId
- ALTER TABLE employee DROP EmpId