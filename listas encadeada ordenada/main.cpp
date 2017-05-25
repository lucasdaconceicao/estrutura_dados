#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
 	//Definindo o registro que
 	// representara cada elemento da lista
	struct Lista
	{
		int num;
		Lista *prox;
	};
	//a lista está vazia,logo,
	//o ponteiro inicio tem o valor NULL
	//o ponteiro inicio conterá o endereco
	//do primeiro elemento da lista
	Lista *inicio=NULL;
	//o ponteiro fim contera o endereco
	//do ultimo elemento da lista
	Lista *fim =NULL;
	//o ponteiro aux é um ponteiro auxiliar
	Lista *aux;
	//o ponteiro anterior é um ponteiro auxiliar
	Lista *anterior;
	//apresentando o menu de opções
	int op,numero,achou;

	do
	{
		system("cls");
		cout<<"\nMENU DE OPCOES\n";
		cout<<"\n1 - Inserir na lista";
		cout<<"\n2 - Consultar toda a lista";
		cout<<"\n3 - Remover da lista";
		cout<<"\n4 - Esvaziar a lista";
		cout<<"\n5 - Sair";
		cout<<"\n - Digite sua opcao: ";
		cin>>op;
		if (op<1||op>5)
			cout<<"Opção invalida!!";
		if (op==1)
		{
			cout<<"Digite o numero a ser inserido na lista: ";
			Lista *novo=new Lista();
			cin>>novo->num;
			if (inicio==NULL)
			{
				//a Lista estava vazia
				//e o elemento inserido sera
				//o primeiro e o ultimo
				inicio=novo;
				fim=novo;
				novo->prox=NULL;
			}
			else
			{
				//a lista ja contem elementos
				//e o novo elemento
				//sera inserido na lista
				//respeitando a ordenação
				//crescente
				anterior=NULL;
				aux=inicio;
				while(aux!=NULL && novo->num > aux->num)
				{
					anterior=aux;
					aux=aux->prox;
				}
				if (anterior==NULL)
				{
					// o novo numero a ser inserido
					//é menor que todos os numeros da lista,
					//logo,sera inserido no inicio
					novo->prox=inicio;
					inicio=novo;
				}
				else if (aux==NULL)
				{
					// o novo numero  ser inserido
					//é maior que todos os numeros da
					//lista,logo,sera
					//inserido no fim
					fim->prox=novo;
					fim=novo;
					fim->prox=NULL;
				}
				else
				{
					//o novo numero a ser inserido
					//sera inserido entre dois
					//numeros que ja estao na lista
					anterior->prox=novo;
					novo->prox=aux;
				}
			}
			cout<<"Numero inserido na lista!!";
		}
		if (op==2)
		{
			if (inicio==NULL)
			{
				//a lista está vazia
				cout<<"Lista vazia!!";
			}
			else
			{
				//a lista contem elementos e estes
				//serao mostrados no inicio ao fim
				cout<<"\nConsultando toda a lista\n";
				aux=inicio;
				while(aux !=NULL)
				{
					cout<<aux->num<<"  ";
					aux=aux->prox;
				}
			}
		}
		if (op==3)
		{
			if (inicio == NULL)
			{
				// a lista está vazia
				cout<<"Lista Vazia!!";
			}
			else
			{
				//a lista contém elementos e o elemento a ser removido deve ser digitado
				cout<<"\nDigite o elemento a ser removido:" ;
				cin>>numero;
				//todas as ocorrências da lista,iguais ao número digitado, serão removidas
				aux = inicio;
				anterior = NULL;
				achou = 0;
				while (aux != NULL)
				{
					if (aux->num == numero)
					{
						// o número digitado foi encontrado na lista e sera removido
						achou = achou + 1;
						if (aux == inicio)
						{
							//o numero a ser removido é o primeiro da lista
							inicio = aux->prox;
							delete(aux);
							aux = inicio;
						}
						else if (aux == fim)
						{
							//o numero a ser removido é o último da lista
							anterior ->prox = NULL;
							fim = anterior;
							delete(aux);
							aux = NULL;
						}
						else
						{
							//o número a ser removido está no meio da lista
							anterior ->prox = aux->prox;
							delete(aux);
							aux = anterior ->prox;
						}
					}
					else
					{
						anterior = aux;
						aux = aux->prox;
					}
				}
				if (achou == 0)
					cout<<"Número não encontrado";
				else if (achou == 1)
					cout<<"Número removido 1 vez";
					else
					cout<<"Número removido "<<achou<<"vezes";
			}
		}
		if (op == 4)
		{
			if (inicio == NULL)
			{

				// a lista está vazia
				cout<<"Lista vazia!!";
			}
			else
			{
				//a lista será esvaziada
				aux=inicio;
				while (aux != NULL)
				{
					inicio = inicio->prox;
					delete (aux);
					aux = inicio;
				}
				cout<<"Lista esvaziada";

			}
		}
		getch ();
	}
	while (op != 5);
}



