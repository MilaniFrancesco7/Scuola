<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">

<head>
	<title>senza nome</title>
	<meta http-equiv="content-type" content="text/html;charset=utf-8" />
	<meta name="generator" content="Geany 1.32" />
</head>

<body>
	<h1>  Numeri primi da 20 a 50</h1>
	<?php
		function primo($num)
		{
			for($i=2;$i<$num;$i++)
				if(!($num%$i))
					return 0;
			return 1;
		}
		 
		$primi = 50;
		 
		for($i=20;$i<=$primi;$i++)
			if(primo($i))
				print $i." ";
	?>
	
	<h1> Fibonacci fino a 50 </h1>
	
	<?php
		function Fibonacci()
		{
			$n1=0;
			$n2=1;
			$n3;
			$i;
			$count=10;    
			echo $n1." ".$n2;   
		
			for($i=2;$i<$count;$i++)
			{    
				$n3=$n1+$n2;    
				echo " ".$n3;    
				$n1=$n2;    
				$n2=$n3;    
			}
		}
		
		Fibonacci();
	?>
</body>

</html>
