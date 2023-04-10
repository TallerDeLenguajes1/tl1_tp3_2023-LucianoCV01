#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
5) Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, 
el usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación.
*/
int main(){
    char *buff; //Variable Auxiliar
    char **puntVectoresChar; //Puntero de punteros char. No hacia falta un puntero doble, la consigna solo pide un arreglo de punteros char.
    int cantidadNombres;

    //Pido al usuario que ingrese la cantidad de nombres
    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &cantidadNombres);

    //Reserva dinamica de memoria para auxiliar y puntero doble
    buff = (char *) malloc(sizeof(char) * 100);
    puntVectoresChar = (char **) malloc(sizeof(char *) * cantidadNombres);

    //Reserva dinamica de memoria para componentes del puntero doble
    for (int i = 0; i < cantidadNombres; i++)
    {
        fflush(stdin);
        printf("Ingrese su/s nombre/s: \n");
        gets(buff);
        
        puntVectoresChar[i] = (char *) malloc(sizeof(char) * (strlen(buff)+1));
        strcpy(puntVectoresChar[i], buff);
    }
    
    //Muestro los nombres
    puts("------------");
    for (int i = 0; i < cantidadNombres; i++)
    {
        puts(puntVectoresChar[i]);
    }
    
    //Libero la memoria
    free(buff);
    for (int i = 0; i < cantidadNombres; i++)
    {
        free(puntVectoresChar[i]);
    }
    free(puntVectoresChar);

    return 0;
}