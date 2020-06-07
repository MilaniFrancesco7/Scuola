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

## Importanza dell'integrità dei dati

La risorsa più importante di ogni organizzazione è l'**informazione**. E' la base fondamentale dell'informatica e dei dati, che al giorno d'oggi controllano il mondo. Le informazioni devono però essere protette da possibili attacchi, per poter garantire la **sicurezza informatica**.
La sicurezza informatica è l'insieme dei prodotti, dei servizi e dei mezzi per la protezione dei sistemi informatici per quanto riguarda la CIA.
Per CIA si intende data Confidentiality, data Integrity, system Availability, che in italiano si traduce in confidenzialità e integrità dei dati, insieme alla disponibilità di sistema. Questi principi sono strettamente connessi e sono alla base della sicurezza di un sistema informatico.
La parte fondamentale è sicuremante l'**integrità dei dati**.
Per integrità dei dati si intende la capacità di mantenere i dati e le risorse garantendo la loro inalterazione e non cancellazione, se non ad opera di soggetti autorizzati. Essa viene garantita da una serie di processi, regole e standard implementati in fase di progettazione.
[Integrità 1](https://it.talend.com/resources/what-is-data-integrity/)
[Integrità 2](https://blog.osservatori.net/it_it/sicurezza-informatica-disponibilit%C3%A0-e-integrit%C3%A0-dei-dati)
Molto importante è quindi conoscere i più importanti metodi d'attacco per poter attuare sistemi di difesa.

 ## Attacchi

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
Nella tipologia spoofing rientra anche l'attacco chiamato **SQL Injection** che riguarda in maniera particolare l'attacco dei database. 
Con questa tecnica è possibile inserire delle stringhe di SQL all'interno di campi di input, che possono essere ad esempio i campi di inserimento utente e password, oppure di ricerca, in maniera tale da fare eseguire le query all'interno del DB, cercando di causare danni o per ottenere dati. Questo tipo di attacco viene utilizzato in particolare in casi in cui l'applicazione che si sta attaccando presenti vulnerabilità piuttosto evidenti.

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
[Phishing](https://www.cybersecurity360.it/nuove-minacce/phishing-cose-e-come-proteggersi-la-guida-completa/)
[Video Youtube](https://www.youtube.com/watch?v=MJxtTIyuqlI&t=1s)


## Difesa dagli attacchi

Per poter garantire l'integrità dei dati all'interno di una base di dati è necessario che essa sia garantita a livello di DBMS e livello di dato stesso.

Anche se piuttosto utopico, spesso per la protezione di un database nelle imprese vengono usate password di default o facilmente indovinabili.
Questo in realtà è un problema facilmente risolvibile, attraverso l'attuazione di una policy che preveda il ricambio regolare di password, con una lunghezza e con un numero di simboli e caratteri alfanumerici.

Invece per potersi difendere da attacchi come l'SQL Injection è importante accertare una validazione dei dati forniti dall'utente.
Come primo passo può essere utilizzata la funzione mysql real escape string, che andrà a rimuovere i caratteri speciali dalla stringa, eliminando quindi gli attacchi concernenti l'utilizzo di apici o uguali.
Invece come secondo passo è consigliato l'utilizzo di una funzione **is numeric**, che andrà a controllare semplicemente se l'input inserito sia di tipo numerico, così da eludere, insieme alla real escape string, l'utilizzo di attacchi con numeri.

La sicurezza nei DBMS deve essere gestita attraverso una serie di passaggi che permetterà di garantire l'ìntegrità del database stesso e dei dati.

Il primo passaggio che si effettua è il **partizionamento**. 
Il partizionamento consiste nella suddivisione del database in più parti, ognuna caratterizzata da un livello di sensibilità. In questo modo il database verrà diviso in componenti più piccoli, che risulteranno più sicuri, oltre che veloci, da gestire. Aumenterà quindi la ridondanza, garantendo l'integrità dato l'accesso da DB separati.

Il secondo passaggio che andremo ad attuare è la **cifratura** dei dati.
Cifrare i dati all'interno di un database permette di proteggere i dati dal furto o dalla manomissione, dal momento che non sono interpretabili se non tramite la chiave di decifratura.
Molto comune è l'utilizzo di funzioni hash, che permettono di attuare una forma di crittografia a "senso unico", quindi rendendo l'operazione di decifrazione impossibile.
Questo tipo di criptazione è utilizzato nel caso delle password, in modo tale che un hacker non possa interpretarle al momento dell'accesso al DB.
Gli algoritmi più utilizzati sono l'MD5, lo SHA1 (anche se ormai obsoleto) e lo SHA2.
[Criptazione](https://www.html.it/pag/54604/cifratura-e-decifratura-dei-dati/)

Un altro passaggio da compiere per poter salvaguardare i dati è il **lock di integrità**, con l'utilizzo di transazioni.
Una transazione è una sequenza di operazioni atomiche che devono essere eseguite senza concludersi con uno stato intermedio.
I lock, letteralmente "blocchi", sono un meccanismo usato per disciplinare l'accesso a risorse condivise.
Semplicemente i dati vengono marcati attraverso delle "etichette", che ne definiscono sensibilità e livelli di accesso.
Per questo meccanismo viene implementato il modulo **Lock Manager** nel DBMS, che tiene traccia delle risorse in uso, delle transazioni che le stanno usando e delle transazioni che ne hanno fatto richiesta.
In questo modo se dovesse venire riscontrata qualche anomalia verrà eseguita l'istruzione di **abort**, che può essere a runtime o di sistema, per concludere la transizione. L'abort a runtime si verifica al momento del riscontro di un'anomalia da parte del DBMS, mentre l'abort di sistema viene lanciato nel caso di un'interruzione brusca per intervento esterno, per bug o per spegnimento del computer.
L'entrata in funzione del meccanismo di abort prevede l'avvio di un altro meccanismo, il **rollback**, che p
[Lock di integrità](http://bias.csr.unibo.it/golfarelli/LabDB/MaterialeDidattico/Funzionalit%C3%A0AvanzateDBMS.pdf)
[Transizione](https://it.wikipedia.org/wiki/Transazione_(basi_di_dati))

## Minacce al database
[Attacco ai database (Wiki)](https://it.wikipedia.org/wiki/Attaccoai_database)
[Protezione delle basi di dati (Wiki)](https://it.wikipedia.org/wiki/Protezione_dai_guasti_(basi_di_dati))


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTk1MTY3NTQ0OSwxMDUxNTc5ODE2LC0yMT
I2NzMxMTM3LC0xMjMxNjM4Mzc0LDM5MjMyNzkzLC0xMTMxNzIz
NTAzLDY3NTgwMzgzOCwtMjA5NzQ5OTg3NiwxMjcwODY0MjAwLC
0xODYxMDA5NTg0LDExMzI3NTY5LC0zNDM1MjQ0MzYsNDQ0MjQy
MTczLC0xNjc2MzI2NzU3LDEwMjc0MjQ4OTQsLTE5OTc1MjUzMD
AsNDUyNTUyNDg3LC05NDk1OTg2MTEsLTk2NjI3NDg5OSwxOTYx
NjIyNzgzXX0=
-->