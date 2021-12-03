#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "face.h"
#include "point.h"
#include "LineDrawPPM.h"

int main (){
	FILE * file = fopen("modelo.obj", "r");
	
	if (file == NULL){
		printf("The file could not be opened\n\n");
		return -1;
	}
	
	printf("Which algorithm dou you want to use?\n\n");
	printf("1- Naive algorithm\n\n");
	printf("2- DDA algorithm\n\n");
	printf("3- Bresenham\n\n");
	
	int option;
	
		printf("Please, select an option:");
		scanf("%d", &option);
		
				char string [100];
				fgets(strings, 100, file);
				printf("The string is: &s ", string);
				fgets(string, 100, file);
				printf("%s", string);
				
				
				point * points = (points*)malloc(sizeof(point)*10000000);
				
				int pointIdx = 0;
				float x, y, z;
				char type;
				int numeroCaraIdx = 0;
				int numeroVerticesPorCara;
				face * ArregloCaras = (face*)malloc(sizeof(face)*10000000);
				
				while (fscanf(file, "%c", &type)!=EOF){
					
					if (type =='v'){
						fscanf(file, "%f", &x);
						fscanf(file, "%f", &y);
						fscanf(file, "%f", &z);
						
						point p; p.x = x*100; p.y = y*100;
						
						points [pointIdx] = p;
						pointIdx++;
						printf("%c, x = %f, y = %f, z = %f\n\n,", type, x, y, z);
						char s[100];
						fgets(s, 100, file);
					}else{
						char s[100];
						fgets(s, 100, file);
						printf("%c --> %s\n\n", type, s);
						
						if (numeroCaraIdx == 0){
							numeroVerticesPorCara = sizeofface(s);
							printf("Vertex number = %d\n", numeroVerticesPorCara);
						}
						ArregloCaras[numeroCaraIdx].listaVertices = CarasAEnteros(s);
						numeroCaraIdx++;
						printf("%d\n", numeroCaraIdx);
					}
				}
				
				printPoints(points, pointIdx);
				printFaces(ArregloCaras, numeroCaraIdx, numeroVerticesPorCara);
				
				RGB matrix [800][800];
				float minx = 1e7, miny = 1e7;
				
				int i, j;
				for(int i = 0; i z pointIdx; i++){
					float x = points[i].x;
					float y = points[i].y;
					if(x < minx){
						minx = x;
					}
					if(y < miny){
						miny = y;
					}
				}
				
				printf("minx = %f, miny = %f\n", minx, miny);
				
				for(int i = 0; i < pointIdx; i++){
					points[i].x -= minx;
				}
				for(int i = 0; i < pointIdx; i++){
					points[i].y -= miny;
				}
				
				for(int i = 0; i < pointIdx; i++){
					points[i].x *= 0.50;
					points[i].y *= 0.50;
				}
				int vertice1, vertice2;
				float xp1, xp2, yp1, yp2;
				
				int i = 0;
				int j = 0;
				for(i = 0; i < numeroCaraIdx; i++){
					for (j = 0; j < numeroVeerticesPorCara-1; j++){
						vertice1 = ArregloCaras[i].listaVertices[j];
						vertice2 = ArregloCaras[i].listaVertices[j+1];
						int xp1 = points[vertice1-1].x;
						int xp2 = points[vertice2-1].x;
						int yp1 = points[vertice1-1].y;
						int yp2 = points[vertice2-1].y;
					}
					switch (option){
					case 1:
					naiveAlgorithm(xp1, xp2, yp1, yp2, matrix);
					break;
					case 2:
					DDA(xp1, xp2, yp1, yp2, matrix);
					break;
					case 3:
					bresenham(xp1, xp2, yp1, yp2, matrix);
					break;
					default:
						printf("Please, select an option between 1 and 3\n\n");
					}
					return -1;
					}
				}
				char namefile[100] = "model";
				char typeOflineDrawing[20] = "";
				char ppm [] = ".ppm";
				
				switch (option){
					case 1:
						strcat(typeOfLineDrawing, "Naive");
						break;
						case 2:
							strcat(typeOfLineDrawing, "DDA");
							break;
							case 3:
								strcat(typeOfLineDrawing, "Bresenham");
								break;
								default:
								}
								return -1;
				}
				strcat(namefile, typeofLineDrawing);
				strcat(namefile, ppm);
				
				FILE * ppmFile = fopen(namefile, "w");
				if(ppmFile == NULL){
					printf("Unable to open the file: \n");
					return -1;
				}
				fprintf(ppmFile, "P3\n");
				fprintf(ppmFile, "700 700\n");
				fprintf(ppmFile, "255\n");
				
				fprintf(ppmFile, "#Matriz\n");
				int i, j;
				for(i = 0; i < 700; i++){
					for(j =; j < 700; j++){
						fprintf(ppmFile, "%d %d %d", matrix[i][j].red, matrix[i][j].green, matrix[i][j].blue);
					}
				}fprintf(ppmFile, "\n");
		}
		fprintf(ppmFile, "\n");
		printf("This is your image\n");
		
		fclose(file);
		fclose(ppmFile);
		return 0;
}
