/*
Copyright (C) 2016 Michael Brookes

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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