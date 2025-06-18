#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define uma variável constante, com o número máximo de clientes que podem ser armazenado no array
#define MAX_CLIENTES 50

// Estrutura para armazenar os dados do cliente
typedef struct
{
    char nome[100];
    char email[100];
    char endereco[100];
    int idade;
} Cliente;

// Array global para armazenar os clientes e contador
Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

// Protótipos das funções
void exibirMenu();
void adicionarCliente();
void listarClientes();

int main()
{
    int opcao;

    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao)
        {
        case 1:
            adicionarCliente();
            break;
        case 2:
            listarClientes();
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
        if(opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }

    } while (opcao != 0);

    return 0;
}

void exibirMenu()
{
    system("clear || cls"); 
    printf("==================================\n");
    printf("      SISTEMA DE CADASTRO\n");
    printf("==================================\n");
    printf("1 - Adicionar Cliente\n");
    printf("2 - Listar Clientes\n");
    printf("0 - Sair\n");
    printf("==================================\n");
    printf("Escolha uma opcao: ");
}

void adicionarCliente()
{
    if (totalClientes >= MAX_CLIENTES)
    {
        printf("Limite de clientes atingido! Não é possível adicionar mais.\n");
        return;
    }

    Cliente novoCliente;

    printf("Digite o nome: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    novoCliente.nome[strcspn(novoCliente.nome, "\n")] = 0; 

    printf("Digite o email: ");
    fgets(novoCliente.email, sizeof(novoCliente.email), stdin);
    novoCliente.email[strcspn(novoCliente.email, "\n")] = 0;

    printf("Digite o endereco: ");
    fgets(novoCliente.endereco, sizeof(novoCliente.endereco), stdin);
    novoCliente.endereco[strcspn(novoCliente.endereco, "\n")] = 0;

    printf("Digite a idade: ");
    scanf("%d", &novoCliente.idade);
    getchar(); // Limpa o '\n' do buffer após o scanf

    clientes[totalClientes] = novoCliente;
    totalClientes++;

    printf("Cliente adicionado com sucesso!\n");
}

void listarClientes()
{
    if (totalClientes == 0)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++)
    {
        printf("-------------------------------\n");
        printf("Nome: %s\n", clientes[i].nome);
        printf("Email: %s\n", clientes[i].email);
        printf("Endereco: %s\n", clientes[i].endereco);
        printf("Idade: %d\n", clientes[i].idade);
        printf("-------------------------------\n");
    }
}
