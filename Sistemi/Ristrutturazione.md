# Descrizione e ristrutturazione di una rete telematica

Nell'anno 2019 ho avuto la possibilità di sostenere un mese di stage, previsto scolasticamente. 
Sono stato assegnato all'azienda DuoLabs di Bassano Del Grappa, dove ho potuto osservare e studiare la rete telematica aziendale.

I dispositivi presenti di rete sono:
- x1 Switch Multilayer Cisco da 32 porte
- x4 Switch ZYXEL AMG-T10B da 8 porte
- x1 Router Cisco RV320
- x1 Server Dati
- x2 Server Web
- x10 Computer

La struttura gerarchica prevede lo switch multilayer Cisco al centro che ridistribuisce la connessione ai 3 switch e al server dati.
I 3 switch ZYXEL interconnettono i 6 computer, divisi in 3 per switch, più un computer aggiuntivo per il terzo switch.
Lo switch centrale è connesso per l'accesso a internet al router Cisco, connesso a sua volta all'ISP. Inoltre il router stesso sostiene l'interconnessione con il server web.

La rete è stata strutturata anche a livello logico per una miglior suddivisione degli ambiti lavorativi, con la definizione di 5 VLAN.
Le VLAN sono così suddivise:
- VLAN 1 / Laboratorio : SW1 ( PC1-PC2)
- VLAN 2 / Programmazione 1 : SW2 ( PC3-PC4-PC5)
- VLAN 3 / Programmazione 2 : SW3 ( PC6-PC7-PC8)
- VLAN 4 / Segreteria : SW4 (PC9)
- VLAN 5 / Presidenza : SW4 (PC10)


Come possiamo vedere la rete è ben strutturata, ma presenta alcuni problemi.
Innanzitutto 


Dispositivi wifi : settati correttamente -> Computer o stampanti senza Ip Statici
Dispositivi ospiti non sicuri: rete staff e rete ospiti
Azioni virus: Problemi -> Non è stato posto un firewall abbastanza potente
Azioni di attacco : La rete non è dotata di DMZ, dal sito web magari
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjA5MDUyNzMyOSwtMTIzOTUxMDQ3MywxNz
Y4MzI5MzQ4LDEzMTM4NjM2MjMsLTE4ODg3MTk5MjIsLTE5NTEw
OTU0NTAsLTE0MTQ4NDc3NTYsMjA5MTIzMDEyOSwtMjA4ODc0Nj
YxMl19
-->