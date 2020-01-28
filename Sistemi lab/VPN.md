log# Creazione VPN
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


## File server.conf
dev tun10
port 1194
proto udp
remote 172.30.4.110
ifconfig 192.168.202.1 192.168.231.1
secret /etc/openvpn/secret.key
log-append /var/log/openvpn-zenmilani.log
comp-lzo
<!--stackedit_data:
<<<<<<< HEAD
eyJoaXN0b3J5IjpbNTAzMDEyOTIwLC0xNDgyNjM5MDM5LC0xMT
cxODQzNDcxLC0xMzI5NjcyOTg5XX0=
-->
=======
eyJoaXN0b3J5IjpbNzU2MTczNzczLDUwMzAxMjkyMCwtMTQ4Mj
YzOTAzOSwtMTE3MTg0MzQ3MSwtMTMyOTY3Mjk4OV19
-->
>>>>>>> 5b4c31b37852f410c7c21967906fc28fe9a877a9
