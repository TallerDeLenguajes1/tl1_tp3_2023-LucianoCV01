#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 5
#define COLUMNAS 12

int main(){
    /*
    2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita 
    generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna es un mes. 
    Ud. debe realizar las siguientes tareas:
    */
    float mProduccion[FILAS][COLUMNAS], promedioGanancia=0, valorMax, valorMin;
    int anio[2], mes[2];
    srand(time(NULL));
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            mProduccion[i][j] = rand()%(40001)+10000; //a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
            printf("%.1f    ", mProduccion[i][j]); //b. Muestre por pantalla los valores cargados
        }
        printf("\n"); 
    }

    valorMax = mProduccion[0][0];
    valorMin = mProduccion[0][0];

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            promedioGanancia += mProduccion[i][j];
            if (valorMax <= mProduccion[i][j])
            {
                valorMax = mProduccion[i][j];
                anio[1] = i+1;
                mes[1] = j+1;
            }
            if (valorMin >= mProduccion[i][j])
            {
                valorMin = mProduccion[i][j];
                anio[0] = i+1;
                mes[0] = j+1;
            }
        }
        printf("------ %dº Año ------\n", i+1);
        printf("Promedio de ganancia: %.2f\n", promedioGanancia/12); //c. Saque el promedio de ganancia por año y muestrelos por pantalla
        promedioGanancia=0;
    }

    //d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    printf("Valor Maximo: %.1f\n", valorMax);
    printf("mes/anio: %d/%d\n", mes[1], anio[1]);
    printf("Valor Minimo: %.1f\n", valorMin);
    printf("mes/anio: %d/%d\n", mes[0], anio[0]);

    return 0;
}