/*
 * Francesco Milani
 * 
 * Esercizio sulle struct
 *
 */


#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct sdate
	{
		int day;
		int month;
		int year;	
		
	} date;
	
	typedef struct stime
	{
		int hour;
		int minutes;
		int seconds;
		
	} time;
	
	typedef struct timestamp
	{
			date sdate;
			time stime;
			
	} timestamp;
	

	date dateInput()
	{
		
		date	Datex;
		
		int 	x;
		int		y=1;
		
		while (y==1){
		printf("Insert the number of the day: ");
		scanf("%d",&Datex.day);
		
		printf("Insert the month: ");
		scanf("%d",&Datex.month);
		
		printf("Insert the year: ");
		scanf("%d",&Datex.year);
	
		x=isdatevalid(Datex);	
		
		if(x==1)
		{
			printf("Re-Insert the date\n");
			y=1;
		}
		else
			y=0;
		}
	
		return Datex;
		
	}
	
	
	int isdatevalid(date Datex)														//Funzione che controlla la data
{
	if(Datex.month>12 || Datex.month<1)
	{
		printf("Error in month\n");
		
		return 1;	
	}
	
	
	
	if(Datex.month==1 || Datex.month==3 || Datex.month==5 || Datex.month==7 || Datex.month==8 || Datex.month==10 || Datex.month==12)			 
	{
		if(Datex.day<1 || Datex.day>31)
		{
		
		printf("Error in day or month\n");
		
		return 1;
		
		}
	}	
	
	if(Datex.month==4 || Datex.month==6 || Datex.month==9 || Datex.month==11)
	{
		if(Datex.day>30 || Datex.day<1)
		{
		
		printf("Error in day or month\n");
		
		return 1;
		
		}
		
	}
	
	if(Datex.month==2)
	{
		if(Datex.day<1 || Datex.day>29)
		{
		
		printf("Error in day or month\n");
		
		return 1;
		
		}
	}

	return 0;
}
	
	
	
	time timeInput()
	{
		
		time	Timex;
		
		printf("Insert the hour: ");
		scanf("%d",&Timex.hour);
		
		printf("Insert the minutes: ");
		scanf("%d",&Timex.minutes);
		
		printf("Insert the seconds: ");
		scanf("%d",&Timex.seconds);
		
		//Controllo validità ora
		
		return Timex;
	}
	
	int istimevalid(time Timex)
	{
		
		if(Timex.hour<0 || Timex.hour>23)
		{
			printf("Error in the hour\n");
			
			return 1;
		}
		
		if(Timex.minutes<0 || Timex.minutes>59)
		{
			printf("Error in the minutes\n");
			
			return 1;
		}
		
		if(Timex.seconds<0 || Timex.seconds>59)
		{
			printf("Error in the seconds\n");
			
			return 1;
		}
		
		
	}
	
	
	
	void printDate(date Datex)
	{
		printf("The date is: %d/%d/%d\n",Datex.day,Datex.month,Datex.year);
	} 
	
	void printTime(time Timex)
	{
		printf("The time is: %d:%d:%d\n",Timex.hour,Timex.minutes,Timex.seconds);
	}		
	
	
	
int main()
{
	
	date Datey=dateInput();
	
		printDate(Datey);
	
	time Timey=timeInput();
	
		printTime(Timey);
	
	
	
	return 0;
}

