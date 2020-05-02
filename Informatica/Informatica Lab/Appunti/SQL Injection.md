

# Test con SQL Injection

Consegna: 

> Dopo aver seguito le videolezioni sulle tecniche di SQL injection, verificare su una propria applicazione **(niente prove su applicazioni e siti web altrui)** che richiede inserimento dati quanto questa sia eventualmente vulnerabile e, di seguito, riportare in un documento i risultati ottenuti durante le fasi di test (oscurare informazioni relative ad account e dati personali) e le istruzioni aggiunte in seguito per proteggere l'applicazione da tali attacchi.

In questo test andrò ad utilizzare un mio form di login.

La query utilizzata per il login è la seguente:

    $query = "SELECT  *  FROM users WHERE email = '$username' AND  password  = '$password'";

Per poter eseguire un attacco SQL Injection sarà necessario andare ad inserire nei campi di nome utente e password questa stringa:

    'OR '1'='1

In questo modo, la query risultante sara:

    SELECT * FROM users WHERE email = '' OR '1'='1' AND passowr = '' OR '1'='1';

Come si può notare, attraverso il primo apice andremo a chiudere il testo dove dovrebbe esserci scritto l'username, andando poi ad inserire del codice SQL che ci restituirà TRUE, data l'uguaglianza 1=1 sempre vera.

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE2NDM3OTMzOTRdfQ==
-->