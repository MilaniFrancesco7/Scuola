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
                <a class="navbar-brand" href="index.php">Pagina Controllo</a>
				<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarResponsive" aria-controls="navbarResponsive" aria-expanded="false" aria-label="Toggle navigation">
					<span class="navbar-toggler-icon"></span>
				</button>
				<div class="collapse navbar-collapse" id="navbarResponsive">
				</div>
			</div>
		</nav>
		
		<div class="wrapper fadeInDown">
			<div id="formContent3">
            
                <?php
                    $connect = mysqli_connect("localhost", "root", "", "esame2013");
					
					$query = "SELECT * from Controllo;";
					
					$result = mysqli_query($connect, $query);

					echo "<table>";
					
					echo "<tr>
                              <th>Data Inizio          </th>
                              <th>Ora Inizio          </th>
                              <th>Data Fine          </th>
                              <th>Ora Fine          </th>
                              <th>Esito          </th>
                              <th>Dazio          </th>
                              <th>Codice Merce          </th>
                              <th>Punto Controllo          </th>
                              <th>Codice Addetto          </th>
                              <th>Note          </th>
                              <th>Contestazione          </th>
						  </tr>";

					while($search = mysqli_fetch_array($result))
					{
						print "<tr>" . "<td>$search[Data_In]</td>" . "<td>$search[Ora_In]</td>" . "<td>$search[Data_Fin]</td>" . "<td>$search[Ora_Fin]</td>" . "<td>$search[Esito]</td>" . "<td>$search[Dazio]</td>" . "<td>$search[Codice_Merce]</td>" . "<td>$search[Codice_Punto]</td>" . "<td>$search[Codice_Addetto]</td>" . "<td>$search[Note]</td>" . "<td>$search[Contestazione]</td></tr>";
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
