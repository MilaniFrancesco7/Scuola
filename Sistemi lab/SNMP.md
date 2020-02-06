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

La cartella di default è posizionata in /var/lib/mrtg

Questa directory non va bene in quanto non sarà accessibile direttamente dall'apache.
Per permettere l'accesso alla cartella da parte dell'apache si creerà un link simbolico, che permetterà di lasciare la cartella nella posizione originale, quindi senza creare pro
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTgxMzYwMTQ0OF19
-->