def selection_sort(lista):
    for i in range(len(lista)):
        menor = i

        for j in range(i + 1, len(lista)):
            if lista[j] < lista[menor]:
                menor = j

        lista[i], lista[menor] = lista[menor], lista[i]

numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21]
print(numeros)

selection_sort(numeros)
print(numeros)