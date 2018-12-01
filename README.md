# Projeto Final MC 833
- Rodrigo Amaral Franscechinelli : 170630
- Victor Gasparotto Capone : 177952

# Compilando o projeto
Para compilar o projeto vá até a pasta raiz deste diretório
e execute: ```make clean && make```, serão gerados dois executáveis:client e server

# Executando o servidor
Para excutar o servidor, use o comando: ```./server <porta> <arquivo_de_dicionario>```
o servidor vai escutar por conexões na <porta> e vai ler as palavras do <arquivo_de_dicionario> para montar seu dicionario.

# Executando o cliente
Para executar o cliente, use o comando: ```./client <servidor> <porta>```
onde <servidor> é o endereço ip do sevidor que está escutando na <porta>
 
# Como jogar
Ao se conectar com o servidor, o cliente exibirá o menu principal

1. Iniciar partida simples
2. Ser carrasco ao iniciar partida
3. jogar no modo multiplayer

O jogador deve digitar uma das opções correspondentes e pressionar ENTER

# A Partida Simples
Na partida simples, o jogador deve adivinhar uma palavra escolhida pelo servidor
para isso ele tenta adivinhar uma letra por vez, sendo que a cada tentativa
correta, o servidor indica em qual posição da palavra aquela letra se encontra
(se houver repetições, todas são reveladas) e a cada tentativa errada o jogador
perde uma vida, o jogo acaba quando o jogador descobrir a palavra ou perder todas
as 6 vidas, o jogador tenta adicinhar uma letra digitando-a e pressionando ENTER,
o jogador pode tentar adicinhar a palavra inteira de uma vez, mas se errar perde o jogo
imediatamente. O jogador também é penalizado se tentar um caracter inválido. A pontuação
do jogador é armazenada no servidor.
