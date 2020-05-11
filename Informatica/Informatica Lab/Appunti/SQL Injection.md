## Milani Francesco<br> 5 AI		<br>	02/05/2020
# Test con SQL Injection

Consegna: 

> Dopo aver seguito le videolezioni sulle tecniche di SQL injection, verificare su una propria applicazione **(niente prove su applicazioni e siti web altrui)** che richiede inserimento dati quanto questa sia eventualmente vulnerabile e, di seguito, riportare in un documento i risultati ottenuti durante le fasi di test (oscurare informazioni relative ad account e dati personali) e le istruzioni aggiunte in seguito per proteggere l'applicazione da tali attacchi.

In questo test andrò ad utilizzare un mio form di login.

## Attacco SQL Injection
La query utilizzata per il login è la seguente:

    $query = "SELECT  *  FROM users WHERE email = '$username' AND  password  = '$password'";

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
### Funzione mysql real escape string

Per poterci difendere possiamo inserire una funzione mysql real escape, scrivendola nel nostro codice in questo modo:

    $username = $_POST["username"];
    $username = mysql_real_escape_string($username);
    $password = $_POST["password"];
    $password = mysql_real_escape_string($password);

In questo modo andremo a rimuovere i caratteri speciali, quindi dalla stringa

    ' OR '1'='1'
 verranno rimossi gli apici, quindi sarà quasi impossibile un attacco attraverso apici o caratteri speciali.

<img src="https://i.ibb.co/vvrKgs2/accesso.png" alt="accesso" border="0"></a>

Nel caso la query fosse di questo tipo:

`$query = "SELECT  *  FROM users WHERE email = $username AND  password  = $password"`

si può notare come non ci sia il carattere di terminazione ' , quindi la query rimane aperta, non viene chiusa.

Per poter eseguire l'SQL Injection si può procedere all'inserimento di
`1 OR 1=1`
nei campi di username e password.

In questo caso il risultato sarà quindi positivo, dato che la query risultante sarà

    $query = "SELECT  *  FROM users WHERE 1 OR 1=1 AND  password  = 1 OR 1=1"

<img src="https://i.ibb.co/L5PfbFV/accesso.png" alt="accesso" border="0"></a>

<img src="https://i.ibb.co/qg3TxVM/accesso.png" alt="accesso" border="0"></a>

Quindi il nostro login non è ancora sicuro, dato l'avvenuto accesso attraverso SQL Injection.

### Funzione is numeric

Attraverso la funzione PHP

    is_numeric()
sarà eseguita una verifica sull'input, e se questo corrisponderà ad un tipo numerico non verrà eseguita la query.

La sintassi del controllo sarà quindi

    if(is_numeric($username))
    {
	    //Errore
    }


<img src="https://i.ibb.co/L5PfbFV/accesso.png" alt="accesso" border="0"></a>

<img src="https://i.ibb.co/vvrKgs2/accesso.png" alt="accesso" border="0"></a>



Questo rende impossibile l'accesso attraverso SQL Injection, in quanto non sarà possibile ne inserire caratteri speciali attraverso la funzione vista in precedenza, ne inserire un input numerico.

<!--stackedit_data:
eyJoaXN0b3J5IjpbOTM1MDg0NDksLTE5NDAxODE4MzUsMTEzNT
Y1MTM0OCwtMjkwMTA3MjkxXX0=
-->