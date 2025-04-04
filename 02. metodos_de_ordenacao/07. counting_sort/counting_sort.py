def counting_sort(lista):
    if not lista:
        return 

    M = max(lista)  
    m = min(lista)  
    range_size = M - m + 1  

    count_a = [0] * range_size
    output_a = [0] * len(lista)

    for num in lista:
        count_a[num - m] += 1  

    for i in range(1, range_size):
        count_a[i] += count_a[i - 1]

    for i in range(len(lista) - 1, -1, -1):
        output_a[count_a[lista[i] - m] - 1] = lista[i]
        count_a[lista[i] - m] -= 1

    lista[:] = output_a

numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21]
print(numeros)

counting_sort(numeros)
print(numeros)