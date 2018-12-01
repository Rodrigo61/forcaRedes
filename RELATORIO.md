# Relatório do Projeto

# Arquitetura
O projeto é desenvolvido sobre uma arquitetura de camadas com 3 divisões

* O cliente: responsável pela comunicação entre usuário final e servidor
* O servidor: responsável por trasmitir mensagens entre o cliente e o 
controlador de jogo
* O controlador de jogo: responsável por manter o estado do jogo atualizado
de acordo com as regras e as mensagens recebidas do servidor

Além disso, o servidor tem a responsabilidade de manter dados sobre
os jogadores conectados e partidas jogadas, conceitualmente, uma 
entidade *JOGADOR* é que é a responsável por repassar mensages de atualização
de estado de jogo para o controlador.

# As mensagens
Foi desenvolvida uma classe de protocolo para auxiliar a criação e
processamento das mensagens trocadas entre cliente e servidor.
Cada mensagem é composta de duas partes: um bytecode e a mensagem em si
cada mensagem é transmitida como um string na qual o primeiro byte indica
qual o tipo de mensagem, esse bytecode é usado para encaminhar a mensagem
para o tratamento adequado, depois desse bytecode, o resto da string
é a mensagem em si.

# Modelo Requisição-Resposta
Para o modo de partida simples, escolhemos o modelo requisição-resposta
por sua simplicidade de implementação e também levando em consideração
que a interface utilizada (terminal) só é atualizada quando o usuário interage
com o programa, assim, não faria sentido o servidor enviar múltiplas mensagens
já a tela não seria atualizada.
