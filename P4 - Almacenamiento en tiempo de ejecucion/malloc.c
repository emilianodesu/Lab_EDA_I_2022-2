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
#include <stdlib.h>

int main(){
    int *arreglo, num, cont;
    printf("Cuantos elementos tiene el conjunto?\n");
    scanf("%d", &num);
    arreglo = (int *)malloc(num * sizeof(int));
    if (arreglo != NULL){
        printf("Vector reservado:\n\t[");
        for (cont = 0; cont < num; cont++){
            printf("\t%d", *(arreglo + cont));
        }
        printf("\t]\n");
        printf("Se libera el espacio reservado.\n");
        free(arreglo);
    }

    return 0;
}