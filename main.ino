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
    uint8_t LED_level = map(ADC_Value, 0, 1024, 0, 6);
    for (uint8_t i = 0; i <= 0 + LED_amount - 1; i++)
    {
        digitalWrite(i, LOW);
    }
    for (uint8_t i = 0; i <= 0 + LED_level - 1; i++)
    {
        digitalWrite(i, HIGH);
    }
}
