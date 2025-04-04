def counting_sort(lista, exp):
    n = len(lista)
    output = [0] * n
    count = [0] * 10  

    for num in lista:
        index = (num // exp) % 10  
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        index = (lista[i] // exp) % 10
        output[count[index] - 1] = lista[i]
        count[index] -= 1

    for i in range(n):
        lista[i] = output[i]

def radix_sort(lista):
    max1 = max(lista)  

    exp = 1
    while max1 // exp > 0:
        # Ordenação estável
        counting_sort(lista, exp)
        exp *= 10

numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21]
print(numeros)

radix_sort(numeros)
print(numeros)