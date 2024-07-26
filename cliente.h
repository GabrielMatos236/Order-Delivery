#include "menu.h"

//Classe do Cliente
class Cliente{
private:
  std::string nomeCliente;
  std::string telefone;
  std::string endereco;

public:
//Construtor e Getters
  Cliente(const std::string& nomeCliente, const std::string& telefone, const std::string& endereco):
    nomeCliente(nomeCliente), telefone(telefone), endereco(endereco) {}

  std::string getNome() const{
    return nomeCliente;
  }
  std::string getEndereco() const{
    return endereco;
  }
};