# Concordo 
<h2>Bem vindo ao Concordo, um clone do Discord para humanos mais civilizados :D</h2>

<h3> by Daniel Henriques</h3>
<br>

## Instalando e executando
<br>
Com o terminal aberto no diretório em que deseja colocar os arquivos, digite:

```console
$ git clone https://github.com/danihenrif/concordo.git
```
Entre no diretório :
```console
$ cd trabalho-02-danihenrif
```
Crie a pasta build (para onde vão os arquivos objetos) com:
```console
$ mkdir build
```
Compile digitando:
```console
$ make
```
Se for "rodar na mão" basta executar digitando:
```console
$ build/concordo
```
Se for rodar com um arquivo .txt, digite :
```console
$ build/concordo < data/"nome do arquivo.txt"
``` 

É importante ressaltar que executando com o arquivo .txt será exposto no terminal apenas a resposta do programa aos comandos.
<br>

# Usar o arquivo txt

Para usar o arquivo txt você poderá criar um novo arquivo na pasta data ou editar os arquivos existentes. É importante saber que deve ser usado apenas um coma              ndo dos descritos a seguir por linha. Ex:
```console
create-user danielhrqs4@yahoo.com senhacorreta daniel henriques
create-user danielhrqs4@yahoo.com senhacorreta daniel henriques
login danielhrqs4@yahoo.com senhaincorreta
login danielhrqs4@yahoo.com.br senhacorreta
login danielhrqs4@yahoo.com senhacorreta
disconnect 2
disconnect 1
disconnect 1
create-server 2 naovaidarpracriar :C
create-server 1 galera-do-counter-strike
login danielhrqs4@yahoo.com senhacorreta
create-server 1 galera-do-counter-strike
create-server 1 galera-do-counter-strike
create-user rafael@yahoo.com senhacorreta rafael cabral
login rafael@yahoo.com senhacorreta
set-server-desc 3 galera-do-counter-strike TAQUINHO É O MAIOR JOGADOR DE CS DO NORDESTE
set-server-desc 2 galera-do-counter-strike TAQUINHO É O MAIOR JOGADOR DE CS DO NORDESTE
set-server-desc 1 galera-do-counter-strike TAQUINHO É O MAIOR JOGADOR DE CS DO NORDESTE
set-server-desc 1 servidor frase qualquer
set-server-invite-code 3 galera-do-counter-strike counterstrike.com
set-server-invite-code 2 galera-do-counter-strike counterstrike.com
set-server-invite-code 1 galera-do-counter-strike counterstrike.com
create-server 2 valorant
create-server 2 ead
create-server 2 liga-das-lendas
create-server 6 cod
list-servers 3
list-servers 2
list-servers 1
```

```console
USUARIO CADASTRADO COM SUCESSO!
JA EXISTE UMA CONTA COM ESSE EMAIL!
SENHA OU USUARIO INVALIDOS!
SENHA OU USUARIO INVALIDOS!
LOGADO COMO danielhrqs4@yahoo.com
USUARIO INEXISTENTE
USUARIO danielhrqs4@yahoo.com DESCONECTADO
NAO FOI POSSIVEL DESCONECTAR, POIS O USUARIO NAO ESTA LOGADO
USUARIO INEXISTENTE
NAO FOI POSSIVEL CRIAR O SERVIDOR, POIS O USUARIO NAO ESTA LOGADO
LOGADO COMO danielhrqs4@yahoo.com
SERVIDOR CRIADO
JA EXISTE UM SERVIDOR COM ESSE NOME
USUARIO CADASTRADO COM SUCESSO!
LOGADO COMO rafael@yahoo.com
USUARIO INEXISTENTE
VOCE NAO PODE ALTERAR A DESCRICAO DE UM SERVIDOR QUE NAO FOI CRIADO POR VOCE
DESCRICAO DO SERVIDOR 'galera-do-counter-strike' MODIFICADA
SERVIDOR 'servidor' NAO EXISTE
USUARIO INEXISTENTE
VOCE NAO PODE ALTERAR O CODIGO DE CONVITE DE UM SERVIDOR QUE NAO FOI CRIADO POR VOCE
CODIGO DE CONVITE DO SERVIDOR 'galera-do-counter-strike' MODIFICADO
SERVIDOR CRIADO
SERVIDOR CRIADO
SERVIDOR CRIADO
USUARIO INEXISTENTE
USUARIO INEXISTENTE
galera-do-counter-strike
valorant
ead
liga-das-lendas

galera-do-counter-strike
valorant
ead
liga-das-lendas
```

