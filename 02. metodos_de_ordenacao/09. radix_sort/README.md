## Radix-Sort

### Visão Geral

O Radix Sort ordena os números **dígito por dígito**, do menos significativo para o mais significativo, usando um algoritmo de ordenação estável (como Counting Sort) para cada posição.

---

### Complexidade Temporal

- Melhor caso: O(nk)
- Caso médio: O(nk)
- Pior caso: O(nk)  
  (onde k é o número de dígitos do maior número)

---

### Complexidade Espacial

- O(n + k) (Devido à estrutura auxiliar usada para a ordenação dos dígitos)
