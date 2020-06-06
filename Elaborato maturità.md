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

### Cenno storico
La storia narra che lo scienziato Guglielmo Marconi e il suo assistente Sir John Ambrose Fleming stessero per dimostrare il funzionamento di un rivoluzionario telegrafo senza fili, quando inaspettatamente la macchina riceve due messaggi: un insulto, e una filastrocca canzonatoria dell'italiano futuro premio nobel. L'esperimento risulta quindi un disastro, dato che qualcuno è riuscito ad inserirsi nelle frequenze radio che Marconi dichiarava come sicure e private. Il colpevole si rivelerà essere l'inventore Nevil Maskelyne, che dal palazzo vicino riuscì ad interferire con le frequenze di Marconi.
Era il 4 giugno 1903, e questo è considerato il primo caso di hacking della storia.

Dai tempi di Marconi, le tecnologie e gli strumenti per la trasmissione, l’immagazzinamento, la gestione e la protezione di dati e informazioni hanno fatto passi da gigante, così come le potenziali minacce, che si sono evolute parallelamente.

## Minacce nel Web
Le tipologie di attacco si possono racchiudere in due categorie principali: attacco attivo e attacco passivo.
L'attacco attivo implica la manomissione di dati o il disturbo del loro funzionamento, danneggiandone l'integrità e la disponibilità. L'attacco passivo invece cerca di intercettare e utilizzare i dati senza danneggiare le risorse del sistema, quindi minacciandone solamente la riservatezza.

### Attacchi passivi
L'attacco passivo più famoso è sicuramente lo **sniffing**.
I packet sniffer erano nati con l'intento di essere programmi di diagnostica per le reti, riuscendo a catturare, analizzare e decodificare tutti i pacchetti in transito nelle comunicazioni. Presto però è diventato uno strumento per malintenzionati.
Infatti intercettando i singoli pacchetti, decodificandoli e analizzandoli, gli *sniffer* riescono a recuperare informazioni sulla comunicazione in atto: dalle informazioni sul traffico di rete ai dati veri e propri, che quindi potrebbero contenere informazioni sensibili.

Esistono molte tattiche per attuare un **packet sniffing**. La più famosa è sicuramente il ***Man in the middle***. 
Grazie a questo attacco, è possibile intercettare una comunicazione in corso tra due nodi inserendosi nel mezzo della comunicazione, arrivando a trasformarsi come "ponte" tra gli stessi due nodi.
Questa operazione consente all'hacker di recuperare le informazioni semplicemente osservando il traffico di passaggio senza che avvenga alcun disturbo, lasciando credere ai due comunicanti di essere soli.

### Attacchi attivi
Negli attacchi attivi, al contrario degli attacchi passivi, esistono molte più tipologie, suddivise per obiettivo dell'attacco.
#### Intercettazione 
Troviamo innanzitutto l'intercettazione, il cui metodo più utilizzato è lo ***spoofing***.
Lo spoofing è un tipo di attacco che consiste nel falsificare l'identità dell'host da cui viene eseguito l'attacco.
Esso può essere attuato in diverse maniere; il più utilizzato è l'IP spoofing, ma esistono il DNS Spoofing (chiamato anche shadow server), il MAC spoofing (chiamato anche MAC flooding), l'ARP spoofing o l'Email Spoofing (utilizzato principalmente come base per il phishing)). 
Lo spoofing fa parte della tipologia di attacchi **Man in the middle**, come lo sniffing visto precedentemente.
Esistono altre tipologie di spoofing che derivano da quelle descritti precedentemente, agendo su tutti i livelli dello modello ISO/OSI.
L'IP spoofing consiste nel falsificare l'indirizzo IP dell'host da cui viene eseguito l'attacco. 
In questo modo l'host viene considerato attendibile dalla rete, cercando di ottenere dati sensibili.
Il DNS spoofing, o shadow server, consiste nel creare record DNS fasulli, inserendoli nella cache del server, attraverso una tecnica chiamata ***cache poisoning***, per poter deviare le richieste DNS ad un server secondario, che si posizionerà quindi davanti al server originario, coprendolo (da qui **shadow** server).
L'utente quindi verrà reinderizzato ad un sito fasullo, molto probabilmente del tutto simile a quello originario, dove inserirà i dati sensibili che verranno poi rubati dall'individuo attaccante.

