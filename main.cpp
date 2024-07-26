#include "sistema.h"
int main(){
  Sistema sistema;
  bool ativo = true;
  while(ativo){
    sistema.loginGeral();
    sistema.cardapio();
  }
}