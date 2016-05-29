#include <iostream>
#include "Lib/PWM/PWMDevice.h"

using namespace std;

int main( ) {
    using namespace abPWM;

    PWMDevice* MotorDevice;
    MotorDevice = new PWMDevice( 9, 42 );

    cout << "Hello, World!" << endl;
    return 0;
}