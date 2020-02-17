<?php
  //ini_set( "display_errors", 0);

  include("parametri.php");

$msg = ""; // Variabile con cui avvisare l'utente
$colore = 1; // 0 = verde; 1 = rosso

// Cambio il colore di $msg in base alla natura dell'avviso (es. verde se l'operazione e' avvenuta con successo)
function stampa($msg, $colore)
{
	if($msg != "")
	{
		if($colore == 0)
			echo "<h2 class=\"verde\">".$msg."</h2>";
		else
			echo "<h2 class=\"rosso\">".$msg."</h2>";
	}
}

$connect = mysqli_connect($server, $username, $password)
    or die("Connessione non riuscita: " . mysqli_error($connect));
print ("<h4>Connesso con successo al server!</h4> " . "$server <br>");
  
  // selezione database
  mysqli_select_db($connect, $database) 
    or die ("Impossibile selezionare il db");
  // Esecuzione della query
  $table = "contatto"; // nome della tabella contenuta nel db
  $query = "insert into $table(ID,Nome,Cognome,Indirizzo,Telefono) values('$id','$nome','$cognome','$indirizzo','$telefono');"; // query da eseguire
  $result = mysqli_query($connect, $query)
    or die ("Errore nella query 1 " . mysqli_error($connect));
  $table = "contatto"; // nome della tabella contenuta nel db
  $query = "select * from $database.$table"; // query da eseguire
  $result = mysqli_query($connect, $query)
    or die ("Errore nella query 2" . mysqli_error($connect));

  print("<h3>Riepilogo contatti</h3>");  

  // Visualizzo il risultato della query
  while ($search = mysqli_fetch_array($result))
    /* $search è un vettore associativo, per accedere all'elemento
       si usa come indice il nome del campo della tabella */
    {
      print "<br>";
      print "$search[ID] " . "$search[Nome] " .  "$search[Cognome] " . "$search[Indirizzo] " . "$search[Telefono]";
    }
  // libero la memoria occupata dall'istruzione SELECT
  mysqli_free_result($result);
  mysqli_close($connect); // chiusura della connessione al server Mysql
?>