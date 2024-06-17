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
/*
Se imprimen 3 valores de un arreglo a través
de aritmética de direcciones.
*/
int main(){
    short arr[5] = {91, 28, 73, 46, 55};
    short *apArr;
    apArr = arr;
    // apunta al inicio del arreglo
    printf("*apArr = %i\n", *apArr);
    // suma una localidad al inicio del arreglo e imprime su valor
    printf("*(apArr+1) = %i\n", *(apArr + 1));
    printf("*(apArr+2) = %i\n", *(apArr + 2));

    return 0;
}