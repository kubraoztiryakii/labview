boolean deger;
int sifir = 0, bir = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int isik = analogRead(A0); //Işık değişkenini A0 pinindeki LDR ile okuyoruz
  delay(50);

  if (isik > 900) { 

    if (deger == false) {
      bir++;
      deger = true;
    }
    Serial.print("Durum: Aydinlik  ");
    Serial.println(bir);

  }
  if (isik <= 900) { 
    if (deger == true) {
      sifir++;
      deger = false;
    }
    Serial.print("Durum: Karanlik ");
    Serial.println(sifir);
  }
}
