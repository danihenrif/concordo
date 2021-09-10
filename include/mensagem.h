#include <iostream>

class Mensagem{
    private:
        std::string dataHora;
        int enviadaPor;
        std::string conteudo;
    
    public:
        Mensagem();
        Mensagem(std::string dataHora, int id, std::string mensagem);
        ~Mensagem();
        
        //Getters
        std::string getDataHora();
        std::string getConteudo();
        int getEnviadoPor();
};

