# Descrizione e ristrutturazione di una rete telematica

Nell'anno 2019 ho avuto la possibilità di sostenere un mese di stage, previsto scolasticamente. 
Sono stato assegnato all'azienda DuoLabs di Bassano Del Grappa, dove ho potuto osservare e studiare la rete telematica aziendale.

I dispositivi presenti di rete sono:
- x1 Switch Multilayer Cisco da 32 porte
- x3 Switch ZYXEL AMG-T10B da 8 porte
- x1 Router Cisco RV320
- x1 Server Dati
- x2 Server Web
- x10 Computer

La struttura gerarchica prevede lo switch multilayer Cisco al centro che ridistribuisce la connessione ai 3 switch e al server dati.
I 3 switch ZYXEL interconnettono i 6 computer, divisi in 3 per switch, più un computer aggiuntivo per il terzo switch.
Lo switch centrale è connesso per l'accesso a internet al router Cisco, connesso a sua volta all'ISP. Inoltre il router stesso sostiene l'interconnessione con il server web.



Dispositivi wifi : settati correttamente -> Computer o stampanti senza Ip Statici
Dispositivi ospiti non sicuri: rete staff e rete ospiti
Azioni virus: Problemi -> Non è stato posto un firewall abbastanza potente
Azioni di attacco : La rete non è dotata di DMZ, dal sito web magari
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTc2ODMyOTM0OCwxMzEzODYzNjIzLC0xOD
g4NzE5OTIyLC0xOTUxMDk1NDUwLC0xNDE0ODQ3NzU2LDIwOTEy
MzAxMjksLTIwODg3NDY2MTJdfQ==
-->