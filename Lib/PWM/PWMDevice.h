//
// Created by Michael Brookes on 27/05/2016.
//

#ifndef BEAGLEBONE_PWM_PWMDEVICE_H
#define BEAGLEBONE_PWM_PWMDEVICE_H

#include "../Device/IDevice.h"
#include "../Exceptions/ExceptionAid.h"
#include "../Overlays/PWM/PWMOverlay.h"
#include "../Overlays/PWM/PinOverlay.h"

namespace abPWM {

    class PWMDevice : public abIDevice::IDevice {

    public:

        PWMDevice( int _block, int _pin );

        short ReadDevice( size_t _BufferSize );

        void InitDevice( ) throw( PWMSetupException& );

        int ConnectToDevice( ) { return 1; }

        int WriteToDevice( size_t _BufferSize ) throw( PWMSetupException& );

        int OpenDevice( ) throw( PWMSetupException& );

        enum BlockNums {
            P9 = 9, //!< P9 on your BBB | USB facing you, P9 is the pin block on the left hand side.
            P8 = 8, //!< P8 on your BBB | USB facing you, P8 is the pin block on the right hand side.
        };

        /**
         \brief PinNum refers to a exposed PWM Pin on your BBB, this enum can be expanded to include more if required.
         */
        enum PinNums {
            PWM42 = 42, //!< GPIO PWM Pin Number 42
            PWM22 = 22, //!< GPIO PWM Pin Number 22
            PWM19 = 19, //!< GPIO PWM Pin Number 19
            PWM14 = 14, //!< GPIO PWM Pin Number 14
        };

        BlockNums BlockNum;
        PinNums PinNum;

    private:

        void SetPinNum( PinNums _pin );

        void SetBlockNum( BlockNums _block );

        PWMOverlay _PWMOverlay;
        PinOverlay* _PinOverlay;

    };

}

#endif //BEAGLEBONE_PWM_PWMDEVICE_H
