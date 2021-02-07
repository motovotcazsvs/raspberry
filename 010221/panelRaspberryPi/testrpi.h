#ifndef TESTRPI_H
#define TESTRPI_H

#include <QObject>

#define GPIO_INPUT   0
#define GPIO_OUTPUT  1
#define GPIO_PWM     2

class TestRPi: public QObject
{
    Q_OBJECT
public:
    explicit TestRPi(int rpi_pin, int rpi_type, void (*isrInput)(void) = nullptr, QObject *parent = nullptr);

    void isrCallback();
    //Q_INVOKABLE void getSwitch(bool);
    bool switch_on;

signals:
    void inputChanged(int value);

public slots:
    void pinHigh();
    void pinLow();
    void pinToggle();
    void setPwmValue(int);

private:
    //int press_key1;
    //int press_key2;

    int value_pwm;
    bool toggle_key_led;
    int pin;

};
#endif // TESTRPI_H
