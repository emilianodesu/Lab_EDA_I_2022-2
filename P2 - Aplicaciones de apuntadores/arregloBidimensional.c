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
Se recorre un arreglo bidimensional a través de un apuntador
*/
int main(){
    int *ap, indice;
    int nums[3][3]={{99, 88, 77},
                    {66, 55, 44},
                    {33, 22, 11}};
    ap = nums;
    for (indice = 0; indice < 9; indice++){
        if ((indice % 3) == 0)
            printf("\n");
        printf("%x\t", (ap + indice));
    }

    return 0;
}