# Desafio Batalha Naval - Três Níveis de Complexidade

Este projeto explora três níveis de complexidade no jogo de Batalha Naval em C, focando em vetores e matrizes.

---

## Níveis

1. **Novato**
   - Tabuleiro 10×10 (iniciado com 0).
   - Posiciona 2 navios (tamanho 3): um horizontal e outro vertical.
   - Exibe coordenadas via `printf`.

2. **Aventureiro**
   - Mesma matriz 10×10.
   - Posiciona 4 navios (2 ortogonais + 2 diagonais).
   - Exibe o tabuleiro completo com `0` (água) e `3` (navio).

3. **Mestre**
   - Mantém os 4 navios do nível anterior.
   - Implementa 3 habilidades (cone, cruz, octaedro) como matrizes 3×5.
   - Sobrepõe efeitos: `1` para água afetada, `5` sobre navio.
   - Usa loops aninhados e condicionais para posicionar áreas de efeito.
   - Exibe tabuleiro rotulado (colunas A–J, linhas 1–10).

---

## Como executar

1. Clone o repositório:
   ```bash
   git clone https://github.com/Cursos-TI/desafio-batalha-naval-Davidcd1.git
   cd desafio-batalha-naval-Davidcd1/
   ```
2. Compile:
   ```bash
   gcc batalhaNaval.c -o batalhaNaval
   ```
3. Execute:
   ```bash
   ./batalhaNaval
   ```
---

## 🏅 Nível Mestre

No nível Mestre, o desafio se intensifica com a implementação de habilidades especiais representadas por matrizes específicas no tabuleiro.

### 🆕 Diferença em relação ao Nível Aventureiro:
- **Habilidades Especiais:** O sistema deve definir áreas de habilidades utilizando matrizes com padrões específicos: cone, cruz e octaedro.
- **Estruturas de Repetição Aninhadas:** Utilização de loops aninhados para percorrer e preencher as áreas afetadas pelas habilidades.

### 🚩 Novas Funcionalidades:
- **Matrizes de Habilidades:** Implementação de três matrizes para representar habilidades especiais no tabuleiro.
- **Padrões de Habilidade:** Criação de padrões específicos (cone, cruz, octaedro) para definir as áreas afetadas.
- **Exibição das Áreas Atingidas:** O sistema exibirá o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas afetadas.

### Exemplo de Saída:

Exemplo e comando:
printf("%d ",matriz[i][j]);

### Exemplo de saída de habilidade em cone:

0 0 1 0 0

0 1 1 1 0

1 1 1 1 1

### Exemplo de saída de habilidade em octaedro:

0 0 1 0 0

0 1 1 1 0

0 0 1 0 0

### Exemplo de saída de habilidade em cruz:

0 0 1 0 0

1 1 1 1 1

0 0 1 0 0

---

## 📋 Requisitos Funcionais Comuns
- **Entrada de Dados:** Os valores serão inseridos manualmente por meio de variáveis no código.
- **Utilização de Matrizes:** Os dados devem ser estruturados de maneira eficiente utilizando matrizes.
- **Exibição de Resultados:** Os resultados devem ser exibidos de forma clara e organizada.

## 📌 Requisitos Não Funcionais Comuns
- **Performance:** O sistema deve executar operações de forma eficiente, sem atrasos perceptíveis.
- **Documentação:** O código deve ser bem documentado, com comentários claros sobre a função de cada parte do código.
- **Manutenibilidade:** O código deve ser organizado e fácil de entender, facilitando futuras manutenções e expansões.

---

Boa sorte no desenvolvimento deste desafio! Aproveite para aprimorar suas habilidades em vetores e matrizes enquanto progride pelos níveis.

Equipe de Ensino - MateCheck
