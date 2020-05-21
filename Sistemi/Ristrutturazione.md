# Descrizione e ristrutturazione di una rete telematica

Nell'anno 2019 ho avuto la possibilità di sostenere un mese di stage, previsto scolasticamente. 
Sono stato assegnato all'azienda DuoLabs di Bassano Del Grappa, dove ho potuto osservare e studiare la rete telematica aziendale.

I dispositivi presenti di rete sono:
- x1 Switch Multilayer Cisco da 32 porte
- x4 Switch ZYXEL AMG-T10B da 8 porte
- x1 Router Cisco RV320
- x1 Server Dati
- x2 Server Web
- x2 Access Point Wi-Fi
- x10 Computer

La struttura gerarchica prevede lo switch multilayer Cisco al centro che ridistribuisce la connessione ai 3 switch e al server dati.
I 3 switch ZYXEL interconnettono i 6 computer, divisi in 3 per switch, più un computer aggiuntivo per il terzo switch.
Lo switch centrale è connesso per l'accesso a internet al router Cisco, connesso a sua volta all'ISP. Inoltre il router stesso sostiene l'interconnessione con il server web e i 2 Access Point per la connessione WiFi.

La rete è stata strutturata anche a livello logico per una miglior suddivisione degli ambiti lavorativi, con la definizione di 4 VLAN.
Le VLAN sono così suddivise:
- VLAN 1 / Laboratorio : SW1 ( PC1-PC2)
- VLAN 2 / Programmazione 1 : SW2 ( PC3-PC4-PC5)
- VLAN 3 / Programmazione 2 : SW3 ( PC6-PC7-PC8)
- VLAN 4 / Segreteria-Presidenza : SW4 (PC9-PC10)

I dispositivi Wi-Fi, ovvero:
- x6 Smartphone
- x5 Tablet
Sono tutti connessi tramite DHCP senza IP statici, quindi non presentano alcun problema da quel punto di vista.

La prima problematica emerge al momento di una connessione da parte di dispositivi ospiti, dato che un dispositivo esterno viene fatto connettere alla rete WiFi aziendale, data la mancanza di una rete ospiti.
Per questo per ovviare al problema predisporrerei l'aggiunta di una VLAN 5, acquistando un ulteriore Access Point, aumentandone quindi il numero a 3. 
L'Access Point verrà collegato al Router, ma per ovviare ad altri 



Dispositivi wifi : settati correttamente -> Computer o stampanti senza Ip Statici
Dispositivi ospiti non sicuri: rete staff e rete ospiti
Azioni virus: Problemi -> Non è stato posto un firewall abbastanza potente
Azioni di attacco : La rete non è dotata di DMZ, dal sito web magari
<!--stackedit_data:
eyJoaXN0b3J5IjpbNTgzNzg3OTAyLDE4Mjc0Nzk2MjUsLTE5Mz
E3NzEwNjEsLTEyMzk1MTA0NzMsMTc2ODMyOTM0OCwxMzEzODYz
NjIzLC0xODg4NzE5OTIyLC0xOTUxMDk1NDUwLC0xNDE0ODQ3Nz
U2LDIwOTEyMzAxMjksLTIwODg3NDY2MTJdfQ==
-->