# Installazione mrtg per protocollo SNMP

SNMP = Simple Network Management Protocol
Protocollo di rete senza connessione che appartiene alla suite di protocolli Internet definito dalla IETF (Internet Engineering Task Force).

Community string: sorta di password o metodo di controllo utilizzato per dare l'accesso alle statistiche del router o di altri dispositivi

## Configurazione

nome community= public

Regola sulla wan -> UDP DMZ net * host-server 161 Allow SNMP connection
```
sudo apt-get install snmp snmpd -y
sudo apt-get install mrtg -y

sudo systemctl start snmpd
sudo systemctl enable snmpd

sudo mkdir /var/www/mrtg
```

La cartella di default è posizionata in /var/lib/mrtg

Questa directory non va bene in quanto non sarà accessibile direttamente dall'apache.
Per permettere l'accesso alla cartella da parte dell'apache si creerà un link simbolico, che permetterà di lasciare la cartella nella posizione originale, quindi senza creare problemi ad eventuali file di configurazione, ma potrà essere visionata anche da un'altra posizione. Nel nostro caso il link simbolico verrà creato con la cartella /var/www/mrtg

http://guide.debianizzati.org/index.php/Mrtg:_monitoriamo_la_banda

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTIzMTQ4MDIzOSw2MTA3MDcxMzcsODQ3MT
YzOTMzLDI3MjAzMjQzMSwtODE4NTgwMzM0LC0xNDA1MjQwOTIw
XX0=
-->