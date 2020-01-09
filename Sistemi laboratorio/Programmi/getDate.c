#include <stdio.h>
#include <time.h>


void mese(int m)

{

   if(m == 1)

      printf("gennaio ");

   else if(m == 2)

      printf("febbraio ");

   else if(m == 3)

      printf("marzo ");

   else if(m == 4)

      printf("aprile ");

   else if(m == 5)

      printf("maggio ");

   else if(m == 6)

      printf("giugno ");

   else if(m == 7)

      printf("luglio ");

   else if(m == 8)

      printf("agosto ");

   else if(m == 9)

      printf("settembre ");

   else if(m == 10)

      printf("ottobre ");

   else if(m == 11)

      printf("novembre ");

   else

      printf("dicembre ");

}


int main()

{

   time_t t = time(NULL);

   struct tm tm = *localtime(&t);

   printf("Content-Type: text/html");

   printf("\n\n");

   printf("<!DOCTYPE html>\n<html>\n<head>\n\t<title>CGI Milani</title>\n</head>\n<body style=\"background-color:black; text-align: center;\" text=\"white\">\n\t<h1>Data e ora:</h1>\n\t<p>");

   printf("%d ", tm.tm_mday);

   mese(tm.tm_mon + 1);

   printf("%d %d:%d:%d</p>\n", tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

   printf("</body>\n</html>");

   return 0;

}
