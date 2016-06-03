//
// Created by Michael Brookes on 27/05/2016.
//

#ifndef BEAGLEBONE_PWM_PWMDEVICE_H
#define BEAGLEBONE_PWM_PWMDEVICE_H

#include <fstream>

#include "../Device/IDevice.h"
#include "../Exceptions/ExceptionAid.h"
#include "../Overlays/PWM/PWMOverlay.h"
#include "../Overlays/PWM/PinOverlay.h"

namespace abPWM {

    using namespace abIDevice;

    class PWMDevice : public abIDevice::IDevice, abPWM::PWMOverlay {

    public:

        PWMDevice( PinBlocks _block, PWMPins _pin ) throw( PWMSetupException& );

        enum ValType{
            Run, Duty, Period
        };

        PinBlocks BlockNum;
        PWMPins PinNum;

        long Get( ValType );

        void Set( ValType, long _val );

    private:

        ValType FT;

        void ReadDevice( ValType _ft );

        short ReadDevice( size_t _BufferSize );

        void InitDevice( ) throw( PWMSetupException& );

        int ConnectToDevice( ) { return 1; }

        int WriteToDevice( size_t _BufferSize ) throw( PWMSetupException& );

        void WriteToDevice( ValType _ft, long int _val ) throw( PWMSetupException& );

        int OpenDevice( ) throw( PWMSetupException& );

        long GetCurrentReading( ValType _ft );

        char* GetFilePath( );

        void SetPinNum( PWMPins _pin );

        void SetBlockNum( PinBlocks _block );

        void SetValType( ValType _ft );

        void SetWriteVal( long int _val );

        void SetFilePaths( );

        long Val2Write;

        ifstream PWMFile;

        string CurrentReading;

        PinOverlay* _PinOverlay;

        char DutyPath[ 50 ];

        char PeriodPath[ 50 ];

        char RunPath[ 50 ];

    };

}

#endif //BEAGLEBONE_PWM_PWMDEVICE_H
