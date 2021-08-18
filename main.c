#include<stdlib.h>
#include<stdio.h>

int main(){
	int x1,y1,x2,y2;
	int acum=0;
	int acum2=0;
	
	printf("Please, introduce the values of X1 and Y1\n");
	scanf("%d %d",&x1,&y1);
	
	printf("\n\Please, introduce the values of X2 and Y2\n");
	scanf("%d %d",&x2,&y2);
	printf("\n  x | y\n");
	if(x1 < x2 || y1 > y2){
		acum=(x2-x1)+1;
		if ( acum%2 == true){
			acum=((acum/2)/2)+1;
			
			for(int i=1;i<x2;i++){
			printf("%3d %3d\n",x1, y1);	
			x1++;
			if(acum*2 != i)	
				if(acum2 == 1){
					y1--;
					acum2=0;
				}
				else
					acum2++;
			   
			}	
		}
		
			
	}


	
}
