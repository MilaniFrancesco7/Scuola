# Studio di fattibilità software gestionale laboratori di chimica

## Descrizione del progetto

Il laboratorio di chimica dell'ITIS E. Fermi di Bassano del Grappa è provvisto di reagenti, vetreria e varie attrezzature.
Ad oggi il tracciamento di ogni singolo componente è stato fatto tramite un semplice file di testo, dove ogni professore avrebbe dovuto inserire i materiali utilizzati e le varie quantità, le loro posizioni all'interno degli armadi e le eventuali mancanze.
Tutto ciò avviene in maniera sporadica, infatti molti professori non aggiornano il file, portando quindi a continue differenze per esempio tra le quantità registrate e le quantità effettivamente presenti in aula. 
Per questo ci è stato richiesto di progettare un software per la gestione di tutto ciò che riguarda il materiale dei laboratori chimici.

## Requisiti richiesti

### Requisiti funzionali

Il software si basa sulla visualizzazione di 4 schermate:
- Schermata Generale
- Schermata Reagenti
- Schermata Vetreria/Attrezzatura
- Schermata Strumentazione
---
#### Schermata Generale
La schermata generale deve contenere **obbligatoriamente**:
-	Funzione di ricerca
-	Collegamenti alle altre schermate
---
#### Schermata Reagenti
La schermata dei reagenti deve contenere **obbligatoriamente**:
- Nome
- Formula
- Stato(Liquido, Solido, Aeriforme)
- Ditta di provenienza
- Pittogramma di sicurezza
- Frasi di rischio
- Scheda di sicurezza ( Cartacea, digitale, data di update )
- Collocazione
	- Consumo (Armadio, Stanza)
	- Magazzino (Armadio, Stanza)
- Quantità confezione (data di aggiornamento)
- Data di scadenza (non tutti)
- Esperienze collegate (Testo scritto dal docente)
	- Nome insegnante
	- Reagenti utilizzati
---
#### Schermata Vetreria/Attrezzatura

La schermata della vetreria e dell'attrezzatura deve contenere **obbligatoriamente**:
- Tipo
	- Misura
- Quantità (data di update)
- Collocazione (Stanza, Armadio)
---
#### Schermata Strumentazione/Apparecchiatura

La schermata della strumentazione e dell'apparecchiatura deve contenere **obbligatoriamente**:

- Tipo (Testo inserito dal docente)
- Caratteristiche tecniche (Testo inserito dal docente)
- Numero di inventario
- Quantità
- Collocazione (Armadio, Stanza)
- Manuale (Collocazione)
- Manutenzione ordinaria (Data, Storico)
- Manutenzione straordinaria (Data, Storico, Tecnici esterni)
- Riparazione (Motivo, data di uscita, data di rientro, ditta riparatrice)
---
### Requisiti non funzionali
- Visualizzazione da PC
- Visualizzazione da Tablet / Smartphone
- Tempo di risposta inferiore ai 5 secondi
- Facilità d'uso per i nuovi utenti attraverso interfaccia semplice
- Utilizzo del server scolastico

### Requisiti di dominio

- Architettura Client/Server
- Tre livelli di accesso:
	- Base -- Solo consultazione
	- Intermedio -- Aggiornamento quantità, uscita per riparazioni, registrazione riparazioni, tarature tecniche, manutenzione ordinaria/straordinaria.
	- Elevato -- Aggiunta di nuovi record
- Deve poter essere utilizzato da 
	-	Insegnanti (Livello elevato)
	-	Studenti (Livello base)
	-	Personale / Assistenti (Livello intermedio)
- Login per insegnanti (Livello elevato) e personale (Livello intermedio) tramite user-id e password
- Scrittura delle pagine attraverso PHP
- Utilizzo di un database MySQL
---
## Split Tree
<img src="https://i.ibb.co/0MTwj08/Split-Tree.png" alt="Split-Tree" border="0"></a>
---
## Attività
| Fasi di progetto | Attività | Sottoattività  | Tempo di scadenza |
| ----------------- | -------- | -------------- | ---------------- |
| Pianificazione del progetto | Studio di fattibilità    |  Requisiti funzionali            |    Entro il 18/02/20 alle 00.00                          |
|                      |                         | Requisiti non funzionali        |                              |
|                      |                         | Requisiti di dominio            |                              |
|                      |                         | Split tree                      |                              |
|                      |                         | Analisi attività                |                              |
|                      | Piano di progetto       | Work Breakdown Structure        | Entro il 25/02/20 alle 00.00 |
|                      |                         | Pianificazione Temporale(GANTT) |                              |
|                      |                         | Analisi tecnologie utilizzate   |                              |
|                      |                         | Individuazione obiettivi        |                              |
|  Ricerca e sviluppo  | Definizione moduli del progetto   |             | Entro il   25/02/20 alle 00.00                  |
|                   |        Sviluppo backend                    |           |  Entro il   30/04/20 alle 00.00  |
|                      |   Sviluppo frontend    || Entro il   30/04/20 alle 00.00         
|  Design  | Design delle funzioni   | Schermata di accesso            | Entro il 30/03/20 alle 00.00                    |
|                      |                         | Schermata principale            |                              |
|                      |                         | Schermate secondarie            |                              |
|                      | Design dell'interfaccia | Interfaccia PC                  | Entro il 30/03/20 alle 00.00 |
|                      |                         | Interfaccia dispositivi mobili  |                              |
| Testing              | Testing interno                |                       |  Entro il 11/05/20 alle 00.00 |
|                      | Testing di integrazione        |                       |                               |
|                      | Analisi dei risultati del test |                       |                               |
| Rilascio             | Installazione software         |                       | Entro il 31/05/20             |
|                      | Integrazione nel sistema       |                       |                               |
|                      | Training                       |                       |                               |
---
## Osservazioni
- Il server dovrà essere creato sul server master della scuola
- Per le frasi di rischio potrebbe essere utile un database
- Per i pittogrammi di sicurezza potrebbe essere utili un database
- Per la quantità della confezione potrebbe essere utile inserire una emoji che indichi il livello della quantità ( Bassa, Media, Alta )
- Per la data di scadenza potrebbe essere utile inserire un avviso appena all'accesso
- Per le quantità della vetreria potrebbe essere utile inserire uno storico per tenere traccia delle modifiche
- La strumentazione sotto i 200€ non viene inventariata
- Sarebbe utile trovare in rete il manuale in formato digitale per le apparecchiature antiquate
- Sarebbe utile mantenere uno storico per la manutenzione ordinaria e straordinaria
<!--stackedit_data:
eyJoaXN0b3J5IjpbNDI1MjA0MDYyLDMzNDgwNjAyMywxMjIzNT
A0MDQzLC03NDIzNzExMDAsLTIyNDk2NTQzOSwtMTE4NTM3NDgz
NiwxOTkxMjY5MDAzLC03MTgxNDMzMTMsMTQ3MzI2MjI1NywxMD
QxNTQ5Mjg3XX0=
-->