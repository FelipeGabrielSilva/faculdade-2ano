#define LED_9 9
#define LED_10 10
#define LED_11 11

void setup() {
  Serial.begin(9600);
  Serial.println("Jarvis desperte...");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_11, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_11, LOW);
}

void loop() {
  if(Serial.available()){

    String data = Serial.readString();
    data.trim();

    Serial.println("----------------------------------------");

    boolean acender = data.equalsIgnoreCase("acender");
    boolean apagar = data.equalsIgnoreCase("apagar");
    boolean animar = data.equalsIgnoreCase("animar");
    boolean parar = data.equalsIgnoreCase("parar");

    int qtd = data.length();
    int posicao = data.indexOf(":");
    int ultPosicao = data.lastIndexOf(data);    

    boolean pos = posicao != -1; 

    if(posicao != -1 && data.substring(posicao + 1) ) {
     acenderLed(pos);
    }

    if(acender) acenderLed(pos);

    if(apagar) apagarLed(pos);

    if(animar) discoteca();
  }
}

void acenderLed(boolean x){
  Serial.println("Acendendo as luzes senhor");
  delay(500);
  
  if(x) digitalWrite(LED_BUILTIN, HIGH);
  else digitalWrite(LED_11, HIGH); 
}

void apagarLed(boolean x){
  Serial.println("Apagando as luzes senhor");
  delay(500);
  if(x) digitalWrite(LED_BUILTIN, LOW);
  else digitalWrite(LED_11, LOW);
}

void discoteca() {
  Serial.println("Modo discoteca ativado");
  delay(500);

  int minDuration = 50; 
  int maxDuration = 500; 
  
  while (true) {
    int randomLED = random(1, 5);
      
    switch (randomLED) {
      case 1:
        digitalWrite(LED_9, HIGH);
        break;
      case 2:
        digitalWrite(LED_10, HIGH);
        break;
      case 3:
        digitalWrite(LED_11, HIGH);
        break;
      case 4:
        digitalWrite(LED_BUILTIN, HIGH);
        break;
    }
  
    delay(random(minDuration, maxDuration));
      
    digitalWrite(LED_9, LOW);
    digitalWrite(LED_10, LOW);
    digitalWrite(LED_11, LOW);
    digitalWrite(LED_BUILTIN, LOW);      
    delay(random(minDuration, maxDuration));
  }
}
