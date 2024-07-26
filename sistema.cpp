#include "sistema.h"

//Declaração das Variáveis do Sistema
bool maisUmItem; // --> Para o usuário não ficar voltando manualmente
bool caixaAberto; // --> Verifica se o usuário está no caixa
bool modoEntrega; // --> Verfifica se o usuário é um Entregador
bool programa; // --> Programa está rodando
bool isBurger, isBebida, isAcomp, isSobre; // --> Confirmar qual item está sendo comprado
std::string confirmacao, nomeC, nomeE, telefone, endereco;
int escolha, escolha2, escolhaC, idEntregador, escolhaPagamento, adicional, verInput , frete;

//Atribuição dos Itens
Sistema::Sistema(){
  acompanhamentos.push_back(Acompanhamentos("Batata Frita", "Batatas fritas douradas clássicas, perfeitamente temperadas e crocantes.", 200, 700, 12));
  acompanhamentos.push_back(Acompanhamentos("Anéis de Cebola", "Anéis de cebola cortados grossos, empanados e fritos até ficarem crocantes e dourados.", 150, 650, 12));
  acompanhamentos.push_back(Acompanhamentos("Palitos de Queijo", "Palitos de mussarela empanados servidos com molho marinara.", 200, 750, 15));
  acompanhamentos.push_back(Acompanhamentos("Nachos", "Chips de tortilla cobertos com queijo derretido, jalapeños, creme de leite, guacamole e salsa.", 300, 1550, 18));
  acompanhamentos.push_back(Acompanhamentos("Batata Smile", "Batatas fritas frescas e crocantes.", 200, 700, 12));
  
  sobremesas.push_back(Sobremesas("Magnus Chocolate Mountain", "Um rico bolo de chocolate coberto com sorvete de baunilha e regado com calda quente.", 800, 12));
  sobremesas.push_back(Sobremesas("Magnus's Berry Bliss Sundae", "Um sundae com camadas de sorvete de baunilha, frutas frescas, chantilly e compota de frutas vermelhas.", 670, 12));
  sobremesas.push_back(Sobremesas("Magnus's Caramel Delight", "Um pudim cremoso de caramelo servido com um bocado de chantilly e uma pitada de sal marinho.", 420, 14));
  sobremesas.push_back(Sobremesas("Magnus's Cookie Monster", "Um biscoito gigante com gotas de chocolate servido quente com uma bola de sorvete de baunilha e calda de chocolate.", 1400, 20));
  sobremesas.push_back(Sobremesas("Magnus's Apple Crisp", "Crumble de maçã quente com cobertura de aveia e canela, servido com uma bola de sorvete de baunilha e calda de caramelo.", 800, 20));
  
  hamburguer.push_back(Hamburguer("Magnus Maximus Burger", "Um imponente hambúrguer duplo de carne com queijo cheddar, bacon crocante, alface, tomate, picles e molho especial do Magnus,", 550, 30));
  hamburguer.push_back(Hamburguer("Mighty Magnus Burger","Um suculento hambúrguer de carne coberto com queijo suíço, cebola caramelizada, cogumelos salteados, alface e um saboroso aioli de alho.", 650, 35));
  hamburguer.push_back(Hamburguer("Magnus BBQ Burger", "Hambúrguer de carne grelhada com molho barbecue defumado, rodelas de cebola crocantes, queijo pepper jack, alface e tomate.", 650, 38));
  hamburguer.push_back(Hamburguer("Magnus Fiesta Burger", "Uma delícia picante com hambúrguer de carne com queijo pepper jack, jalapeños, abacate, alface, tomate e uma picante maionese chipotle.", 450, 30));
  hamburguer.push_back(Hamburguer("Magnus Classic Cheeseburger","Um favorito atemporal com hambúrguer de carne, queijo americano, alface, tomate, picles, cebola, ketchup e mostarda.", 400, 25));
  hamburguer.push_back(Hamburguer("Magnus Veggie Delight","Um hambúrguer vegetariano grelhado com mussarela fresca, pimentão vermelho assado, alface, tomate e molho pesto de manjericão.", 350, 20));

  bebidas.push_back(Bebidas("Coca-Cola", 600, 8));
  bebidas.push_back(Bebidas("Sprite", 600, 8));
  bebidas.push_back(Bebidas("Água Crystal", 500, 5));
  bebidas.push_back(Bebidas("Chá Gelado", 450, 5));
  bebidas.push_back(Bebidas("Fanta Laranja", 600, 8));
  bebidas.push_back(Bebidas("Del Valle Uva", 600, 8));

  combos.push_back(Combos("The Magnum Opus", 75));
  combos.push_back(Combos("The Masterpièce", 73));
  combos.push_back(Combos("The Magnificent", 70));
  combos.push_back(Combos("The Marvelous", 69));
}

