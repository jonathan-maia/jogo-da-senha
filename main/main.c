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

    //perguntando se ir� jogar contra a m�quina.
    printf("Se desejar jogar contra o computador, digite 1. Para jogar contra outra pessoa, digite qualquer outro n�mero :");
    scanf("%d", &maquina);

    // jogar contra m�quina e gerar senha aleat�ria
    if(maquina==1){
      srand((unsigned)time(NULL));
      senha = (rand() % v2) +1;
      
    }else{
      //pedindo senha ao jogador1
      printf("Jogador 1 - Digite uma senha entre %d e %d para ser descoberta pelo jogador 2 : ", v1,v2);
      scanf("%d", &senha);
  
      //verificando se senha est� dentro das especifica��es e pedindo outra senha
      while(senha < v1 || senha > v2){
        printf("Senha fora do intervalo permitido, digite outra senha: ");
        scanf("%d", &senha);
      }
      //limpando terminal
      system("cls");
    }

    //Jogador 2
    printf("Jogador 2 - Voc� tem %d chances para descobrir a senha ! \n",chances);

    //palpites e repostas
    for(i = 1; i < chances+1; i++){
      printf("D� o %d� palpite : ",i);
      scanf("%d", &palpite);
      if(palpite < v1 || palpite > v2){
        printf("O palpite foi fora do intervalo ! (de %d a %d) \n", v1,v2);
        i = i-1;
      }else{
        if(senha == palpite){
          printf("Voc� acertou ! A senha era %d ! \n", senha);
          printf("Deseja jogar novamente ? (Digite 1 para sim ou outro n�mero para sair): ");
          scanf("%d",&continua);
          break;
        }else if(i == 5 ){
          printf("Voc� perdeu. Tente novamente depois.\n");
          printf("Deseja jogar novamente ? (Digite 1 para sim ou outro n�mero para sair)");
          scanf("%d",&continua);
        }else if(senha == palpite-1 || senha == palpite+1){
          printf("T� QUENTE !!! \n");
        }else{
          if(palpite > senha){
            printf("A senha � menor que %d ! \n",palpite);
          }else{
            printf("A senha � maior que %d! \n",palpite);
          }
        }
      }
    }
  }while( continua == 1);

  printf("*********** Jogo encerrado ***********");
  
  return 0;
}