Bu arayüz, grup arkadaşlarımla yapmaya çalıştığımız interferometre ölçü aletinin oluşturduğu aydınlık ve karanlık saçakları saymak üzere geliştirilmiştir. Saçakları saymak, ölçümü yapabilmek için önemli ve gerekli bir unsurdur.
Bu sistemde alıcı olarak 5 mm LDR (light dependent resistors), mikrodenetleyici olarak Arduino UNO kartı kullanılmıştır. LDR bağlantısında gerilim bölücü olarak 10kR direnç kullanılmıştır. Veri, Arduino UNO kartını Analog0 girişinden alınmıştır.

Blok diyagramı:
![image](https://user-images.githubusercontent.com/97691264/172058049-1d60886c-bd37-4f33-9fb2-5b90b26735f6.png)

Arayüz:
![image](https://user-images.githubusercontent.com/97691264/172058077-9733f100-cacb-4f30-94e8-a2a8de03650a.png)

Arduino Kodu:

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
