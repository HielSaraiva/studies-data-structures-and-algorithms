def insertion_sort(lista):
    for i in range(1, len(lista)):
        pivo = lista[i]
        j = i - 1

        while j >= 0 and lista[j] > pivo:
            lista[j + 1] = lista[j]
            j = j - 1
        
        lista[j + 1] = pivo

numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21]
print(numeros)

insertion_sort(numeros)
print(numeros)