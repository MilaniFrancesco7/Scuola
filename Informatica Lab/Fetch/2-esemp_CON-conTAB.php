<HTML>
<HEAD>
 <TITLE>New Document</TITLE>
</HEAD>
<BODY>

   <h1> Esempio connessione </h1>
   
   <table border="1">

  <tr >
      <td bgcolor=GREY> codice   </td>
      <td  bgcolor=GREY> nome nave</td>
       <td  bgcolor=GREY> bandiera</td>
   </tr>

        <?php
           $db =mysqli_connect("localhost","root","","agenzia");
            if(!$db)  {
                print ("Errore di connessione");
                die();
                       }
           /*
           OPPURE CONTROLLARE CON:
           if ($db->connect_errno){
            echo "connessione fallita ";
            exit();
            }*/
            $query="Select * from navi";
            $result = $db -> query($query);
        if(!$result)
            die ("Errore nella query");
          echo "<h1>Contenuto della tabella NAVI</h1>";
            /*
            while($riga=mysqli_fetch_object($result )){
            $id=$riga->Id_Nave;
            $nave=$riga->Nave;
            $bandiera = $riga->Bandiera;
            echo $id."  -  ".$nave."  -  ".$bandiera;
            echo "<br>";
                 }
              */
            /* SECONDO METODO METTIAMO TUTTO IN TABELLA HTML
               e usiamo fetch array
            */
 while($row=mysqli_fetch_array($result))
 //oppure  mysqli_fetch_assoc
    {
  ?>

   <tr>
      <td>
       <?php
       echo ($row["Id_Nave"]);    ?>
      </td>
      <td>
      <?php
      echo ($row["Nave"]);
      ?>
      </td>
       <td>
      <?php
      echo ($row["Bandiera"]);      }
      ?>
      </td>
  </tr>


  <?php
/*modificare per visualizzare descrizione prodotto non codice*/
mysqli_free_result($result);
mysqli_close($db);
?>
</table>
</body>
</html>
