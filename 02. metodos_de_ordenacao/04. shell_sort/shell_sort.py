def shell_sort(lista):
    n = len(lista)
    gap = n // 2 

    while gap > 0:
        for i in range(gap, n):  
            temp = lista[i]  
            j = i  

            while j >= gap and lista[j - gap] > temp:
                lista[j] = lista[j - gap]  
                j -= gap

            lista[j] = temp
        gap = gap // 2

numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21]
print(numeros)

shell_sort(numeros)
print(numeros)