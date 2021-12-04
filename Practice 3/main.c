#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void fotograma(int alto, int ancho);
void Llenar(int alto, int ancho);
void Archivo(int cont);
void Bienvenida();

FILE *archivo;

struct Pixeles
{
    int Rojo;
    int Verde;
    int Azul;   
}RGB[2000];

struct Imagen
{
    struct Pixeles RGB[2000];
}foto[2000];

int main()
{

int cont, page=0;
system("color f4");
initwindow(720,480);
setbkcolor(15);
clearviewport();
Bienvenida();
for(int ciclo=0;ciclo<10;ciclo++)
{
    for(cont=1;cont<7;cont++)
    {
        setactivepage(0);
        setvisualpage(1);
        cleardevice();
        Archivo(cont);
    }
}
closegraph();
}
void Bienvenida()
{
    setcolor(BLACK);
    settextstyle(2,0,8);
    outtextxy(40,40,"H");Beep(200,100);delay(500);outtextxy(70,40,"O");Beep(200,100);delay(500);
    outtextxy(100,40,"L");Beep(200,100);delay(500);outtextxy(130,40,"A");Beep(200,100);delay(500);
}
void Archivo(int cont)
{
    int  alto=0, ancho=0, aux=0;
    char nombre[20];
    switch(cont)
    {
    case 1:
            strcpy(nombre,"foto1.txt");     fflush(stdin);      break;  
    case 2:
            strcpy(nombre,"foto2.txt");     fflush(stdin);      break;
    case 3:
            strcpy(nombre,"foto3.txt");     fflush(stdin);      break;
    case 4:
            strcpy(nombre,"foto4.txt");     fflush(stdin);      break;
    case 5:
            strcpy(nombre,"foto5.txt");     fflush(stdin);      break;
    case 6:
            strcpy(nombre,"foto6.txt");     fflush(stdin);      break;
    }
    archivo=fopen(nombre,"r");
        if(archivo==NULL)
        {
            system("CLS");
            gotoxy(20,20);printf("ERROR AL CREAR EL ARCHIVO");
            system("pause");
            return;
        }
    setcolor(BLACK);
    settextstyle(11,0,1);
    //outtextxy(2,690,"¡¡ARCHIVO DE TEXTO ABIERTO CON EXITO!!");
    fscanf(archivo,"%d %d",&alto,&ancho);
    fscanf(archivo,"%d",&aux);
    Llenar(alto, ancho);
}
void Llenar(int alto, int ancho)
{   
    for(int i=0;i<ancho;i++)
    {
        for(int j=0; j<alto;j++)
        {
            int auxR=0, auxG=0,auxB=0;
            fscanf(archivo,"%d %d %d",&auxR,&auxG,&auxB);
            foto[j].RGB[i].Azul=auxB; foto[j].RGB[i].Rojo=auxR; foto[j].RGB[i].Verde=auxG;
        }
    }
    fotograma(alto,ancho);
}
void fotograma(int alto, int ancho)
{   
    for(int i=0;i<ancho;i++)
    {
        for(int j=0; j<alto;j++)
        {
        putpixel(j+20,i+20,COLOR(foto[j].RGB[i].Rojo,foto[j].RGB[i].Verde,foto[j].RGB[i].Azul));
        }
    }
fclose(archivo);
}
