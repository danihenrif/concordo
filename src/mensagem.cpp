#include "mensagem.h"

Mensagem::Mensagem(){
}

Mensagem::Mensagem(std::string dataHora, int id, std::string mensagem){
    this->dataHora = dataHora;
    enviadaPor = id;
    conteudo = mensagem; 
}

Mensagem::~Mensagem(){
    
}

std::string Mensagem::getDataHora(){
    return dataHora;
}

std::string Mensagem::getConteudo(){
    return conteudo;
}

int Mensagem::getEnviadoPor(){
    return enviadaPor;
}