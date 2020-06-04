# Maturità 2020

>Traccia:
> Le minacce dal web sono in continua evoluzione, descrivere le più comuni; e visto che l’integrità dei dati nell'ambito della sicurezza informatica ha un ruolo fondamentale, descrivere quali accorgimenti il programmatore può prendere in fase di definizione del DB.

## Cose da inserire
- Minacce web - Descrivere le più comuni
	- SQL injection
	- Phishing
	- Attacchi vari
- Integrità dei dati nella sicurezza informatica
- SQL mapping
- Accorgimenti in fase di definizione 
	- Criptazione dei dati
	- Normalizzazione del DB
	- Posizionamento del DB nella rete
	- Protezione delle credenziali 

# Introduzione
La risorsa più importante al giorno d'oggi è l'informazione. 

## Minacce Web
- Cenno storico : Guglielmo Marconi e il primo caso di "hacking" della storia
	- La storia narra che lo scienziato Guglielmo Marconi e il suo assistente Sir John Ambrose Fleming stessero per dimostrare il funzionamento di un rivoluzionario telegrafo senza fili, quando inaspettatamente la macchina riceve due messaggi: un insulto, e una filastrocca canzonatoria dell'italiano futuro premio nobel. L'esperimento risulta quindi un disastro, dato che qualcuno è riuscito ad inserirsi nelle frequenze radio che Marconi dichiarava come sicure e private. Il colpevole si rivelerà essere l'inventore Nevil Maskelyne, che dal palazzo vicino riuscì ad interferire con le frequenze di Marconi.
	Era il 4 giugno 1903, e questo è considerato il primo caso di hacking della storia.
	- È un tranquillo pomeriggio di giugno quello in cui Sir John Ambrose Fleming e Guglielmo Marconi stanno per dimostrare il funzionamento di un rivoluzionario telegrafo senza fili.
I due scienziati sono pronti, a 300 miglia di distanza, quando, ancor prima di cominciare, la macchina riceve due inaspettati messaggi: un insulto e una filastrocca canzonatoria che accusa il futuro premio Nobel di essere un truffatore.
L’esperimento è un disastro: qualcuno è riuscito a inserirsi in quelle frequenze radio che Marconi dichiarava essere sicure e private.
Il colpevole?
L’illusionista e inventore Nevil Maskelyne, che dall’edificio a fianco, con un altro telegrafo, interferisce con la presentazione.
Per molti, questo, è a tutti gli effetti il primo esempio di hacking della storia
	- Dai tempi di Marconi, le tecnologie e gli strumenti per la trasmissione, l’immagazzinamento, la gestione e la protezione di dati e informazioni hanno fatto passi da gigante, così come le potenziali minacce, che si sono evolute parallelamente.
- DOS - Denial Of Service
- Malware - Virus, Trojan, Spyware
	- programmi utilizzati per disturbare le operazioni svolte da un computer, **rubare informazioni sensibili**, ottenere accesso a sistemi informatici privati o addirittura prendere il controllo dell’intero dispositivo
	- Ramsonware
		- tiene sotto sequestro il pc della vittima – o il suo contenuto, ad esempio crittografandolo – chiedendo poi un riscatto.
- Phishing
	- tentativo di ottenere dati sensibili – password, pin, etc... – attraverso l’uso di e-mail truffaldine che sembrano provenire da fonti sicure.

[https://www.youtube.com/watch?v=MJxtTIyuqlI&t=1s](https://www.youtube.com/watch?v=MJxtTIyuqlI&t=1s)

## Minacce al database
[Attacco ai database (Wiki)](https://it.wikipedia.org/wiki/Attaccoai_database)
[Protezione delle basi di dati (Wiki)](https://it.wikipedia.org/wiki/Protezione_dai_guasti_(basi_di_dati))

Tipologie di minacce
-	Segretezza
-	Privacy
-	Integrità 
-	Disponibilità

Tipi di attacchi
- Rilascio improprio di informazioni
- Modifica impropria di dati
- Negazione del servizio

Cause
- Accidentali
- Fraudolente




## Sicurezza delle reti (Libro)

### Definizione di sicurezza informatica
- Insieme dei prodotti, servizi, regole organizzative e comportamenti individuali che proteggono i sistemi informatici di un'azienda.

### Minacce all'integrità dei dati
- Minacce naturali
- Minacce umane
	- Dovute a soggetti che hanno interessi personali ad acquisire le informazioni di un'azienda o limitare l'operatività danneggiando i processi aziendali
	- Minacce in rete
		- Con l'avvento di internet le informazioni e l'elaborazione non sono più concentrate ma distribuite, attraverso una comunicazione in "broadcast", su linee condivise.
		- Le reti locali in broadcast costituiscono un punto debole dal punto di vista della sicurezza.
			- In una rete LAN Ethernet il mezzo fisico di comunicazione è condiviso da tutti gli host ed è collocato all'interno dello Switch che ha il compito di amplificare il segnale ritrasmettendolo sulle altre sue porte.
			- La rete è poi connessa a internet tramite un router, passibile di accessi indesiderati da host esterni.
	
### Sicurezza di un sistema informatico
- Garantire la sicurezza significa impedire a potenziali soggetti attaccanti l'accesso o l'uso non autorizzato di informazioni e risorse
### CIA
Cia : Confidentiality, Integrity, Availability
Data Confidentiality
Data Integrity 
System Availability

Gli obiettivi da ottenere per la sicurezza del sistema informativo:
- Autenticazione
- Autorizzazione
- Riservatezza 
- Disponibilità
- Integrità
- Paternità
<!--stackedit_data:
eyJoaXN0b3J5IjpbNjI0NjI3MzcyLC0xNjUxMzczMjE5LDIwND
U2NzMyODAsMTc4MTgzNzc2OCw0ODEzMDI1OSwtMTIwODkzNTU3
MywxNjA5ODkwMjU2LDEwNTM5OTk5MzgsMTY0MTUwOTIxLC0xNz
Y3MzA2NDY5LC0yMDY4NjU4MzYsMTA5MzYzNDQ5OCwtNjQ0NzI4
MzAxLDg1NzIyNjQyNV19
-->