//Função para deixar o nome em maiúsculo
void Sistema::capsLock(std::string& str){
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

//Função para gerar 5 números aleatórios para o Id da compra "#"
void Sistema::gerarIdCompra(){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 9);// --> Intervalo
  for(int i=0; i<5; i++){
    int numeroAleatorio = dis(gen);
    std::cout << numeroAleatorio;
  }
}

//Função para impedir números como nome do cliente
std::string Sistema::semNumero(const std::string &input){
  std::string valido = input;
  bool contemNumero = false;

  for(char c : valido){
    if(std::isdigit(c)){
      contemNumero = true;
      break;
    }
  }
  while(contemNumero){
    std::cout << "\nInválido!\n";
    std::cout << "Digite apenas letras: ";
    std::cin >> valido;

    contemNumero = false;
    for(char c: valido){
      if(std::isdigit(c)){
        contemNumero = true;
        break;
      }
    }
  }
  return valido;
}

//Função para verificar o input do usuário
int Sistema::verificarInput(){
  std::cin >> verInput;
  while(std::cin.fail()){ // --> Serve pra impedir erros com letras
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "\nInválido!\n";
    std::cout << "Digite Novamente: ";
    std::cin >> verInput;
  }
  return verInput;
}

//Função do Login do Usuário
void Sistema::loginPedido(){
  clientes.clear();
  std::cout << "Seu Nome: ";
  std::getline(std::cin >> std::ws, nomeC);
  nomeC = semNumero(nomeC); // --> Chama a Função
  capsLock(nomeC); // --> Chama a Função

  std::cout << "\nSeu Telefone: ";
  std::getline(std::cin >> std::ws, telefone);
  telefone.erase(std::remove_if(telefone.begin(), telefone.end(), ::isspace), telefone.end());
  while(telefone.size() != 9){ // --> Serve para que o telefone tenha sempre 9 dígitos
    std::cerr << "\nNúmero de telefone inválido! Deve conter exatamente 9 dígitos!\n";
    std::getline(std::cin >> std::ws, telefone);
  }

  std::cout << "\nSeu Endereço: ";
  std::getline(std::cin >> std::ws, endereco);
  endereco = semNumero(endereco); // --> Chama a Função
  capsLock(endereco); // --> Chama a Função
  while(fretes.find(endereco) == fretes.end()){
    std::cout << "\nNão entregamos nesse endereço.\n";
    std::cout << "Digite outro Endereço: ";
    std::getline(std::cin >> std::ws, endereco);
    capsLock(endereco); // --> Chama a Função
  }
  Cliente novoCliente(nomeC, telefone, endereco);
  clientes.push_back(Cliente(novoCliente));// --> Encapsulamento
}

//Função do Entregador
void Sistema::loginEntregador(){
  modoEntrega = true;
  std::cout << "Usuário: ";
  std::getline(std::cin >> std::ws, nomeE);
  nomeE = semNumero(nomeE); // --> Chama a Função
  capsLock(nomeE); // --> Chama a Função

  std::cout << "Senha: ";
  idEntregador = verificarInput();
  while(idEntregador != 123456789){ // --> Senha
    std::cout << "\nSenha Inválida!\n";
    std::cout << "Digite Novamente: ";
    idEntregador = verificarInput(); // --> Chama a Função
  }
  Entregador novoEntregador(nomeE, idEntregador);
  entregadores.push_back(Entregador(novoEntregador));// --> Encapsulamento
}

