/**********************************************************
*****
*
* Curso: Ciência da Computação
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: gcc (tdm-1) 4.9.2
* IDE : Vscode
* Sistema Operacional: Windows 11 e Windows 10
***********************************************************
****/

typedef struct {
  char nome[8];
  int matricula;
  float nota1, nota2, nota3;
} Aluno;

typedef struct No {
  Aluno dados_no;
  struct No *prox;
} No;

typedef struct {
  No *cabeca;
}Lista;

/*
a) Inserir aluno;
b) Remover aluno
c) Alterar cadastro do aluno
d) Excluir a lista
e) Buscar dados de um aluno, fornecendo o dado de matrícula
f) Exibir todos os dados de todos os alunos
g) Encontrar o aluno com maior nota da primeira prova
h) Encontrar aluno com maior média geral
i) Encontrar aluno com menor média geral
j) Listar os alunos aprovados e reprovados, considerando o valor 6 para aprovação
k) Verificar se a lista está ordenada ou não (a ordem pode ser crescente ou decrescente);
l) Fazer uma cópia da lista L1 em uma outra lista L2;
m) Inverter uma lista L1 colocando o resultado em L2;
n) Intercalar duas listas, L1 e L2, gerando uma lista L3. Considere que L1, L2 e L3 estão 
ordenadas.
*/

Aluno criar_novo_aluno();
int inserir_aluno(Lista *alunos, Aluno novo_aluno);
int remover_aluno(Lista *alunos, int matricula);
void alterar_cadastro(Lista *alunos, int matricula);
void excluir_lista(Lista *alunos);
void buscar_dados_aluno(Lista *alunos, int matricula);
void exibir_todos_dados_alunos(Lista *alunos);
void encontrar_aluno_com_maior_nota_da_primeira_prova(Lista *alunos);
void encontrar_aluno_com_maior_media_geral(Lista *alunos);
void encontrar_aluno_com_menor_media_geral(Lista *alunos);
void listar_alunos_aprovados_e_reprovados(Lista *alunos);
int verificar_se_lista_esta_ordenada(Lista *alunos);
void fazer_copia_lista_l1_em_lista_l2(Lista *alunos, Lista *alunos2);
void inverter_lista_l1_colocando_resultado_em_lista_l2(Lista *alunos, Lista *alunos2);
void intercalar_duas_listas_l1_e_l2_gerando_lista_l3(Lista *alunos, Lista *alunos2,  Lista *alunos3);

//auxiliares
void inicializa_lista(Lista *alunos);
int vazia_lista(Lista *alunos);
void exibir_dados_aluno(Aluno aluno);
