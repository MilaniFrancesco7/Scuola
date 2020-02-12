# Normalizzazione di schemi relazionali

La forma normale di una base di dati è un aspetto che ne garantisce la **qualità** e assicura l'assenza di **ridondanze** e anomalie nelle **fasi di inserimento, modifica e cancellazione**

La forma normale viene definita nel modello ER

## Processo di normalizzazione dello schema

Il processo di normalizzazione è composto da una serie di test che certificano se il modello soddisfa una data forma normale

#### Forme normali esistenti:
- Prima forma normale (1NF)
- Seconda forma normale (2NF)
- Terza forma normale (3NF)
- Forma normale di Boyce e Codd (BCNF)
- Quarta e quinta forma normale (4NF, 5NF)

## Processo di normalizzazione dei dati

Processo di analisi degli schemi forniti, basato sulle loro dipendenze funzionali e sulle chiavi primarie, per raggiungere le proprietà desiderate di:
- **Minimizzazione delle ridondanze**
- **Minimizzazione delle anomalie di:**
	- **Inserimento**
	- **Modifica**
	- **Cancellazione**

## Dipendenza funzionale
Si ha dipendenza funzionale tra attributi quando il valore di un insieme di attributi A determina un singolo valore dell'attributo B

Es. A(Nome, Cognome) -> B(Codice Fiscale)

## Definizioni utili

#### Chiave primaria
Insieme di uno o più attributi che identificano univocamente una tupla di una tabella
#### Chiave candidata
Insieme di uno o più attributi che possono svolgere la funzione di chiave primaria
#### Attributo no chiave
Campo che non fa parte della chiave primaria

# Forme normali

## Prima Forma Normale (1NF)

Il dominio di un attributo (ovvero i valori che può assumere) deve comprendere solo valori atomici (semplici, indivisibili)
e il valore di qualsiasi attributo in una tupla è un valore singolo del dominio

Es. 	Voto
		1Semestre A, 2Semestre B

Normalizzata: 
		Voto	Semestre
		A			1
		B			2

## Seconda Forma Normale (2NF)
Da una relazione già in prima forma normale, tutti i suoi attributi 
devono dipendere dall'intera chiave, cioè non deve possedere attributi che dipendono soltanto da una parte della chiave.

La seconda forma normale elimina così la dipendenza parziale degli attributi della chiave.

Riguarda le tabelle in cui la chiave primaria è composta da più attributi.

## Terza Forma Normale (3NF)
Da una relazione già in prima e seconda forma normale, tutti gli attributi devono dipendere direttamente dalla chiave.
Stabilisce quindi che non esistano dipendenze tra le colonne di una tabella se non basate sulla chiave primaria.

Se un attributo A ne determina un altro B, allora sarà necessario creare un'altra tabella con l'attributo A come chiave.

## Forma Normale di Boyce-Codd
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjg4OTc1MDQ5LDYxOTM3NTkxNV19
-->