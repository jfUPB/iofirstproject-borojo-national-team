void task1()
{
    // Definición de estados y variable de estado
    enum class Task1States
    {
        INIT,
        WAIT_TIMEOUT
    };
    static Task1States task1State = Task1States::INIT;

    // Definición de variables static (conservan
    // su valor entre llamadas a task1)
    static uint32_t lasTime = 0;
    static uint32_t lastbt1nState = LOW;
    static uint32_t lastbt2nState = LOW;

    // Constantes

    constexpr uint32_t INTERVAL = 1000;
    constexpr uint8_t button1Pin = 12;
    constexpr uint8_t button2Pin = 13;
    constexpr uint8_t button3Pin = 32;
    constexpr uint8_t button4Pin = 33;
    constexpr uint8_t ledRed = 14;
    constexpr uint8_t ledGreen = 25;
    constexpr uint8_t ledBlue = 26;
    constexpr uint8_t ledYellow = 27;

    // MÁQUINA de ESTADOS

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        pinMode(button1Pin, INPUT_PULLUP);
        pinMode(button2Pin, INPUT_PULLUP);
        pinMode(button3Pin, INPUT_PULLUP);
        pinMode(button4Pin, INPUT_PULLUP);
        pinMode(ledRed, OUTPUT);
        pinMode(ledGreen, OUTPUT);
        pinMode(ledBlue, OUTPUT);
        pinMode(ledYellow, OUTPUT);
        lasTime = millis();
        task1State = Task1States::WAIT_TIMEOUT;

        break;
    }
    case Task1States::WAIT_TIMEOUT:
    {
        uint8_t btn1State = digitalRead(button1Pin);
        uint8_t btn2State = digitalRead(button2Pin);
        uint8_t btn3State = digitalRead(button3Pin);
        uint8_t btn4State = digitalRead(button4Pin);

        // Evento 2

        if ((lastbt1nState != btn1State) || (lastbt2nState != btn2State))
        {

            digitalWrite(ledRed, LOW);
            digitalWrite(ledBlue, LOW);
            digitalWrite(ledYellow, LOW);
            digitalWrite(ledGreen, LOW);

            if (btn1State == LOW && btn2State == LOW)
            {
                digitalWrite(ledRed, HIGH);
                Serial.println("ledRed is on");
            }
            // Evento 3
            if (btn1State == LOW && btn2State == HIGH)
            {
                digitalWrite(ledGreen, HIGH);
                Serial.println("ledGreen is on");
            }
            // Evento 4
            if (btn1State == HIGH && btn2State == LOW)
            {
                digitalWrite(ledBlue, HIGH);
                Serial.println("ledBlue is on");
            }

            // Evento 5
            if (btn1State == HIGH && btn2State == HIGH)
            {
                digitalWrite(ledYellow, HIGH);
                Serial.println("ledYellow is on");
            }
            lastbt1nState = btn1State;
            lastbt2nState = btn2State;
        }

        break;
    }
    default:
    {
        Serial.println("Error");
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
