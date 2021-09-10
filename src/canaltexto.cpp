#include <iostream>

#include "canaltexto.h"



CanalTexto::CanalTexto(){}

CanalTexto::CanalTexto( string nome ){
    nomeCanalTexto = nome;
}

CanalTexto::~CanalTexto(){}

std::string CanalTexto::getNomeCanalTexto(){
    return this->nomeCanalTexto;
}

std::string CanalTexto::addMensagem( Mensagem mensagem ){
    this->mensagens.push_back(mensagem);
    return "MENSAGEM ADICIONADA EM '" + this->getNomeCanalTexto() + "'";
}

std::string CanalTexto::listMensagens( vector<Usuario> &vetorUsuarios ){
    string retorno = "#Mensagens do canal '" + nomeCanalTexto + "'\n";
    string nome;

    std::vector<Mensagem>::iterator it;
    for( it = mensagens.begin(); it != mensagens.end() ; it++ ){
        vector<Usuario>::iterator it2;
        for( it2 = vetorUsuarios.begin(); it2 != vetorUsuarios.end(); it2++ ){
            if( it2->getid() == it->getEnviadoPor()){
                nome = it2->getNomeUsuario();
                break;
            }
        }
        retorno += "<" + nome + "> disse : " + it->getConteudo() +  "\nem: "  + it->getDataHora() + "\n";
    }
    return retorno;
}