//Função do Login Geral
void Sistema::loginGeral(){
  std::cout << "\nBem-Vindo!\n";
  std::cout << "1 --- Fazer Pedido.\n";
  std::cout << "2 -- Entregar Pedidos.\n";
  escolha2 = verificarInput(); // --> Chama a Função
  while(escolha2 <= 0 || escolha2 >= 3){
    std::cout << "\nInválido!\n";
    std::cout << "Digite Novamente: ";
    escolha2 = verificarInput(); // --> Chama a Função
  }
  if(escolha2 == 1){
    loginPedido();
  }else{
    loginEntregador();
  }
}

//Função para exibir as compras feitas
void Sistema::exibirEntrega(){
  if(modoEntrega == true){
    if(exibirProdutos.empty()){
      std::cout << "\nNão há pedidos para entrega!";
    }else{
      std::cout << "\nPedidos Disponíveis:\n";
      for(const auto& cliente : exibirProdutos){
        std::cout << "\nPedido #", gerarIdCompra(); // --> Chama a Função
        std::cout << "\nCliente: " << cliente.first.first;
        std::cout << "\nEndereço: " << cliente.first.second;
        std::cout << "\nTelefone: " << cliente.second.first;
        std::cout << "\nItens:\n";
        for(const std::string& item : cliente.second.second){
          std::cout << " - " << item << "\n";
        }
      }
    }
    std::exit(0);
  }
}

//Função para evitar repetição de código
void Sistema::comprarCombo(){
  if(escolhaC == 1){
    total += ((hamburguer[2].preco + bebidas[0].preco2 + acompanhamentos[3].preco3 + sobremesas[3].preco4) / 4) + 54;
    compras.push_back(hamburguer[2].nome);
    compras.push_back(bebidas[0].nome2);
    compras.push_back(acompanhamentos[3].nome3);
    compras.push_back(sobremesas[3].nome4);
  }else if(escolhaC == 2){
    total += ((hamburguer[1].preco + bebidas[1].preco2 + acompanhamentos[2].preco3 + sobremesas[4].preco4) / 4) + 54;
    compras.push_back(hamburguer[1].nome);
    compras.push_back(bebidas[1].nome2);
    compras.push_back(acompanhamentos[2].nome3);
    compras.push_back(sobremesas[4].nome4);
  }else if(escolhaC == 3){
    total += ((hamburguer[0].preco + bebidas[4].preco2 + acompanhamentos[0].preco3 + sobremesas[2].preco4) / 4) + 54;
    compras.push_back(hamburguer[0].nome);
    compras.push_back(bebidas[4].nome2);
    compras.push_back(acompanhamentos[0].nome3);
    compras.push_back(sobremesas[2].nome4);
  }
  else if(escolhaC == 4){
    total += ((hamburguer[3].preco + bebidas[5].preco2 + acompanhamentos[1].preco3 + sobremesas[1].preco4) / 4) + 54;
    compras.push_back(hamburguer[3].nome);
    compras.push_back(bebidas[5].nome2);
    compras.push_back(acompanhamentos[1].nome3);
    compras.push_back(sobremesas[1].nome4);
  }else{
    return;
  }
  maisItemCombo(); // --> Chama Função
}

//Função verificação da compra de mais um item 
void Sistema::maisItemCombo(){
  maisUmItem = true;
  while(maisUmItem == true){
    std::cout << "\nPedido Adicionado ao Carrinho!";
    std::cout << "\nEscolha seu Combo ou Aperte 0 para retornar: ";
    escolhaC = verificarInput(); // --> Chama a Função
    while(escolhaC < 0 || escolhaC >= 5){
      std::cout << "\nInvalido!\n";
      std::cout << "Digite Novamente: ";
      escolhaC = verificarInput(); // --> Chama a Função
    }if(escolhaC == 0){
      maisUmItem = false;
    }
    comprarCombo(); // --> Chama Função
  }
}

