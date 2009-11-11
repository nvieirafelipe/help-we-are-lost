/*--------------------------------------------------Alunos
Felipe Vieira		08160913

Rafael Mardegan		xXxXxXxX

Paulo Cecilio		xXxXxXxX
*/


/*--------------------------------------------------Referências*/
#include"cidades.c"
#include<stdlib.h>
#include<stdio.h>


/*--------------------------------------------------Estruturas*/
struct no
{
       int destino;
	   int percurso;
       struct no *prox;
};


/*--------------------------------------------------Declaração de funções*/
int inserir_fim(struct no **pilha, int destino, int percurso);
int remover_fim(struct no **pilha);


/*--------------------------------------------------Variáveis Globais*/


/*--------------------------------------------------Principal*/
int main()
{
	int visitadas[N], todasCidadesVisitadas=0;
    int origem, melhorCidade;
    int percursoTotal=0;
	int i=0, j=0;

	struct no *pilha = (struct no*)NULL;

    for(i=0;i<N;i++)
		for(j=0;j<N;j++) matrizAdjacencia[i][j] = INF;

	preencherMatrizAdjacencia();
	preencheVetorNomeCidades();

    for(i=0;i<N;i++) visitadas[i] = 0;

	percursoTotal = 0;

	printf("Digite a origem da viagem: ");
	scanf("%d", &origem);

	inserir_fim(&pilha, origem, 0);
	while (pilha != NULL) {
		i = remover_fim(&pilha);
		visitadas[i]++;

		todasCidadesVisitadas = 1;
		for (j=0; j<N; j++)
		{
			if (visitadas[j]<1)
			{
				todasCidadesVisitadas = 0;
			}
		}

		if(todasCidadesVisitadas == 1)
		{
			printf("Achou solucao\n");
		}
		else
		{
			melhorCidade = -1;
			for (j=0; j<N; j++)
			{
				  if (matrizAdjacencia[i][j] < INF && i != j) {
					  //Define a primeira "melhorCidade" válida
					  if (melhorCidade == -1) melhorCidade = j;

					  //Prioridade para cidade não visitadas
					  if (visitadas[melhorCidade] > visitadas[j]) melhorCidade = j;

					  //Prioridade para o menor caminho desde que a cidade já tendo sido visitada não substitua uma cidade não visitada
					  if ((visitadas[melhorCidade] >= visitadas[j]) && (matrizAdjacencia[i][melhorCidade] > matrizAdjacencia[i][j])) melhorCidade = j;
				  }
			}
			percursoTotal = percursoTotal + matrizAdjacencia[i][melhorCidade];
			inserir_fim(&pilha, melhorCidade, matrizAdjacencia[i][melhorCidade]);
		}
	}

	for(j=0;j<N;j++)
	{
		visitadas[j] = 0;
	}

	inserir_fim(&pilha, melhorCidade, 0);
	while (visitadas[origem] == 0)
	{
		i = remover_fim(&pilha);
		visitadas[i]++;

		if (visitadas[origem] == 0)
		{
			if (matrizAdjacencia[i][origem] < INF)
			{
				//pilha[ini++] = j;
				percursoTotal = percursoTotal + matrizAdjacencia[i][origem];
				inserir_fim(&pilha, origem, matrizAdjacencia[i][origem]);
			}
			else
			{
				melhorCidade = -1;
				for (j=0; j<N; j++)
				{
					if (matrizAdjacencia[i][j] < INF && i != j) {
						//Define a primeira "melhorCidade" válida
						if (melhorCidade == -1) melhorCidade = j;

						//Prioridade para cidade não visitadas
						if (visitadas[melhorCidade] > visitadas[j]) melhorCidade = j;

						//Prioridade para o menor caminho desde que a cidade já tendo sido visitada não substitua uma cidade não visitada
						if ((visitadas[melhorCidade] >= visitadas[j]) && (matrizAdjacencia[i][melhorCidade] > matrizAdjacencia[i][j])) melhorCidade = j;
					}
				}
				percursoTotal = percursoTotal + matrizAdjacencia[i][melhorCidade];
				inserir_fim(&pilha, melhorCidade, matrizAdjacencia[i][melhorCidade]);
			}
		}
	}
	remover_fim(&pilha);
	printf("Total percorrido: %dkm's", percursoTotal);
    return (int)getc(stdin);
}


/*---------------------------------------------------Inserir destino no fim da pilha*/
int inserir_fim(struct no **pilha, int destino, int percurso){
	 struct no *aux1;

     aux1 = (*pilha);
     int result;
	 if(aux1 == NULL){
		 (aux1) = (struct no*)malloc(sizeof(struct no));
		 if(aux1 == NULL){
			 result = -1;
		 }
		 else{
			 aux1->destino = destino;
			 aux1->percurso = percurso;
			 aux1->prox = (struct no*)NULL;
			 (*pilha) = aux1;
			 result = 1;
		 }
	 }
	 else{
		 struct no *aux2;

		 while(aux1->prox != NULL){
			aux1 = aux1->prox;
		 }

		 if(aux1->prox == NULL){
			 aux2 = (struct no*)malloc(sizeof(struct no));
			 if(aux2 == NULL){
				 result = -1;
			 }
			 else{
				 aux2->destino = destino;
				 aux2->percurso = percurso;
				 aux2->prox = (struct no*)NULL;
				 aux1->prox = aux2;
				 result = 1;
			 }
		 }
	 }
   return result;
}


/*---------------------------------------------------Remover destino no fim da pilha*/
int remover_fim(struct no **pilha){
	int destino, percurso;
	char resposta;

    struct no *aux = (struct no*)NULL;
	aux = (*pilha);

	if((*pilha) == NULL){
		return -1;
	}
	else{
        while((*pilha)->prox != NULL){
			(*pilha) = (*pilha)->prox;
	    }

		destino = (*pilha)->destino;
		percurso = (*pilha)->percurso;

		(*pilha) = (struct no*)NULL;
		(pilha) = &aux;
		free(aux);

		printf("%dkm's para %s \n", percurso, nomeCidades[destino]);
		return destino;
	}
}