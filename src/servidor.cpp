#include <iostream>

#include "servidor.h"
#include "usuario.h"


Servidor::Servidor(){
}

Servidor::Servidor(int id, string nome){
    this->usuarioDonold = id;
    this->nomeServidor = nome;
}

Servidor::~Servidor(){}

string Servidor::getNomeServidor(){
    return this->nomeServidor;
}

void Servidor::setParticipantesIDs(int id){
    this->participantesIDs.push_back(id);
}

void Servidor::setDescricaoServidor(string descricao){
    this->descricaoServidor = descricao;
}

void Servidor::setCodigoConviteServidor(string codigo){
    this->codigoConvite = codigo;
}

int Servidor::getUsuarioDonold(){
    return this->usuarioDonold;
}

string Servidor::getCodigoConvite(){
    return this->codigoConvite;
}

std::vector<int> Servidor::getIdUsuarios(){
    return this->participantesIDs;
}

string Servidor::getNomesCanaisServidor(){
    std::vector<CanalTexto>::iterator it;
    std::string retorno = "#canais de texto\n";
    for( it = canaisTexto.begin() ; it != canaisTexto.end() ; it++ ){
        retorno += it->getNomeCanalTexto() + "\n" ;
    } 
    return retorno;  
}

bool Servidor::buscaUsuarioServidor(int id){
    /*std::vector<int>::iterator it = find(participantesIDs.begin(), participantesIDs.end(), id);*/
    std::vector<int>::iterator it;
    for( it = participantesIDs.begin(); it != participantesIDs.end() ; it++ ){
        if(*it == id)
            return true;
    }
    /*if(it == participantesIDs.end()){
        return false;
    }*/
    return false;
}

void Servidor::removeParticipante(int id){
    std::vector<int>::iterator it;
    for( it = participantesIDs.begin(); it != participantesIDs.end() ; it++ ){
        //Achou o usuário(id)
        if( *(it) == id ){
        participantesIDs.erase(it);
        return;
        }
    }
}

bool Servidor::checaExisteCanalTexto( string nome ){
    std::vector<CanalTexto>::iterator it;
    for( it = canaisTexto.begin() ; it != canaisTexto.end() ; it++ ){
        //Canal texto existe
        if( it->getNomeCanalTexto() == nome ){
            return true;
        }
    }
    return false;//Não existe
}

void Servidor::adicionaCanal( CanalTexto canal ){
    canaisTexto.push_back(canal);
} 

string Servidor::adicionaMensagem(int id, string mensagem, string canal){
    if( canaisTexto.empty() ){
        std::cout << "aqui";
        return "NAO HA CANAIS CADASTRADOS NO SERVIDOR";
    }
    else{
        //Pega o endereço do canalTexto
        vector<CanalTexto>::iterator it;
        for( it = canaisTexto.begin() ; it != canaisTexto.end() ; it++ ){
            if( it->getNomeCanalTexto() == canal ){
                break;
            }
        }
        time_t now = time(0);
        string dataHora = ctime(&now);
        Mensagem *msg = new Mensagem( dataHora,id, mensagem );
        return it->addMensagem(*msg);
    }
}

string Servidor::listaMensagens(string canal, vector<Usuario> &vetorUsuarios){
    //Procura o canal de texto
    vector<CanalTexto>::iterator it;
    for( it = canaisTexto.begin(); it != canaisTexto.end(); it++ ){
        if( it->getNomeCanalTexto() == canal ){
            break;
        }
    }
    return it->listMensagens(vetorUsuarios);
}