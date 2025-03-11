/** Button test for FDD EMU

*/

#define ANALOG_PIN A7
#define BOUD 115200



const char* line = "Sum: %6i | count: ";
long sum = 0;
long counter =0;
long outputDelay =100;
long currentTS = 0;
char buf [100];



void setup() {
  Serial.begin(BOUD);

}



void loop() {
  
  int value = analogRead(ANALOG_PIN);
  //Serial.println(value);
  sum += value;
  counter ++;
  long ts = millis();
  if((currentTS + outputDelay) < ts){

      int average = sum/counter;
      float volt = ((float)average)*0.00488f;
      sprintf(buf, line,sum);
      Serial.print(buf);
      Serial.print(counter);
      Serial.print("| av: ");
      Serial.print(average);
      Serial.print("| U: ");
      Serial.println(volt);
      sum = 0;
      counter = 0;
      currentTS = ts;
    
  }
}
