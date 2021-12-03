#include "point.h"
#include <stdio.h>

void printPoint(point * points, int pointIdx){
	printf("Point impression: \n");
	int i;
	int j;
	for(i = 0; i < pointIdx; i++){
	
	printf("%d --> %f, %f\n\n", i+1, points[i].x, points[i].y);
}
return;
}
