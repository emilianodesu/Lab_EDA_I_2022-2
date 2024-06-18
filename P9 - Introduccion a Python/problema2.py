"""Programa que permite calcular el area de algunas figuras geometricas"""

import math

def circulo(radio):
    """Area de un circulo"""
    return math.pi*radio*radio

def rectangulo(base, altura):
    """Area de un recténgulo"""
    return base*altura

def triangulo(base, altura):
    """Area de un triéngulo"""
    return base*altura/2

while True:
    print("\nMenu de figuras geométricas")
    print("1. Área de un círculo")
    print("2. Área de un rectángulo")
    print("3. Área de un triángulo")
    print("4. Salir\n")
    choice = int(input("Elige una opción: "))
    if choice == 1:
        r = float(input("\nIntroduce el radio del círculo: "))
        print(f"\nEl área del círculo es: {circulo(r):.2f}")
    elif choice == 2:
        b = float(input("\nIntroduce la base del rectángulo: "))
        a = float(input("Introduce la altura del rectángulo: "))
        print(f"\nEl área del rectángulo es: {rectangulo(b, a):.2f}")
    elif choice == 3:
        b = float(input("\nIntroduce la base del triángulo: "))
        a = float(input("Introduce la altura del triángulo: "))
        print(f"\nEl área del triángulo es: {triangulo(b, a):.2f}")
    elif choice == 4:
        break
    else:
        print("Elige una opción válida")
