#define MAX 100

typedef struct  {
  int chave;
}ITipoElem;


typedef struct {
  ITipoElem A[MAX];
  int Nelem;
}ILista;


typedef struct {
  int chave;
  int cont;
}ITipoElemCont;

typedef struct {
  ITipoElemCont A[MAX];
  int Nelem;
}IListaReg;

int iniciar(ILista *L);

void exibir_lista(ILista *L);

void exibir_lista_registro(IListaReg *L);

int aux_vazia(ILista *L);

int ordenada(ILista *L);

void copia_lista(ILista *L, ILista *P);

void copia_lista_sem_repetidos(ILista *L, ILista *P);

void inverte_lista(ILista *L, ILista *P);

void intercala_lista(ILista *L, ILista *P, ILista *K);

void contador_registros(ILista *L, IListaReg *K);

void frequencia_lista(ILista *L);
