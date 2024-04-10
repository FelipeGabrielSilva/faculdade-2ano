void setup(){
  Serial.begin(9600);
  Serial.println(("Inicializando o arduino..."));
}

void loop(){
  /* 
    Seriak.available = retorna true se existirem dados a serem lidos
      pela porta USB (porta Serial/COM)
   */

   if(Serial.available()){
    /*  
    data = dados/valores
    readString = receber/lê os dados enviados à porta serial/COM como string
     */
    String data = Serial.readString();

    //toFloat() = converte uma String para Float (decimal/flutuante) | toInt()
    float number = data.toFloat();
    number = number * 2;

    Serial.println(number);
   }

}
