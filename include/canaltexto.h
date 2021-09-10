#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <iostream>
using std::string;
#include <vector>
using std::vector;

#include "mensagem.h"
#include "usuario.h"

class CanalTexto{
	private:
		std::string nomeCanalTexto;
		std::vector<Mensagem> mensagens; 

	public:
		//Construtores e destrutores
		CanalTexto();
		CanalTexto( string nome );
		~CanalTexto();
		
		/*!	Getter para o nome do canal de texto.*/
		std::string getNomeCanalTexto();

		/*!	Adiciona mensagem no canal de texto.
			@param mensagem a mensagem a ser adicionada.
		*/
		std::string addMensagem( Mensagem mensagem);

		/*!	Lista as mensagens do canal de texto
			@param vetorUsuarios um vetor contendo os objetos usuários para comparar o id e printar o nome
		*/
		std::string listMensagens( vector<Usuario> &vetorUsuarios);

};


#endif
