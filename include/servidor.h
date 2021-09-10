#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
using std::string;
#include <vector>
using std::vector;
#include <iterator>

#include "canaltexto.h"


class Servidor{
	private:
		int usuarioDonold; //Id do usuário que criou o servidor
		string nomeServidor;
		string descricaoServidor;
		string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesIDs;
	public:
		//Construtores e destrutores
		Servidor();
		Servidor(int id, string nome);
		~Servidor();

		/*! Setter para a descrição do servidor
			@param descricao a nova descrição
		*/
		void setDescricaoServidor(string descricao);

		/*! Setter para o código de convite do servidor
			@param codigo o novo código de convite
		*/
		void setCodigoConviteServidor(string codigo);

		/*! Setter para a lista de participantes do servidor
			@param codigo o novo código de convite
		*/
		void setParticipantesIDs(int id);

		
		/*! Getter para o nome do servidor*/
		string getNomeServidor();

		/*! Getter para o dono do servidor*/
		int getUsuarioDonold();

		/*! Getter para o código de convite*/
		string getCodigoConvite();

		/*! Getter para os IDs dos usuários*/
		std::vector<int> getIdUsuarios();

		/*! Getter para a lista de canais do servidor*/
		string getNomesCanaisServidor();

		
		/*! Checa se um determinado usuário está no servidor
			@param id do usuário procurado
			@return true usuário está no servidor
			@return false usuário não está no servidor 
		*/
		bool buscaUsuarioServidor(int id);

		/*! Remove um usuário do servidor
			@param id do usuário a ser removido
		*/
		void removeParticipante(int id);

		/*! Checa se um canal de texto existe
			@param nome do canal de texto
			@return true se o canal de texto existe
			@return false se o canal de texto não existe
		*/
		bool checaExisteCanalTexto( string nome );
		
		/*! Adiciona um canal de texto ao servidor
			@param canal nome  do canal de texto
		*/
		void adicionaCanal( CanalTexto canal );

		/*! Adiciona uma mensagem em um canal.
			@param id do usuário
			@param canal em que a mensagem será adicionada
			@param mensagem a ser adicionada
			@return string com mensagem de retorno
		*/

		string adicionaMensagem(int id, string canal, string mensagem);

		/*! Lista as mensagens de um canal
			@param canal em as mensagens serão lsitadas
			@param vector<Usuario> &vetorUsuarios o vetor de usuários do sistema para pegar os nomes dos usuários
			@return string com mensagem de retorno
		*/
		string listaMensagens(string canal, vector<Usuario> &vetorUsuarios);

};

#endif
