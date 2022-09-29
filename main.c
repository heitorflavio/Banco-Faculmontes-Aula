#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 15

int cad = -1;

typedef struct Banco
{
    int nconta;
    char cliente[40], tconta;
    float saldo;
}TBanco;
TBanco B[MAX];

int LocalizaConta(int NumConta)
{
    for(int i=0; i<=cad; i++)
    {
        if (B[i].nconta == NumConta)
            return(i); // Retorna a posi��o que tem a conta
    }
    return(-1);// N�o achou
}

void addCliente ()
{
    int cod, achou=0;
    do
    {
        achou=0;
        system("cls");
        printf("------------- Inclus�o de Clientes -------------\n");
        printf("Informe o n�mero da Conta...: ");
        scanf("%d", &cod);
        for(int i=0; i<=cad; i++)
        {
            if (B[i].nconta == cod)
                achou = 1;
        }
        if (achou)
        {
            printf("Conta j� existe!!");
            fflush(stdin);
            getchar();
        }
        else
        {
            // Cadastrar conta
            cad++;
            printf("\nInforme Tipo da Conta (P/C)...: ");
            fflush(stdin);
            B[cad].tconta = getchar();
            printf("\nInforme Nome do Cliente...: ");
            fflush(stdin);
            gets(B[cad].cliente);
            B[cad].nconta = cod;
            B[cad].saldo = 0.0;
            achou=2;
        }
    }while(achou!=2);
}
int main()
{
    //TBanco B[MAX];
    int op, i, x, z, NConta;
    float VlrDep=0;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("\n\tBanco Faculmontes\n\n");
        printf("1. Cadastro Conta\n");
        printf("2. Fazer Dep�sito\n");
        printf("3. Fazer transfer�ncia\n");
        printf("4. Listar todas as contas\n");
        printf("5. Excluir a conta\n");
        printf("0. Sair\n");

        scanf("%d", &op);
        system("cls || clear");

        switch(op)
        {
            case 1:
                printf("Cadastro de Conta\n");
                addCliente();
                break;

            case 2:
                printf("Dep�sito\n");
                printf("Informe a conta...: \n");
                scanf("%i", &NConta);
                x = LocalizaConta(NConta);
                if (x>-1)
                {
                    printf("Informe o valor do dep�sito..:\n");
                    scanf("%f", &VlrDep);
                    B[x].saldo = B[x].saldo + VlrDep;
                    printf("\nSaldo Final R$%.2f\n", B[x].saldo);
                }
                else
                {
                    printf("\n Conta não localizada!!\n\n");
                }
                break;

            case 3:
                printf("Transfer�ncia\n");
                printf("Informe a Conta Origem...: \n");
                scanf("%i", &NConta);
                x = LocalizaConta(NConta); // Conta Origem
                if (x>-1)
                {
                    printf("Informe a Conta Destino...: \n");
                    scanf("%i", &NConta);
                    z = LocalizaConta(NConta); // Conta destino
                    if (z>-1)
                    {
                        printf("\nSaldo Origem( Dono: %s ): R$%.2f\t\tSaldo Destino ( Dono: %s ): R$%.2f\n", B[x].cliente, B[x].saldo, B[z].cliente ,B[z].saldo);
                        printf("Informe o valor a ser transferido..:\n");
                        scanf("%f", &VlrDep);
                        if (B[x].saldo>= VlrDep)
                        {
                            B[x].saldo = B[x].saldo - VlrDep;
                            B[z].saldo = B[z].saldo + VlrDep;
                            printf("\nSaldo Origem( Dono: %s ): R$%.2f\t\tSaldo Destino ( Dono: %s ): R$%.2f\n", B[x].cliente, B[x].saldo, B[z].cliente ,B[z].saldo);
                        }
                        else
                        {
                            printf("\nConta Origem não possui saldo suficiente!!\n\n");
                        }

                    }
                    else
                    {
                        printf("\nConta Destino n�o EXISTE!!\n\n");
                    }

                }
                else
                {
                    printf("\nConta Origem não EXISTE!!\n\n");
                }
                break;

            case 4:
                printf("Listar Contas\n");
                printf("\nTP Nome---------------- Numero- Saldo---------");
                for (i=0; i<=cad; i++)
                {
                    printf("\n%c  %20s %6d  %15.2f", B[i].tconta, B[i].cliente, B[i].nconta, B[i].saldo);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;

            case 5:
                printf("Informe a conta...: \n");
                scanf("%i", &NConta);
                x = LocalizaConta(NConta);
                if (x>-1)
                {
                    for (i=x; i<=cad; i++)
                    {
                        B[i] = B[i+1];
                    }
                    cad--;
                    printf("\nConta excluida com sucesso!!\n\n");
                }
                else
                {
                    printf("\n Conta não localizada!!\n\n");
                }
                break;

            case 0:
                printf("Bye.. Bye\n");
                break;

            default:
                printf("Digite uma opção valida\n");
        }
    } while(op);
    printf("\n");
    system("pause");
    return 0;

}