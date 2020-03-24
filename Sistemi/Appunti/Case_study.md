

Case study - Milani Francesco
5AI
22/03/2020

## Sabbioni Grafica S.r.l - progettazione di una rete informatica LAN

#### Problema

> Sabbioni Grafica S.r.l. è una nuova azienda che si occupa di grafica e della redazione di libri di testo. 
> Vi operano complessivamente 14 dipendenti più il proprietario, il Dott. Giancarlo Minghetti, che è anche il direttore.
La Sabbioni Grafica S.r.l. ha deciso di trasferirsi in una sede di dimensioni maggiori e dotare l’azienda di una rete informatica interna per ottimizzare la condivisione e lo scambio dei dati.
Per la progettazione della rete aziendale, la Sabbioni Grafica S.r.l. si è rivolta a noi della Fast Solutions S.r.l., azienda di consulenza informatica ed elettronica.

#### Operazione preliminare: richiesta di maggiori informazioni

> Abbiamo chiesto informazioni sulla struttura e sull’estensione dell’azienda Sabbioni Grafici S.r.l. , sul numero di postazioni presenti, su quelle da creare, sulla loro dislocazione, e sulle ulteriori esigenze.

Secondo le informazioni che ci ha comunicato la Sabbioni Grafica S.r.l., l’azienda è costituita da 5 uffici: 
- l’ufficio del direttore, con 2 postazioni; 
- l’ufficio dei redattori, con 2 postazioni; 
- l’ufficio amministrativo, con 2 postazioni e 1 stampante; 
-  l’ufficio dei programmatori, con 5 postazioni più 2 libere; 
-  l’ufficio dei grafici, con 5 postazioni.

La Sabbioni Grafica S.r.l. ha anche l’esigenza di avere un collegamento a Internet per fruire dei servizi Web e di salvare i propri dati informatici in un server dedicato. Quindi occorre una stanza nuova, in cui collocare il server.

In totale saranno quindi 18 postazioni + 1 stampante + 1 server.

#### Rappresentazione grafica dell'azienda

<a href="https://ibb.co/THwY9Cc"><img src="https://i.ibb.co/GVdnzh7/case-study.png" alt="case-study" border="0"></a>

### Progettazione della rete

In base alla classificazione delle reti, la tipologia consona alla Sabbioni Grafica S.r.l è la LAN, Local Area Network, con un'estensione ridotta fino a cento metri e confinata in un edificio.

Per quanto riguarda la topologia fisica, viene scelta la topologia a stella, che prevede che ciascuno dei nodi sia collegato ad un dispositivo centrale, uno switch, che mette quindi i vari nodi in comunicazione tra loro. Questa topologia garantisce la tolleranza ai guasti, semplicità di gestione e soprattutto flessibilitò ed espandibilità, ovvero le caratteristiche che sono state richieste dall'azienda.

Infine come topologia logica viene scelto il tipo broadcast, in cui ogni nodo invia i propri dati mediante una scheda di rete a tutti gli altri nodi. La topologia scartata è di tipo token, caduta in disuso e meno efficace rispetto al broadcast. 

#### Analisi degli apparati di rete

Date le informazioni ricevute dall'azienda, si può procedere alla definizione degli apparati di rete necessari al funzionamento:
- Per le 18 postazioni serviranno 18 PC con scheda di rete, ciascuna da 1 Gb/s, che garantisce prestazioni ottime;
- Per il server dedicato aziendale sarà quindi necessario 1 server con scheda di rete, anch'essa da 1 Gb/s;
- Per l'ufficio amministrativo la stampante dovrà avere la scheda di rete sempre da 1 Gb/s;

Si prosegue poi alla definizione degli apparati di rete che serviranno per la creazione della rete:
- Per l'ufficio direttore, redattori e per la stanza server occorrono 3 switch da 4 porte da 1 Gb/s;
- Per l'ufficio amministrativo e per lo switch principale, 2 switch da 8 porte da 1 Gb/s;
- Per l'ufficio programmatori e grafici, 2 switch da 16 porte da 1 Gb/s. 16 porte in quanto, data la potenziale crescita dell'azienda, si prevede un maggior numero di impiegati;
- Per il controllo della rete 1 router con 2 porte, una di esse da 1 Gb/s per il collegamento alla LAN;
- 27 cavi UTP di categoria 6. Viene scelta questa categoria per garantire un futuro all'azienda in cui, data la miglioria della connessione dovuta all'avanzamento tecnologico, non sia necessario ri-cablare completamente tutta la rete. I cavi verranno usati specificatamente: 20 per collegamenti switch-PC, switch-stampante, switch-server, 6 per collegamenti switch-switch principale, 1 per collegamento switch-router.

#### Rappresentazione grafica della rete 

Il numero degli switch e delle postazioni è stato definito seguendo i livelli gerarchici dell'azienda.
<!--stackedit_data:
eyJoaXN0b3J5IjpbOTc0Mjk0NDgyLDIwNTQzNDQ1ODldfQ==
-->