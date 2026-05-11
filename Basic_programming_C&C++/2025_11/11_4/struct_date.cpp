#include <stdio.h>
#include <string.h>

int month_day1[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int month_day2[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

typedef struct {
	int year;
	int month;
	int day;
}Date;

Date get_date(Date d, int n)
{
	int i = d.month - 1;
	int feb = 0, temp = month_day2[i]; 
	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		temp = month_day1[i];
	d.day = n + d.day;
	while (d.day > temp) {		
		if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
			d.day -= month_day1[i];
			feb = 1;
		}			
		else {
			d.day -= month_day2[i];
			feb = 0;
		}
		d.month++;
		if (i == 11)
		{
			i = 0;
			d.year++;
			d.month = 1;
		}
	i++;
	if (feb) temp = month_day1[i];
	else temp = month_day2[i];
	}
	return d;
}

int main()
{
	Date date, newdate;
	int n;
	scanf("%d/%d/%d", &date.year, &date.month, &date.day);
	scanf("%d", &n);
	newdate = get_date(date, n);
	printf("%d/%d/%d\n", newdate.year, newdate.month, newdate.day);
	return 0;
}
