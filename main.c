#include <stdio.h>
//O objetivo da atividade é aplicar conhecimentos adquiridos em sala de aula em um enunciado mais elaborado e inserido no contexto mercadológico
//Sabrina Helena Ferreira - 1433925
//Ultima atualizacao: 11/12/2022

// No estoque, 1 = Mascara lisa infantil - 2 = Mascara estampada infantil - 3 = Mascara adulta lisa - 4 = Mascara adulta estampada


// Com essa declaração, fica globalmente disponível.
int quantidadeMascaraLI = 0, quantidadeMascaraEI = 0, quantidadeMascaraLA = 0, quantidadeMascaraEA = 0; // A = adulto -  I = infantil - // E = estampada - L = lisa
int estoque[4][4], lucro[4][2];
//MLI = Mascara lisa infantil - MEI = Mascara estampada infantil - MEA = Mascara estampada adulta - MLA = mascara lisa adulta
int quantidadeVendas = 0, lucroMLI, lucroMEI, lucroMLA, lucroMEA, quantVendasMLI = 0, quantVendasMEI = 0, quantVendasMLA = 0, quantVendasMEA = 0;

void MenuPrincipal() { //Metodo de menu principal
  int opcao, opcaoTamanhoMascara, opcaoEstampaMascara, quantidade, x = 0;
  while (x == 0) {
    printf("\nOla! Oque deseja fazer? \n1 - Gerenciar estoque \n2 - Relatorio "
           "de mascaras em estoque \n3 - Comprar \n4 - Relatorio "
           "de vendas \n5 - Relatorio de lucros \n6 - Sair do loop \nOPCAO: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
      printf("\nVoce deseja adicionar uma mascara: \n1 - Tamanho infantil \n2 "
             "- Tamanho adulto \nOPCAO: ");
      scanf("%d", &opcaoTamanhoMascara);
      printf(
          "\nQual a estampa da mascara? \n1 - Lisa \n2 - Estampada \nOPCAO: ");
      scanf("%d", &opcaoEstampaMascara);
      printf("\nQual a quantidade que deseja adicionar no estoque ? ");
      scanf("%d", &quantidade);
      //Verificacao do tamanho e estampa da mascara escolhidos pelo usuario para alterar a quantidade no estoque.
      if (opcaoTamanhoMascara == 1 && opcaoEstampaMascara == 1)
        quantidadeMascaraLI += quantidade;
      else if (opcaoTamanhoMascara == 1 && opcaoEstampaMascara == 2)
        quantidadeMascaraEI += quantidade;
      else if (opcaoTamanhoMascara == 2 && opcaoEstampaMascara == 1)
        quantidadeMascaraLA += quantidade;
      else if (opcaoTamanhoMascara == 2 && opcaoEstampaMascara == 2)
        quantidadeMascaraEA += quantidade;
    } else if (opcao == 2) {

    //Organizacao da matriz de estoque
    //Primeira coluna: mascaras diferentes separadas de 1 a 4.
    //Segunda coluna: quantidades de cada mascara no estoque
    //Terceira coluna: Custos de producao
    //Quarta coluna: valores de venda
      estoque[0][0] = 1; // Mascara lisa infantil
      estoque[1][0] = 2; // Mascara estampada infantil
      estoque[2][0] = 3; // Mascara adulta lisa
      estoque[3][0] = 4; // Mascara adulta estampada
      estoque[0][1] = quantidadeMascaraLI;
      estoque[1][1] = quantidadeMascaraEI;
      estoque[2][1] = quantidadeMascaraLA;
      estoque[3][1] = quantidadeMascaraEA;
      estoque[0][2] = 1; // Custos de producao
      estoque[1][2] = 2;
      estoque[2][2] = 2;
      estoque[3][2] = 3;
      estoque[0][3] = 2; // Valores de venda
      estoque[1][3] = 3;
      estoque[2][3] = 3;
      estoque[3][3] = 4;

      printf("\nMascara - Quantidade - Valor Prod. - Valor venda \n");
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          printf("   %d", estoque[i][j]);
        }
        printf("\n");
      }
    }
    //Condicao de compra
    //Retira da quantidade no estoque a quantidade inserida pelo usuario para compra
    //Calcula o lucro subtraindo a quantidade multiplicado pelo valor de producao pela quantidade multiplicado pelo preco de venda
    //Coloca na segunda coluna da matriz de lucro esse valor, e incrementa 1 para a quantidade de vendas do produto em questao.
    else if (opcao == 3) {
      printf("\nVoce deseja comprar uma mascara: \n1 - Tamanho infantil \n2 - "
             "Tamanho adulto \nOPCAO: ");
      scanf("%d", &opcaoTamanhoMascara);
      printf(
          "\nQual a estampa da mascara? \n1 - Lisa \n2 - Estampada \nOPCAO: ");
      scanf("%d", &opcaoEstampaMascara);
      printf("\nQual a quantidade que deseja comprar? ");
      scanf("%d", &quantidade);
      if (opcaoTamanhoMascara == 1 && opcaoEstampaMascara == 1) {
        quantidadeMascaraLI = quantidadeMascaraLI - quantidade;
        lucroMLI = (quantidade * estoque[0][3]) - (quantidade * estoque[0][2]);
        lucro[0][1] = lucroMLI;
        quantVendasMLI++;
      } else if (opcaoTamanhoMascara == 1 && opcaoEstampaMascara == 2) {
        quantidadeMascaraEI = quantidadeMascaraEI - quantidade;
        lucroMEI = (quantidade * estoque[1][3]) - (quantidade * estoque[1][2]);
        lucro[1][1] = lucroMEI;
        quantVendasMEI++;
      } else if (opcaoTamanhoMascara == 2 && opcaoEstampaMascara == 1) {
        quantidadeMascaraLA = quantidadeMascaraLA - quantidade;
        lucroMLA = (quantidade * estoque[2][3]) - (quantidade * estoque[2][2]);
        lucro[2][1] = lucroMLA;
        quantVendasMLA++;
      } else if (opcaoTamanhoMascara == 2 && opcaoEstampaMascara == 2) {
        quantidadeMascaraEA = quantidadeMascaraEA - quantidade;
        lucroMEA = (quantidade * estoque[3][3]) - (quantidade * estoque[3][2]);
        lucro[3][1] = lucroMEA;
        quantVendasMEA++;
      }
      quantidadeVendas++;
    }
    //Apenas impressao das vendas totais e das vendas de cada produto.
     else if (opcao == 4) {
      printf("\nA quantidade de vendas totais ate agora foi: %d \nA quantidade "
             "de vendas e mascaras infantis lisas e': %d \nA quantidade de "
             "vendas de mascaras infantis estampadas e': %d \nA quantidade de "
             "vendas de mascaras adultas lisas e': %d \nA quantidade de "
             "mascaras estampadas adultas e': %d",
             quantidadeVendas, quantVendasMLI, quantVendasMEI, quantVendasMLA,
             quantVendasMEA);

    }
    //Impressao dos lucros de cada produto.
     else if (opcao == 5) {
      lucro[0][0] = 1; // Mascara lisa infantil
      lucro[1][0] = 2; // Mascara estampada infantil
      lucro[2][0] = 3; // Mascara adulta lisa
      lucro[3][0] = 4; // Mascara adulta estampada
      printf("\nMascara - Lucro atual \n");
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
          printf("   %d", lucro[i][j]);
        }
        printf("\n");
      }
    }
    //Flag
    else if(opcao == 6){
        x = 1;
    }
  }
}

int main(void) {
  MenuPrincipal();
  return 0;
}
