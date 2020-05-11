<!--
Milani Francesco
5AI
050320

Pagina Index
-->

<html>
	<head>
		<title>Esame 2013</title>
		<meta name="viewport" content="width=device-width">
	</head>
	
	<body>
		<link href="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"></script>
		<script src="//cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>

		<nav class="navbar navbar-expand-lg navbar-dark bg-dark static-top">
			<div class="container">
                <a class="navbar-brand" href="index.php">Pagina Funzionamento Query SQL</a>
				<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarResponsive" aria-controls="navbarResponsive" aria-expanded="false" aria-label="Toggle navigation">
					<span class="navbar-toggler-icon"></span>
				</button>
				<div class="collapse navbar-collapse" id="navbarResponsive">
				</div>
			</div>
		</nav>
		
		<div class="wrapper fadeInDown">
            
            <div id="formContent">
				<?php
					session_start();
					
					if(isset($_SESSION['aggiunto']))
					{
						echo "Passeggero aggiunto con successo !<br>";
						unset($_SESSION['aggiunto']);
					}
				?>
			</div>
			&nbsp;
            <div id="formContent">
                <div class="fadeIn first">
					<p>Test Funzionamento Codice SQL</p>
				</div>
                
                <button type="button" onclick="window.location.href='/Esame2013/Entita/Addetto.php'">Visualizza "Addetto"</button>
                <button type="button" onclick="window.location.href='/Esame2013/Entita/Categoria.php'">Visualizza "Categoria"</button>
                <button type="button" onclick="window.location.href='/Esame2013/Entita/Controllo.php'">Visualizza "Controllo"</button>
                <button type="button" onclick="window.location.href='/Esame2013/Entita/Merce.php'">Visualizza "Merce"</button>
                <button type="button" onclick="window.location.href='/Esame2013/Entita/Passeggero.php'">Visualizza "Passeggero"</button>
                <button type="button" onclick="window.location.href='/Esame2013/Entita/Punto_Controllo.php'">Visualizza "Punto Controllo"</button>
                <button type="button" onclick="window.location.href='/Esame2013/Entita/Viaggio.php'">Visualizza "Viaggio"</button>
                <button type="button" onclick="window.location.href='/Esame2013/Query/Query1.php'">Visualizza Query 1</button>
                <button type="button" onclick="window.location.href='/Esame2013/Query/Query2.php'">Visualizza Query 2</button>
                <button type="button" onclick="window.location.href='/Esame2013/Query/Query3.php'">Visualizza Query 3</button>
                <button type="button" onclick="window.location.href='/Esame2013/Query/Query4.php'">Visualizza Query 4</button>
                <button type="button" onclick="window.location.href='/Esame2013/Query/Query5.php'">Visualizza Query 5</button>
                <button type="button" onclick="window.location.href='/Esame2013/Query/Query6.php'">Visualizza Query 6</button>
                <br>
                <button type="button" onclick="window.location.href='Inserisci_Passeggero.php'">Inserisci Passeggero</button>
			</div>
		</div>
	
	</body>
</html>
