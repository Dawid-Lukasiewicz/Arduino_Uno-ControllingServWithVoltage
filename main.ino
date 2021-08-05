#include <LiquidCrystal.h>
#include <Servo.h>

#define LED_amount 5

LiquidCrystal lcd(13, 12, 11, 10, 8, 7);
Servo serv;

void setup()
{
    lcd.begin(16, 2);
    serv.attach(9);
    for (uint8_t i = 0; i <= 0 + LED_amount - 1; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{
    // ADC read
    uint16_t ADC_Value = analogRead(PIN_A0);

    // Serv control with ADC
    uint8_t Angle = map(ADC_Value, 0, 1023, 0, 180);
    serv.write(Angle);

    // LCD display
    float Voltage = ADC_Value * 5.0 / 1024;
    lcd.setCursor(0, 0);
    lcd.print("Voltage ");
    lcd.print(Voltage);
    lcd.print(" V");

    // LED visualization
    uint16_t LED_light = map(ADC_Value, 0, 1023, 0, LED_amount * 100);
    if (LED_light < 75)
    {
        digitalWrite(0, LOW);
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }

    else if (LED_light < 125 && LED_light > 75)
    {
        digitalWrite(0, HIGH);
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (LED_light < 225 && LED_light > 175)
    {
        digitalWrite(0, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (LED_light < 325 && LED_light > 275)
    {
        digitalWrite(0, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (LED_light < 425 && LED_light > 375)
    {
        digitalWrite(0, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    }
    else if (LED_light < 525 && LED_light > 475)
    {
        digitalWrite(0, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
}
