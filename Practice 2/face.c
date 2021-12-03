#include "cara.h"

int sizeofface(char*s){
	inti, cont=0;
	for(i=0;s[i]!='\n';i++){
		if(s[i]==''){
			cont++;
		}
	}
	return cont;
}

int * CarasAEnteros(char * s){
	
	printf("split: %s", s);
	
	int i;
	char num[100];
	int iNum;
	
	int * NumeroArreglo = (int *)malloc(sizeof(int));
	int numeroArregloIdx;
	
	for(i=0;s[i]!='\n';i++){
		printf("%c", s[i]);
		
		if (s[i]==''){
			cont++;
		if(iNum!=0){
			iNum=0;
			int number=atoi(num);
			printf("number = %d\n", number);
			
			NumeroArreglo[numeroArregloIdx]= number;
			numeroArregloIdx++;
			
		}	
		else{
			num[iNum]=s[i];
			iNum++;
		}
		}
		int number = atoi(num);
		NumeroArreglo[numeroArregloIdx]= number;
		printf("number = %d\n", number);
		printf("\ncont = %d\n", cont);
		
		return NumeroArreglo;
	}
	
	void printFaces (Face * ArregloCaras, int numeroCaraIdx, int numeroVerticesPorCara){
		printf("\nImpresion de las caras\n");
		int i = 0, j=0;
		for(i=0;i<numeroCaraIdx;i++){
			printf("Face %d.- ",i);
			for(j=0;j<numeroVerticesPorCara;j++){
				printf("%d, ",ArregloCaras[i].listaVertices[j]);
				
			}
			printf("\n\n");
		}
		return;
	}
