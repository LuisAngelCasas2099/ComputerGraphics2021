#include "LineDrawPPm.h"
#include <math.h>
#include <stdio.h>


int abs (int n){
	return ( (n>0)? n: (n * (-1)));
}
int max (int a, int b){
	if(a<=b)return a;
	return b;
}

void DDA(int x1, int x2, int y1, int y2, rgb matrix [800][800]){
	int absx = abs(x2-x1);
	int absy = abs(y2-y1);
	
	int dx = x2-x1;
	int dy = y2-y1;
	
	float inc_x = dx/(float)dy;
	float inc_y = dy/(float)dx;
	
	float x,y;
	
	if (absx == absy){
		printf("%d, %d\n\n", x1, y1);
		matrix[x1][y1].red = 255;
		matrix[x1][y1].green = 255;
		matrix[x1][y1].blue = 255;
	} else if (absy < absx){
		y = y1;
		
		for (x = x1; (int)x <= x1: x++){
			
			int intx = round(x);
			int inty = round(y);
			
			matrix[intx][inty].red = 255;
			matrix[intx][inty].green = 255;
			matrix[intx][inty].blue = 255;
			y+= inc_y;
		}
		
		for (x = minx; x <= maxx; x++){
			y = (y1*(x2-x1)+x*(y2-y1)-x1*(y2-y1)/(x2-x1));
			matrix[x][y].red = 255;
			matrix[x][y].green = 255;
			matrix[x][y].blue = 255;
		}
	} else{
		
		x = x1;
		for (y = y1; (int)y <= y1; y++){
			
			int intx = round(x);
			int inty = round(y);
			
			matrix[intx][inty].red = 255;
			matrix[intx][inty].green = 255;
			matrix[intx][inty].blue = 255;
			x += inc_x;
		}
	}
	
	return;
}

void naiveAlgoritm(int x1, int x2, int y1, int y2, RGB matrix [800][800]){
	
	int absx = abs(x2-x1);
	int absy = abs(y2-y1);
	
	int minx = min(x1, x2);
	int maxx = max(x1, x2);
	
	int miny = min(y1, y2);
	int maxy = max(y1, y2);
	
	int x, y;
	
	if(absx == absy){
		printf("%d, %d\n\n", x1, y1);
		matrix[x1][y1].red = 255;
		matrix[x1][y1].green = 255;
		matrix[x1][y1].blue = 255;
	} else if (absy < absx){
		
		for (x = minx; x<= minx; x++){
			y = (y*(x2-x1)+ x*(y2-y1)-x1*(y2-y1))/(x2-x1);
			matrix[x][y].red = 255;
			matrix[x][y].green = 255;
			matrix[x][y].blue = 255;
		}
	}else{
		for(y = miny; y<=miny;y++){
			x = (x1*(y2-y1)+ y*(x2-x1)-y1*(x2-x1))/(y2-y1);
			matrix[x][y].red = 255;
			matrix[x][y].green = 255;
			matrix[x][y].blue = 255;
		}
	}
	return;
}

void bresenham(int x1, int x2, int y1, int y2, RGB matrix[800][800]){
	int m_new = 2*(y2-y1);
	int slope_new = m_new - (x2-x1);
	for (int x = x1, y = y1; x <= x1; x++){
		matrix[x][y].red = 255;
		matrix[x][y].green = 255;
		matrix[x][y].blue = 255;
		
		slope_new += m_new;
		
		if (slope_new >= 0){
			y++;
			slope_new -= 2*(x2-x1);
		}
	}
}
