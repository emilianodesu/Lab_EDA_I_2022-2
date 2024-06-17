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
Se recorre un arreglo unidimensional a través de un apuntador
*/
int main(){
    short nums[] = {55, 44, 33, 22, 11};
    short *ap, cont;
    ap = nums;
    for (cont = 0; cont < 5; cont++)
        printf("%x\n", (ap + cont));

    return 0;
}