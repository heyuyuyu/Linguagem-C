#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>


struct Lab {
  char medicamento[30];
  char laboratorio[30];
  int dataValidade;
  float precoCusto;
  char principioAtivo[30];
  int quantEstoque;
  char unidade[30];
};


int i, med;
struct Lab a[50];


void ListaMed() {
  for (i = 0; i < med; i++) {
    printf("\nListando medicamentos...\n");
    printf("\n\nMedicamento: %s", a[i].medicamento);
    printf("\n\nLaboratorio: %s", a[i].laboratorio);
    printf("\n\nData validade: %d", a[i].dataValidade);
    printf("\n\nPrincipio ativo: %s", a[i].principioAtivo);
    printf("\n\nQuantidade estoque: %d", a[i].quantEstoque);
    printf("\n\nPreco custo: %.2f", a[i].precoCusto);
    printf("\n\nUnidade: %s", a[i].unidade);
  }
}


void ListaMedLab(char laboratorioBuscado[30]) {
  printf("\nEscolha um dos laboratorios que ja foram citados: ");
  scanf("%s", laboratorioBuscado);

  printf("\nMedicamentos do Laboratorio %s:\n", laboratorioBuscado);
  for (i = 0; i < med; i++) {
    if (strcmp(a[i].laboratorio, laboratorioBuscado) == 0) {
      printf("Medicamento: %s\n", a[i].medicamento);
    }
  }
}


void CalcularQtd() {
  for (i = 0; i < med; i++) {
    if (a[i].quantEstoque < a[i].quantEstoque) {
      printf("\n\nMedicamento: %s", a[i].medicamento);
    }
  }
}


void MostrarMedi() {
  time_t agora;
  time(&agora);

  for (i = 0; i < med; i++) {
    int diasRestantes = (a[i].dataValidade - agora) / (60 * 60 * 24); //60=segundos 60=minutos 24=horas

    if (diasRestantes <= 30) {
      printf("\n\nMedicamento vencido ou vencendo em breve: %s", a[i].medicamento);
    }
  }
}

void Valorpago() {
  setlocale(LC_ALL, "Portuguese");
  float precoCustoTotal = 0.0;
  for (i = 0; i < med; i++) {
    precoCustoTotal += a[i].precoCusto;
  }
  printf("O valor total: %.2f\n", precoCustoTotal);
}

int main(void) {
  int op;

  printf("Gostaria de listar quantos medicamentos? ");
  scanf("%d", &med);
  
  printf("Listando medicamentos...\n");

  for (i = 0; i < med; i++) {
    printf("\nInsira o nome do medicamento: ");
    scanf("%s", a[i].medicamento);
    printf("Insira o laboratorio: ");
    scanf("%s", a[i].laboratorio);
    printf("Insira a data de validade: ");
    scanf("%d", &a[i].dataValidade);
    printf("Insira o Preco: ");
    scanf("%f", &a[i].precoCusto);
    printf("Principio ativo: ");
    scanf("%s", a[i].principioAtivo);
    printf("Insira a quantidade de estoque: ");
    scanf("%d", &a[i].quantEstoque);
    printf("Insira a unidade: ");
    scanf("%s", a[i].unidade);
  }

  do {
    printf("\nMenu\n");
    printf("\n1. Listar todos medicamentos e seus dados.");
    printf("\n2. Listar todos medicamentos de um laboratorio.");
    printf("\n3. Calcular e mostrar a quantidade de medicamentos com quantidade menor a informada pelo usuario.");
    printf("\n4. Mostrar os medicamentos cuja validade e de ate 30 dias a partir de uma data informada pelo usuario.");
    printf("\n5. Calcular o valor total pago pelos medicamentos.");
    printf("\n6. Sair");
    printf("\n\nInsira sua opcao desejada: ");
    scanf("%d", &op);
    if (op == 1) {
      printf("\n\nEscolheu a opcao 1!\n");
      ListaMed();
    } else if (op == 2) {
      char laboratorioBuscado[30];
      ListaMedLab(laboratorioBuscado);
    } else if (op == 3) {
      CalcularQtd();
    } else if (op == 4) {
      MostrarMedi();
    } else if (op == 5) {
      Valorpago();
    } else if (op == 6) {
      printf("Obrigado por usar o programa!\n");
    }

  } while (op != 6);

  return 0;
}





