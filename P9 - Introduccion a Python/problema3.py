"""Escribir una función es_potencia_de_dos que reciba como
parámetro un número natural, y devuelva True si el número
es una potencia de 2, y False en caso contrario."""

def es_potencia_de_dos(numero):
    """Funcion que determina si un numero es potencia de dos"""
    pot = 0
    num = 1
    while num <= numero:
        if num == numero:
            return True
        pot += 1
        num = 2**pot
    return False

while 1:
    valor = int(input("Ingresa un numero (-1 para detener el programa): "))
    if valor == -1:
        break
    if es_potencia_de_dos(valor):
        print(f"{valor} es potencia de 2")
    else:
        print(f"{valor} no es potencia de 2")