//Função para uma compra adicional
int Sistema::maisItem(){
  maisUmItem = true;
  while(maisUmItem == true){
    std::cout << "\nPedido Adicionado ao Carrinho!";
    std::cout << "\nEscolha seu Lanche ou Aperte 0 para retornar: ";
    adicional = verificarInput(); // --> Chama a Função
    while(adicional < 0 || adicional >= 7){ // --> Impedir erros de numeração dos itens
      std::cout << "\nInválido!";
      std::cout << "\nEscolha seu Lanche ou Aperte 0 para retornar: ";
      adicional = verificarInput(); // --> Chama a Função
    }if(adicional == 0){
      break; // --> Retornar ao Menu
    }
    adicional -= 1;
    if(isBurger == true){
      total += hamburguer[adicional].preco;
      compras.push_back(hamburguer[adicional].nome);
    }else if(isBebida == true){
      total += bebidas[adicional].preco2;
      compras.push_back(bebidas[adicional].nome2);
    }else if(isAcomp == true){
      total += acompanhamentos[adicional].preco3;
      compras.push_back(acompanhamentos[adicional].nome3);
    }else if(isSobre == true){
      total += sobremesas[adicional].preco4;
      compras.push_back(sobremesas[adicional].nome4);
    }
  }
  return adicional;
}

