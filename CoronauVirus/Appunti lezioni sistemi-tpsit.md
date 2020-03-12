# Appunti lezioni telematiche sistemi / tpsit

# Docker
Questo servizio permette di installare qualsiasi servizio (apache2, nano...) su un "contenitore" senza che vengano salvati ulteriori dati al di fuori di esso.

Si utilizza prevalentemente per testare funzionalità e programmi senza dover intaccare il proprio server.

## Installazione

`sudo apt-get update`
`sudo apt-get upgrade`
`sudo apt-get install docker.io`

## Utilizzo

Per prima cosa eseguiamo una "copia" di un sistema

		docker pull debian:latest

Ora visualizziamo tutti i contenitori esistenti

		docker images

Ora creiamo un nuovo contenitore

		docker run -it --name NOMECONTENITORE debian:latest

Ora saremo dentro al nostro contenitore.
Per eseguire un primo test procediamo con l'installazione di apache

		yum install httpd -y

Successivamente installare anche "nano" che utilizzeremo per creare il file "index.html"

		yum install nano

Ora creiamo il nostro file index.html che sarà situato in "/var/www/html/"

		nano /var/www/html/index.html

Inseriamo dentro un qualsiasi codice in html

		<html>
		
		<head>
			<title>Primo test docker</title>
		</head>

		<body>
			<center>
				<h1>Hello World</h1>
			</center>
		</body>

		</html>

Ora salviamo con CTRL+O e CTRL+X per uscire dal nano

Ora usciamo dal nostro container

		exit

Ora diamo un nome al nostro contenitore

		docker commit NOMECONTENITORE NOMECONTENITORE:v1
			"v1" è il nome della versione

Ora controllando i vari contenitori dovrebbe esserci nella lista il contenitore appena "creato"

		docker images

Ora per testare il nostro apache lanciamo il contenitore

		docker run -p 8080:80 NOMECONTENITORE:v1 /usr/sbin/httpd -D FOREGROUND

Ora apriamo un browser e controlliamo il risultato

		IP:8080

## Come operare su un docker

Dopo averlo creato e operato sul contenitore bisogna uscire e creare un commit con il seguente comando

		docker commit NOMEIMMAGINE NOMEIMMAGINE:VERSIONE

		es. docker commit webserver webserver:v1

Ora le nostre modifiche effettuate sul nuovo contenitore sono state salvate
Per effettuare altre modifiche occorre startare il docker e successivamente entrare nel terminale del docker

		docker start NOMEIMMAGINE
		docker attach NOMEIMMAGINE

		es. docker start webserver
		    docker attach webserver

Una volta terminato di effettuare ulteriori modifiche bisogna rieseguire il commit

		docker commit NOMEIMMAGINE NOMEIMMAGINE:VERSIONE

		es. docker commit webserver webserver:v2

Per tornare ad effettuare delle modifiche utilizzare il seguente comando

		docker run -it nome:versione
		es. docker run -it debian:v1

## Altro

In caso vengano creati dei contenitori "none" si possono eliminare con il seguente comando

		docker images -q --no-trunc -f dangling=true | xargs -r docker rmi

Per cancellare tutti i contenitori utilizzare il seguente comando

		docker rmi -f $(docker images -q)

		Oppure provare questo comando
		docker image prune

Per visualizzare tutti i contenitori e tutti gli "snapshot", compresi quelli non committati utilizzare il seguente comando

		docker container ls --all

In caso bisogna rimuovere un docker e i suoi volumi utilizzare il seguente comando

		docker rm -v NOME

> Es. docker rm -v webserver

Per cancellare tutti i docker in status di "Exit" utilizzare il seguente comando

		sudo docker ps -a | grep Exit | cut -d ' ' -f 1 | xargs sudo docker rm



# ProxMox

ProxMox è il "concorrente open-source" di VMWare, si tratta di una distribuzione Linux basata su Debian con un kernel Ubuntu LTS modificato e consente l'implementazione e la gestione di macchine virtuali e container.

# Container LXC
LXC è un ambiente di virtualizzazione a container, che opera a livello del sistema operativo e permette di eseguire diversi ambienti Linux virtuali isolati tra loro su una singola macchina reale avente il kernel Linux.

Appunti durante l'installazione:
- Non serve essere tassativi con i numeri come con le macchine virtuali durante l'assegnazione di RAM, Disco e Core, in quanto non si ha la pesantezza di una macchina virtuale emulata completamente, quindi le risorse non saranno mai occupate totalmente, perchè lo scheduler penserà a controllare i processi in modo da non creare rallentamenti.

# Reverse proxy

Un reverse proxy è un tipo di proxy che recupera i contenuti per conto di un client da uno o più server. Questi contenuti sono poi trasferiti al client come se provenissero dallo stesso proxy, che quindi appare al client come un server.

Permete quindi di mascherare il fatto che si stia utilizzando un altro sito per accedere a determinate funzioni, ma mostrandolo sempre sotto lo stesso dominio.

Un esempio può essere il sito del registro scolastico.
Il server dell'itis riceve le richieste e le inoltra ad altri server che si occupano dei servizi richiesti.

# Raid
In informatica il RAID, acronimo di Redundant Array of Independent Disks ovvero insieme ridondante di dischi indipendenti, è una tecnica di installazione raggruppata di diversi dischi rigidi in un computer (o collegati ad esso) che fa sì che gli stessi nel sistema appaiano e siano utilizzabili come se fossero un unico volume di memorizzazione.

In pratica il raid si utilizza per dare una continuità di servizio all'utente. Si usa infatti per avere una copia completa dei file sempre attiva durante il funzionamento, che in caso di guasti non porterebbe alla perdita completa del lavoro.

Al momento dell'acquisto di due dischi, che possono costare all'incirca 100€ l'uno, si può dire come si paghino 200€ per avere 100€ di spazio, in quanto un disco sarà completamente copiato all'interno dell'altro e collaboreranno in maniera tale da non perdere i dati se uno dei due dovesse rompersi.
Questo porta ad un incremento dell'affidabilità e delle prestazioni in lettura, ma non in scrittura.

## Raid 4
 Il raid 4 si basa sullo XOR, ovvero 0 0 -> 1, cioè metà del lavoro viene scritto su un disco, metà sull'altro, e il lavoro completo viene salvato sul disco 3. In questo modo però l'usura del terzo disco sarà incrementata notevolmente rispetto agli altri due, dovuto alla massiccia quantità di lavoro da svolgere, in quanto la parità viene eseguita solamente al suo interno.

## Raid 5
Per risolvere il problema dell'usura del terzo disco, è stato creato il Raid 5, dove si fa slittare di volta in volta la parità di disco in disco, dividendo così il carico di lavoro in maniera uniforme.

La differenza tra raid 4 e 5 dipende infatti solamente dalla strategia utilizzata.

# Attività di laboratorio

## Creazione pc virtuale con 2 dischi in raid 1

Disco da 4 GB
Dopo la creazione della VM su virtualbox creeremo un secondo disco e lo collegheremo alla macchina
Ci ricorderemo di impostare il controller dischi con minimo 4 porte disco

## Installazione pc virtuale con 2 dischi in raid 1 software
Durante l'installazione partizioneremo i due dischi con lo stesso schema di partizionamento, ma di tipo 0xf
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTc3NTI0MzA0Ml19
-->