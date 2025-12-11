#pragma once

#include <iostream>

template <typename C, typename V>
class ABB;

template <typename C, typename V>
class NoABB
{
public:
    NoABB(C chave, V valor)
        : chave(chave), valor(valor),
          esq(nullptr), dir(nullptr) {}

    ~NoABB() = default;

    C getChave() { return chave; }
    V &getValor() { return valor; }

private:
    C chave;
    V valor;
    NoABB *esq;
    NoABB *dir;

    friend class ABB<C, V>;
};

template <typename C, typename V>
class ABB
{
public:
    ABB() {
        this->raiz = nullptr;
    }
    
    ~ABB() = default;

    // insere o par (chave, valor) na árvore
    void inserir(C chave, V valor){
        this->raiz = inserirNo(this->raiz, chave, valor);
    }
    
    // retorna uma referência ao nó com a chave especificada
    NoABB<C, V>* buscar(C chave){
        auto p = this->raiz;
        while(p != nullptr){
            if(chave == p->chave){
                return p;
            }
            if(chave < p->chave)
                p = p->esq;
            else
                p = p->dir;
        }
        return nullptr;
    }

    // remove o nó com a chave especificada
    void remover(C chave){
        this->raiz = removerNo(this->raiz, chave);
    }

    // imprime a árvore
    void imprimir(){
        this->imprimirNo(raiz, 0, 'R');
    }
    
    // retorna uma referência ao nó com a menor chave
    NoABB<C, V>* minimo();

    NoABB<C, V>* minimo(NoABB<C, V>* no){
        if(no == nullptr)
            return nullptr;

        auto p = no;
        while(p->esq != nullptr)
            p = p->esq;

        return p;
    }


    // retorna uma referência ao nó com a maior chave
    NoABB<C, V>* maximo();
    // retorna uma referência ao nó com a chave sucessora da chave especificada
    NoABB<C, V>* sucessor(C chave);
    // retorna uma referência ao nó com a chave antecessora da chave especificada
    NoABB<C, V>* antecessor(C chave);
    // retorna o número de nós da árvore
    int tamanho();
    // retorna true se a árvore estiver vazia
    bool vazia();

private:
    NoABB<C, V>* inserirNo(NoABB<C, V> *no, C chave, V valor){
        if(no == nullptr)
            return new NoABB(chave, valor);
        if(chave == no->chave)
            no->valor = valor;
        else if(chave < no->chave)
            no->esq = inserirNo(no->esq, chave, valor);
        else
            no->dir = inserirNo(no->dir, chave, valor);
        return no;
    }

    NoABB<C, V>* removerNo(NoABB<C, V>* no, C chave){
        if(no == nullptr){
            return nullptr;
        }
        if(chave < no->chave){
            no->esq = removerNo(no->esq, chave);
        }
        else if (chave > no->chave){
            no->dir = removerNo(no->dir, chave);
        }
        else{
            NoABB<C, V>* t = nullptr;
            //achamos a chave a ser removida
            //caso 1: nó folha
            if(no->dir == nullptr &&
                no->esq == nullptr){
                delete no;
                return nullptr;
            }
            //caso 2: nó com 1 filho
            //2a: nó apenas com filho direito
            if(no->esq == nullptr){
                t = no->dir;
                no->dir = nullptr;
                delete no;
                return t;
            }
            //2b: nó apenas com o filhon esq.
            if(no->dir == nullptr){
                t = no->esq;
                no->esq = nullptr;
                delete no;
                return t;
            }
            //Caso 3: tem dois filhos!
            auto s = minimo(no->dir);
            no->chave = s->chave;
            no->valor = s->valor;
            no->dir = removerNo(no->dir, 
                s->chave);
        }
        return no;
    }

    void imprimirNo(NoABB<C, V> *no, int nivel, char lado){
        for(int i = 0; i < nivel; i++){
            std::cout << "-->";
        }
        if(no == NULL)
            std::cout << "(" << lado << ") (VAZIO)" << std::endl;
        else{
            std::cout << "(" << lado << ") (" 
                        << no->chave << ", " << no->valor << ")" << std::endl;

            imprimirNo(no->esq, nivel + 1, 'E');
            imprimirNo(no->dir, nivel + 1, 'D');
        }
    }


    NoABB<C, V> *raiz;
};


