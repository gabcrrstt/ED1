/**********************************************************
*****
* Alunos: William Cardoso Barbosa 
* Curso: Ciência da Computação
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: gcc (tdm-1) 4.9.2
* IDE : Vscode
* Sistema Operacional: Windows 11 e Windows 10
***********************************************************
****/

#define MAX 100

typedef struct {
  char nome[8];
  int matricula;
  float nota1, nota2, nota3;
} Aluno;

typedef struct {
  Aluno A[MAX];
  int nElem;
}Lista;


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
int cheia(Lista *alunos);
int busca_sequencial(Lista *alunos, int matricula);
void exibir_dados_aluno(Aluno aluno);