def bucket_sort(lista):
    min_val = min(lista)
    max_val = max(lista)
    
    n = len(lista)
    buckets = [[] for _ in range(n)]

    interval = (max_val - min_val) / (n - 1) if n > 1 else 1

    for num in lista:
        bi = int((num - min_val) / interval)
        bi = min(bi, n - 1)
        buckets[bi].append(num)

    for bucket in buckets:
        # Insertion-Sort
        for i in range(1, len(bucket)):
            key = bucket[i]
            j = i - 1
            while j >= 0 and bucket[j] > key:
                bucket[j + 1] = bucket[j]
                j -= 1
            bucket[j + 1] = key

    i = 0
    for bucket in buckets:
        for num in bucket:
            lista[i] = num
            i += 1

numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21, 0.4]
print(numeros)

bucket_sort(numeros)
print(numeros)