//Função do Cardápio
void Sistema::cardapio(){
  exibirEntrega();
  if(escolha2 == 1){
    programa = true;
    compras.clear();
    total = 0;
    while(programa == true){
      std::cout << "\nBem Vindo ao Mr.Magnus's Burgers!\n";
      std::cout << "\n1 --- Lanches.\n";
      std::cout << "2 --- Bebidas.\n";
      std::cout << "3 --- Acompanhamentos.\n";
      std::cout << "4 --- Sobremesas.\n";
      std::cout << "5 --- Combos.\n";
      std::cout << "\n6 --- Cancelar.\n";
      std::cout << "7 --- Finalizar.\n";
      std::cout << "8 --- Limpar Carrinho.\n";
      std::cout << "\nCarrinho: ";
      if(compras.empty()){
        std::cout << "vazio";
      }else{
        for(std::string v : compras){
          std::cout << v << ", ";
        }
      }
      std::cout << "     Total: R$" << total << "\n";
      escolha = verificarInput(); // --> Chama a Função

      switch(escolha){
        case 1:{
          isBurger = true;
          std::cout << "------LANCHES------\n";
          for(size_t i=0; i< hamburguer.size(); i++){
            std::cout << "\n" << (i+1) << "." << hamburguer[i].nome << "\n";
            std::cout << hamburguer[i].calorias << " kcal  R$" << hamburguer[i].preco << "\n";
            std::cout << hamburguer[i].descricao << "\n";
          }
          std::cout << "\nEscolha seu Lanche ou Aperte 0 para retornar: ";
          escolha = verificarInput();
          while(escolha < 0 || escolha >= 7){ // --> Impedir erros de numeração dos itens
            std::cout << "\nInválido!";
            std::cout << "\nDigite Novamente: ";
            escolha = verificarInput(); // --> Chama a Função
          }if(escolha == 0){
            break; // --> Retornar ao Menu
          }
          escolha -= 1;
          total += hamburguer[escolha].preco;
          compras.push_back(hamburguer[escolha].nome);
          escolha = maisItem();
          isBurger = false;
          break;
        }
        case 2:{
          isBebida = true;
          std::cout << "------BEBIDAS------\n";
          for(size_t i=0; i<bebidas.size(); i++){
            std::cout << "\n" << (i+1) << "." << bebidas[i].nome2 << "\n";
            std::cout << bebidas[i].ml << " ml  R$" << bebidas[i].preco2 << "\n";
          }
          std::cout << "\nEscolha sua Bebida ou Aperte 0 para retornar: ";
          escolha = verificarInput();
          while(escolha < 0 || escolha >= 7){ // --> Impedir erros de numeração dos itens
            std::cout << "\nInválido!";
            std::cout << "\nDigite Novamente: ";
            escolha = verificarInput(); // --> Chama a Função
          }if(escolha == 0){
            break; // --> Retornar ao Menu
          }
          escolha -= 1;
          total += bebidas[escolha].preco2;
          compras.push_back(bebidas[escolha].nome2);
          escolha = maisItem();
          isBebida = false;
          break;
        }
        case 3:{
          isAcomp = true;
          std::cout << "------ACOMPANHAMENTOS------\n";
          for(size_t i=0; i< acompanhamentos.size(); i++){
            std::cout << "\n" << (i+1) << "." << acompanhamentos[i].nome3 << "\n";
            std::cout << acompanhamentos[i].porcao << "g  R$" << acompanhamentos[i].preco3 << "\n";
            std::cout << acompanhamentos[i].descricao2 << "\n";
          }
          std::cout << "\nEscolha seu Acompanhamento ou Aperte 0 para retornar: ";
          escolha = verificarInput();
          while(escolha < 0 || escolha >= 6){ // --> Impedir erros de numeração dos itens
            std::cout << "\nInválido!";
            std::cout << "\nDigite Novamente: ";
            escolha = verificarInput(); // --> Chama a Função
          }if(escolha == 0){
            break; // --> Retornar ao Menu
          }
          escolha -= 1;
          total += acompanhamentos[escolha].preco3;
          compras.push_back(acompanhamentos[escolha].nome3);
          escolha = maisItem();
          isAcomp = false;
          break;
        }
        case 4:{
          isSobre = true;
          std::cout << "------SOBREMESAS------\n";
          for(size_t i=0; i<sobremesas.size(); i++){
            std::cout << "\n" << (i+1) << "." << sobremesas[i].nome4 << "\n";
            std::cout << sobremesas[i].calorias3 << " kcal  R$" << sobremesas[i].preco4 << "\n";
            std::cout << sobremesas[i].descricao3 << "\n";
          }
          std::cout << "\nEscolha sua Sobremesa ou Aperte 0 apra retornar: ";
          escolha = verificarInput();
          while(escolha < 0 || escolha >= 6){ // --> Impedir erros de numeração dos itens
          std::cout << "\nInválido!";
          std::cout << "\nDigite Novamente: ";
            escolha = verificarInput(); // --> Chama a Função
          }if(escolha == 0){
            break; // --> Retornar ao Menu
          }
          escolha -= 1;
          total += sobremesas[escolha].preco4;
          compras.push_back(sobremesas[escolha].nome4);
          escolha = maisItem();
          isSobre = false;
          break;
        }
        case 5:{
          std::cout << "------COMBOS------\n";
          for(size_t i=0; i<combos.size(); i++){
            std::cout << "\n" << (i+1) << "." << combos[i].nome5 << "  R$" << combos[i].preco5 << "\n";
          }
          std::cout << "\nEscolha seu Combo ou Aperte 0 para retornar: ";
          escolhaC = verificarInput(); // --> Chama a Função
          while( escolha < 0 || escolhaC >= 5){ // --> Impedir erros de numeração dos itens
            std::cout << "\nInválido!";
            std::cout << "\nDigite Novamente: ";
            escolhaC = verificarInput(); // --> Chama a Função
          }if(escolhaC == 0){
            break; // --> Retornar ao Menu
          }
          comprarCombo(); // --> Chama Função
          break;
        }
        case 6:{
          std::cout << "Volte Sempre!";
          std::exit(0);
          break;
        }
        case 7:{
          caixaAberto = true;
          caixa(); // --> Chama a Função
          if(escolha == 0){
            break;
          }
          programa = false;
          break;
        }
        case 8:{
          if(compras.empty() || total == 0){
            std::cout << "\nNão há itens no seu carrinho!\n";
            break;
          }else{
            compras.clear(); // --> limpa o carrinho
            total = 0;
            std::cout << "\nCarrinho Esvaziado!\n";
            break;
          }
        }
        default:{
          std::cout << "\nInválido!";
          break;
        }
      }
    }
  }
}

