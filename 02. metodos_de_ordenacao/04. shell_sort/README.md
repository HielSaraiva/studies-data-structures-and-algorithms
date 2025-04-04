## Shell-Sort

### Visão Geral

O Shell Sort é uma extensão do Insertion Sort que melhora seu desempenho dividindo o array em segmentos menores e ordenando-os com espaçamentos maiores. Os elementos são comparados e trocados a uma certa distância, diminuindo progressivamente esse intervalo até 1 (quando se torna um Insertion Sort).

---

### Complexidade Temporal

- Melhor caso: O(n log n)
- Caso médio: Depende do gap sequence usado (pode ser O(n log² n))
- Pior caso: O(n²)

---

### Complexidade Espacial

- O(1) (Ordenação in-place)
