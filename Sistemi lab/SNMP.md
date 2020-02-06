# Installazione mrtg per protocollo SNMP

SNMP = Simple Network Management Protocol
Protocollo di rete senza connessione che appartiene alla suite di protocolli Internet definito dalla IETF (Internet Engineering Task Force).

Community string: sorta di password o metodo di controllo utilizzato per dare l'accesso alle statistiche del router o di altri dispositivi

## Configurazione

Sulla community string inserire il nomehost

Inserire il comando da terminale
```bash
cfgmaker community@nomehost
```

Questo creerà un prototipo di file di tipo mrtg per il nostro host

La cartella predefinita è messa sotto var/
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTk5NDQ5NDQ3NV19
-->