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
                <a class="navbar-brand" href="index.php">Pagina Funzionamento Query 6 SQL</a>
				<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarResponsive" aria-controls="navbarResponsive" aria-expanded="false" aria-label="Toggle navigation">
					<span class="navbar-toggler-icon"></span>
				</button>
				<div class="collapse navbar-collapse" id="navbarResponsive">
				</div>
			</div>
		</nav>
		
		<div class="wrapper fadeInDown">
			<div id="formContent4">
            
                <?php
                    $connect = mysqli_connect("localhost", "root", "", "esame2013");
					
					$query = "SELECT * from Punto_Controllo;";
					
					$result = mysqli_query($connect, $query);

					echo "<table>";
					
					echo "<tr>
                              <th>Posizione          </th>
						  </tr>";

					while($search = mysqli_fetch_array($result))
					{
						print "<tr>" . "<td align='center'>$search[Posizione]</td></tr>";
					}
					
					echo "</table>";
                ?>
                
                <center>
                    <button type="button" onclick="window.location.href='../index.php'">Torna al Menù</button>
                </center>
			</div>
		</div>
	
	</body>
</html>
