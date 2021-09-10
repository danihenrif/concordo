#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Sistema::Sistema()
{
  this->Id = 0;
}

int Sistema::getId()
{
  return Id;
}

bool Sistema::checaUsuarioExiste(int id)
{
  //Se o id for maior que o Id do último usuário registrado, então não existe
  //Já que não há função de excluir um usuário(conta de usuário)
  if (id <= 0 or id > Id)
  {
    return false;
  }
  else
  {
    return true;
  }
}

/* COMANDOS */
string Sistema::quit()
{
  return "Saindo...";
}

string Sistema::create_user(const string email, const string senha, const string nome)
{

  //Checa se o email ja está cadastrado com outra conta
  vector<Usuario>::iterator it = find_if( usuarios.begin(), usuarios.end(), checaEmailJaCadastradoPredicate(email));
  if( it != usuarios.end() ){
    return "JA EXISTE UMA CONTA COM ESSE EMAIL!";   
  }

  //Cria a conta
  Id++;
  Usuario *user = new Usuario(email, senha, nome, Id);
  usuarios.push_back(*(user));
  delete user;
  string idToString = to_string(Id);
  return "USUARIO CADASTRADO COM SUCESSO! id = " + idToString;
}

string Sistema::login(const string email, const string senha)
{

  //Checa se o email e senha são válidos
  vector<Usuario>::iterator it = find_if( usuarios.begin(), usuarios.end(), checaEmailESenhaValidosPredicate(email,senha));
  if( it == usuarios.end() ){
    return "SENHA OU USUARIO INVALIDOS!";
  }

  //busca o id do usuário
  int id = it->getid();
  //Loga
  usuariosLogados[id].first = "";  //Servidor
  usuariosLogados[id].second = ""; //Canal
  return "LOGADO COMO " + email;

}

string Sistema::disconnect(int id)
{

  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL DESCONECTAR, POIS O USUARIO NAO ESTA LOGADO";   
  }

  //Realiza o disconnect
  std::string retorno = usuarios[id - 1].getEmail(); //O id começa em indice 1 o vetor de usuarios em 0
  usuariosLogados.erase(id);
  return "USUARIO " + retorno + " DESCONECTADO";

}

string Sistema::create_server(int id, const string nome)
{

  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL CRIAR O SERVIDOR, POIS O USUARIO NAO ESTA LOGADO";  
  }
  
  //Checa se o servidor já existe
  vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(nome));
  if( it2 != servidores.end() ){
    return "JA EXISTE UM SERVIDOR COM ESSE NOME";    
  }

  //Servidor não existe, então cria o servidor
  Servidor *server = new Servidor(id, nome);
  servidores.push_back(*(server));
  delete server;
  return "SERVIDOR CRIADO";

}

string Sistema::set_server_desc(int id, const string nome, const string descricao)
{
  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }
  
  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL MUDAR A DESCRICAO DO SERVIDOR, POIS O USUARIO NAO ESTA LOGADO"; 
  }

  //Checa se o servidor existe
  vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(nome));
  if( it2 == servidores.end() ){
    return "SERVIDOR '" + nome + "' NAO EXISTE";
  }

  //Checa se o usuario é dono do servidor
  if (id == it2->getUsuarioDonold())
  {
    //Muda a descrição do servidor
    it2->setDescricaoServidor(descricao);
    return "DESCRICAO DO SERVIDOR '" + nome + "' MODIFICADA";
  }
  else
  {
    return "VOCE NAO PODE ALTERAR A DESCRICAO DE UM SERVIDOR QUE NAO FOI CRIADO POR VOCE";
  }
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo)
{
  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL MUDAR O CODIGO DE CONVITE, POIS O USUARIO NAO ESTA LOGADO";
  }

  //Checa se o servidor existe
  vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(nome));
  if( it2 == servidores.end() ){
    return "SERVIDOR '" + nome + "' NAO EXISTE";
  }

  //Checa se o usuario é dono do servidor
  if (id == it2->getUsuarioDonold())
  {
    //Muda o convite
    it2->setCodigoConviteServidor(codigo);

    if (codigo == "")
      return "CODIGO DE CONVITE DO SERVIDOR '" + nome + "' REMOVIDO";
    else
      return "CODIGO DE CONVITE DO SERVIDOR '" + nome + "' MODIFICADO";
  }
  else
  {
    return "VOCE NAO PODE ALTERAR O CODIGO DE CONVITE DE UM SERVIDOR QUE NAO FOI CRIADO POR VOCE";
  }
}

