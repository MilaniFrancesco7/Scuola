<?php

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

function connessione($server, $username, $password)
{
	$conn = mysqli_connect($server, $username, $password) or die("Connessione non riuscita: ".mysqli_error($conn));
	return $conn;
}

$conn = connessione($server, $username, $password);
mysqli_select_db($conn, $database) or die ("Impossibile selezionare il db");

// Inserimento
if(isset($_POST['invia']))
{
	$query = "insert into $database.$tabella (nome, cognome, telefono, indirizzo) values
		('".$_POST['nome']."', '".$_POST['cognome']."', '".$_POST['telefono']."', '".$_POST['indirizzo']."')";
	$conn->query($query) or die("Errore: ".mysqli_error($conn));
	if(mysqli_affected_rows($conn) > 0)
	{
		$msg = "Inserimento avvenuto con successo";
		$colore = 0;
	}
	else if(mysqli_affected_rows($conn) == 0)
		$msg = "Attenzione! Nessuna riga &egrave stata inserita";
	else
		$msg = "Errore nell'inserimento del record";
}

// Modifica
if(isset($_POST['modifica']))
{
	$query = "update $database.$tabella set nome='".$_POST['nome']."', cognome='".$_POST['cognome']."', telefono='".$_POST['telefono']."',
	indirizzo='".$_POST['indirizzo']."' where id='".$_POST['id']."'";
	$conn->query($query) or die("Errore: ".mysqli_error($conn));
	if(mysqli_affected_rows($conn) > 0)
	{
		$msg = "Modifica avvenuta con successo";
		$colore = 0;
	}
	else if(mysqli_affected_rows($conn) == 0)

}

// Cancellazione parziale
if(isset($_POST['cancella']))
{
	$query = "delete from $database.$tabella where id='".$_POST['id']."'";
	$conn->query($query) or die("Errore: ".mysqli_error($conn));
	if(mysqli_affected_rows($conn) > 0)
	{
		$msg = "Cancellazione avvenuta con successo";
		$colore = 0;
	}
	else if(mysqli_affected_rows($conn) == 0)
		$msg = "L'id inserito non esiste";
	else
		$msg = "Errore nella cancellazione del record";
}

// Cancellazione totale
if(isset($_POST['tutto']))
{
	$query = "delete from $database.$tabella";
	$conn->query($query) or die("Errore: ".mysqli_error($conn));
	if(mysqli_affected_rows($conn) > 0)
	{
		$msg = "Cancellazione avvenuta con successo";
		$colore = 0;
	}
	else if(mysqli_affected_rows($conn) == 0)
		$msg = "Attenzione! Nessuna riga &egrave stata cancellata";
	else
		$msg = "Errore nella cancellazione dei record";
}

?>

<!DOCTYPE html>
<html xml:lang="it" lang="it">

<head>
	<title>Rubrica Gusella</title>
	<meta http-equiv="content-type" content="text/html;charset=utf-8" />
	<style>
		table, th, td
		{
			border: 1px solid black;
			border-collapse: collapse;
		}
		
		th, td
		{
			padding: 5px;
			text-align: left;    
		}
		
		.verde
		{
			color: lightgreen;
		}
		
		.rosso
		{
			color: red;
		}
	</style>
</head>

<body>
	<h1>Rubrica di Gusella Michele</h1>
	<?php stampa($msg, $colore); ?>
	
	<h3>Inserisci i dati:</h3>
	<form method="post">
		Nome:
		<input type="text" name="nome" maxlength="30" size="30" required> <br>
		Cognome:
		<input type="text" name="cognome" maxlength="30" size="30" required> <br>
		Indirizzo:
		<input type="text" name="indirizzo" maxlength="50" size="50" required> <br>
		Numero di telefono:
		<input type="text" name="telefono" maxlength="10" size="10" required> <br>
		<input type="reset" name="reset" value="Resetta i dati">
		<input type="submit" name="invia" value="Inserisci">
	</form>
	
	<h3>Modifica un record:</h3>
	<form method="post">
		ID:
		<input type="text" name="id" maxlength="3" size="30" placeholder="L'id del record che viene modificato" required> <br>
		Nome:
		<input type="text" name="nome" maxlength="30" size="30" required> <br>
		Cognome:
		<input type="text" name="cognome" maxlength="30" size="30" required> <br>
		Indirizzo:
		<input type="text" name="indirizzo" maxlength="50" size="50" required> <br>
		Numero di telefono:
		<input type="text" name="telefono" maxlength="10" size="10" required> <br>
		<input type="reset" name="reset" value="Resetta i dati">
		<input type="submit" name="modifica" value="Modifica il record">
	</form>
	
	<h3>Cancella un record:</h3>
	<form method="post">
		ID:
		<input type="text" name="id" size="30" maxlength="3" placeholder="L'id del record che viene cancellato"> <br>
		<input type="submit" name="cancella" value="Cancella il record selezionato">
		<input type="submit" name="tutto" value="Cancella tutti i record dalla tabella">
	</form>
	
	<h3>Rubrica:</h3>
	<table>
		<tr>
			<th>ID</th>
			<th>Nome</th>
			<th>Cognome</th>
			<th>Indirizzo</th>
			<th>Telefono</th>
		</tr>
		<?php
			$query = "select * from $database.$tabella";
			$risultato = mysqli_query($conn, $query) or die ("Errore nella query: ".mysqli_error($conn));

			while($cerco = mysqli_fetch_array($risultato))
			{
				echo "<tr>\n\t\t\t";
				echo "<td>$cerco[id]</td>\n\t\t\t";
				echo "<td>$cerco[nome]</td>\n\t\t\t";
				echo "<td>$cerco[cognome]</td>\n\t\t\t";
				echo "<td>$cerco[indirizzo]</td>\n\t\t\t";
				echo "<td>$cerco[telefono]</td>\n\t\t";
				echo "</tr>\n\t\t";
			}
			
			mysqli_free_result($risultato);
			mysqli_close($conn);
		?>
	</table>
</body>

</html>