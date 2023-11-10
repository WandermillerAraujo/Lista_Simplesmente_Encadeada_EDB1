#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Lista.h"

TEST_CASE("Inserir no início da Lista")
{
    /*
        Primeiro --> S3
        { S3 --> S2 --> S1 --> nullptr }
        Ultimo --> S1
    */
    Lista lista;

    CHECK(lista.tamanho() == 0);

    const std::string s1 = "A";
    
    CHECK( lista.inserirInicio(s1) == true );
    CHECK(lista.tamanho() == 1);

    CHECK( lista.primeiroElemento() == s1 );
    CHECK( lista.ultimoElemento() == s1 );

    const std::string s2 = "B";

    CHECK( lista.inserirInicio(s2) == true );
    CHECK(lista.tamanho() == 2);

    CHECK( lista.primeiroElemento() == s2 );
    CHECK( lista.ultimoElemento() == s1 );

    const std::string s3 = "c";

    CHECK( lista.inserirInicio(s3) == true );
    CHECK(lista.tamanho() == 3);

    CHECK( lista.primeiroElemento() == s3 );
    CHECK( lista.ultimoElemento() == s1 );
}

TEST_CASE("Inserir no fim da Lista")
{
    Lista lista;

    CHECK(lista.tamanho() == 0);

    const std::string s1 = "A";
    
    CHECK( lista.inserirFim(s1) == true );
    CHECK(lista.tamanho() == 1);

    CHECK( lista.primeiroElemento() == s1 );
    CHECK( lista.ultimoElemento() == s1 );

    const std::string s2 = "B";

    CHECK( lista.inserirFim(s2) == true );
    CHECK(lista.tamanho() == 2);

    CHECK( lista.primeiroElemento() == s1 );
    CHECK( lista.ultimoElemento() == s2 );

    const std::string s3 = "c";

    CHECK( lista.inserirFim(s3) == true );
    CHECK(lista.tamanho() == 3);

    CHECK( lista.primeiroElemento() == s1 );
    CHECK( lista.ultimoElemento() == s3 );
}

TEST_CASE("Remover do início da Lista")
{
    Lista lista;

    const std::string ss[] = {"A", "B", "C", "D", "E"};

    for(std::string s : ss)
    {
        lista.inserirFim(s);
    }

    

    CHECK( lista.tamanho() == 5 );

    int i = 0;

    // { C --> D --> E --> nullptr }
    while( lista.tamanho() > 0 )
    {
        CHECK( lista.primeiroElemento() == ss[i++] );

        lista.removerInicio();
    }    
}

TEST_CASE("Remover do fim da Lista")
{
    Lista lista;

    const std::string ss[] = {"A", "B", "C", "D", "E"};

    for(std::string s : ss)
    {
        lista.inserirFim(s);
    }

    CHECK( lista.tamanho() == 5 );

    int i = 4;
    while( lista.tamanho() > 0 )
    {
        CHECK( lista.ultimoElemento() == ss[i--] );

        lista.removerFim();
    }    
}