//Função que calcula o Frete
void Sistema::calcularFrete(){
  total += fretes[endereco];
}

//Serve para verificar a confirmacao e evitar erros
void Sistema::confirmarPagamento(){
  if(confirmacao == "s"){
    std::cout << "\nPagamento Confirmado!";
    std::cout << "\nObrigado e Volte Sempre!\n";
    caixaAberto = false;
  }else if(confirmacao == "n"){
    return;
  }else{
    std::cout << "\nInválido!\n";
    std::cout << "Confirma o Pagamento? (s/n): ";
    std::cin >> confirmacao;
    confirmarPagamento(); // --> Chama Função
  }
}

//Construtor do Caixa
void Sistema::caixa(){
  while(caixaAberto){
    if(compras.empty()){
      std::cout << "\nNão há itens no seu carrinho!";
      std::cout << "\nDigite 0 para Retornar ao Menu ou 1 para Sair:";
      escolha = verificarInput();
      if(escolha == 1){
        std::cout << "\nObrigado e Volte Sempre!\n";
        return;
      }else{
        break;
      }
    }else{
      exibirProdutos.insert(std::make_pair(std::make_pair(nomeC, endereco), std::make_pair(telefone, compras)));    
      for(const auto& cliente: clientes){
        std::cout << "\n" <<  cliente.getNome() << ", você está comprando: ";
        if(compras.empty()){
          std::cout << "Nada!\n";
          return;
        }else{
          for(std::string v : compras){
            std::cout << v << ", ";
          }
        }
      }
      calcularFrete();
      for(const auto& cliente : clientes){
        std::cout << "\nSeu endereço é: " << cliente.getEndereco() << ". o Valor da Entrega é de: R$" << fretes[endereco];
      }
      std::cout << "\nSeu total é de: R$" << total << "\n";
      if(total == 0){
        std::cout << "Volte sempre!";
        caixaAberto = false;
      }else{
        std::cout << "Escolha sua forma de pagamento:\n";
        std::cout << "1 --- Débito.\n";
        std::cout << "2 --- Crédito.\n";
        std::cout << "3 --- Pix.\n";
        std::cout << "\n0 --- Retornar ao Cardápio.\n";
        escolhaPagamento = verificarInput(); // --> Chama a Função
        while(escolhaPagamento < 0 || escolhaPagamento >= 4){
          std::cout << "\nInválido!\n";
          std::cout << "Digite Novamente: ";
          escolha = verificarInput(); // --> Chama a Função
        }
        if(escolhaPagamento == 0){
          break;
        }

        switch(escolhaPagamento){
          case 1:{
            std::cout << "\nSeu total é de: R$" << total << "\n";
            std::cout << "Confirma o Pagamento? (s/n): ";
            std::cin >> confirmacao;
            confirmarPagamento(); // --> Chama Função
            break;
          }
          case 2:{
            std::cout << "\nSeu total é de: R$" << total << "\n";
            std::cout << "Confirma o Pagamento? (s/n): ";
            std::cin >> confirmacao;
            confirmarPagamento(); // --> Chama Função
            break;
          }
          case 3:{
            std::cout << "\nSeu total é de: R$" << total << "\n";
            std::cout << "Confirma o Pagamento? (s/n): ";
            std::cin >> confirmacao;
            confirmarPagamento(); // --> Chama Função
            break;
          }
          default:{
            std::cout << "\nInválido\n";
            break;
          }
        }
      }
    }
  }
}