# Funcionalidades do Concordo

<span style="color:#ff4040">ERROS COMUNS:</span>
<br>

Utilizar qualquer um dos comandos com um conta inexistente ou conta existente mas que não está logada :
<br>
```console
<disconnect> <create-server> <set-server-invite-code> <list-servers> <remove-server> <enter-server> 
<leave-server> <list-participantes> 
```
Serão apresentadas mensagens de erro caso sejam usados tais comandos com as condições apresentadas.
<br>
<h2> Como usar cada comando ?</h2><br>

<h2> Sair do sistema </h2>

```console
quit

“Saindo do Concordo”

```

<h2> Criar usuário </h2>

```console
$   create-user <email> <senha> <nome>

ex: create-user danielhrqs4@yahoo.com 123456 Daniel Henriques

ex: create-user auxiliar@hotmail.com 123 Penicilino da Silva

ex: create-user auxiliar2@hotmail.com 123 Parecetamol dos Santos
```
<span style="color:green">OPERAÇÃO BEM SUCEDIDA:</span>
<br>
Você receberá a seguinte mensagem de retorno no terminal :
```console
USUARIO CADASTRADO COM SUCESSO!
```

<span style="color:#ff4040">ERRO:</span>
<br>
Registrar uma conta com um email já cadastrado.
Você receberá a seguinte mensagem de retorno no terminal :
```console
JA EXISTE UMA CONTA COM ESSE EMAIL!
```

<h2> Entrar no sistema </h2>

```console
    login <email> <senha>

ex: login danielhrqs4@yahoo.com 123456 
    "LOGADO COMO danielhrqs4@yahoo.com"

ex: login danielhrqs4@yahoo.com senhaerrada
    "SENHA OU USUARIO INVALIDOS!"

ex: login danielhrqs4@HOTMAIL.com 123456
    "SENHA OU USUARIO INVALIDOS!"

ex: login auxiliar@hotmail.com 123
    "LOGADO COMO auxiliar@hotmail.com"

ex: auxiliar2@hotmail.com 123
    "LOGADO COMO auxiliar2@hotmail.com"
```

<h2> Desconectar do Concordo </h2>

```console
    disconnect <id>

    disconnect 1 
    “USUARIO danielhrqs4@yahoo.com DESCONECTADO”
    disconnect 1
    “NAO FOI POSSIVEL DESCONECTAR, POIS O USUARIO NAO ESTA LOGADO"
```

<h2> Criar servidores </h2>

```console
    create-server <id> <nome-do-servidor>

    create-server 1 counter-strike
    "SERVIDOR CRIADO"

    create-server 1 counter-strike
    "JA EXISTE UM SERVIDOR COM ESSE NOME"
    
    create-server 2 valorant
    "SERVIDOR CRIADO"

    create-server 2 lol
    "SERVIDOR CRIADO"

    create-server 2 dota
    "SERVIDOR CRIADO"
```

<h2> Mudar a descrição do servidor </h2>

Somente o dono do servidor (criador) poderá alterar a descrição

```console
    set-server-desc <id> <nome-do-servidor> <descricao-do-servidor>

    set-server-desc 1 counter-strike "Esse servidor é para pessoas que jogam cs"
    "DESCRICAO DO SERVIDOR counter-strike MODIFICADA"

    set-server-desc 2 counter-strike "Não vai dar certo :C"
    "VOCE NAO PODE ALTERAR A DESCRICAO DE UM SERVIDOR QUE NAO FOI CRIADO POR VOCE"
```

<h2> Setar código de convite para o servidor </h2>

Somente o dono do servidor (criador) poderá alterar o código de convite

```console
    set-server-invite-code <id> <nome-do-servidor> <codigo-de-convite>

    set-server-invite-code 1 counter-strike codigocorreto
    "CODIGO DE CONVITE DO SERVIDOR counter-strike MODIFICADO"
    
    set-server-invite-code 1 counter-strike 
    "CODIGO DE CONVITE DO SERVIDOR counter-strike REMOVIDO"

    set-server-invite-code 2 counter-strike 
    "VOCE NAO PODE ALTERAR O CODIGO DE CONVITE DE UM SERVIDOR QUE NAO FOI CRIADO POR VOCE"
```

<h2> Listar servidores </h2>

Se não houver servidores cadastrados no sistema será avisado.<br>
Qualquer usuário logado pode listar os servidores do sistema.

