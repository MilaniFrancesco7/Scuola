<?php
  //ini_set( "display_errors", 0);

  include("parametri.php");

  $id=$_POST["id"];
  $nome=$_POST["nome"];
  $cognome=$_POST["cognome"];
  $indirizzo=$_POST["indirizzo"];
  $telefono=$_POST["telefono"];
  
  print("<html><head><title>Rubrica in PhP</title></head><body>");
  print("<h1>Rubrica in PhP</h1>");

  // Connessione al server dbms
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
  print("</body></html>");  
  // libero la memoria occupata dall'istruzione SELECT
  mysqli_free_result($result);
  mysqli_close($connect); // chiusura della connessione al server Mysql
?>