string Sistema::list_servers(int id)
{
  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL LISTAR OS SERVIDORES, POIS O USUARIO NAO ESTA LOGADO";
  }
  string listaServidores = "";

  //Checa se há servidores cadastrados no sistema (lista de servidores não é vazia)
  if (this->servidores.empty())
  {
    return "NAO HA SERVIDORES CADASTRADOS NO SISTEMA";
  }
  else
  {
    for (vector<Servidor>::iterator it = servidores.begin(); it != servidores.end(); it++)
    {
      listaServidores += it->getNomeServidor() + "\n";
    }
  }
  return listaServidores;
}

string Sistema::remove_server(int id, const string nome)
{
  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL REMOVER O SERVIDOR, POIS O USUARIO NAO ESTA LOGADO";
  }

  //Checa se há servidores cadastrados no sistema (lista de servidores não é vazia)
  if (this->servidores.empty())
  {
    return "NAO HA SERVIDORES CADASTRADOS NO SISTEMA";
  }

  //Checa se o servidor existe
  vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(nome));
  if( it2 == servidores.end() ){
    return "SERVIDOR '" + nome + "' NAO EXISTE";
  }

  //Checa se o usuario é dono do servidor
  if (id == it2->getUsuarioDonold())
  {
    //Remove o servidor
    servidores.erase(it2);
    //Remove os usuários dos canais do servidor e canais de texto
    map<int, pair<string, string> >::iterator it3;
    for (it3 = usuariosLogados.begin(); it3 != usuariosLogados.end(); it3++)
    {
      //Se o nome do servidor for igual
      if (it3->second.first == nome)
      {
        //Remove  servidor e canal dos usuários que estão visualizando o servidor
        it3->second.first = "";
        it3->second.second = "";
      }
    }
    return "SERVIDOR '" + nome + "' REMOVIDO";
  }
  else
  {
    return "VOCE NAO EH DONO DO SERVIDOR '" + nome + "'";
  }
}

string Sistema::enter_server(int id, const string nome, const string codigo)
{
  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL ENTRAR, POIS O USUARIO NAO ESTA LOGADO";
  }

  //Checa se o servidor existe
  vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(nome));
  if( it2 == servidores.end() ){
    return "SERVIDOR '" + nome + "' NAO EXISTE";
  }

  //Checa se o usuário já está no servidor
  if ((it2->buscaUsuarioServidor(id)))
  {
    return "VOCE JA ESTA NO SERVIDOR";
  }

  //Entra no servidor
  //Se não tiver código de convite ou for o dono do servidor
  if ((it2->getCodigoConvite() == "") or (id == it2->getUsuarioDonold()))
  {
    //Adiciona à lista de participantes do servidor
    it2->setParticipantesIDs(id);
    //Salva que está visualizando o servidor
    usuariosLogados[id].first = nome;
    return "ENTROU NO SERVIDOR COM SUCESSO";
  }

  //Se pedir código de convite
  else if (it2->getCodigoConvite() != "")
  {

    //Se o codigo de entrada não for vazio e o informado for
    if (codigo == "")
    {
      return "O SERVIDOR REQUER CODIGO DE CONVITE";
    }

    //Se o codigo for incorreto
    if (codigo != it2->getCodigoConvite())
    {
      return "O CODIGO DE CONVITE INFORMADO EH INCORRETO";
    }

    //Se o codigo for correto loga no servidor
    if (codigo == it2->getCodigoConvite())
    {
      //Adiciona à lista de participantes do servidor
      it2->setParticipantesIDs(id);
      //Salva que está visualizando o servidor
      usuariosLogados[id].first = nome;
      return "ENTROU NO SERVIDOR COM SUCESSO";
    }
  }
  return "";
}

