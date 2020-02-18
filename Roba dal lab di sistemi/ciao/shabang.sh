#!/bin/bash
PORTA=8080;
ESEGUIBILE="./es"
while true
do
	echo "Invocazione ${ESEGUIBILE} in porta ${PORTA}"
	nc.traditional -l -p${PORTA} -c"${ESEGUIBILE}"
done
