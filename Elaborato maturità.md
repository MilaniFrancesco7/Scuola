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

#### Cenno storico
La storia narra che lo scienziato Guglielmo Marconi e il suo assistente Sir John Ambrose Fleming stessero per dimostrare il funzionamento di un rivoluzionario telegrafo senza fili, quando inaspettatamente la macchina riceve due messaggi: un insulto, e una filastrocca canzonatoria dell'italiano futuro premio nobel. L'esperimento risulta quindi un disastro, dato che qualcuno è riuscito ad inserirsi nelle frequenze radio che Marconi dichiarava come sicure e private. Il colpevole si rivelerà essere l'inventore Nevil Maskelyne, che dal palazzo vicino riuscì ad interferire con le frequenze di Marconi.
Era il 4 giugno 1903, e questo è considerato il primo caso di hacking della storia.

Dai tempi di Marconi, le tecnologie e gli strumenti per la trasmissione, l’immagazzinamento, la gestione e la protezione di dati e informazioni hanno fatto passi da gigante, così come le potenziali minacce, che si sono evolute parallelamente.

#### Minacce nel Web
Le tipologie di attacco si possono racchiudere in due categorie principali: attacco attivo e attacco passivo.
L'attacco attivo implica la manomissione di dati o il disturbo del loro funzionamento, danneggiandone l'integrità e la disponibilità. L'attacco passivo invece cerca di intercettare e utilizzare i dati senza danneggiare le risorse del sistema, quindi minacciandone solamente la riservatezza.

L'attacco passivo più famoso è sicuramente lo **sniffing**.
I packet sniffer erano nati con l'intento di essere programmi di diagnostica per le reti, riuscendo a catturare, analizzare e decodificare tutti i pacchetti in transito nelle comunicazioni. Presto però è diventato uno strumento per malintenzionati.
Infatti intercettando i singoli pacchetti, decodificandoli e analizzando le pa



## Minacce Web
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
eyJoaXN0b3J5IjpbMTIwMTEyNzg1NSwtODY3NTMxOTY0LC0xMz
IxNDI2MzU0LC0xNjUxMzczMjE5LDIwNDU2NzMyODAsMTc4MTgz
Nzc2OCw0ODEzMDI1OSwtMTIwODkzNTU3MywxNjA5ODkwMjU2LD
EwNTM5OTk5MzgsMTY0MTUwOTIxLC0xNzY3MzA2NDY5LC0yMDY4
NjU4MzYsMTA5MzYzNDQ5OCwtNjQ0NzI4MzAxLDg1NzIyNjQyNV
19
-->