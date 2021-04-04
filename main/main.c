#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(void)
{
  setlocale(LC_ALL, "Portuguese-brazilian"); //Mudar config de utf8 p/ ISO 8859-1

  int chances = 5, palpite,v1=0 , v2=100, aux;
  int continua, senha, i, maquina;

  do{

    //perguntando se irá jogar contra a máquina.
    printf("Se desejar jogar contra o computador, digite 1. Para jogar contra outra pessoa, digite qualquer outro número :");
    scanf("%d", &maquina);

    if(maquina==1){
      srand((unsigned)time(NULL));
      senha = (rand() % v2) +1;
      printf("%d", senha);
      
    }else{
      //pedindo senha ao jogador1
      printf("Jogador 1 - Digite uma senha entre %d e %d para ser descoberta pelo jogador 2 : ", v1,v2);
      scanf("%d", &senha);
      system("cls");
  
      //verificando se senha está dentro das especificações
      while(senha < v1 || senha > v2){
        printf("Senha fora do intervalo permitido, digite outra senha : ");
        scanf("%d", &senha);
      }
    }

    //Jogador 2
    printf("Jogador 2 - Você tem %d chances para descobrir a senha ! \n",chances);

    //palpites e repostas
    for(i = 1; i < chances+1; i++){
      printf("Dê o %dº palpite : ",i);
      scanf("%d", &palpite);
      if(palpite < v1 || palpite > v2){
        printf("O palpite foi fora do intervalo ! (de %d a %d) \n", v1,v2);
        i = i-1;
      }else{
        if(senha == palpite){
          printf("Você acertou ! A senha era %d ! \n", senha);
          printf("Deseja jogar novamente ? (Digite 1 para sim ou outro número para sair): ");
          scanf("%d",&continua);
          break;
        }else if(i == 5 ){
          printf("Você perdeu. Tente novamente depois.\n");
          printf("Deseja jogar novamente ? (Digite 1 para sim ou outro número para sair)");
          scanf("%d",&continua);
        }else if(senha == palpite-1 || senha == palpite+1){
          printf("TÁ QUENTE !!! \n");
        }else{
          if(palpite > senha){
            printf("A senha é menor que %d ! \n",palpite);
          }else{
            printf("A senha é maior que %d! \n",palpite);
          }
        }
      }
    }
  }while( continua == 1);

  printf("*********** Jogo encerrado ***********");
  
  return 0;
}