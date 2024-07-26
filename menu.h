#include <iostream>// --> Entrada e Saída
#include <string>// --> Manipulação de String
#include <vector>// --> Contêiner Dinâmico
#include <limits>// --> Constantes de Limites Numéricos
#include <algorithm>// --> Funções Algorítmas
#include <cctype>// --> Manipulação de Char
#include <cstdlib>// --> Conversão de Strings
#include <random>// --> Geração de Números Aleatórios
#include <map>// --> Contêiner Associativo
#include <unordered_map>// --> <map> sem ordem definida
using namespace std;

//Classes dos Itens do Menu
class Hamburguer{
public:
  std::string nome;
  std::string descricao;
  int calorias;
  float preco;

//Construtor
  Hamburguer(const std::string& nome, const std::string& descricao, const int& calorias, const float& preco):
    nome(nome), descricao(descricao), calorias(calorias), preco(preco) {}
};

class Bebidas{
public:
  std::string nome2;
  int ml;
  float preco2;

//Construtor
  Bebidas(const std::string& nome2, const int& ml, const float& preco2):
    nome2(nome2), ml(ml), preco2(preco2){}
};

class Acompanhamentos{
public:
  std::string nome3;
  std::string descricao2;
  int porcao;
  int calorias2;
  float preco3;

//Construtor
  Acompanhamentos(const std::string& nome3, const std::string& descricao2, const int& porcao, const int& calorias2, const float& preco3):
    nome3(nome3), descricao2(descricao2), porcao(porcao), calorias2(calorias2), preco3(preco3) {}
};

class Sobremesas{
public:
  std::string nome4;
  std::string descricao3;
  int calorias3;
  float preco4;

//Construtor
  Sobremesas(const std::string& nome4, const std::string& descricao3, const int& calorias3, const float& preco4):
    nome4(nome4), descricao3(descricao3), calorias3(calorias3), preco4(preco4) {}
};

class Combos{
public:
  std::string nome5;
  int preco5;

//Construtor
  Combos(const std::string& nome5, const int& preco5):
    nome5(nome5), preco5(preco5) {}
};