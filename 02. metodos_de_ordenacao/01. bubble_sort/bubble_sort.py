def bubble_sort(lista):
    for i in range(len(lista)):
        for j in range(len(lista) - i - 1):
            if lista[j] > lista[j + 1]:
                lista[j], lista[j + 1] = lista[j + 1], lista[j]


numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21]
print(numeros)

bubble_sort(numeros)
print(numeros)
