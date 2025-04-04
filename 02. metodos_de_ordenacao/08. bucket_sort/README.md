## Bucket-Sort

### Visão Geral

O Bucket Sort distribui os elementos em **baldes** (subarrays) e ordena cada um individualmente (geralmente com Insertion Sort). Depois, os baldes são concatenados para formar o array final ordenado.

---

### Complexidade Temporal

- Melhor caso: O(n)
- Caso médio: O(n + k) (sendo k o número de baldes)
- Pior caso: O(n²) (se os elementos ficarem concentrados em poucos baldes)

---

### Complexidade Espacial

- O(n + k) (Devido à criação dos baldes)