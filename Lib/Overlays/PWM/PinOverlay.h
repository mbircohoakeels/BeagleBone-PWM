//
// Created by Michael Brookes on 29/05/2016.
//

#ifndef BEAGLEBONE_PWM_PINOVERLAY_H
#define BEAGLEBONE_PWM_PINOVERLAY_H

#include "../iDeviceOverlay.h"
#include "../../Exceptions/ExceptionAid.h"

#define MAX_BUF 255

namespace abPWM {

    class PinOverlay : public abIDevice::iDeviceOverlay {

    public:

        PinOverlay( PinBlocks _BLOCK, PWMPins _PIN ) throw( PWMSetupException& );

        struct OverlaySettings {
            const char *Overlay = "bone_pwm_P";
            const char *OverlayDir = "/sys/devices/ocp.3/";
            const char *SearchFile = "pwm_test_P";
            bool OverlayLoaded;
        } Settings;

        char PinOverlayDir[MAX_BUF]; //!< Stores the PWM folder name

    private:
        void SetBlock( PinBlocks _BLOCK );
        void SetPin( PWMPins _PIN );

        void FindPinDir( );

        char PinOverlayName[24];

        PWMPins Pin;
        PinBlocks Block;

    };

}


#endif //BEAGLEBONE_PWM_PINOVERLAY_H
