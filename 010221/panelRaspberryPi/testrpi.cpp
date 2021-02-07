#include "testrpi.h"
#include "wiringPi.h"
#include "softPwm.h"

TestRPi::TestRPi(int rpi_pin, int rpi_type, void (*isrInput)(void), QObject *parent) : QObject(parent)
{
    int d = wiringPiSetup();
    //wiringPiSetupGpio(void);
    //wiringPiSetupPhys(void);
    //wiringPiSetupSys(void);
    pin = rpi_pin;
    toggle_key_led = false;
    switch_on = false;
    value_pwm = 0;
    
    switch(rpi_type)
    {
        case GPIO_INPUT:
        {
            pinMode(pin, INPUT);
            wiringPiISR(pin, INT_EDGE_BOTH, isrInput);
            break;
        } 

        case GPIO_OUTPUT:
        {
            pinMode(pin, OUTPUT);
            break;
        } 

        case GPIO_PWM:
        {
            softPwmCreate(pin, value_pwm, 100);
            break;
        }
    }
}



void TestRPi::isrCallback()
{
    emit inputChanged(digitalRead(pin));
}

void TestRPi::pinHigh()
{
    digitalWrite(pin, HIGH);
}

void TestRPi::pinLow()
{
    digitalWrite(pin, LOW);
}

void TestRPi::pinToggle()
{
    toggle_key_led != toggle_key_led;
    digitalWrite(pin, toggle_key_led);
}

void TestRPi::setPwmValue(int value)
{
    softPwmWrite(pin, value);
}

/*void TestRPi::getSwitch(bool on_off)
{
    switch_on = on_off;
}*/
