<?php

function somma($a, $b)
{
	return ($a + $b);
}

?>
<head>
<title>Prova funzione</title>
</head>
<body>
	<?php
	$valore1 = 10;
	$valore2 = 42;
	print("valore1 = $valore1<br>");
	print("valore2 = $valore2<br>");
	$somma = somma($valore1, $valore2);
	print("somma = $somma<br>");
	?>
</body>

</html>
