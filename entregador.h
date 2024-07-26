#include "cliente.h"

//Classe do Entregador
class Entregador{
private:
  std::string nomeEntregador;
  int id;

public:
//Construtor e Getters
  Entregador(const std::string& nomeEntregador, const int& id):
    nomeEntregador(nomeEntregador), id(id) {}

  std::string getNome() const{
    return nomeEntregador;
  }
  int getId() const{
    return id;
  }
};