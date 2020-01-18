# Creazione VPN
Sul server
sudo apt-get install openvpn


Direttive server
- dev tun "num"
- port "porta"
- proto udp
- non serve direttiva remote ( se non c'è vuol dire che è un server )
Ho necessità che il server sia in ascolto su una precisa interfaccia
[listen IPmio] -> non serve

- ifconfig IPmio IPaltro //Differenza tra i due
esempio: ifconfig 192.168.209.1 192.168.210.1
ip

client 
direttive
- remote IPWANaltro

-- No certificati
-- chiave segreta

- openvpn --genkey --secret chiave.key
(condivisione)

secret./etc/openvpn/chiave.key

- log-append /var/log/openvpn-miavpn.log
#per i file di log
#attuare la rotazione dei log

opzioni da inserire
- comp-lzo #comprimere il traffico (ottimizzare il flusso dati) 
<!--stackedit_data:
eyJoaXN0b3J5IjpbNTAzMDEyOTIwLC0xNDgyNjM5MDM5LC0xMT
cxODQzNDcxLC0xMzI5NjcyOTg5XX0=
-->