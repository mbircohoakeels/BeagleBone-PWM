//
// Created by Michael Brookes on 29/05/2016.
//

#ifndef BEAGLEBONE_PWM_PINOVERLAY_H
#define BEAGLEBONE_PWM_PINOVERLAY_H

#include "../iDeviceOverlay.h"
#include "../../Exceptions/ExceptionAid.h"

#define MAX_BUF 255

namespace abPWM {

    class PinOverlay : public iDeviceOverlay {


    public:

        PinOverlay( int _BLOCK, int _PIN ) throw( PWMSetupException& );

        struct OverlaySettings {
            const char *Overlay = "bone_pwm_P";
            const char *OverlayDir = "/sys/devices/ocp.3/";
            const char *SearchFile = "pwm_test_P";
            bool OverlayLoaded;
        } Settings;

    private:
        void SetBlock( int _BLOCK );
        void SetPin( int _PIN );

        void FindPinDir( );

        char PinOverlayDir[MAX_BUF]; //!< Stores the PWM folder name
        char PinOverlayName[24];

        int Pin;
        int Block;

    };

}


#endif //BEAGLEBONE_PWM_PINOVERLAY_H