```console
    list-servers <id>
    
    list-servers 1
    
    "counter-strike
     valorant
     lol
     dota          "
```

<h2> Remover servidor </h2>

Se não houver servidores cadastrados no sistema será avisado.<br>

```console
    remove-server <id> <nome-do-servidor>

    remove-server 1 valorant
    "VOCE NAO EH DONO DO SERVIDOR"
    
    remove-server 2 valorant
    "SERVIDOR 'valorant' REMOVIDO"

    remove-server 1 ead
    "SERVIDOR ead NAO EXISTE"

    se a os servidores forem listados novamente, aparecerá :
    list-servers 1
    
    "counter-strike
     lol
     dota    "
```

<h2> Entrar em um servidor </h2>
O dono do servidor pode entrar sem o código de convite.
Se o servidor não tiver código de convite qualquer usuário pode entrar.

```console
    enter-server <id> <nome-do-servidor>

    enter-server 1 counter-strike
    "ENTROU NO SERVIDOR COM SUCESSO"
    
    enter-server 1 counter-strike
    "VOCE JA ESTA NO SERVIDOR"

    enter-server 1 valorant
    "ENTROU NO SERVIDOR COM SUCESSO"

    enter-server 2 counter-strike
    "O SERVIDOR REQUER CODIGO DE CONVITE"

    enter-server 2 counter-strike codigoerrado
    "O CODIGO DE CONVITE INFORMADO EH INCORRETO"

    enter-server 2 counter-strike codigocorreto
    "ENTROU NO SERVIDOR COM SUCESSO"
```

<h2> Sair do servidor </h2>


```console
    leave-server <id> <nome-do-servidor>
    
    leave-server 3 counter-strike
    "VOCE NAO ESTA NO SERVIDOR"

    leave-server 2 counter-strike 
    "SAINDO DO SERVIDOR 'counter-strike'"
```

<h2>  Listar pessoas no servidor </h2>

Apeas os usuários que estão no servidor poderão listar.
```console
    list-participants <id> <nome-do-servidor>
    
    enter-server 3 counter-strike codigocorreto
    "ENTROU NO SERVIDOR COM SUCESSO"
    
    list-participants 1 counter-strike
    "Daniel Henriques
     Paracetamol dos Santos
    "
```


<h2>  Criar um canal do servidor  </h2>
Qualquer usuario que estiver visualizando o servidor pode criar um canal.

```console
    create-channel <id> <nome-do-canal>

    create-channel 1 canal1
    "CANAL DE TEXTO 'canal1' CRIADO"

    create-channel 1 canal2
    "CANAL DE TEXTO 'canal2' CRIADO"

    create-channel 1 canal3
    "CANAL DE TEXTO 'canal3' CRIADO"
    
    create-channel 1 'canal1' JA EXISTE
    list-channels
```

<h2>  Entrar em um canal  </h2>
Só pode entrar em um canal se já estiver no servidor.

```console
    enter-channel <id> 

    enter-channel 1 canal1
    "ENTROU NO CANAL 'canal1'"
    
    enter-channel 1 'naoexiste'
    "CANAL 'naoexiste' INEXISTENTE" 
    list-channels
```

<h2>  Sair de um canal  </h2>
Só poderá sair de um canal se estiver no canal.

```console
    leave-channel <id> 

    leave-channel 1 
    "SAIU DO CANAL 'canal1'"
    
    leave-channel 1 naoexiste
    "CANAL 'naoexiste' INEXISTENTE" 
    list-channels
```

<h2>  Listar canais do servidor </h2>

Apenas os usuários que estão visualizando o servidor(enter-server) poderão listar.
```console
    list-channels <id> 
    
    list-channels 1
    #canais de texto
    canal1
    canal2
    canal3


    list-channels 2
    "VOCE NAO ESTA VISUALIZANDO O SERVIDOR"
```

<h2>  Enviar mensagem para o canal </h2>

Apenas os usuários que estão visualizando o servidor(enter-server) poderão mandar.
```console
    send-message 1 <id> <mensagem> 
    
    send-message 1 Oi galera
    "MENSAGEM ADICIONADA EM 'canal1'"

```

<h2>  Visualizar mensagens do canal </h2>

Apenas os usuários que estão visualizando o servidor(enter-server) poderão visualizar.
```console
    list-messages <1> 
    
    list-messages 1 
    " 
      #MENSAGENS DO CANAL 'canal 1'
      Daniel Henriques <Sun Jul 25 19:54:16 2021>: Oi galera  
    "

```
