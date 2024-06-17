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

void pasarValor(int);
void pasarReferencia(int *);

int main(){
    int nums[] = {55, 44, 33, 22, 11};
    int *ap, cont;
    ap = nums;
    printf("Pasar valor: %d\n", *ap);
    pasarValor(*ap);
    printf("Pasar referencia: %d\n", *ap);
    pasarReferencia(ap);
    printf("Valor final: %d\n", *ap);

    return 0;
}

void pasarValor(int equis){
    printf("%d\n", equis);
    equis = 128;
    printf("%d\n", equis);
}

void pasarReferencia(int *equis){
    printf("%d\n", *equis);
    *equis = 128;
    printf("%d\n", *equis);
}