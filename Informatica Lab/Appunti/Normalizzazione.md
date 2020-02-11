﻿# Normalizzazione di schemi relazionali

## Forme normali

Definizione: Proprietà di uno schema relazionale che ne garantisce la **qualità**, cioè l'**assenza di determinati difetti**

### Relazione non normalizzata: 
- Ridondante
- Comportamenti poco desiderabili durante gli aggiornamenti -> anomalie

### Normalizzazione:
- Attività che permette di trasformare schemi non normalizzati in schemi che soddisfano una forma normale
- Tecnica di verifica dei risultati di progettazione
- **NON**è una tecnica di progettazione

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