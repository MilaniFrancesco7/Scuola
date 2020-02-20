# Cacti
Con il cacti andremo a tracciare
- m0n0wall
- Server -> Dischi, Rete
- Apparecchiatura a scelta dell'istituto (switch) -> 172.30.1. (100-125) 
--- non tutti i numeri sono coperti ---

## Procedura
https://linuxhostsupport.com/blog/how-to-install-cacti-snmp-monitoring-tool-on-debian-9/

```bash
sudo apt update && sudo apt -y upgrade
sudo apt install mariadb-server mariadb-client
```
In modalità root
```bash
mysql_secure_installation
#password sempre lasolita
```
y sempre
```bash
sudo nano /etc/mysql/mariadb.conf.d/50-server.cnf
#modificare le righe
character-set-server = utf8mb4
collation-server = utf8mb4_unicode_ci

sudo systemctl restart mariadb #restart mariadb
sudo apt install php php-mysql php-snmp
sudo apt install cacti snmpd #installa cacti
```
Configure database for cacti with dbconfig-common? -> yes
Password-> lasolita

credenziali
nome utente -> admin
password -> lasolita           
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTExMzUxOTA4NzQsLTE1NTMwMjY5OTQsLT
c5NDI4NTA3OSwyMDg2NDcwNTgyLC0xNDkzODU0MzhdfQ==
-->