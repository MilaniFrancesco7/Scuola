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

## Definizioni utili

#### Chiave primaria
Insieme di uno o più attributi che identificano univocamente una tupla di una tabella
#### Chiave candidata
Insieme di uno o più attributi che possono svolgere la funzione di chiave primaria
#### Attributo no chiave
Campo che non fa parte della chiave primaria
<!--stackedit_data:
eyJoaXN0b3J5IjpbNjE5Mzc1OTE1XX0=
-->