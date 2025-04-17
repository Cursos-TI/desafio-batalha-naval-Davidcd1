// Desafio Batalha Naval - MateCheck
// Nível Mestre: Posiciona navios, verifica limites, evita sobreposições e aplica habilidades.

#include <stdio.h>

#define Tam_Tabuleiro 10
#define N_Navios 4
#define N_Partes 3
#define SIZE_X 5
#define SIZE_Y 3

// Atualiza tabuleiro com navios e habilidades
void atualizar(int tabuleiro[Tam_Tabuleiro][Tam_Tabuleiro],
    int navios[N_Navios][N_Partes][2],
    int cone[SIZE_Y][SIZE_X],
    int octaedro[SIZE_Y][SIZE_X],
    int cruz[SIZE_Y][SIZE_X]);

// Ajusta partes de um navio para ficar dentro dos limites
void verificarLimites(int navio[N_Partes][2]);

// Retorna 1 se algum par de navios se sobrepõe
int verificarTodosNavios(int navios[N_Navios][N_Partes][2]);

// Retorna 1 se dois navios compartilham alguma célula
int verificarSobreposicao(int navio1[N_Partes][2], int navio2[N_Partes][2]);

// Reposiciona navio ao longo de eixo (0=y, 1=x) sem sair do tabuleiro
void reposicionarNavio(int navio[N_Partes][2], int eixo, int casas);

// Reseta tabuleiro e posiciona navios atualizados
void atualizarTabuleiro(int tabuleiro[Tam_Tabuleiro][Tam_Tabuleiro],
    int navios[N_Navios][N_Partes][2]);

// Exibe tabuleiro com índices e valores (0=água,3=navio,1/5=habilidades)
void exibirTabuleiro(int tabuleiro[Tam_Tabuleiro][Tam_Tabuleiro]);

int main() {
    // Inicializa tabuleiro 10x10 com água
    int tabuleiro[Tam_Tabuleiro][Tam_Tabuleiro] = {0};

    // Define 4 navios (tamanho 3): duas orientações e duas diagonais
    int navios[N_Navios][N_Partes][2] = {
        {{2, 7}, {2, 8}, {2, 9}}, // Horizontal
        {{2, 2}, {3, 2}, {4, 2}}, // Vertical
        {{7, 1}, {8, 2}, {9, 3}}, // Diagonal principal
        {{7, 8}, {8, 7}, {9, 6}}  // Diagonal secundária
    };

    // Matriz de área para cada habilidade (1=efeito)
    int cone[SIZE_Y][SIZE_X] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };
    int octaedro[SIZE_Y][SIZE_X] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };
    int cruz[SIZE_Y][SIZE_X] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };

    atualizar(tabuleiro, navios, cone, octaedro, cruz);
    exibirTabuleiro(tabuleiro);
    return 0;
}

void atualizar(int tabuleiro[Tam_Tabuleiro][Tam_Tabuleiro],
    int navios[N_Navios][N_Partes][2],
    int cone[SIZE_Y][SIZE_X],
    int octaedro[SIZE_Y][SIZE_X],
    int cruz[SIZE_Y][SIZE_X]) {
    // Garante que cada parte do navio esteja dentro dos limites
    for(int i=0; i<N_Navios; i++) {
        verificarLimites(navios[i]);
    }

    // Posiciona navios no tabuleiro
    for(int i=0; i<N_Navios; i++) {
        for(int j=0; j<N_Partes; j++) {
            tabuleiro[ navios[i][j][0] ][ navios[i][j][1] ] = 3;
        }
    }

    // Ajusta navios até que não haja sobreposição
    while(verificarTodosNavios(navios)) {
        // Tenta mover cada navio livremente para evitar colisão
        for(int i=0; i<N_Navios; i++) {
            int movimento = 1;
            // Reposiciona até resolver sobreposição
            while(verificarTodosNavios(navios)) {
                // Tenta deslocar em y+, y-, x+, x-
                reposicionarNavio(navios[i], 0, movimento);
                reposicionarNavio(navios[i], 0, -movimento);
                reposicionarNavio(navios[i], 1, movimento);
                reposicionarNavio(navios[i], 1, -movimento);
                movimento++;
                atualizarTabuleiro(tabuleiro, navios);
            }
        }
    }

    // Associa habilidades aos navios
    int (*poderes[N_Navios])[SIZE_X] = {cone, cruz, octaedro, cone};

    for(int i=0; i<N_Navios; i++) {
        int cy = navios[i][1][0], cx = navios[i][1][1];
        int (*hab)[SIZE_X] = poderes[i];
        // Sobrepõe área de efeito
        for(int y=0; y<SIZE_Y; y++) for(int x=0; x<SIZE_X; x++) {
            if(hab[y][x]) {
                int py = cy + (y - SIZE_Y/2);
                int px = cx + (x - SIZE_X/2);
                if(py>=0 && py<Tam_Tabuleiro && px>=0 && px<Tam_Tabuleiro) {
                    if(tabuleiro[py][px]==0) tabuleiro[py][px]=1;
                    else if(tabuleiro[py][px]==3) tabuleiro[py][px]=5;
                }
            }
        }
    }
}

void verificarLimites(int navio[N_Partes][2]) {
    for(int i=0;i<N_Partes;i++){
        if(navio[i][0]<0) navio[i][0]=0;
        if(navio[i][0]>=Tam_Tabuleiro) navio[i][0]=Tam_Tabuleiro-1;
        if(navio[i][1]<0) navio[i][1]=0;
        if(navio[i][1]>=Tam_Tabuleiro) navio[i][1]=Tam_Tabuleiro-1;
    }
}

int verificarTodosNavios(int navios[N_Navios][N_Partes][2]){
    for(int i=0;i<N_Navios;i++) for(int j=i+1;j<N_Navios;j++)
        if(verificarSobreposicao(navios[i], navios[j])) return 1;
    return 0;
}

int verificarSobreposicao(int a[N_Partes][2], int b[N_Partes][2]){
    for(int i=0;i<N_Partes;i++) for(int j=0;j<N_Partes;j++)
        if(a[i][0]==b[j][0] && a[i][1]==b[j][1]) return 1;
    return 0;
}

void reposicionarNavio(int navio[N_Partes][2], int eixo, int casas){
    if(navio[1][eixo]+casas>=0 && navio[1][eixo]+casas<Tam_Tabuleiro) {
        for(int i=0;i<N_Partes;i++) navio[i][eixo]+=casas;
    }
}

void atualizarTabuleiro(int tabuleiro[Tam_Tabuleiro][Tam_Tabuleiro],
    int navios[N_Navios][N_Partes][2]) {
    for(int y=0;y<Tam_Tabuleiro;y++) for(int x=0;x<Tam_Tabuleiro;x++) tabuleiro[y][x]=0;
    for(int i=0;i<N_Navios;i++) for(int j=0;j<N_Partes;j++)
        tabuleiro[ navios[i][j][0] ][ navios[i][j][1] ]=3;
}

void exibirTabuleiro(int tabuleiro[Tam_Tabuleiro][Tam_Tabuleiro]){
    char alfa[10]={'A','B','C','D','E','F','G','H','I','J'};
    int num;
    printf("   "); for(int i=0;i<Tam_Tabuleiro;i++) printf("%c ",alfa[i]);
    printf("\n");
    for(int y=0;y<Tam_Tabuleiro;y++){
        printf(y<9?"%d  ":"%d ",y+1);
        for(int x=0;x<Tam_Tabuleiro;x++) printf("%d ",tabuleiro[y][x]);
        printf("\n");
    }
}
