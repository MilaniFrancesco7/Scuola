# Normalizzazione di schemi relazionali

La forma normale di una base di dati è un aspetto che ne garantisce la **qualità** e assicura l'assenza di **ridondanze** e anomalie nelle **fasi di inserimento, modifica e cancellazione**

La forma normale viene definita nel modello ER

## Processo di normalizzazione

Il processo di normalizzazione è composto da una serie di test che certificano se il modello soddisfa una data forma normale

#### Forme normali esistenti:
- Prima forma normale (1FN)
- Seconda forma normale (2FN)
- Terza forma normale (3FN)
- Forma 

## Dipendenze funzionali
- Tipo di vincolo (FD)

Considerando 
- Un'istanza r di uno schema R(X)
- Due sottoinsiemi di attributi Y e Z di X
- In r vale la dipendenza funzionale Y -> Z (Y determina funzionalmente Z) se:
	- per ogni coppia di tuple t1 e t2 di r con gli stessi valori su Y, t1 e t2 hanno gli stessi valori anche su Z


## Esempi di FD

Impiegato -> Stipendio
Progetto -> Bilancio
Impiegato, Progetto -> Funzione

Banale: Impiegato,Progetto -> Progetto

Y -> A è non banale se A non appartiene a Y
Y -> Z è non banale se nessun attributo in Z appartiene a Y

### Anomalie e FD

Problematiche
Impiegato -> Stipendio
Progetto -> Bilancio

Non problematica
Impiegato, Progetto -> Funzione

- Le prime due FD non hanno sulla sinistra una chiave e causano anomalie
- La terza FD ha sulla sinistra una chiave e non causa anomalie

## Seconda forma normale (2NF)

- Per evitare le anomalie
- Definizione:
	- Uno schema R(X) è in seconda forma normale se e solo se ogni attributo non primo ( Non appartenente a nessuna chiave )
	 dipende completamente da ogni chiave ( Non dipende solo da una parte ) 
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE0Mjg5NzI0MTRdfQ==
-->