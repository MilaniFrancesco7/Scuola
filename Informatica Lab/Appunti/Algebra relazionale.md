# Algebra relazionale

E' una branca dell'algebra che si utilizza per interrogare le basi di dati.
Come da definizione: linguaggio **procedurale** di **interrogazione di basi di dati.**

E' costituita da un insieme di operatori definiti su relazioni, che producono relazioni e che possono essere composti per formulare interrogazioni complesse. 

# Operazioni dell'algebra relazionale (operazioni relazionali)

 - **Unione**
 - **Differenza**
 - **Prodotto cartesiano**
 - **Proiezione**
 - **Selezione**
 - **Join**

Sono le operazioni che definiscono l'algebra relazionale.
Ogni operazione restituisce una relazione.
La join è un esempio di operazione addizionale, ovvero più operazioni di base combinate, che non aggiungono potere, ma sono utili per abbreviare.

## Unione

L'unione di due tuple si può compiere solo se:
- Hanno lo stesso **grado**, ovvero numero di campi
- Gli attributi sono **compatibili** cioè sono dello stesso tipo

Si indica con la " U "
- Le tuple duplicate vengono **eliminate**
- Il grado risultante della relazione è uguale al grado delle relazioni operandi.

R U S = Insieme delle tuple in R, in S o in entrambe

## Differenza
La differenza di due tuple si può compiere solo se:
- Hanno lo stesso **grado**
- Gli attributi sono **compatibili**

Si indica con la " --- "
- I nomi degli attributi sono quelli della prima relazione
- Il grado risultante della relazione è uguale al grado delle relazioni operandi

R --- S = insieme delle tuple che sono in R ma non in S

## Prodotto Cartesiano
Il prodotto cartesiano di due tuple si può compiere in ogni caso.

Si indica con la " x "
- I nomi degli attributi rimangono invariati, se sono uguali tra le due relazioni sarà opportuno rinominarli.
- Il grado risultante della relazione sarà la somma dei gradi relazi


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTIxOTUwNzc2NSwtMTU2NTY2MjgyM119
-->