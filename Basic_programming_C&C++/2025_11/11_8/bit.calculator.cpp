#include <stdio.h>

#define football 0
#define swim 1
#define music 2
#define art 3
#define basketball 4

typedef struct {
	int no;
	char name[20];
	float score;
	int hobby;
} Student;

int main() {
	Student stu;
	stu.hobby = 0;
	stu.hobby = stu.hobby | 1 << football; 
	stu.hobby |= 1 << swim;					
	if (stu.hobby & 1 << swim)				
		printf("ºãÊéË¾ ¼ÊÊ­ÂÙ³Þ.\n");
	stu.hobby &= ~(1 << football);			
	if (stu.hobby & 1 << football == 0)		
		printf("¾¢°é¶¦ ¼ÊÊ­Â×¼è Ê±²÷³Þ.\n");
	
	return 0;
}
