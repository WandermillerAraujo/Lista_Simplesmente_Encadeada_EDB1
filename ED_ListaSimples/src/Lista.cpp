#include "Lista.h"
#include <iostream>

Lista::Lista()
{
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->quantidade = 0;
}

Lista::~Lista()
{

}

bool Lista::inserirInicio(const std::string& elemento)
{
    No* novo = new No(elemento);

    if (this->quantidade == 0){
        this->primeiro = novo;
        this->ultimo = novo;
    }
    else {
        novo->proximo = this->primeiro;
        this->primeiro = novo;
    }

    ++this->quantidade;
    return true;
}

bool Lista::inserirFim(const std::string& elemento)
{
    No* novo = new No(elemento);

    if (this->quantidade == 0){
        this->primeiro = novo;
        this->ultimo = novo;
    }
    else {
        this->ultimo->proximo = novo;
        this->ultimo = novo;
    }

    ++this->quantidade;
    return true;
}

bool Lista::removerInicio()
{
    if (this->quantidade == 0){
        return false; // está vazia, não há nada a ser removido.
    }
    else if (this->quantidade == 1){
        delete this->primeiro;
        this->primeiro = nullptr;
        this->ultimo = nullptr;
    }
    else {
        No* aux = this->primeiro;
        this->primeiro = this->primeiro->proximo;
        delete aux;
    }

    --this->quantidade;
    return true;
}

bool Lista::removerFim()
{
    if(this->quantidade == 0){
        return false;
    }
    else if (this->quantidade == 1){
        delete this->primeiro;
        this->primeiro = nullptr;
        this->primeiro = nullptr;
    }
    else {
        No* aux = this->primeiro;

        while (aux->proximo != this->ultimo){
            aux = aux->proximo;
        }
        delete this->ultimo;
        this->ultimo = aux;
        aux->proximo = nullptr;
    }

    --this->quantidade;
    return true;
}

const std::string& Lista::primeiroElemento() const
{
    if (quantidade > 0)
    {
        return primeiro->valor;
    }
    else
    {
        throw std::out_of_range("A lista está vazia. Não é possível acessar o primeiro elemento.");
    }
}

const std::string& Lista::ultimoElemento() const
{
    if (quantidade > 0)
    {
        return ultimo->valor;
    }
    else
    {
        throw std::out_of_range("A lista está vazia. Não é possível acessar o último elemento.");
    }
}

unsigned long Lista::tamanho() const
{
    return quantidade;
}

void Lista::imprimir() const
{
    No* atual = primeiro;

    std::cout << "{ ";

    while (atual != nullptr)
    {
        std::cout << atual->valor << ", ";
        atual = atual->proximo;
    }

    std::cout << "} " << std::endl;
}

Lista::No::No(std::string valor)
{
    this->valor = valor;
    this->proximo = nullptr;
}

Lista::No::~No()
{
}
