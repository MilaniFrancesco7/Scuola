# Installazione mrtg per protocollo SNMP

SNMP = Simple Network Management Protocol
Protocollo di rete senza connessione che appartiene alla suite di protocolli Internet definito dalla IETF (Internet Engineering Task Force).

Community string: sorta di password o metodo di controllo utilizzato per dare l'accesso alle statistiche del router o di altri dispositivi

## Configurazione

Sulla community string inserire il nomehost

nome host scelto= milani

```
```
sudo apt-get install snmp snmpd -y
```
sudo apt-get install mrtg -y
```
sudo mkdir /var/www/mrtg
```

```

La cartella di default è posizionata in /var/lib/mrtg

Questa directory non va bene in quanto non sarà accessibile direttamente dall'apache.
Per permettere l'accesso alla cartella da parte dell'apache si creerà un link simbolico, che permetterà di lasciare la cartella nella posizione originale, quindi senza creare problemi ad eventuali file di configurazione, ma potrà essere visionata anche da un'altra posizione. Nel nostro caso il link simbolico verrà creato con la cartella /var/www/mrtg



<!--stackedit_data:
eyJoaXN0b3J5IjpbMTAwMzc0OTk4NiwtODE4NTgwMzM0LC0xND
A1MjQwOTIwXX0=
-->