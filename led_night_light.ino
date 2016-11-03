///
/// Пины датчиков
///
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9
#define PIR_PIN 8
#define LIGHT_PIN 7

// время горения света - 5 мин.
#define TIME_DELAY 300000

// Включен ли свет
int _isLight;

void setup() {
  // led лента
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // датчик движения
  pinMode(PIR_PIN, INPUT);

  // датчик света
  pinMode(LIGHT_PIN, INPUT);

  //Serial.begin(9600);
  //Serial.println("Controller is init");

  _isLight = 0;
}

void loop() {

  // значение датчика движения
  int pirValue = digitalRead(PIR_PIN);

  //Serial.print("Pir value: ");
  //Serial.println(pirValue);

  //Serial.print("_isLight = ");
  //Serial.println(_isLight);

  int lightSensor = digitalRead(LIGHT_PIN);
  //Serial.print("Light sensor: ");
  //Serial.println(lightSensor);
  delay(10);

  // если lightSensor == 1 - света нет
  if(pirValue == HIGH && _isLight == 0/* && lightSensor == 1*/){
    _isLight = 1;
    //Serial.println("Set color");

    setColor(90, 90, 90);

    delay(TIME_DELAY);

    //Serial.println("Reset light");
    _isLight = 0;
    setColor(0, 0, 0);
    //Serial.println();
  }
}

// установить цвет RGB ленты
void setColor(int red, int green, int blue)
{
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