string Sistema::leave_server(int id, const string nome)
{
//Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL SAIR DO SERVIDOR, POIS O USUARIO NAO ESTA LOGADO";
  } 

  string servidorVisualizado = usuariosLogados[id].first;

  //Checa se o usuário está em algum servidor
  if(servidorVisualizado == ""){
    return "VOCE NAO ENTROU EM NENHUM SERVIDOR";
  }

  //Procura o servidor
  vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(servidorVisualizado));
  if( it2 == servidores.end() ){
    return "SERVIDOR '" + servidorVisualizado + "' NAO EXISTE";
  }

  //Checa se o usuário está no servidor
  //Não está
  if (!(it2->buscaUsuarioServidor(id)))
  {
    return "VOCE NAO ESTA NO SERVIDOR";
  }
  //Está
  else
  {
    //Para de visualizar o servidor
    usuariosLogados[id].first = "";
    //Para de visualizar um canal(se tiver)
    usuariosLogados[id].second = "";
    //tira da lista do servidor
    it2->removeParticipante(id);
    return "SAINDO DO SERVIDOR '" + nome + "'";
  }
  return "";
}

string Sistema::list_participants(int id)
{
  std::string stringRetorno = "#Lista de participantes\n";

  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL LISTAR PARTICIPANTES, POIS O USUARIO NAO ESTA LOGADO";
  }

  //Checa qual servidor o usuário está visualuzando
  std::string servidorVisualizado = usuariosLogados[id].first;
  if (servidorVisualizado == "")
  {
    return "O USUARIO NAO ESTA VISUALUZANDO NENHUM SERVIDOR";
  }
  else
  {
    //Acha o servidor
    vector<Servidor>::iterator it2;
    for (it2 = servidores.begin(); it2 != servidores.end(); it2++)
    {
      if (it2->getNomeServidor() == servidorVisualizado)
      {
        //Servidor achado
        //Busca o vetor de usuarios
        vector<int> idDosUsuarios = it2->getIdUsuarios();
        //Compara com a lista de usuários no sistema e printa
        for (vector<int>::iterator it3 = idDosUsuarios.begin(); it3 != idDosUsuarios.end(); it3++)
        {
          for (vector<Usuario>::iterator it4 = usuarios.begin(); it4 != usuarios.end(); it4++)
          {
            if ( *(it3) == it4->getid() )
            {
              stringRetorno += it4->getNomeUsuario() + "\n";
            }
          }
        }

        if(stringRetorno != "#Lista de participantes\n"){
          return stringRetorno;
        }
      }
    }
      return "SERVIDOR '" + servidorVisualizado + "' INEXISTENTE" ;
  }
}

string Sistema::list_channels(int id)
{
 //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL LISTAR OS CANAIS, POIS O USUARIO NAO ESTA LOGADO";
  }


  //Pega o servidor que está sendo visualizado pelo usuário
  string servidorVisualizado = usuariosLogados[id].first;
  //Se não estiver visualizando qualquer servidor
  if( servidorVisualizado == "" ){
    return "VOCE NAO ESTA VISUALIZANDO NENHUM SERVIDOR";
  } 
  //Se estiver visualizando um servidor
  else{
    //Procura o servidor
    vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(servidorVisualizado));
    if( it2 == servidores.end() ){
      return "SERVIDOR '" + servidorVisualizado + "' NAO EXISTE";
    }

    //Busca e retorna os nomes dos canais
      return it2->getNomesCanaisServidor();
  }
}

string Sistema::create_channel(int id, const string nome)
{
//Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL LISTAR OS SERVIDORES, POIS O USUARIO NAO ESTA LOGADO";
  }


//Checa o servidor que o usuário está visualizando
  string servidorVisualizado = usuariosLogados[id].first;
  //Se estiver visualizando algum servidor
  if( servidorVisualizado != "" ){  
    //Pega o endereço do servidor
      vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(servidorVisualizado));
      if( it2 == servidores.end() ){
        return "SERVIDOR '" + servidorVisualizado + "' NAO EXISTE";
      }

    //Checa se já existe um canal de texto
      //Existe
      if( it2->checaExisteCanalTexto(nome) ){
        return "CANAL DE TEXTO '" + nome + "' JA EXISTE" ;
      }
      
      //Não existe
      else{
      //Cria o canal
        CanalTexto *canal = new CanalTexto(nome);
        //Adiciona o canal
        it2->adicionaCanal( *(canal) );
        delete canal;
        return "CANAL DE TEXTO '" + nome + "' CRIADO";
      }
  }
  //Se não estiver visualizando algum servidor
  else{
    return "ENTRE EM UM SERVIDOR PARA PODER CRIAR UM CANAL";
  }
  
  return "";
}

