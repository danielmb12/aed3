#include <iostream>

using namespace std;

class celula
{
private:
	string nome;
	celula * proxima;
public:
	celula()
	{
		proxima = NULL;
	}
	celula(string n)
	{
		nome = n;
	}
	
	celula(string n, celula *p){
		nome = n;
		proxima = p;
	}

	string getNome()
	{
		return nome;
	}
	void setNome(string n)
	{
		nome = n;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	lista(celula *i)
	{
		inicio = i;
	}
	~lista()
	{
		esvaziar();
		cout << "\nPassou no metodo destrutor";
	}
	celula * getInicio()
	{
		return inicio;
	}

	void setInicio(celula *i)
	{
		inicio = i;
	}

	void inserirInicio(string n)
	{
		celula *nova = new celula;
		nova->setNome(n);
		nova->setProxima(inicio);
		inicio = nova;
	}

	void inserirFim(string n)
	{
		celula *nova = new celula(n, NULL);
		//nova->setNome(n);
		//nova->setProxima(NULL);
		if(inicio == NULL)
		{
			inicio = nova;
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			aux->setProxima(nova);
		}
	}


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout << aux->getNome() << endl;
				aux = aux->getProxima();
			}
		}
	}

	void esvaziar()
	{
		celula *aux = inicio;
		while(aux != NULL)
		{
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\nLista esvaziada com sucesso.";
	}


};

int main()
{
	lista listaAlunos;
	listaAlunos.inserirInicio("Miguel");
	listaAlunos.inserirFim("Ana");
	listaAlunos.esvaziar();
	listaAlunos.inserirFim("Vinicius");
	listaAlunos.imprimir();
	return 0;
}
