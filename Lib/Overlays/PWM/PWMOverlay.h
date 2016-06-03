//
// Created by Michael Brookes on 27/05/2016.
//

#ifndef BEAGLEBONE_PWM_PWMOVERLAY_H
#define BEAGLEBONE_PWM_PWMOVERLAY_H

#include "../iDeviceOverlay.h"
#include "../../Exceptions/ExceptionAid.h"

namespace abPWM {

    class PWMOverlay : public abIDevice::iDeviceOverlay {
    public:

        PWMOverlay( ) throw( PWMSetupException& );

        struct OverlaySettings {
            const char *Overlay = "am33xx_pwm";
            const char *SearchFile = "/sys/devices/ocp.3/48300000.epwmss/modalias";
            bool OverlayLoaded;
        } Settings;

    };

}

#endif //BEAGLEBONE_PWM_PWMOVERLAY_H
