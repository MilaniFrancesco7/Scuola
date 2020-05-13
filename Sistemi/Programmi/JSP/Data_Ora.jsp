<html>
    <head>
        <title>Data e Ora corrente</title>
    </head>

    <body>
        <h3> Ora corrente: </h3>
        <c:set var = "now" value = "<% = new java.util.Date()%>" />

        <p> <fmt:formatDate type = "time" 
            value = "${now}" /> </p>
    </body>        
</html> 