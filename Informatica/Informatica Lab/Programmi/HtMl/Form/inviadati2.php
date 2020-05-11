<html>
<head>
	<title>Riepilogo dati</title>
	<meta http-equiv="content-type" content="text/html;charset=utf-8" />
	<meta name="generator" content="Geany 1.32" />
</head>

<body>
	Benvenuto al calcolo dei cateti<br>
	Cateto 1: <?php echo $_POST["cateto1"]; ?><br>
	Cateto 2: <?php echo $_POST["cateto2"]; ?><br>
	<?php
	$cateto1=$_POST["cateto1"];
	$cateto2=$_POST["cateto2"];
	$ipotenusa=($cateto1*$cateto1)+($cateto2*$cateto2);
	echo "Ipotenusa: ".sqrt($ipotenusa)."<br>";
	?>
</body>

</html>
