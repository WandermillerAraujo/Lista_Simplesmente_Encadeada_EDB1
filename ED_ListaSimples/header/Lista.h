#ifndef LISTA_H
#define LISTA_H

#include <string>

class Lista 
{
    public:
        Lista();
        ~Lista();
        bool inserirInicio(const std::string& elemento);
        bool inserirFim(const std::string& elemento);
        bool removerInicio();
        bool removerFim();
        const std::string& primeiroElemento() const;
        const std::string& ultimoElemento() const;
        unsigned long tamanho() const;
        void imprimir() const;
   
    private:
        class No
        {
        public:
            ~No();
            
            No( std::string valor );

            std::string valor;

            No* proximo;
        };

        No* primeiro;
        No* ultimo;
        unsigned long quantidade;
};

#endif