#include <stdlib.h>
#include <stdio.h>


typedef struct Face{
	int * listaVertices;
}Face;

int sizeofface(char * s);

int * CarasAEnteros(char * s);

void printFaces (Face * ArregloCaras, int numeroCaraIdx, int numeroVerticesPorCara);
