#include <stdio.h>

struct ContaBancaria {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[10];
};

void depositar(struct ContaBancaria* conta, float valor) {
    conta->saldo += valor;
    printf("Depósito realizado com sucesso!\n");
}

void sacar(struct ContaBancaria* conta, float valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso!\n");
    } else {
        printf("Saldo insuficiente!\n");
    }
}

void imprimirSaldo(struct ContaBancaria conta) {
    printf("Saldo atual: %.2f\n", conta.saldo);
}

int main() {
    struct ContaBancaria conta;
    int opcao;
    float valor;


    do {
        printf("\n1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Consultar saldo\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor que deseja depositar: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Digite o valor que deseja sacar: ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
            case 3:
                imprimirSaldo(conta);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}

