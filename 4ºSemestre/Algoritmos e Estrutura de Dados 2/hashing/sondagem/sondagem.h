#pragma once

class FSondagem{
public:
    virtual int p(int chave, int k) = 0;
    virtual void redim_callback(int novo_m) { }
};

class SondagemLinear : public FSondagem{
public:
    int p(int chave, int k){
        return k;
    }
};

class SondagemQuadratica : public FSondagem{
public:
    int p(int chave, int k){
        return k*k;
    }
};

class SondagemHashDuplo : public FSondagem{
public:
    SondagemHashDuplo(int s){
        this->s = s;
    }
    int p(int chave, int k){
        return k* ((chave % s)+1);
    }
    void redim_callback(int novo_m){
        this->s = novo_m - 1;
    }
private:
    int s;
};