
</body>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">

<head>
	<title>Fibonacci_Pitagorico</title>
	<meta http-equiv="content-type" content="text/html;charset=utf-8" />
	<meta name="generator" content="Geany 1.32" />
		<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
<?php
	echo "<center><h1> Esempio di output con tag html prodotti con document.write </h1>";
	echo " <h4>Successione di Fibonacci</h4>";
	
	function Fibonacci()
	{
		$n1=0;
		$n2=1;
		$n3;
		$i;
		$count=10;    
		echo $n1." ".$n2;//printing 0 and 1    
    
		for($i=2;$i<$count;$i++)//loop starts from 2 because 0 and 1 are already printed    
		{    
			$n3=$n1+$n2;    
			echo " ".$n3;    
			$n1=$n2;    
			$n2=$n3;    
		}
	}
	
	Fibonacci();


		function TavolaPitagorica()
		{
			$r=11;
			$c=11;
			$riga;
			$colonna;
			
			echo "<table border=\"5\">";
		  for ($riga = 0; $riga < $r; $riga++)
		  {
			echo "<tr>"; // scrivo il tag di apertura riga
		    
		    for ($colonna = 0; $colonna < $c; $colonna++)
				echo "<td>".$riga*$colonna."</td>";
		      
			echo "</tr>"; // scrivo il tag per chiusura riga  
		  }
		  echo "</table>";  // chiudo il tag table
		  
		}   
	
	TavolaPitagorica();

	echo "</center>";
?>

</body>
</html>
