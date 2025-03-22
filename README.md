## Tarefas 
    - Configurar BT_A e BT_B
    - Configurar Display OLED

    - Definir Struct de escolha
        - Duas escolhas e Um ponteiro para a próxima escolha

    - Definir lista de histórico de escolhas do jogador -> MAX = 4;

    - Configurar fluxo de jogo
        1. Jogador inicia na Escolha1 e opta por Escolha1->opcA ou Escolha1->opcB  com os botões
        2. Após a escolha, ele passa para Escolha1->proxEsc
        3. Após 0,5 segundos os textos das escolhas de Escolha2 são exibidos
        4. Repete o fluxo até a Escolha4
        5. Após a escolha da Escolha4, o jogador é direcionado para ver a tela do serial monitor e ver o histórico de escolhas
        6. Após 5 segundos, o jogo é reiniciado