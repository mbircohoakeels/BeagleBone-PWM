#include <iostream>
#include "Lib/PWM/PWMDevice.h"

using namespace std;

int main( ) {
    using namespace abPWM;

    PWMDevice* MotorDevice;
    MotorDevice = new PWMDevice( PWMOverlay::BLOCK_P9 , PWMOverlay::PIN_42 );

    MotorDevice->Set( MotorDevice->Run, 1 );
    MotorDevice->Set( MotorDevice->Duty, 300000 );
    MotorDevice->Set( MotorDevice->Period, 750000 );

    cout << "Duty = " << MotorDevice->Get( MotorDevice->Duty ) << endl;
    cout << "Period = " << MotorDevice->Get( MotorDevice->Period ) << endl;
    cout << "Run = " << MotorDevice->Get( MotorDevice->Run ) << endl;
    cout << "Polarity = " << MotorDevice->Get( MotorDevice->Polarity ) << endl;
    MotorDevice->Get( MotorDevice->Power_Control ); //has to be Get and then accessed via MotorDevice->Power_ControlStr atm
    cout << "Power Control = " << MotorDevice->Power_ControlStr << endl;
    cout << "Power Runtime - Active = " << MotorDevice->Get( MotorDevice->Power_RunTime_Active ) << endl;
    cout << "Power Runtime - Suspended = " << MotorDevice->Get( MotorDevice->Power_RunTime_Suspended ) << endl;

    return 0;
}