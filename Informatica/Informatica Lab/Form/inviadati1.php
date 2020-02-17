<html>
<head>
	<title>Riepilogo dati</title>
	<meta http-equiv="content-type" content="text/html;charset=utf-8" />
</head>
<body>
	Benvenuto <?php echo $_POST["nome"]," ",$_POST["cognome"]; ?><br>
	Ore Mensili: <?php echo $_POST["ore"]; ?><br>
	Paga Oraria: <?php echo $_POST["paga"]; ?><br>
	<?php
	$paga=$_POST["paga"];
	$ore=$_POST["ore"];
	$stipendio=$paga*$ore;
	echo "Stipendio: ".$stipendio."<br>";
	?>
</body>
</html>
