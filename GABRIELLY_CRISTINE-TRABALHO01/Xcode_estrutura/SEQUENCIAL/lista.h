/*
 Alunos: Gabrielly Cristine
* Curso: Ciência da Computação
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Apple clang version 14.0.3 (clang-1403.0.22.14.1)
* IDE : Xcode
* Sistema Operacional: MacOs Veentura 13.1
 */

#ifndef lista_h
#define lista_h


//struct


#define MAX 5

typedef struct {
  char nome[8];
  int matricula;
  float nota1, nota2, nota3,media;
} Aluno;

typedef struct {
  Aluno A[MAX];
  int nElem;
}Lista;
// fim do struct

//funcoes
Aluno criar_novo_aluno();
//void Inserir_Lista(Lista *alunos, Aluno novo_aluno);
int inserir_aluno(Lista *alunos, Aluno novo_aluno); // insere o aluno no inicio da lista
void inserir_aluno_fim_lista(Lista *alunos, Aluno aluno);
int remover_aluno(Lista *alunos, int matricula);
void alterar_cadastro(Lista *alunos, int matricula);
void excluir_lista(Lista *alunos);
int buscar_dados_aluno(Lista *alunos, int matricula);
void exibir_todos_dados_alunos(Lista *alunos);
void encontrar_aluno_com_maior_nota_da_primeira_prova(Lista *alunos);
void encontrar_aluno_com_maior_media_geral(Lista *alunos);
void encontrar_aluno_com_menor_media_geral(Lista *alunos);
void listar_alunos_aprovados_e_reprovados(Lista *alunos);
int verificar_se_lista_esta_ordenada(Lista *alunos);
void fazer_copia_lista_l1_em_lista_l2(Lista *alunos, Lista *alunos2);
void inverter_lista_l1_colocando_resultado_em_lista_l2(Lista *alunos, Lista *alunos2);
void intercalar_duas_listas_l1_e_l2_gerando_lista_l3(Lista *alunos, Lista *alunos2,  Lista *alunos3);
// fim das funcoes

// aux
void inicializa_lista(Lista *alunos);
int vazia_lista(Lista *alunos);
int cheia(Lista *alunos);
int busca_sequencial(Lista *alunos, int matricula);
int exibir_todos_alunos(Lista *alunos, Aluno aluno);
void exibir_dados_aluno(Aluno aluno);
void atualizar_arquivo(Lista *alunos);
// fim das aux

#endif /* lista_h */
