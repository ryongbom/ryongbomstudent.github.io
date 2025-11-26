#include <stdio.h> 
  
typedef struct {
    int year;
    int month;
    int day;
} Date;

int isLeapYear(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}

Date get_date(Date d, int n)
{
    int i, days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    days[2] = 28 + isLeapYear(d.year);
            
    for (i = 0; i < n; i++) { 
        d.day++;
        if (d.day > days[d.month]) {
            d.day = 1;
            d.month++;
            if (d.month > 12) {
                d.month = 1;
                d.year++;
                days[2] = 28 + isLeapYear(d.year);
            }
        }
    }
    return d;
}

int main() {
    Date d, newdate;
    int n;
    scanf("%d/%d/%d", &d.year, &d.month, &d.day);
    scanf("%d", &n);
    newdate = get_date(d, n);
    printf("%d/%d/%d\n", newdate.year, newdate.month, newdate.day);
    return 0;
}
