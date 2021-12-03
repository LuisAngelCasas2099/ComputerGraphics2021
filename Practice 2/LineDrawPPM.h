typedef struct RGB{
	int red;
	int green;
	int blue;
}RGB;

int abs (int n);
int max (int a, int b);
int min (int a, int b);

void DDA(int x1, int x2, int y1, int y2, rgb matrix [800][800]);
void naiveAlgorithm(int x1, int x2, int y1, int y2, RGB matrix[800][800]);
void bresenham(int x1, int x2, int y1, int y2, RGB matrix [800][800]);
