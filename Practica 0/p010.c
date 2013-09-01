#include<stdio.h>

struct pto{
	float x;
	float y;
};

struct pto medio(struct pto p1, struct pto p2)
{
	struct pto m;
	m.x=((p1.x+p2.x)/2);
	m.y=((p1.y+p2.y)/2);
	return m;
}

int main(void)
{
	struct pto p1, p2;
	p1.x=2;
	p1.y=4;
	p2.x=3;
	p2.y=8;
	
	printf("el punto medio es (%f,%f)\n", medio(p1,p2).x,medio(p1,p2).y);
	return 0;
}		 	
