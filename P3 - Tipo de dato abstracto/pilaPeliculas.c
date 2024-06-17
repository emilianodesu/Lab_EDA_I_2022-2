/*
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Jorge A. Solano
 *
 */

#include <stdio.h>
#define TAM 2
#define NUM_DIR 2

struct pelicula{
    char nombre[20];
    char genero[20];
    short anio;
    short numDirectores;
    char directores[NUM_DIR][20];
};

void llenarArreglo(struct pelicula *);
void imprimirArreglo(struct pelicula *);

int main(){
    struct pelicula arreglo[TAM];
    llenarArreglo(arreglo);
    imprimirArreglo(arreglo);

    return 0;
}

void llenarArreglo(struct pelicula arreglo[TAM]){
    int iesimo, enesimo;
    for (iesimo = 0; iesimo < TAM; iesimo++){
        struct pelicula movie;
        printf("####### Pelicula %d #######\n", iesimo + 1);
        printf("Ingrese nombre pelicula:");
        setbuf(stdin, NULL);
        scanf("%s", movie.nombre);
        getchar();
        printf("Ingrese genero pelicula:");
        setbuf(stdin, NULL);
        scanf("%s", movie.genero);
        getchar();
        printf("Ingrese anio pelicula:");
        setbuf(stdin, NULL);
        scanf("%d", &movie.anio);
        movie.numDirectores = NUM_DIR;
        for (enesimo = 0; enesimo < NUM_DIR; enesimo++){
            printf("Ingrese director %d:", enesimo + 1);
            setbuf(stdin, NULL);
            scanf("%s", movie.directores[enesimo]);
            getchar();
        }
        arreglo[iesimo] = movie;
    }
}

void imprimirArreglo(struct pelicula arreglo[TAM]){
    int iesimo, enesimo;
    printf("####### Contenido del arreglo #######\n");
    for (iesimo = TAM - 1; iesimo >= 0; iesimo--){
        printf("####### Pelicula %d #######\n", iesimo + 1);
        printf("PELICULA: %s\n", arreglo[iesimo].nombre);
        printf("GINERO: %s\n", arreglo[iesimo].genero);
        printf("ANIO: %d\n", arreglo[iesimo].anio);
        printf("DIRECTOR(ES):\n");
        for (enesimo = 0; enesimo < arreglo[iesimo].numDirectores; enesimo++){
            printf("%s\n", arreglo[iesimo].directores[enesimo]);
        }
    }
}