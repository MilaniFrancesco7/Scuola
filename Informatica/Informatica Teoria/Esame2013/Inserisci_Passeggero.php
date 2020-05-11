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
                <a class="navbar-brand" href="index.php">Pagina Passeggero</a>
				<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarResponsive" aria-controls="navbarResponsive" aria-expanded="false" aria-label="Toggle navigation">
					<span class="navbar-toggler-icon"></span>
				</button>
				<div class="collapse navbar-collapse" id="navbarResponsive">
				</div>
			</div>
		</nav>
		
		<div class="wrapper fadeInDown">
			<div id="formContent2">
                <div class="fadeIn first">
					<p>Test Funzionamento Codice SQL</p>
				</div>

                <form action="insert.php" method="get">
                    <input type="text" id="nome" class="fadeIn second" name="nome" placeholder="Nome">
                    <input type="text" id="cognome" class="fadeIn second" name="cognome" placeholder="Cognome">
                    <input type="text" id="nazionalita" class="fadeIn second" name="nazionalita" placeholder="Nazionalità">
                    <br>
                    <input type="submit" class="fadeIn fourth" value="Esegui Query">
                </form>
			</div>
		</div>
	
	</body>
</html>
