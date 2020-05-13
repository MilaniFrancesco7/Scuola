<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="ISO-8859-1" %>
<%@ page import="java.util.*" %>

<!DOCTYPE html>
<html>
    <head>
        <title>Data e Ora corrente</title>
    </head>

    <body bgcolor= <% 
    if(request.getParameter("bgcolor") == null)
    {
        out.print("");
    }
    else
    {
        out.print(request.getParameter("bgcolor"));
    }
    %>>
    <center>
        <h2> Data e Ora attuali: </h3>
        <h3><% out.print(new Date().toString()); %></h4>
  
        <h2> Scelta colore con POST</h2>  
        <form action="Data_Ora.jsp" method="post">
            <label for="favcolor">Scegli un colore di sfondo:</label>
            <input type="color" id="bgcolor" name="bgcolor" value="#000000"><br><br>
            <input type="submit">     
        </form>        

        <h2>Scelta colore con GET</h2> 
        <form action="Data_Ora.jsp" method="get">
            <label for="favcolor">Scegli un colore di sfondo:</label>
            <input type="color" id="bgcolor" name="bgcolor" value="#ff0000"><br><br>
            <input type="submit">     
        </form>

        <h2>Dettagli della connessione:</h2>
        Request method: 
        <%= request.getMethod() %>
        <br><br>
        Request URI: 
        <%= request.getRequestURI() %>
        <br><br>
        Request protocol: 
        <%= request.getProtocol() %>
        <br><br>
        Remote Host: 
        <%= request.getRemoteHost() %>
        <br><br>
        Remote Address: 
        <%= request.getRemoteAddr() %>
        <br>
    </center>
    </body>        
</html> 