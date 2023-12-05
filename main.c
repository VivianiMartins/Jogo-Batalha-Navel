#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define DIMENSAO 12

void criarMatrizInicial(int tabuleiro[][DIMENSAO]){
    //preenchendo todo o tabuleiro
    int posicao = 1;
    for (int e = 0 ; e < DIMENSAO; e++)
    {
        for( int f = 0; f < DIMENSAO; f++)
        {
            tabuleiro[e][f]= '.';
        }
    }

    //inserindo os navios
    criarNavios(tabuleiro);

    //viasualisando os navios
    verNavios(tabuleiro);

    //criando o tabuleiro visual
    for (int i=0 ; i < DIMENSAO;i++)
    {
        for( int j = 0; j<DIMENSAO; j++)
        {
            if (j==0 && i==0 || j==11 && i==0 ){
                printf(" ",tabuleiro[i][j]);
            }else{
                if(j==0 || j==11){
                    printf("|",tabuleiro[i][j]);
                }else{
                    if(i==0 || i==11 ){
                        printf("_____",tabuleiro[i][j]);
                    }else{
                        if(posicao < 10){
                            printf("  %d  ",posicao);
                            posicao = posicao + 1;

                        }else{
                            if(posicao >= 10 && posicao < 100)
                            {
                                printf("  %d ",posicao);
                                posicao = posicao + 1;
                            }else{
                                printf(" %d ",posicao);
                                posicao = posicao + 1;
                            }
                        }
                    }
                }
            }
        }
         printf ("%\n");
    }
}

void criarNavios(int tabuleiro[][DIMENSAO]){
    int posicaoLinha = 1;
    int posicaoColuna = 1;

    //sorteio para 5 navios tipo 1
    for(int a = 0; a<5; a++){
        posicaoLinha = (rand()%10)+1;
        posicaoColuna = (rand()%10)+1;

        while(tabuleiro[posicaoLinha][posicaoColuna] == 'W'){
            posicaoLinha = (rand()%10)+1;
            posicaoColuna = (rand()%10)+1;
        }

        tabuleiro[posicaoLinha][posicaoColuna] = 'W';
    }

    //sorteio para 1 navio tipo 2
    for(int b = 0; b<1; b++){
        posicaoLinha = (rand()%10)+1;
        posicaoColuna = (rand()%10)+1;

        if(posicaoColuna == 10){
            posicaoColuna = posicaoColuna - 1;
        }

        while(tabuleiro[posicaoLinha][posicaoColuna] == 'W' || tabuleiro[posicaoLinha][posicaoColuna+1] == 'W'){
            posicaoLinha = (rand()%10)+1;
            posicaoColuna = (rand()%10)+1;

            if(posicaoColuna == 10){
                posicaoColuna = posicaoColuna - 1;
            }
        }

        tabuleiro[posicaoLinha][posicaoColuna] = 'W';
        tabuleiro[posicaoLinha][posicaoColuna+1] = 'W';
    }

    //sorteio para 2 navios tipo 3
    for(int c = 0; c<2; c++){
        posicaoLinha = (rand()%10)+1;
        posicaoColuna = (rand()%10)+1;

        if(posicaoColuna == 9){
                posicaoColuna = posicaoColuna - 1;
        }else{
            if(posicaoColuna == 10){
                posicaoColuna = posicaoColuna - 2;
            }
        }

        while(tabuleiro[posicaoLinha][posicaoColuna] == 'W' || tabuleiro[posicaoLinha][posicaoColuna+1] == 'W' || tabuleiro[posicaoLinha][posicaoColuna+2] == 'W'){
            posicaoLinha = (rand()%10)+1;
            posicaoColuna = (rand()%10)+1;

            if(posicaoColuna == 9){
                posicaoColuna = posicaoColuna - 1;
            }else{
                if(posicaoColuna == 10){
                    posicaoColuna = posicaoColuna - 2;
                }
            }
        }

        tabuleiro[posicaoLinha][posicaoColuna] = 'W';
        tabuleiro[posicaoLinha][posicaoColuna+1] = 'W';
        tabuleiro[posicaoLinha][posicaoColuna+2] = 'W';
    }

    //sorteio para 1 navios tipo 4
    for(int d = 0; d<1; d++){
        posicaoLinha = (rand()%10)+1;
        posicaoColuna = (rand()%10)+1;

        if(posicaoColuna == 8){
                posicaoColuna = posicaoColuna - 1;
        }else{
            if(posicaoColuna == 9){
                posicaoColuna = posicaoColuna - 2;
            }else{
                if(posicaoColuna == 10){
                    posicaoColuna = posicaoColuna - 3;
                }
            }
        }

        while(tabuleiro[posicaoLinha][posicaoColuna] == 'W' || tabuleiro[posicaoLinha][posicaoColuna+1] == 'W' || tabuleiro[posicaoLinha][posicaoColuna+2] == 'W'|| tabuleiro[posicaoLinha][posicaoColuna+3] == 'W'){
            posicaoLinha = (rand()%10)+1;
            posicaoColuna = (rand()%10)+1;

            if(posicaoColuna == 8){
                posicaoColuna = posicaoColuna - 1;
            }else{
                if(posicaoColuna == 9){
                    posicaoColuna = posicaoColuna - 2;
                }else{
                    if(posicaoColuna == 10){
                        posicaoColuna = posicaoColuna - 3;
                    }
                }
            }
        }

        tabuleiro[posicaoLinha][posicaoColuna] = 'W';
        tabuleiro[posicaoLinha][posicaoColuna+1] = 'W';
        tabuleiro[posicaoLinha][posicaoColuna+2] = 'W';
        tabuleiro[posicaoLinha][posicaoColuna+3] = 'W';
    }
}

