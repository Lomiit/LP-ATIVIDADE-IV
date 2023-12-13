#include <stdio.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

float calcularValorTotal(struct Produto produto) {
    return produto.preco * produto.quantidade;
}

void realizarCompra(struct Produto* produto, int quantidade) {
    if (produto->quantidade >= quantidade) {
        produto->quantidade -= quantidade;
        printf("Compra realizada com sucesso!\n");
    } else {
        printf("Quantidade insuficiente em estoque!\n");
    }
}

int main() {
    struct Produto produto;
    int opcao, quantidade;

    // Preencha os detalhes do produto aqui

    do {
        printf("\n1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &quantidade);
                realizarCompra(&produto, quantidade);
                break;
            case 2:
                printf("Valor total em estoque: %.2f\n", calcularValorTotal(produto));
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
