#include <iostream>
#include "usuario.h"

Usuario::Usuario(){
}

Usuario::Usuario( string email, string senha, string nome, int id){
    this->nomeUsuario = nome;
    this->email = email;
    this->senha = senha;
    this->id = id;
}

Usuario::~Usuario(){}

void Usuario::setid( int id ){
    this->id = id;
}
void Usuario::setEmail( string email ){
    this->email = email;
}
void Usuario::setNomeUsuario( string nome ){
    this->nomeUsuario = nome;
}
void Usuario::setSenha( string senha){
    this->senha = senha;
}

int Usuario::getid(){
    return this->id;
}
string Usuario::getEmail(){
    return this->email;
}
string Usuario::getNomeUsuario(){
    return this->nomeUsuario;
}
string Usuario::getSenha(){
    return this->senha;
}
