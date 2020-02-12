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

L'Unione, la Differenza e il Prodotto Cartesiano sono operazioni **binarie** perchè si servono di due relazioni.
La Proiezione e la Selezione sono operazioni **unarie** perchè si servono di una sola relazione.

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
Il prodotto cartesiano di due relazioni si può compiere in ogni caso.

Si indica con la " x "
- I nomi degli attributi rimangono invariati, se sono uguali tra le due relazioni sarà opportuno rinominarli.
- Il grado risultante della relazione sarà la somma dei gradi relazioni operandi

R x S = Prodotto cartesiano di grado k= kr + ks

## Proiezione
La proiezione di una relazione si può fare in ogni caso.

Si indica con il " π "
- La relazione avrà grado n, dipendente dagli attributi proiettati

πA1,A2...AM(R) = Proiezione di R su un insieme di attributi A

## Selezione
La selezione di una relazione si può compiere in ogni caso.

Si indica con il " ϱ " (Rho)
- Il risultato sarà una relazione che conterrà tutte e sole le tuple che verificheranno il predicato

ϱF(R) = Selezione su una relazione R dato un predicato F.

### Predicati

Predicato **semplice** : <. >. =. <=. >=
Combinazione **booleana** : AND (∧), OR (∨), NOT (¬)

## Join
La Join è un'operazione composta, ovvero un **prodotto cartesiano** seguito da una **selezione**.

Si indica con " |X| "
- Il grado risultante, come nel prodotto cartesiano, sarà la somma dei gradi
- Il risultato sarà una relazione, come nella selezione, che conterrà tutte e sole le tuple che verificheranno il predicato

R |X| a0a' S = Join di due relazioni R ed S, con attributi a(R) e a'(S).

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTI1NzMxNDQ3MSwtMTU2NTY2MjgyM119
-->