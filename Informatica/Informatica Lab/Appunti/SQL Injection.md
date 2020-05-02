

# Test con SQL Injection

Consegna: 

> Dopo aver seguito le videolezioni sulle tecniche di SQL injection, verificare su una propria applicazione **(niente prove su applicazioni e siti web altrui)** che richiede inserimento dati quanto questa sia eventualmente vulnerabile e, di seguito, riportare in un documento i risultati ottenuti durante le fasi di test (oscurare informazioni relative ad account e dati personali) e le istruzioni aggiunte in seguito per proteggere l'applicazione da tali attacchi.

In questo test andrò ad utilizzare un mio form di login.

## Attacco SQL Injection
La query utilizzata per il login è la seguente:

    $query = "SELECT  *  FROM users WHERE email = $username AND  password  = $password";

Per poter eseguire un attacco SQL Injection sarà necessario andare ad inserire nei campi di nome utente e password questa stringa:

    'OR '1'='1

In questo modo, la query risultante sara:

    SELECT * FROM users WHERE email = '' OR '1'='1' AND passowr = '' OR '1'='1';

Come si può notare, attraverso il primo apice andremo a chiudere il testo dove dovrebbe esserci scritto l'username, andando poi ad inserire un'operazione OR che ci restituirà TRUE, data l'uguaglianza 1=1 sempre vera. 
La stessa cosa avverrà anche nel campo della password.

In questo modo il database restituirà tutte le righe della tabella, quindi dando una risposta positiva allo script di login che ci lascerà perciò accedere al sito.

<img src="https://i.ibb.co/2jnNnnt/accesso.png" alt="accesso" border="0"></a>

<img src="https://i.ibb.co/qg3TxVM/accesso.png" alt="accesso" border="0"></a>

Questo determina la non sicurezza del nostro login, data la facilità di accesso tramite SQL Injection.

##  Metodi di difesa
### Mysql real escape string

Per poterci difendere possiamo inserire una funzione mysql real escape, scrivendola nel nostro codice in questo modo:

    $username = $_POST["username"];
    $username = mysql_real_escape_string($username);
    $password = $_POST["password"];
    $password = mysql_real_escape_string($password);

In questo modo andremo a rimuovere i caratteri speciali, quindi dalla stringa

    ' OR '1'='1'
 verranno rimossi gli apici, quindi sarà quasi impossibile un attacco attraverso apici o caratteri speciali.

<img src="https://i.ibb.co/vvrKgs2/accesso.png" alt="accesso" border="0"></a>

Rimane però ancora un problema:
L'escape string, 
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjk0MTA0MDQzLDExMzU2NTEzNDgsLTI5MD
EwNzI5MV19
-->