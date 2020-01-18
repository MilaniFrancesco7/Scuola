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

- ifconfig IPmio IPaltro
esempio: ifconfig 192.168.209.1 192.168.210.1
ip

client 
direttive
- remote IPWANaltro



<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE3Njg2OTgwNywtMTMyOTY3Mjk4OV19
-->