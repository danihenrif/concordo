#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using std::string;

class Usuario{
	private:
		int id;
		string nomeUsuario;
		string email;
		string senha;
	public:
		//Construtores e destrutores
		Usuario();
		Usuario( string email, string senha, string nome, int id );
		~Usuario();

		/*! Setter para o id do usuário
			@param id do usuário
		*/		
		void setid( int id );

		/*! Setter para o email do usuário
			@param email do usuário
		*/	
		void setEmail( string email);

		/*! Setter para o nome do usuário
			@param id do usuário
		*/	
		void setNomeUsuario( string nome);

		/*! Setter para a senha do usuário
			@param senha do usuário
		*/	
		void setSenha( string senha);

		
		
		/*! Getter para o id do usuário
			@param id do usuário
		*/	
		int getid();

		/*! Setter para o email do usuário
			@param email do usuário
		*/
		string getEmail();

		/*! Setter para o nome do usuário
			@param id do usuário
		*/	
		string getNomeUsuario();

		/*! Setter para a senha do usuário
			@param senha do usuário
		*/	
		string getSenha();


};

#endif
