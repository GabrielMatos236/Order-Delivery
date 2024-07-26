#include "entregador.h"

//Classe do Sistema
class Sistema{
private:
  std::vector<std::string> compras; // --> Exibe as compras no carrinho
  int total = 0; // --> Total do carrinho

  std::vector<Hamburguer> hamburguer;
  std::vector<Bebidas> bebidas;
  std::vector<Acompanhamentos> acompanhamentos;
  std::vector<Sobremesas> sobremesas;
  std::vector<Combos> combos;
  std::vector<Cliente> clientes;
  std::vector<Entregador> entregadores;
  std::unordered_map<std::string, double> fretes{
  {"AUXILIADORA", 5},
  {"BELA VISTA", 5},
  {"MENINO DEUS", 4},
  {"CENTRO", 0},
  {"PARTENON", 6},
  {"FLORESTA", 3},
  {"HIGIENOPOLIS", 6},
  {"JARDIM BOTANICO", 6},
  {"MOINHOS DE VENTO", 5},
  {"MONTSERRAT", 4},
  {"PASSO DAS PEDRAS", 12},
  {"RUBEM BERTA", 5},
  {"SANTA CECILIA", 4},
  {"NAVEGANTES", 6},
  {"AZENHA", 4},
  {"PETROPOLIS", 6},
  {"SANTANA", 4},
  {"RIO BRANCO", 3},
  {"CIDADE BAIXA", 0}
};
  std::map<pair<string, string>, pair<string, vector<string>>> exibirProdutos;

public:
//Funções do Sistema
  Sistema();
  void capsLock(std::string& str);
  void gerarIdCompra();
  std::string semNumero(const std::string& input);
  int  verificarInput();
  void loginGeral();
  void loginPedido();
  void loginEntregador();
  void exibirEntrega();
  void comprarCombo();
  void maisItemCombo();
  int  maisItem();
  void cardapio();
  void calcularFrete();
  void confirmarPagamento();
  void caixa();
};