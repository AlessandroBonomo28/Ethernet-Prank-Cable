/*
  Arduino Micro Pro
  The unstable ethernet cable prank
  - goodman117 16/10/2025
*/
const int LXPIN = 17; // debug led on Arduino pro micro
const int ETHPIN = 3; // control pin of relay connected to the eth cable (normally closed)
int ONLINE_SECONDS;
const int MIN_ONLINE_SEC = 60*15;
const int MAX_ONLINE_SEC =  60*40;
int OFFLINE_SECONDS;
const int MIN_OFFLINE_SEC= 30;
const int MAX_OFFLINE_SEC = 60;  

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(LXPIN, OUTPUT);
  pinMode(ETHPIN, OUTPUT);
}

void loop() {
  ONLINE_SECONDS = random(MIN_ONLINE_SEC, MAX_ONLINE_SEC);
  digitalWrite(LXPIN, LOW);  
  digitalWrite(ETHPIN, LOW); 
  Serial.println("ONLINE");
  for (int i=0;i < ONLINE_SECONDS;i++){
    Serial.print(ONLINE_SECONDS - i);
    Serial.println("s rimasti alla disconnessione");
    delay(1000);
  }                    
  digitalWrite(LXPIN, HIGH);   
  digitalWrite(ETHPIN, HIGH); 
  OFFLINE_SECONDS = random(MIN_OFFLINE_SEC, MAX_OFFLINE_SEC);
  Serial.println("Staccah Staccah! (OFFLINE)");
  for (int i=0;i < OFFLINE_SECONDS;i++){
    Serial.print(OFFLINE_SECONDS - i);
    Serial.println("s rimasti alla riconnessione");
    delay(1000);
  }
  

}
