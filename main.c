/*
Batallha Naval
Autores: Gustavo Pelanda e Stephanie Calegari
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<locale.h>

void instrucoes ();
void jogar ();
void recordes ();
void salvarecordes ();
void sair ();

void main(){

setlocale(LC_ALL, "Portuguese");

int a=1, x=0;
do {
      printf("BATALHA NAVAL\n");
      printf("\n1)Instruções\n2)Jogar\n3)Records\n\nDigite 0 para sair\n");
      printf("\nSelecione:");

      do {
            scanf("%d", &a);

            system("cls || clear"); //limpa a tela

            switch(a){
            case 1:
                instrucoes();
                break;

            case 2:
                jogar();
                break;

            case 3:
                {
                 int b;
                 do{
                  printf("\n1)Registrar Recorde\n2)Ver Recordes\n");
                  printf("\nSelecione:");
                  scanf("%d", &b);
                  system("cls || clear");
                  switch (b){
                    case 1:
                         salvarecordes();
                         break;
                    case 2:
                         recordes();
                         break;
                    default:
                         printf("Digite 1 para registrar um recorde ou 2 para ver os recordes registrados\n");
                         break;
                   }
                   } while(b!=0);
               }
               break;

            case 0:
                sair();
                x=9;
                break;

            default:
                printf("Digite uma opção válida\n");
                printf("\n1)Instruções\n2)Jogar\n3)Records\n0)sair\n");
                printf("\nSelecione:");
        }
    } while(a);
}while(x==0);
}

void instrucoes (){
    printf("\tOBJETIVO: \nDestruir todos os barcos do inimigo.\n");
    printf("Primeiramente, o jogador deve posicionar seus barcos em seu tabuleiro.\n");
    printf("Tendo todos eles posicionados, o jogador deve então escolher as posições\ndo tabuleiro inimigo que deseja atacar.\n");
    printf("O jogo termina quando um dos jogadores tiver toda sua frota destruída.\n");
}
void jogar (){
      int **mat;
    int escolha1, m, d, i;
  char b;
  //função tamanho tabuleiro:
  do{
  printf("Escolha o tamanho do tabuleiro:\n1)Pequeno (8x8)\n2)Médio (10x10)\n3)Grande (12x12)\nSelecione:");
  scanf("%d", &escolha1);
  if(escolha1==1){
    m=9;

  }
  if(escolha1==2){
    m=11;

  }
  if(escolha1==3){
    m=13;

  }
  }while(escolha1<1||escolha1>3);
  mat = (int **)calloc(m,sizeof(int *));
  for(i=0; i<m; i++){
     mat[i] = (int *)calloc(m,sizeof(int));
  }
  printf("\nTabuleiro escolhido:\n");

  int j, k;
  int num = 1;
  char c= 'A';

  for (k=1; k<m; k++){
    mat[0][k]=num;
    num++;
  }

  for(j=1; j<m; j++){
    mat[j][0]=c;
    c++;
  }
 for (j=1; j<m; j++){
    for (k=1; k<m; k++){
      mat[j][k]= '-';
    }
  }
  for(k=1; k<m; k++){
    printf("\t%d", mat[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat[j][k]);
    }
    printf("\n");
  }
  //fazer esperar o tempo e apagar tudo, 5 segundos.
  int tempo = clock();
  while(clock() - tempo < 3000);
  system("cls");

  //função posicionamento player 1:
  printf("Tabuleiro - PLAYER 1\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat[j][k]);
    }
    printf("\n");
  }
  int linha_mat, coluna_mat, linha_mati, coluna_mati, linha_matf, coluna_matf;
  int numeroi, numerof;
  char caracteri, caracterf;
  int mat1[m][m];
      for(j=0; j<m; j++){
        for (k=0; k<m; k++){
          mat1[j][k] = mat[j][k];
        }
      }

  printf("\n");
  //Posicionamento barco 1:
  printf("Posicionamento do barco 1 --> tamanho=2\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat1[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat1[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat1[j][k]);
    }
    printf("\n");
  }
/*
  //Posicionamento barco 2
  printf("\nPosicionamento do barco 2 --> tamanho=3\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat1[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat1[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat1[j][k]);
    }
    printf("\n");
  }
  //Posicionamento barco 3:
  printf("Posicionamento do barco 3 --> tamanho=3\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat1[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat1[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat1[j][k]);
    }
    printf("\n");
  }
  //Posicionamento barco 4
  printf("\nPosicionamento do barco 4 --> tamanho=4\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat1[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat1[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat1[j][k]);
    }
    printf("\n");
  }
  //Posicionamento barco 5
  printf("\nPosicionamento do barco 5 --> tamanho=5\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat1[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro final:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat1[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat1[j][k]);
    }
    printf("\n");
  }
*/
  printf("\nPosicionamento finalizado\n");

  //fazer esperar o tempo e apagar tudo, 3 segundos.
  tempo = clock();
  while(clock() - tempo < 3000);
  system("cls");

  printf("\nTabuleiro - PLAYER 2\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat[j][k]);
    }
    printf("\n");
  }

    //função posicionamento player 2:
  int mat2[m][m];
      for(j=0; j<m; j++){
        for (k=0; k<m; k++){
          mat2[j][k] = mat[j][k];
        }
      }

  printf("\n");
  //Posicionamento barco 1:
  printf("Posicionamento do barco 1 --> tamanho=2\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat2[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat2[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat2[j][k]);
    }
    printf("\n");
  }

 /* //Posicionamento barco 2
  printf("\nPosicionamento do barco 2 --> tamanho=3\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat2[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat2[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat2[j][k]);
    }
    printf("\n");
  }
  //Posicionamento barco 3:
  printf("Posicionamento do barco 3 --> tamanho=3\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat2[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat2[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat2[j][k]);
    }
    printf("\n");
  }
  //Posicionamento barco 4
  printf("\nPosicionamento do barco 4 --> tamanho=4\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat2[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat2[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat2[j][k]);
    }
    printf("\n");
  }
  //Posicionamento barco 5
  printf("\nPosicionamento do barco 5 --> tamanho=5\n");
  //posição inicial:
  do{
    setbuf (stdin , NULL);
  printf("Linha da primeira posição: ");
  scanf("%c", &caracteri);
  if(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracteri)<'A'||toupper(caracteri)>('A'+(m-1)));

  do{
  printf("\nColuna da primeira posição: ");
  scanf("%d", &numeroi);
  if(numeroi<1||numeroi>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numeroi<1||numeroi>(1+(m-1)));
  linha_mati = toupper(caracteri)-'@';
  coluna_mati = numeroi;

  //posição final:
  do{
    setbuf (stdin , NULL);
  printf("\nLinha da última posição: ");
  scanf("%c", &caracterf);
  if(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caracterf)<'A'||toupper(caracterf)>('A'+(m-1)));

  do{
  printf("\nColuna da última posição: ");
  scanf("%d", &numerof);
  if(numerof<1||numerof>(1+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerof<1||numerof>(1+(m-1)));

  linha_matf = toupper(caracterf)-'@';
  coluna_matf = numerof;

  //atribuição da letra 'X':
  for(j = linha_mati; j<=linha_matf; j++){
    for (k = coluna_mati; k <=coluna_matf; k++){
        mat2[j][k] = 'X';
    }
  }

    //imprime matriz dps do posicionamento:
  printf("\nTabuleiro final:\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat2[0][k]);
  }
  printf("\n");
  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat2[j][k]);
    }
    printf("\n");
  }
*/
  printf("\nPosicionamento finalizado\n");

  //fazer esperar o tempo e apagar tudo, 3 segundos.
  tempo = clock();
  while(clock() - tempo < 3000);
  system("cls");

  //posição tiros:
  int t1=0, acertos1=0, t2=0, acertos2=0;
  char caractert1, caractert2;
  int numerot1, numerot2;
  int linha_tiro1, coluna_tiro1, linha_tiro2, coluna_tiro2;
  int mat_tiro1[m][m], mat_tiro2[m][m];
  int mat_printa1[m][m],mat_printa2[m][m];
  //mat tiro recebe a matriz com as posições dos barcos
  for(j=0; j<m; j++){
    for (k=0; k<m; k++){
      mat_tiro1[j][k] = mat2[j][k];
      mat_tiro2[j][k] = mat1[j][k];
    }
  }
  //mat pra printar recebe matriz vazia
  for(j=0; j<m; j++){
    for (k=0; k<m; k++){
      mat_printa1[j][k] = mat[j][k];
      mat_printa2[j][k] = mat[j][k];
    }
  }



  do{
    // imprimir o tabuleiro vazio
  printf("\nPLAYER 1\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat_printa1[0][k]);
  }
  printf("\n");

  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat_printa1[j][k]);
    }
    printf("\n");
  }
  do{
    setbuf (stdin , NULL);
  printf("\nLinha do tiro: ");
  scanf("%c", &caractert1);
  if(toupper(caractert1)<'A'||toupper(caractert1)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caractert1)<'A'||toupper(caractert1)>('A'+(m-1)));

  do{
  printf("\nColuna do tiro: ");
  scanf("%d", &numerot1);
  if(numerot1<1||numerot1>((m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerot1<1||numerot1>((m-1)));

  linha_tiro1 = toupper(caractert1)-'@';
  coluna_tiro1 = numerot1;

  if(mat_tiro1[linha_tiro1][coluna_tiro1]=='-'){
    printf("\nAcertou a água!\n");
    (t1)++;
    mat_printa1[linha_tiro1][coluna_tiro1] = '~';
  }
  if(mat_tiro1[linha_tiro1][coluna_tiro1]=='X'){
    printf("\nAcertou um barco!!\n");
    (acertos1)++;
    (t1)++;
    mat_printa1[linha_tiro1][coluna_tiro1] = '*';
  }
  if((mat_tiro1[linha_tiro1][coluna_tiro1]=!'X')||(mat_tiro1[linha_tiro1][coluna_tiro1]=!'-')){
    printf("\nPosição invalida, tente novamente.\n");
    (t1)++;
  }

  printf("\nTiros: %d\nAcertos: %d\n\nTabuleiro com os tiros:\n\n", t1, acertos1);
  for(k=1; k<m; k++){
    printf("\t%d", mat_printa1[0][k]);
  }
  printf("\n");

  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat_printa1[j][k]);
    }
    printf("\n");
  }

  //fazer esperar o tempo e apagar tudo, 5 segundos.
  tempo = clock();
  while(clock() - tempo < 5000);
  system("cls");

  // imprimir o tabuleiro vazio
  printf("\nPLAYER 2\n");
  for(k=1; k<m; k++){
    printf("\t%d", mat_printa2[0][k]);
  }
  printf("\n");

  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat_printa2[j][k]);
    }
    printf("\n");
  }
  do{
    setbuf (stdin , NULL);
  printf("\nLinha do tiro: ");
  scanf("%c", &caractert2);
  if(toupper(caractert2)<'A'||toupper(caractert2)>('A'+(m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(toupper(caractert2)<'A'||toupper(caractert2)>('A'+(m-1)));

  do{
  printf("\nColuna do tiro: ");
  scanf("%d", &numerot2);
  if(numerot2<1||numerot2>((m-1))){
    printf("Opção invalida. Tente novamente.\n");
  }
  }while(numerot2<1||numerot2>((m-1)));

  linha_tiro2 = toupper(caractert2)-'@';
  coluna_tiro2 = numerot2;

  if(mat_tiro2[linha_tiro2][coluna_tiro2]=='-'){
    printf("\nAcertou a água!\n");
    (t2)++;
    mat_printa2[linha_tiro2][coluna_tiro2] = '~';
  }
  if(mat_tiro2[linha_tiro2][coluna_tiro2]=='X'){
    printf("\nAcertou um barco!!\n");
    (acertos2)++;
    (t2)++;
    mat_printa2[linha_tiro2][coluna_tiro2] = '*';
  }
  if((mat_tiro2[linha_tiro2][coluna_tiro2]=!'X')||(mat_tiro2[linha_tiro2][coluna_tiro2]=!'-')){
    printf("\nPosição invalida, tente novamente.\n");
    (t2)++;
  }

  printf("\nTiros: %d\nAcertos: %d\n\nTabuleiro com tiros:\n\n", t2, acertos2);
  for(k=1; k<m; k++){
    printf("\t%d", mat_printa2[0][k]);
  }
  printf("\n");

  for(j=1; j<m; j++){
    for (k=0; k<m; k++){
      printf("%c\t", mat_printa2[j][k]);
    }
    printf("\n");
  }

  //fazer esperar o tempo e apagar tudo, 5 segundos.
  tempo = clock();
  while(clock() - tempo < 5000);
  system("cls");

  }while((acertos1!=2)&&(acertos2!=2));
  if((acertos1 == 2)&&(acertos2 < 2)){
    printf("\n----PLAYER 1 VENCEU!!----\n");
    printf("\n-----COM %d TIROS!!-----\n", t1);
  }
  if((acertos2 == 2)&&(acertos1 <2)){
    printf("\n----PLAYER 2 VENCEU!!----\n");
    printf("\n----COM %d TIROS!!----\n", t2);
  }
  if((acertos1 == 2)&&(acertos2 == 2)){
    printf("\n----EMPATE!!----\n");
    printf("\n----COM %d TIROS!!----\n", t1);
  }

}
void salvarecordes () {
FILE *fp;
char ch;
  fp = fopen("teste.txt", "w" );
  if (fp == NULL)
  {
    printf ("O arquivo nao pode ser aberto. \n" );
    exit (1);
  }
  printf ("Digite seu nome, a quantidade de movimentos realizados e #: \n" );
  do{
      ch = getchar();
      fputc ( ch, fp );
    }while (ch!='#');
  fclose (fp);
}

void recordes ()
{
  FILE *fp;
  char ch;

  fp = fopen("teste.txt", "r");
  if (fp == NULL)
  {
    printf ("O arquivo nao pode ser aberto. \n" );
    exit (1);
  }
  do
  {
    ch=fgetc(fp);
    putchar(ch);
  } while (ch!=EOF);
  fclose(fp);
}


void sair (){
    exit(0);
}
