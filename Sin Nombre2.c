#include <stdio.h>
#include <math.h>

int main(){

    int x1;
	int x2;
	int y1;
	int y2;

    printf("Please enter two ordered pairs: (x1,y1),(x2,y2)\n");
    scanf("(%d,%d),(%d,%d)", &x1, &y1, &x2, &y2);

    if(x2 < x1){
        x1 = x1 ^ x2;
        x2 = x1 ^ x2;
        x1 = x1 ^ x2;

        y1 = y1 ^ y2;
        y2 = y1 ^ y2;
        y1 = y1 ^ y2;        
    };

    if(x1 < 0 || x1 > 100 || x2 < 0 || x2 > 100 || y1 < 0 || y1 > 100 || y2 < 0 || y2 > 100){
        printf("Invalid input.\n");
    }
	else{

        double x1f = (double)x1;
        double x2f = (double)x2;
        double y1f = (double)y1;
        double y2f = (double)y2;

        double m = (y2f - y1f)/(x2f - x1f);

        printf("  X  , Y\n");
        for(int i=x1; i<=x2; i++)
		{        
            printf("%3d ", i);
            printf("%3d\n", (int)round(m*(i-x1)+y1));
        }

    }

    return 0;
}
