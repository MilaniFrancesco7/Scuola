
# I Docker 
Servizio che permette di installare qualsiasi servizio(apache2, nano) su un "contenitore" senza che vengano salvati ulteriori dati al di fuori di questo contenitore.
Questo contenitore sarà una "copia" del nostro sistema.

hub.docker.com -> Docker pre-configurati

## Installazione

sudo apt-get install docker.io

## Utilizzo
Copia di un sistema ( ultima versione debian )
```bash
docker pull debian:latest
```
Visualizzare i docker presenti
```bash
docker images
```
#### Comandi
```bash
docker run -it --name debian debian:latest #del nome debian,lancia l'istanza debian:latest
```
Ora saremo entrati dentro ad una sottomacchina.
Le dimensioni del disco e le specifiche sono quelle della macchina, ma possono essere limitate.

L'indirizzo sarà 172.17.0.1 -> ovvero la scheda di rete che si affaccia verso tutti i docker presenti

eth0-> Fuori
docker0-> Dentro -> Switch ipotetico -> Container

Il docker all'installazione sarà totalmente senza servizi

Anche per ragioni di sicurezza, il docker viene chiuso dentro al suo contesto, in modo tale da non fare danni.

### Chiusura
```docker commit debian debian:v1 ```
Verrà creata un salvataggio allo stato del docker, in modo tale da poter tornare a lavorarci
Le modifiche vengono sommate al docker, ve
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjA2NzI1MzQ5NSwxMzc0MjQ5MTI5LDYzMz
Y3MjQ1MF19
-->