//
// Created by Michael Brookes on 27/05/2016.
//

#include "PWMOverlay.h"

namespace abPWM {

    PWMOverlay::PWMOverlay( ) throw( PWMSetupException& ) {

        if( ! this->IsLoaded( this->Settings.SearchFile ) ) {
            this->Settings.OverlayLoaded = this->Load( this->Settings.Overlay );
        }

        if( !this->Settings.OverlayLoaded ) {
            snprintf( this->ErrMessage, sizeof( this->ErrMessage ),
                      "Fatal Analog Error - Unable to load overlay : %s",
                      this->Settings.Overlay );
            throw PWMSetupException( this->ErrMessage );
        }

    }

}