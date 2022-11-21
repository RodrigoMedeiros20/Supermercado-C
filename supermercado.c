#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct itens {
	int quantidade;
	float valor;
	char nome[50];
};

int main() {
	
	setlocale(LC_ALL, "");
	
	//declaração de variáveis
	int i, j, k, l;
	int qtd_carrinho = 0, qtd_caixa = 0;
	float soma = 0;
	char recebe_arquivo[15];
	char *separa;
	struct itens carrinho[10];
	struct itens caixa[10];
	
	//ENTRADA - Menu do Código
	while(1) {
		printf("-----------------------------------------\n");
		printf("1 - Inserir apenas um item\n");
		printf("2 - Processar apenas um item\n");
		printf("3 - Processar todos os itens\n");
		printf("4 - Mostrar itens do carrinho\n");
		printf("5 - Imprimir nota fiscal\n");
		printf("6 - Sair\n");
		scanf("%d", &i);
		
	//PROCESSAMENTO
		switch(i) {
			
			//Insere apenas um item
			case 1:
				printf("-----------------------------------------\n");
				if (qtd_carrinho < 10) {
					printf("Nome do produto: ");
					scanf("%s", carrinho[qtd_carrinho].nome);
					
					printf("Quantidade do produto: ");
					scanf("%d", &carrinho[qtd_carrinho].quantidade);
					
					printf("Valor individual do produto: ");
					scanf("%f", &carrinho[qtd_carrinho].valor);
					
					printf("-----------------------------------------\n");
					printf("Quantidade: %dx\nProduto: %s\nValor R$%.2f\n", carrinho[qtd_carrinho].quantidade, carrinho[qtd_carrinho].nome, carrinho[qtd_carrinho].valor);
					
					qtd_carrinho += 1;
					
				}else {
					printf("Não há mais espaço no carrinho!\n");
				}
				break;
				
			//Processa apenas um item
			case 2:
				printf("-----------------------------------------\n");
				if (qtd_carrinho > 0) {
					if (qtd_caixa < 10) {
						caixa[qtd_caixa] = carrinho[qtd_carrinho - 1];
						
						printf("%dx %s: %.2f\n", caixa[qtd_caixa].quantidade, caixa[qtd_caixa].nome, (float)caixa[qtd_caixa].quantidade * caixa[qtd_caixa].valor);
						
						qtd_carrinho -= 1;
						qtd_caixa += 1;
						
					}else {
						printf("Caixa cheio!\n");
					}
				}else {
					printf("Sem itens no carrinho!\n");
				}
				break;
				
			//Processa todos os itens do carrinho
			case 3:
				printf("-----------------------------------------\n");
				if (qtd_carrinho == 0) {
					printf("Carrinho vazio!\n");
				}
				
				for (j = qtd_carrinho - 1; qtd_caixa < 10 && qtd_carrinho > 0; j--) {
				caixa[qtd_caixa] = carrinho[qtd_carrinho - 1];
				
				printf("%dx %s: %.2f\n", caixa[qtd_caixa].quantidade, caixa[qtd_caixa].nome, (float)caixa[qtd_caixa].quantidade * caixa[qtd_caixa].valor);
						
				qtd_carrinho -= 1;
				qtd_caixa += 1;
				}
				break;
			
			//Mostrar itens do carrinho
			case 4:
				printf("-----------------------------------------\n");
				if (qtd_carrinho != 0) {
					for (k = qtd_carrinho - 1; k >= 0; k--) {
						printf("%dx\t%s\t\t\t\t\tR$ %.2f\t\n", carrinho[k].quantidade, carrinho[k].nome, carrinho[k].valor);
						
					}
				}else {
					printf("Carrinho vazio!\n");
				}
				break;
			
			//Imprimir a nota fiscal
			case 5:
				printf("-----------------------------------------\n");
				printf("Itens comprados: \n");
				printf("Quantidade		Descrição		Valor final		\n");
				printf("************************************************************\n");
				
				if (qtd_caixa != 0) {
					for (l = 0; l < qtd_caixa; l++) {
						printf("%dx\t%s\t\t\t\t\tR$ %.2f\t\n", caixa[l].quantidade, caixa[l].nome, caixa[l].valor);
						
						soma += caixa[l].quantidade * caixa[l].valor;
					}
					printf("************************************************************\n");
					printf("Total:\t\t\t\t\t\tR$ %.2f\n", soma);
				}else {
					printf("Caixa vazio!");
				}
				break;
				
			//Sair do programa
			case 6:
				return 0;
		}
	}
}