#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Aluno{
	char nome[40];
	char curso[60];
	int matricula;
	
}Elemento;

typedef struct celulA{
	Elemento info;
	struct celulA *prox;
}Celula;

typedef struct filA{
	Celula *inicio;
	Celula *fim;
}Fila;

//INICIAR FILA
void iniciarFila(Fila *fila){
	fila->inicio= NULL;
	fila->fim=NULL;
}


//VERIFICAR SE ESTA VAZIA
int filaVazia(Fila *fila){
	if (fila->inicio==NULL) {
		return 1;
	}
	
	return 0;
}

//CRIAR CELULA
Celula *criarCelula (){
	Celula *nova = (Celula *) malloc (sizeof(Celula));
	nova->prox = NULL;
	
	return nova;
}

//CRIAR UM ELEMENTO
Elemento criarElemento(char nome[], char curso[], int matricula) {
	Elemento elemento;
	strcpy(elemento.nome, nome);
	strcpy(elemento.curso, curso);
	elemento.matricula=matricula;
	
	return elemento;
}

//COMPARAR ELEMENTO
int compararElemento (Elemento e1,Elemento e2){
	return strcmp(e1.nome,e2.nome);
}


//ENFILEIRA NA FILA
int enfileirar (Fila *fila,Elemento novo){
	Celula *novaCelula;
	
	novaCelula = criarCelula();
	
	if (novaCelula == NULL ){
		printf("erro - memoria cheia.\n");
		return 0;
	}
	
	(*novaCelula).info = novo;
	
	 if (filaVazia(fila)) {
	 	 fila->fim= novaCelula;
	 	 fila->inicio= novaCelula;
	 	return 1;
	 	
	 }
	 
	fila->fim->prox=novaCelula;
	fila->fim=novaCelula;
	 return 1;
}

//DESEMFILA DA FILA
Elemento desenfileirar(Fila *fila) {
	Celula *removida;
	Elemento removido = criarElemento (" "," ", 0);
	
	if (filaVazia(fila)){
		printf("erro- lista vazia.");
		return removido;
	}
	
	removida = fila->inicio;
	removido = removida-> info;
	fila->inicio =  fila->inicio-> prox;
	free(removida);
	

	return removido;
}




//IMPRIMIR ELEMENTO, USADO NO MENU PARA IMPRIMIR A LISTA TODA.
void imprimirElemento(Elemento elemento){
	printf("\nNome: %s\n Matricula: %d\n nCurso: %s\n",elemento.nome,elemento.matricula,elemento.curso);
} 


//SABER PROXIMO DA FILA
void proximo(Fila *fila){
	if (filaVazia(fila)){
		
		printf("erro - filha vazia\n");
	
	}
	
	printf("proximo da fila: \n");
	imprimirElemento(fila->inicio->info);

	
}
//SABER ULTIMO DA FILA
void Ultimo(Fila *fila){
	if (filaVazia(fila)){
		
		printf("erro - filha vazia\n");
	
		
	}
	
	printf("ultimo da fila: \n");
	imprimirElemento(fila->fim->info);

	
}
int tamanhoFila(Fila * fila){
	Celula *  aux=fila->inicio;
	int tamanho=0;
	if(filaVazia(fila)){
		return tamanho;
	}else{

		while(aux!=NULL){
			
			aux=aux->prox;
			tamanho++;
		}
		return tamanho;
	}

}
void liberarFila(Fila *fila){
	while(fila->inicio!=NULL){
		desenfileirar(fila);
	}
	printf("Fila liberada");
}

//IMPRIMIR TODOS OS VALORES DA FILA
void imprimirFila(Fila *fila, Fila * faux){

		
		
		Elemento Aux=criarElemento("","",0);
		
	
		if(filaVazia(fila)) {
			
			printf("fila vazia\n");
			return ;
		}
		
		else{
			
			printf(": FILA:\n");
			while(fila->inicio != NULL){
				Aux= desenfileirar(fila);
				imprimirElemento(Aux);
				enfileirar(faux,Aux);
			}
			while(faux->inicio != NULL){
				Aux=desenfileirar(faux);
				enfileirar(fila,Aux);
			}
		
		
		}
	}
