#define  LED_11 11

void setup() {
  Serial.begin(9600);
  Serial.println("Jarvis Acorde...");
  pinMode(LED_BUILTIN, OUTPUT); //constante porta digital 13
  pinMode(LED_11, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_11, LOW );
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readString();

    data.trim();
    Serial.println("----------");
    Serial.println("Dado recebido...: " + data);

    /*startsWith = retorna true se a String começa com o valor de outra String (param)*/
    boolean comecaCom = data.startsWith("c"); // computador | algoritmos    
    Serial.println("startsWith...: " + String(comecaCom));

    //endsWith = retorna true se a String termina com o valor de outra String (param)
    boolean terminaCom = data.endsWith("r"); // computador | algoritmos    
    Serial.println("endsWith.....: " + String(terminaCom));

    //equals = retorna true somente se as Strings forem iguais
    boolean acendeLed = data.equalsIgnoreCase("acender"); //ACENDER
    boolean apagaLed = data.equalsIgnoreCase("apagar"); //APAGAR

    Serial.println("acendeLed....: " + String(acendeLed));
    Serial.println("apagaLed.....: " + String(apagaLed));

    if(acendeLed) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (apagaLed) {
      digitalWrite(LED_BUILTIN, LOW);
    }

    // retorna um inteiro (sem sinal) com a quantidade de caracteres na String
    int qtdeCaracteres = data.length();
    Serial.println("qtdeCaracteres...: " + String(qtdeCaracteres));

    // contais = retornar true se uma String está contida (exista) em outra
    // retorna um inteiro com a posição onde a String (param) foi encontrada
    //  retornar -1 se não encontrar
    int posicao = data.indexOf("o"); //computador (1) | algoritmos (3)
    Serial.println("posicao..........: " + String(posicao));

    int ultimaPosicao = data.lastIndexOf("o"); // computador (8) | algoritmos (8)
    Serial.println("ultimaPosicao....: " + String(ultimaPosicao));

    String pedacoString = data.substring(2, 6);
    Serial.println("pedacoString.....: " + pedacoString); // mput | gori

    String novaString = String(data);
    novaString.replace("o", "O");
    Serial.println("novaString.......:" + novaString);

    int inteiro = data.toInt();
    float flutuante = data.toFloat();
    Serial.println("inteiro..........: " + String(inteiro));
    Serial.println("flutuante........: " + String(flutuante));
    data.toUpperCase();
    data.toLowerCase();
    String maiusculas = data;
    String minusculas = data;
    Serial.println(maiusculas + " - " + minusculas);

    Serial.println("----------");
  }
  delay(500);
}
