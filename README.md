Leitura da posição do joystick

Este projeto tem como objetivo monitorar a posição de um joystick conectado a uma placa BitDogLab, enviando os dados de coordenadas (X, Y) e a direção detectada para um servidor web construído com Express TS.
O servidor exibe os dados em tempo real por meio de uma página HTML simples, atualizada automaticamente.


🔧 Como funciona
A Placa lê os valores analógicos do joystick  lê os valores analógicos do joystick
e determina a direção com base nas coordenadas X e Y, podendo identificar até nove direções distintas: Centro, Norte, Sul, Leste, Oeste, Nordeste, Noroeste, Sudeste e Sudoeste.

A cada nova leitura, ele envia uma requisição POST com os dados para o servidor  na rota /posicao.

O servidor armazena os últimos valores recebidos.

A rota principal (/) exibe a posição X, Y e a direção em uma página HTML que é recarregada automaticamente a cada segundo para mostrar os dados mais recentes.
