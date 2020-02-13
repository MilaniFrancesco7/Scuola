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


valori numerici oid -> Standard rispettato per le apparecchiature che supportano snmpd

Configurazione snmpd sul sever

### SNMPD Server per mostrare le informazioni del file system

1.  scaricare il pacchetto cfgstoragemaker
[http://snapshot.debian.org/archive/debian-archive/20090802T004153Z/debian/pool/main/c/cfgstoragemaker/cfgstoragemaker_1.1-3_all.deb](http://snapshot.debian.org/archive/debian-archive/20090802T004153Z/debian/pool/main/c/cfgstoragemaker/cfgstoragemaker_1.1-3_all.deb)
3.  trasferirlo da host a server con sftp ( Attraverso FileZilla )
4.  Nel server inserire il comando:
```
sudo dpkg -i cfgstoragemaker_1.1-3_all.deb
```
5. Creare un file nominato "HOST-RESOURCES-MIB.t
copiare il contenuto dal seguente link all'interno del file /usr/share/snmp/mibs/HOST-RESOURCES-MIB.txt [https://github.com/haad/net-snmp/blob/master/mibs/HOST-RESOURCES-MIB.txt](https://github.com/haad/net-snmp/blob/master/mibs/HOST-RESOURCES-MIB.txt)
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE2MDg4ODE5ODksLTE1NjA2NzY3ODgsMT
k5NDE1NjUwNSwtMjMxNDgwMjM5LDYxMDcwNzEzNyw4NDcxNjM5
MzMsMjcyMDMyNDMxLC04MTg1ODAzMzQsLTE0MDUyNDA5MjBdfQ
==
-->