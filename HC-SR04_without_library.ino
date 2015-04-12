const int Trig = 7; 
const int Echo = 8;           // обозначим к какой ножке и что подключаем 

  
void setup(){
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);         // Инициализируем сериал порт, дабы вывести результат на монитор
}

unsigned int time_us=0;       // Переменная для хранения временного интервала
unsigned int distance_sm=0;   // Переменная для хранения расстояния в сантиметрах

void loop()
{
  digitalWrite(Trig, HIGH);    // Подаем сигнал на выход микроконтроллера
  delayMicroseconds(10);       // Удерживаем 10 микросекунд
  digitalWrite(Trig, LOW);     // Затем убираем
  time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
  distance_sm=time_us/58; // Пересчитываем в сантиметры
  if (distance_sm<928){
    Serial.println(distance_sm); // Выводим на порт
  }
  delay(500);
}