string Sistema::enter_channel(int id, const string nome)
{
//Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL ENTRAR NO CANAL, POIS O USUARIO NAO ESTA LOGADO";
  }


//Checa o servidor que o usuário está visualizando
  string servidorVisualizado = usuariosLogados[id].first;
  //Se estiver visualizando algum servidor
  if( servidorVisualizado != "" ){  
      
    //Pega o endereço do servidor
      vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(servidorVisualizado));
      if( it2 == servidores.end() ){
        return "SERVIDOR '" + servidorVisualizado + "' NAO EXISTE";
      }

    //Checa se o canal de texto existe
      //Existe
      if( it2->checaExisteCanalTexto(nome) ){
        //Usuario entra no canal
        usuariosLogados[id].second = nome;
        return "ENTROU NO CANAL '" + nome + "'";
      }
      //Não existe
      else{
        return "CANAL '" + nome + "' INEXISTENTE" ;
      }
  }
  //Se não estiver visualizando algum servidor
  else{
    return "ENTRE EM UM SERVIDOR PARA PODER ENTRAR EM UM CANAL";
  }
 
}

string Sistema::leave_channel(int id)
{
//Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL SAIR DO CANAL, POIS O USUARIO NAO ESTA LOGADO";
  }


//Sai do canal
 //Checa o servidor e o canal que o usuário está visualizando 
  string servidorVisualizado = usuariosLogados[id].first;
  string canalVisualizado = usuariosLogados[id].second;
  //Se estiver visualizando algum servidor e algum canal de texto
  if( servidorVisualizado != "" and canalVisualizado != "" ){  
      //Pega o endereço do servidor
      vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(servidorVisualizado));
      if( it2 == servidores.end() ){
        return "SERVIDOR '" + servidorVisualizado + "' NAO EXISTE";
      }

    //Checa se o canal de texto existe
      //Existe
      if( it2->checaExisteCanalTexto(canalVisualizado) ){
        //Usuario entra no canal
        usuariosLogados[id].second = "";
        return "SAIU DO CANAL '" + canalVisualizado + "'";
      }
      //Não existe
      else{
        return "CANAL '" + canalVisualizado +  "' INEXISTENTE";
      }
  }
  //Se não estiver visualizando algum servidor ou canal de texto
  else{
    return "VOCE NAO ESTA DENTRO DE UM SERVIDOR OU CANAL DE TEXTO PARA SAIR";
  }
}

string Sistema::send_message(int id, const string mensagem)
{
  //Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL ENVIAR MENSAGEM, POIS O USUARIO NAO ESTA LOGADO";
  }

  //Pega o canal e o servidor que o usuário está
  string canal = usuariosLogados[id].second;
  string servidor = usuariosLogados[id].first;
  
  if( servidor == "" ){
    return "USUARIO NAO ENTROU EM QUALQUER SERVIDOR";
  }
  if( canal == "" ){
    return "USUARIO NAO ESTA EM QUALQUER CANAL";
  }
  
  //Pega o endereço do servidor
  vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(servidor));
  if( it2 == servidores.end() ){
    return "SERVIDOR '" + servidor + "' NAO EXISTE";
  }

  return it2->adicionaMensagem(id, mensagem, canal);
}

string Sistema::list_messages(int id)
{
//Checa se o usuário existe
  if (!checaUsuarioExiste(id))
  {
    return "USUARIO INEXISTENTE";
  }

  //Checa se o usuário está logado
  map<int, pair<string, string> >::iterator it = usuariosLogados.find(id);
  if( it == usuariosLogados.end() ){
    return "NAO FOI POSSIVEL LISTAR AS MENSAGENS, POIS O USUARIO NAO ESTA LOGADO";
  }

  //Pega o canal e o servidor que o usuário está
  string servidor = usuariosLogados[id].first;
  string canal = usuariosLogados[id].second;
  
  if( servidor == "" ){
    return "USUARIO NAO ENTROU EM QUALQUER SERVIDOR";
  }
  if( canal == "" ){
    return "USUARIO NAO ESTA EM QUALQUER CANAL";
  }
  
  //Pega o endereço do servidor
  vector<Servidor>::iterator it2 = find_if( servidores.begin(), servidores.end(), checaServidorExistePredicate(servidor));
  if( it2 == servidores.end() ){
    return "SERVIDOR '" + servidor + "' NAO EXISTE";
  }

  return it2->listaMensagens(canal, usuarios);
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
