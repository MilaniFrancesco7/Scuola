Migrazione IP server


Nel nostro caso, si deve migrare l’IP della rete LAN, da 192.168.1.0 a 192.168.31.0 , e l'IP della rete DMZ da 192.168.100.0 a 192.268.131.0 .

Il numero 31 indica il numero di postazione nel laboratorio

12.2 Migrazione indirizzo IP server

Per la migrazione dell'indirizzo IP del server avremo bisogno di uno strumento installato precedentemente, ovvero l'SSH, che useremo per connetterci in remoto al server dal client.

- agire dalla modalità root@client
- Inserire il seguente comendo
    - sshuds@ipServer
    - Rispondere "yes" alla domanda

Ora siamo possiamo agire come fossimo fisicamente sul terminale del server.

- agire dalla modalità root@server
- Inserire il seguente comando
    - ifconfig enp0s3 tempIP netmask 255.255.255.0
    - route add default gw newGW

- Entrare nella configurazione web di m0n0wall
- Interfaces: DMZ
    - IP: 192.168.131.0
- Services: DHCP server -> DMZ
    - Range: 192.168.131.100 to 192.168.131.199

- Riavviare il router

- Agire dalla modalità uds@server
- sudo dhclient enp0s3 -> Richiesta DHCP

In questo momento l'interfaccia di rete avrà due IP assegnati, per risolvere questo problema è necessario

- Agire dalla modalità root@server
- ifdown enp0s3 -> disabilita interfaccia
- ifup enp0s3 -> abilita interfaccia











