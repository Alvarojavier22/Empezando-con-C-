#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main (){
  cout << "*************************************" <<endl;
  cout << "* Bem-vindos ao jogo da adivinhacao!*" <<endl;
  cout << "*************************************" <<endl;

  cout << "Escolha seu nivel de dificuldade: " << endl;
  cout << "Fácil (F), Médio (M) ou Dificil (D)" << endl;

  char dificuldade;
  cin >> dificuldade;

  int numero_de_tentativas;

  if(dificuldade == 'F'){
    numero_de_tentativas = 15;
  }
  else if(dificuldade == 'M'){
    numero_de_tentativas = 10;
  }
  else{
    numero_de_tentativas = 5;
  }

  srand(time(NULL));
  const int NUMERO_SECRETO = rand() % 100;

  bool nao_acertou = true;
  int tentativas = 0;

  double pontos = 1000.0;

  for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){
    int chute;
    cout << "Tentativa " << tentativas << endl;
    cout << "Qual seu chute? ";
    cin >> chute;

    double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
    pontos = pontos - pontos_perdidos;

    cout << "O valor do seu chute é: " << chute << endl;

    bool acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;


    if(acertou){
      cout << "Parabéns! Vocé acertou o número secreto!" << endl;
      nao_acertou = false;
      break;
    }
    else if(maior){
      cout << "Seu chute foi maior que o número secreto!" << endl;
    }
    else {
      cout << "Seu chute foi menor que o número secreto!" << endl;
    }

  }
  cout << "Fim de jogo!" << endl;
  if(nao_acertou){
    cout << "Vocé perdeu! Tente novamente!" << endl;
  }
  else{
  cout << "Vocé acertou o número secreto em " << tentativas << " tantativas." << endl;
  cout.precision(2);
  cout << fixed;
  cout << "Sua puntuacao foi de " << pontos << " pontos." << endl;
}
}
