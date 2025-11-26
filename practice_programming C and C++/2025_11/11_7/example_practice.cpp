#include <stdio.h>

typedef struct {
	int year;
	int month;
	int day;
} Date;

typedef union {
    int age;
    Date date;
} EntryDate;

typedef struct {
  	int no;
  	char name[20];
  	float score;
	EntryDate entry_date;
} Student;

int main() {
  	Student stu;
  	stu.entry_date.date.year = 2020;
  	printf("%d ", stu.entry_date.date.year);
	stu.entry_date.age = 12;
	printf("%d", stu.entry_date.date.year);
	return 0;
}
