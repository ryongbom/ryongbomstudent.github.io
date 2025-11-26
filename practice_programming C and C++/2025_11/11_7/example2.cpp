#include <stdio.h>

#define AGETAG 0 
#define DATETAG 1

typedef struct {
	int year;
	int month;
	int day;
} Date;

typedef struct {
	int tag;
	union {
	    int age;
	    Date date;
	} entry_date;
} Student;

int main() {
  	Student student;
	student.tag = AGETAG;
	student.entry_date.age = 15;
	if (student.tag == AGETAG) {
		int year = 2022 - student.entry_date.age + 12;
		printf("ËË ÂØ»¶Ë¼ %d-%d-%dËæ ËÓÂØÂ×Êî»¡³£³Ş.", year, 4, 1); 
	}
	else if (student.tag == DATETAG)
		printf("ËË ÂØ»¶Ë¼ %d-%d-%dËæ ËÓÂØÂ×Êî»¡³£³Ş.", student.entry_date.date.year, student.entry_date.date.month, student.entry_date.date.day); 

	return 0;
}
