///
/// Скетч ночника в спальню, который включается по датчику движения
///

// Пины датчиков
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9
#define PIR_PIN 8

// время горения света - 5 мин.
#define TIME_DELAY 300000

// включен ли свет
int _isLight;

void setup() {

  // led лента
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // датчик движения
  pinMode(PIR_PIN, INPUT);

  _isLight = 0;
}

void loop() {

  // значение датчика движения
  int pirValue = digitalRead(PIR_PIN);

  delay(10);

  if(pirValue == HIGH && _isLight == 0){
    _isLight = 1;

    setColor(90, 90, 90);

    delay(TIME_DELAY);

    _isLight = 0;
    setColor(0, 0, 0);
  }
}

// установить цвет RGB ленты
void setColor(int red, int green, int blue)
{
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
