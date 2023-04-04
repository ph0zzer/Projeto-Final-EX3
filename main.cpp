#include <iostream>
#define maximo 8

using namespace std;

struct Stack { 
    int dado; 
    Stack *prox;
}; 

void push(Stack * & topo, int dado){

  if(maximo <= 0){   //Verifica se o valor maximo definido pelo usuario nao seja 0
    printf("Pilha sem espaços disponiveis!\n");
   } 
    
  else {    
    if(topo == NULL){        //Verifica se a pilha esta inicialmente vazia
    
      Stack *pilha = NULL;  //Aloca espaço para novo nivel da pilha
      pilha = (Stack*) calloc (1, sizeof(Stack));  
      
      if(pilha == NULL){     //Verifica se foi alocado memória
     printf("ERRO DE ALOCAÇÂO!\n");
      } 
        
      else{  //aloca elemento na pilha
      pilha->dado = dado;   //Novo nivel recebe dado informado pelo usuario
      pilha->prox = NULL;   //Nivel mais baixo da pilha aponta para NULO
      topo = pilha;         //Atualiza Topo para novo nivel
      cout << "\n\nValor " << dado << " Adicionado à pilha!\n";  
      return;
      }
   }
      
  else  { //verifica se pilha não esta cheia
    Stack *pilha = NULL;
      pilha = (Stack*) calloc (1, sizeof(Stack)); //aloca ponteiro
    
    if(pilha == NULL){ 
      printf("ERRO DE ALOCAÇÂO!\n");}//verifica falha na alocação
    else{ //demais elementos da pilha
      pilha->dado = dado;
      pilha->prox = topo;
      topo = pilha;
      cout << "\nValor " << dado << " Adicionado à pilha!\n";   
     } 
    } 
   }  
  }

int pop(Stack * & topo){  //Função para remover elementos da pilha
 
	Stack * aux;               //Ponteiro váriavel
    aux = topo;
  
  int val;                   //Valor a ser removido da pilha
    val = aux->dado;
  
	 topo = aux->prox;         //Topo passa a aponta para o proximo elemento da pilha
   free(aux);                //Libera Endereço do antigo topo

  if(aux != topo){           //Verifica se o topo foi removido
    cout << "\n\n"<< val << " Removido da pilha!\n";
  }

  else{
    cout << "Erro ao remover nivel atual!\n";
  }
	 return val;             //Retorna valor removido da pilha
 }

void listar(Stack * & topo){
  if(topo == NULL){  //Verifica se pilha está vazia
		printf("\nPilha vazia\n");
	}

  else{ //Lista todos elementos da pilha
    
		
		struct Stack * aux = topo;
		while(aux != NULL){ //Percorre a pilha inteira
			printf("%d\n", aux->dado);
			aux = aux->prox;  
			}
	}
}

void empilhar(Stack *& p3, Stack * p2, Stack * p1){

  while(p2 != NULL && p1 != NULL){

    cout <<"\n\nPilha 1 Atual:\n"; listar(p1);
    cout <<"\nPilha 2 Atual:\n"; listar(p2);
    cout <<"\nPilha 3 Atual:\n"; listar(p3);
    
    if(p1->dado < p2->dado){
      push(p3, pop(p1));
    }
    else if(p1->dado > p2->dado){
      push(p3, pop(p2));
    }
  }

  while(p2 != NULL || p1 != NULL){
    if(p2 == NULL && p1!= NULL){
      push(p3,pop(p1));
    }
      
    else if(p1==NULL && p2 != NULL){     
      push(p3, pop(p2));
    }
  }
  return;
  }

int main() {
  
  Stack *p1 = NULL; 
  Stack *p2 = NULL;
  Stack *p3 = NULL;
  

   push(p1, 33);
   push(p1, 30);
   push(p1, 26);
   push(p1, 24);
   push(p1, 20);
  
   push(p2, 31);
   push(p2, 28);
   push(p2, 27);
   push(p2, 25);
   push(p2, 22);
   
  empilhar(p3, p2, p1);
  cout << "\n\nPilha 3 Atual:\n"; listar(p3);
  }
  