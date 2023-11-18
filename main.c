#include "ContaBancaria.h"

int main()
{
    inicializar();

    int op = OP_NAO_SELECIONADA;
    int num;
    double valor;

    while (op != OP_SAIR)
    {
        op = menu();

        switch (op)
        {
        case OP_INSERIR:
            if(isFull())
            {
                printf("Realocando memoria");
                expandir();
            }
            inserir(contas);
            break;
        case OP_ALTERAR:
            printf("Digite o número da conta: ");
            scanf("%d", &num);
            Conta *encontrado = buscar(contas, contadorClientes, num);

            if (!encontrado)
            {
                printf("Cliente não encontrado");
                break;
            }
            alterar(encontrado, num);
            break;
        case OP_LISTAR:
            listar(contas, contadorClientes);
            break;
        case OP_DEPOSITAR:
            printf("Digite o numero da conta: ");
            scanf("%d", &num);
            printf("Digite o valor a ser depositado: ");
            scanf("%lf", &valor);
            depositar(contas, contadorClientes, num, valor);
            break;
        case OP_SACAR:
            printf("Digite o numero da conta: ");
            scanf("%d", &num);
            printf("Digite o valor a ser sacado: ");
            scanf("%lf", &valor);
            sacar(contas, contadorClientes, num, valor);
            break;
        case OP_IMPRIMIR:
            printf("Digite o numero da conta: ");
            scanf("%d", &num);
            imprimir(contas, contadorClientes, num);
            break;
        case OP_SALDOGERAL:
            printf("Saldo acumulado: %.4lf\n", saldoGeral(contas, contadorClientes));
            break;
        case OP_SAIR:
            break;
        default:
            printf("Digite uma das opcoes no menu\n");
        }
    }

    finalizar();

    return 0;
}