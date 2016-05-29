//
// Created by Michael Brookes on 29/05/2016.
//

#include "PinOverlay.h"

namespace abPWM {

    PinOverlay::PinOverlay( ) throw( PWMSetupException& ) {

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