<?php

	session_start();

	$connect = mysqli_connect("localhost", "root", "", "esame2013");
		  
	//Controllo connessione
	if (!$connect)
	{
		echo "Connessione al Database fallita: " . mysqli_connect_error();
		exit();
	}
	
	$nome = $_GET["nome"];
	$cognome = $_GET["cognome"];
	$nazionalita = $_GET["nazionalita"];
	
	$query = "INSERT INTO Passeggero (Nome, Cognome, Nazionalita) VALUES ('$nome', '$cognome', '$nazionalita');";
				
	if(mysqli_query($connect, $query))
	{
		$_SESSION['aggiunto'] = 1;
	}
	
	mysqli_close($connect);
	
	header("location: index.php");

?>
