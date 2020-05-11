/*  Milani Francesco 
*   5 AI
*   20042020 
*   
*   Esercizio di laboratorio di TPSIT
*
*   La servlet se interrogata dal browser "normalmente" dovrà proporre una semplice pagina con un form 
*   dove si deve indicare data e ora di inizio e fine e descrizione appuntamento.
*   La data e l'ora di inizio e fine dovrà essere proposta non tramite javascript ma tramite generazione 
*   predefinita dalla servlet come orario corrente per l'inizio, e dopo un ora per la fine.
*   L'utente può comunque modificare in libertà gli orari.
*   
*   Alla conferma della form la servlet stessa dovrà restituire un contenuto XML pronto per essere 
*   digerito dall'applicazione calendario di propria preferenza.
*
*   Opzione 1: prevedere la risposta con tipi diversi di file calendario, xml o meno.
*/

import java.io.*;
import java.text.*;
import java.util.Date;
import javax.servlet.*;
import javax.servlet.http.*;

public class calendario_Milani extends HttpServlet 
{

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException 
    {
    
        if(req.getParameter("inviadati") == null)       // Se il pulsante non è stato attivato
        {
            String pattern = "yyyy-MM-dd";              // Pattern per la data
            SimpleDateFormat simpleDateFormat = new SimpleDateFormat(pattern);
            String currentdate = simpleDateFormat.format(new Date());
            
            String timepattern = "HH:mm";               // Pattern per l'ora completa
            String hourpattern = "HH";                  // Pattern per l'ora
            String minutepattern  = "mm";               // Pattern per i minuti

            SimpleDateFormat simpleTimeFormat = new SimpleDateFormat(timepattern);
            SimpleDateFormat simpleHourFormat = new SimpleDateFormat(hourpattern);
            SimpleDateFormat simpleMinuteFormat = new SimpleDateFormat(minutepattern);
            String currenttime = simpleTimeFormat.format(new Date());
            String currenthour = simpleHourFormat.format(new Date());
            String currentminute = simpleMinuteFormat.format(new Date());

            int currenthourint = Integer.parseInt(currenthour);         // Calcolo dell'ora seguente
            int nexthour = currenthourint + 1;

            if(currenthourint == 24)
                nexthour = 00;     

            res.setContentType("text/html");                            // Sezione HTML
            PrintWriter out = res.getWriter();

            out.println("<html>");
            out.println("<head>");
            out.println("<title>Calendario Milani</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Calendario Milani</h1>");
            out.println("<form method=\"POST\">");

            out.println("Giorno e ora di inizio appuntamento:");
            out.println("<br>");
            out.println("<input type=\"date\" id=\"date\" name=\"datestart\" value=\""+currentdate+"\"max=\"2030-01-01\">");
            out.println("<input type=\"time\" id=\"time\" name=\"timestart\" value=\""+currenttime+"\">");
            out.println("<br>");
            out.println("<br>");

            out.println("Giorno e ora di fine appuntamento:");
            out.println("<br>");
            out.println("<input type=\"date\" id=\"date\" name=\"datefinish\" value=\""+currentdate+"\"max=\"2030-01-01\">");
            out.println("<input tyoe=\"time\" id=\"time\" name=\"timefinish\" value=\""+nexthour+":"+currentminute+"\">");  
            out.println("<br>");
            out.println("<br>");

            out.println("<input type=\"submit\" name=\"inviadati\" value=\"Invia i dati\">");
            out.println("</form>");
            out.println("</body>");
            out.println("</html>");
        }
        else
        {
            res.setContentType("text/xml");                 // Sezione XML
            PrintWriter out = res.getWriter();
            
            out.println("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
            out.println("<calendar>");
            out.println("<event>");

            out.println("<datestart>"+req.getParameter("datestart")+"</datestart>");
            out.println("<timestart>"+req.getParameter("timestart")+"</timestart>");

            out.println("<datefinish>"+req.getParameter("datefinish")+"</datefinish>");
            out.println("<timefinish>"+req.getParameter("timefinish")+"</timefinish>");

            out.println("</event>");
            out.println("</calendar>");
        }
    }

   public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException 
   {
       doGet(req, res);
   }

}