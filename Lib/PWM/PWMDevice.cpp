//
// Created by Michael Brookes on 27/05/2016.
//

#include "PWMDevice.h"

namespace abPWM {

    PWMDevice::PWMDevice( int _block, int _pin ) {

        this->SetBlockNum( (BlockNums)_block );
        this->SetPinNum( (PinNums)_pin );

        if( this->_PWMOverlay.Settings.OverlayLoaded ) {
            this->_PinOverlay = new PinOverlay( this->PinNum, this->BlockNum );

            if( this->_PinOverlay->Settings.OverlayLoaded ) {
                //good to go
            }
        }

    }

    short PWMDevice::ReadDevice( size_t _BufferSize ) {

    }

    void PWMDevice::InitDevice( ) throw( PWMSetupException& ) {

    }

    int PWMDevice::WriteToDevice( size_t _BufferSize ) throw( PWMSetupException& ) {

    }

    int PWMDevice::OpenDevice( ) throw( PWMSetupException& ) {

    }

    void PWMDevice::SetPinNum( PinNums _pin ) { this->PinNum = _pin; }

    void PWMDevice::SetBlockNum( BlockNums _block ) { this->BlockNum = _block; }

}