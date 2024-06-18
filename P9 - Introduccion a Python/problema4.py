"""Escribir un programa que le pida al usuario que ingrese
una sucesión de números naturales (primero uno, luego otro,
y así hasta que el usuario ingrese -1 como condición de
salida). Al final, el programa debe imprimir cuantos numeros
fueron ingresados, la suma total de los valores y el promedio."""

lista_num = []
numero = 0
cantidad = 0
suma = 0
promedio = 0
while numero != -1:
    numero = int(input("Ingresa un número (-1 para dejar de capturar): "))
    if numero != -1:
        lista_num.append(numero)
        cantidad += 1
for i in lista_num:
    suma += i
promedio = suma / cantidad
print(f"Se ingresaron {cantidad} valores.")
print(f"La suma es {suma}.")
print(f"El promedio es {promedio}.")