#### Produzione
Un altro tipo di attacco è la produzione, che consiste nell'introdurre nuovi elementi nel sistema con l'obiettivo non di ottenere informazioni ma di provocare un danno.
Sono quindi degli attacchi di sabotaggio che hanno l'obiettivo di ridurre l'integrità e la disponibilità delle risorse del sistema.
Le principali tecniche di disturbo sono gli attacchi malware e gli attacchi di tipo DoS.
I **malware** sono software "malevoli" che mettono a rischio un sistema. Essi cercano di invadere, danneggiare o disattivare computer, sistemi e reti. Il loro scopo è quello di lucrare illecitamente a spese degli utenti.
Le due categorie più utilizzate all'interno dei malware sono **virus**   e **worm**.
- I **virus** sono software che hanno il compito di moltiplicarsi ***"infettando"*** altri file o altri host presenti nella rete, senza farsi rilevare dall'utente. Solitamente i virus sfruttano falle o vulnerabilità presenti in un sistema operativo o in un software, cercando di rendere inutilizzabile il dispositivo attraverso attività distruttive o di ostruzionismo.
Il virus più potente mai creato è il ***MyDoom*** (in italiano "Il mio destino"). Questo tipo di virus è riuscito a causare 38 miliardi di danni in tutto il mondo, diffondendosi attaccando tutti i file presenti sul PC.
[1](https://www.laramind.com/blog/top-10-virus-piu-pericolosi-della-storia/)
- Gli attacchi **worm** sono simili ai virus, ma si differenziano per la capacità di riuscire a moltiplicarsi senza doversi "legare" ad altri file o software, utilizzando invece direttamente gli host presenti nella rete. 
[2](https://it.wikipedia.org/wiki/Worm)
Come il virus punta a rendere inutilizzabile il dispositivo, occupando una grande quantità di risorse computazionali.
Spesso un attacco worm o un attacco virus coincide con l'installazione di altre tipologie di malware (famiglia di cui worm e virus fanno parte), come ad esempio **backdoor** o **keylogger**, sfruttati dall'hacker per ottenere dati sensibili.

Un ulteriore attacco di produzione è il **Denial of Service** (DoS) o la sua evoluzione, il **Distribuited Denial of Service** (DDoS).
Questo attacco mira a "tenere occupato" un host, solitamente server, con operazioni sostanzialmente inutili, in maniera tale da potergli impedire di offrire i propri servizi alla rete.
[3](https://Librodisistemi)
Esistono diverse tipologie di attacchi DoS, alcune cercano di impedire l'accesso di un individuo specifico ad un network o una risorsa, mentre altre cercano di rendere la risorsa inaccessibile per qualsiasi utente.
Queste tipologie di interruzioni, nel caso di attacchi ad aziende, causano perdite finanziarie che possono essere anche molto pesanti.
[4](https://academy.binance.com/it/security/what-is-a-dos-attack)
La metodologia più utilizzata è il ***buffer overflow***, che consiste nell'invio di un traffico maggiore di quanto il sistema a cui si mira sia in grado di gestire. Questo attacco permette quindi di riuscire a rendere inutilizzabile il sistema, facendolo collassare.
Un altro tipo di attacco DoS molto utilizzato è il ***SYN flood***, che attacca il server autenticandosi solamente in maniera parziale. In questo modo verrà lasciata in attesa la connessione sulla porta per il ***three way handshake***, procedendo quindi a fare la stessa operazione su tutte le porte fino a mettere fuori uso il server.
Infine il DDos, che può essere visto come "l'evoluzione" del DoS, dato che rispetto al DoS che avviene principalmente da una sola macchina, il DDoS consiste nell'utilizzo di diversi dispositivi che prendono di mira una singola risorsa. Per questo motivo ha infatti molta più probabilità di successo rispetto al DoS normale per la maggior quantità di traffico prodotto. Inoltre questo metodo viene preferito per l'enorme difficoltà nel rintracciare la fonte da dove avviene l'attacco, dato che questa proviene da più punti e non da un singolo host.

#### Phishing

Il phishing è una tipologia di attacco che concerne anche con il mondo delle truffe; ha infatti l'obiettivo di rubare le informazioni e i dati personali delle vittime per poterli utilizzare a scopo di lucro.
E' una sorta di forma di "adescamento", infatti la molteplicità degli attacchi avviene attraverso l'inganno psicologico dell'utente, sfruttando le meccaniche dell'ingegneria sociale.

Il metodo utilizzato solitamente è l'email.
Il messaggio è costruito in maniera tale da sembrare proveniente da un'organizzazione attendibile, come potrebbero essere una banca o la posta.
Generalmente il contenuto indica problemi relativi alla sicurezza dell'account della vittima, invitandolo a cliccare su un link.
Quel link collega ad un sito fittizio controllato da chi ci sta attaccando. E' quasi impossibile riconoscere un sito fittizio dal sito originale, dato che spesso sono totalmente identici, tranne ovviamente che per l'indirizzo URL, che può essere il primo campanello d'allarme unito al fatto di non essere in una connessione sicura. Solitamente gli URL fittizzi hanno al loro interno punti o underscore che ad un primo sguardo fanno sembrare come l'indirizzo sia corretto. (Es. https://face.book.com)
Dopodichè viene richiesto all'utente di inserire le proprie credenziali o i propri dati, senza rendersi conto di averli inviati ad un criminale.

[Video Youtube](https://www.youtube.com/watch?v=MJxtTIyuqlI&t=1s)

## Impo
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
eyJoaXN0b3J5IjpbMTczNTMwNzg2MCw0NDQyNDIxNzMsLTE2Nz
YzMjY3NTcsMTAyNzQyNDg5NCwtMTk5NzUyNTMwMCw0NTI1NTI0
ODcsLTk0OTU5ODYxMSwtOTY2Mjc0ODk5LDE5NjE2MjI3ODMsLT
E4OTk1ODAwMCwtMTU0ODIwNjU2NCwtMzk5NTY5ODMyLC0zMTE1
NzMxNzUsMTMyNTYwNDg1NywtMTEwODgxMDgxNiwtODc2NzI3MT
UyLDIwNzY5MDM2NSwxMzA4NTAzOTI4LDE2MTc5MjEyNzAsLTc2
MTQ5MjY2Ml19
-->