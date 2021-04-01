#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int senha,i,chances = 5, palpite,v1=0 , v2=100, v5 =1;
  int continua;

  do{
    //pedindo senha ao jogador1
    printf("Jogador 1 - Digite uma senha entre %d e %d para ser descoberta pelo jogador 2 : ", v1,v2);
    scanf("%d", &senha);
    system("clear");
 
    //verificando se senha está dentro das espedificações
    while(senha < v1 || senha > v2){
      printf("Senha fora do intervalo permitido, digite outra senha : ");
      scanf("%d", &senha);
    }
    //Jogador 2
    printf("Jogador 2 - Você tem %d chances para descobrir a senha ! \n",chances);

    //palpites e repostas
    for(i = 1; i < chances+1; i++){
      printf("Dê o %d º palpite : ",i);
      scanf("%d", &palpite);
      if(palpite < v1 || palpite > v2){
        printf("O palpite foi fora do intervalo ! (de %d a %d) \n", v1,v2);
        i = i-1;
      }else{
        if(senha == palpite){
          printf("Você acertou ! A senha era %d ! \n", senha);
          printf("Deseja jogar novamente ? (Digite 1 para sim ou outro número para sair.)");
          scanf("%d",&continua);
          break;
        }else if(i == 5 ){
          printf("Você perdeu. Tente novamente depois.\n");
          printf("Deseja jogar novamente ? (Digite 1 para sim ou outro número para sair.)");
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