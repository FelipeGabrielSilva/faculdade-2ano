/*
  método setup() = método (função) de inicialização
    no projeto (códgio) de Arduino

  executado uma única vez a cada nova alimentação
    ou ao pressionar o botão "reset" (na placa)
*/

void setup() {
  /*
    Serial (classe) e begin (método): 9600 (baud rate)
    baud rate (eletrônica) = velocidade de comunicação COM

    Serial = meio de input e output de dados
      input (entrada de dados da COM)
      output (saída ou escrita de dados da COM)
  */
  Serial.begin(9600);

  /*
    Serial.println = método de impressão (saída de dados)
      enviar uma String para a COM
  */
  Serial.println("Arduino inicializado!...");

  /*
    definindo que a porta digital 13 é um componente de saída
    método pinMode = configura o comportamento das portas digitais
  */
  pinMode(13, OUTPUT);

  /*
    método digitalWrite = exrita digital (0 e 1) na porta 13
    const LOW = led desliga (tensão = 0v)
    const HIGH = led ligado (tensão = 5v)
  */
  digitalWrite(13, HIGH);

}

/*
  método loop() = método responsável pela execução
    ou iteração enquanto houver alimentação
*/
void loop() {
  Serial.println("Em execução...");
  /*
    método delay = expera X milisegundo na execução do loop
      1000 milisegundo = 1 segundo
  */
  acender();
  apagar();
}

void acender() {
   Serial.println("Led acesso...");
  digitalWrite(13, HIGH);
  delay(250);
}

void apagar() {
   Serial.println("Led apagado...");
  digitalWrite(13, LOW);
  delay(250);
}
