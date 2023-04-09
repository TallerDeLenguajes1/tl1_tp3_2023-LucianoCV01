#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRES 5

/*
3) Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char 
y una vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria) 
(Lea las notas 1 y 2)
*/
int main(){
    char *buff; //Variable Auxiliar
    char **puntVectoresChar; //Puntero de punteros char

    //Reserva dinamica de memoria para auxiliar y puntero doble
    buff = (char *) malloc(sizeof(char) * 100);
    puntVectoresChar = (char **) malloc(sizeof(char *) * NOMBRES);

    //Reserva dinamica de memoria para componentes del puntero doble
    for (int i = 0; i < NOMBRES; i++)
    {
        printf("Ingrese sus nombres: \n");
        gets(buff);
        
        puntVectoresChar[i] = (char *) malloc(sizeof(char) * (strlen(buff)+1));
        strcpy(puntVectoresChar[i], buff);
    }
    
    //Muestro los nombres
    puts("------------");
    for (int i = 0; i < NOMBRES; i++)
    {
        puts(puntVectoresChar[i]);
    }
    
    //Libero la memoria
    free(buff);
    for (int i = 0; i < NOMBRES; i++)
    {
        free(puntVectoresChar[i]);
    }
    free(puntVectoresChar);

    return 0;
}