void verNavios(int tabuleiro[][DIMENSAO]){
    int posicao = 1;

    for (int i=0;i<DIMENSAO;i++)
    {
        for( int j = 0; j<DIMENSAO; j++)
        {
            if (j==0 && i==0 || j==11 && i==0 ){
                printf(" ",tabuleiro[i][j]);
            }else{
                if(j==0 || j==11){
                    printf("|",tabuleiro[i][j]);
                }else{
                    if(i==0 || i==11 ){
                        printf("_____",tabuleiro[i][j]);
                    }else{
                        if(tabuleiro[i][j] == 'W'){
                            printf("  %c  ",tabuleiro[i][j]);
                            posicao = posicao + 1;
                        }else{
                            if(posicao < 10){
                                printf("  %d  ",posicao);
                                posicao = posicao + 1;
                            }else{
                                if(posicao < 100)
                                {
                                    printf("  %d ",posicao);
                                    posicao = posicao + 1;
                                }else{
                                    printf(" %d ",posicao);
                                    posicao = posicao + 1;
                                }
                            }
                        }

                    }
                }
            }
        }
         printf ("%\n");

    }
}

int AguaouNavio(int tabuleiro[][DIMENSAO], int tiro){
    int contadorPontos = 0;
    int l = 1;
    int c = 1;

    if(tiro>=1 && tiro<=10){
        c = tiro;
        if(tabuleiro[l][c] == 'W'){
            printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
            contadorPontos = contadorPontos+1;
        }else{
            printf("Errou, atirou na água!\n");
        }
    }else{
        if(tiro>10 && tiro<=20){
            l = 2;
            c = tiro - 10;

            if(tabuleiro[l][c] == 'W'){
                printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                contadorPontos = contadorPontos+1;
            }else{
                printf("Errou, atirou na água!\n");
            }
        }else{
            if(tiro>20 && tiro<=30){
                l = 3;
                c = tiro - 20;

                if(tabuleiro[l][c] == 'W'){
                    printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                    contadorPontos = contadorPontos+1;
                }else{
                    printf("Errou, atirou na água!\n");
                }
            }else{
                if(tiro>30 && tiro<=40){
                    l = 4;
                    c = tiro - 30;

                    if(tabuleiro[l][c] == 'W'){
                        printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                        contadorPontos = contadorPontos+1;
                    }else{
                        printf("Errou, atirou na água!\n");
                    }
                }else{
                    if(tiro>40 && tiro<=50){
                        l = 5;
                        c = tiro - 40;

                        if(tabuleiro[l][c] == 'W'){
                            printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                            contadorPontos = contadorPontos+1;
                        }else{
                            printf("Errou, atirou na água!\n");
                        }
                    }else{
                        if(tiro>50 && tiro<=60){
                            l = 6;
                            c = tiro - 50;

                            if(tabuleiro[l][c] == 'W'){
                                printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                                contadorPontos = contadorPontos+1;
                            }else{
                                printf("Errou, atirou na água!\n");
                            }
                        }else{
                            if(tiro>60 && tiro<=70){
                                l = 7;
                                c = tiro - 60;

                                if(tabuleiro[l][c] == 'W'){
                                    printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                                    contadorPontos = contadorPontos+1;
                                }else{
                                    printf("Errou, atirou na água!\n");
                                }
                            }else{
                                if(tiro>70 && tiro<=80){
                                    l = 8;
                                    c = tiro - 70;

                                    if(tabuleiro[l][c] == 'W'){
                                        printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                                        contadorPontos = contadorPontos+1;
                                    }else{
                                        printf("Errou, atirou na água!\n");
                                    }
                                }else{
                                    if(tiro>80 && tiro<=90){
                                        l = 9;
                                        c = tiro - 80;

                                        if(tabuleiro[l][c] == 'W'){
                                            printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                                            contadorPontos = contadorPontos+1;
                                        }else{
                                            printf("Errou, atirou na água!\n");
                                        }
                                    }else{
                                        if(tiro>90 && tiro<=100){
                                            l = 10;
                                            c = tiro - 90;

                                            if(tabuleiro[l][c] == 'W'){
                                                printf("Acertou! Coordenadas: (%d,%d).\n", l, c);
                                                contadorPontos = contadorPontos+1;
                                            }else{
                                                printf("Errou, atirou na água!\n");
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return contadorPontos;
}

void tiroPreenchimento(int tabuleiro[][DIMENSAO], int tiro){
    int l = 1;
    int c = 1;

    if(tiro>=1 && tiro<=10){
        c = tiro;

        if(tabuleiro[l][c] == 'W'){
            tabuleiro[l][c] = 'N';
        }else{
           tabuleiro[l][c] = 'X';
        }
    }else{
        if(tiro>10 && tiro<=20){
            l = 2;
            c = tiro - 10;

            if(tabuleiro[l][c] == 'W'){
                tabuleiro[l][c] = 'N';
            }else{
               tabuleiro[l][c] = 'X';
            }
        }else{
            if(tiro>20 && tiro<=30){
                l = 3;
                c = tiro - 20;

                if(tabuleiro[l][c] == 'W'){
                    tabuleiro[l][c] = 'N';
                }else{
                   tabuleiro[l][c] = 'X';
                }
            }else{
                if(tiro>30 && tiro<=40){
                    l = 4;
                    c = tiro - 30;

                    if(tabuleiro[l][c] == 'W'){
                        tabuleiro[l][c] = 'N';
                    }else{
                       tabuleiro[l][c] = 'X';
                    }
                }else{
                    if(tiro>40 && tiro<=50){
                        l = 5;
                        c = tiro - 40;

                        if(tabuleiro[l][c] == 'W'){
                            tabuleiro[l][c] = 'N';
                        }else{
                           tabuleiro[l][c] = 'X';
                        }
                    }else{
                        if(tiro>50 && tiro<=60){
                            l = 6;
                            c = tiro - 50;

                            if(tabuleiro[l][c] == 'W'){
                                tabuleiro[l][c] = 'N';
                            }else{
                               tabuleiro[l][c] = 'X';
                            }
                        }else{
                            if(tiro>60 && tiro<=70){
                                l = 7;
                                c = tiro - 60;

                                if(tabuleiro[l][c] == 'W'){
                                    tabuleiro[l][c] = 'N';
                                }else{
                                   tabuleiro[l][c] = 'X';
                                }
                            }else{
                                if(tiro>70 && tiro<=80){
                                    l = 8;
                                    c = tiro - 70;

                                    if(tabuleiro[l][c] == 'W'){
                                        tabuleiro[l][c] = 'N';
                                    }else{
                                       tabuleiro[l][c] = 'X';
                                    }
                                }else{
                                    if(tiro>80 && tiro<=90){
                                        l = 9;
                                        c = tiro - 80;

                                        if(tabuleiro[l][c] == 'W'){
                                            tabuleiro[l][c] = 'N';
                                        }else{
                                           tabuleiro[l][c] = 'X';
                                        }
                                    }else{
                                        if(tiro>90 && tiro<=100){
                                            l = 10;
                                            c = tiro - 90;

                                            if(tabuleiro[l][c] == 'W'){
                                                tabuleiro[l][c] = 'N';
                                            }else{
                                               tabuleiro[l][c] = 'X';
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

void atualizacoesTabuleiro(int tabuleiro[][DIMENSAO], int tiro){
    int posicao = 1;

    tiroPreenchimento(tabuleiro, tiro);

    for (int i=0 ; i < DIMENSAO;i++)
    {
        for( int j = 0; j<DIMENSAO; j++)
        {
            if (j==0 && i==0 || j==11 && i==0 ){
                printf(" ",tabuleiro[i][j]);
            }else{
                if(j==0 || j==11){
                    printf("|",tabuleiro[i][j]);
                }else{
                    if(i==0 || i==11 ){
                        printf("_____",tabuleiro[i][j]);
                    }else{
                        if(posicao<10){
                            if(tabuleiro[i][j]=='N'){
                                printf("  N  ", tabuleiro[i][j]);
                                posicao = posicao + 1;
                            }else{
                                if(tabuleiro[i][j]=='X'){
                                    printf("  X  ", tabuleiro[i][j]);
                                    posicao = posicao + 1;
                                }else{
                                    printf("  %d  ",posicao);
                                    posicao = posicao + 1;
                                }
                            }
                        }else{
                            if(posicao>=10 && posicao<100){
                                if(tabuleiro[i][j]=='N'){
                                    printf("  N  ", tabuleiro[i][j]);
                                    posicao = posicao + 1;
                                }else{
                                    if(tabuleiro[i][j]=='X'){
                                        printf("  X  ", tabuleiro[i][j]);
                                        posicao = posicao + 1;
                                    }else{
                                        printf("  %d ",posicao);
                                        posicao = posicao + 1;
                                    }
                                }
                            }else{
                                if(tabuleiro[i][j]=='N'){
                                    printf("  N  ", tabuleiro[i][j]);
                                    posicao = posicao + 1;
                                }else{
                                    if(tabuleiro[i][j]=='X'){
                                        printf("  X  ", tabuleiro[i][j]);
                                        posicao = posicao + 1;
                                    }else{
                                        printf(" %d ",posicao);
                                        posicao = posicao + 1;
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
         printf ("%\n");
    }
}

void resultadoFinal(int tabuleiro[][DIMENSAO], int tiro){
    int resultado = 0;

    printf("Jogo Batalha Naval:\n\n");
    atualizacoesTabuleiro(tabuleiro,tiro);
    resultado = AguaouNavio;
    if(resultado == 17){
        printf("\nVocê ganhou o jogo!! Afundou os 9 navios!");
    }else{
        printf("\nVocê perdeu ganhou o jogo. Não afundou os 9 navios :(");
    }
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    char tabuleiro[DIMENSAO][DIMENSAO];
    int tiro = 0;

    //tabuleiro inicial
    printf("Jogo Batalha Naval:\n");
    criarMatrizInicial(tabuleiro);
    printf("O total de tiros restantes = 25 \n");
    printf("\nDigite o numero de onde quer atirar: ");
    scanf("%d", &tiro);
    system("cls");

    //jogadas
    for(int k=24 ; k>0 ; k--){
        int teste = k;
        printf("Jogo Batalha Naval:\n\n");
        AguaouNavio(tabuleiro, tiro);
        atualizacoesTabuleiro(tabuleiro,tiro);

        //Opção criada porque o k estava recebendo 88 toda vez que digitava 23.
        //E 23 e 22 não estavam atualizando seus conteúdos
        if(tiro == 23){
            k = teste;
            if(tabuleiro[3][3] == 'W'){
                tabuleiro[3][3] = 'N';
            }else{
                tabuleiro[3][3] = 'X';
            }
        }else{
            if(tiro == 22){
                if(tabuleiro[3][2] == 'W'){
                    tabuleiro[3][2] = 'N';
                }else{
                    tabuleiro[3][2] = 'X';
                }
            }
        }

        printf("O total de tiros restantes = %d \n", k);
        printf("\nDigite o numero de onde quer atirar: ");
        scanf("%d", &tiro);

        //se o tiro for fora dos numeros
        while(tiro<1 || tiro>100){
            printf("\nDigite o numero de onde quer atirar: ");
            scanf("%d", &tiro);
        }

        fflush(stdin);
        system("cls");
    }

    resultadoFinal(tabuleiro, tiro);

    return(0);
}
