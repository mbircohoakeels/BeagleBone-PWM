//
// Created by Michael Brookes on 27/05/2016.
//

#include "PWMDevice.h"

namespace abPWM {

    PWMDevice::PWMDevice( PinBlocks _block, PWMPins _pin ) throw( PWMSetupException& ) {

        this->SetBlockNum( _block );
        this->SetPinNum( _pin );

        if( this->Settings.OverlayLoaded ) {
            this->_PinOverlay = new PinOverlay( this->BlockNum, this->PinNum );

            if( this->_PinOverlay->Settings.OverlayLoaded )
                this->SetFilePaths( );
        }

    }

    void PWMDevice::ReadDevice( ValType _ft ) {
        this->SetValType( _ft );
        this->ReadDevice( 1024 );
    }

    short PWMDevice::ReadDevice( size_t _BufferSize ) {
        if( !this->PWMFile.is_open( ) ) {
            if( this->OpenDevice( ) ) {
                try {
                    getline( this->PWMFile, this->CurrentReading );
                    this->PWMFile.close( );
                }
                catch( ifstream::failure e ) {
                    cout << "Exception caught handling binary file : " << e.what( ) << endl;
                }
            }
            return 0;
        }
    }

    void PWMDevice::InitDevice( ) throw( PWMSetupException& ) {
        if( !this->Settings.OverlayLoaded ) {
            snprintf( this->ErrMessage, sizeof( this->ErrMessage ),
                      "Fatal PWM Error - Unable to set up your PWM device : %s",
                      this->Settings.Overlay );
            throw PWMSetupException( this->ErrMessage );
        }
    }

    void PWMDevice::WriteToDevice( ValType _ft, long int _val ) throw( PWMSetupException& ) {
        this->SetValType( _ft );
        this->SetWriteVal( _val );
        this->WriteToDevice( 1024 );
    }

    int PWMDevice::WriteToDevice( size_t _BufferSize ) throw( PWMSetupException& ) {
        ofstream PWMWriteFile;
        PWMWriteFile.open( this->GetFilePath( ) );
        if( PWMWriteFile.is_open( ) ) {
            PWMWriteFile << this->Val2Write;
            PWMWriteFile.close( );
        }
    }

    int PWMDevice::OpenDevice( ) throw( PWMSetupException& ) {
        try {
            this->PWMFile.open( this->GetFilePath( ), ios::binary );
            return 1;
        } catch ( exception& e ) {
            snprintf( this->ErrMessage, sizeof( this->ErrMessage ),
                      "Fatal PWM Error - Unable to create FileHandle : %s - %s",
                      this->_PinOverlay->PinOverlayDir, e.what( ) );
            throw PWMSetupException( this->ErrMessage );
        }
    }

    long PWMDevice::Get( ValType _vt ) { return this->GetCurrentReading ( _vt ); }

    void PWMDevice::Set( ValType _vt, long _val ) { this->WriteToDevice( _vt, _val ); }

    long PWMDevice::GetCurrentReading( ValType _ft ) {
        this->ReadDevice( _ft );
        if( this->CurrentReading.length() > 0 ) {
            if( _ft != Run ) {
                return stoi( this->CurrentReading );
            }
            else{
                string isTrue ("1");
                return ( this->CurrentReading.compare( isTrue ) == 0 ) ? true : false;
            }
        }
        else
            return 1;
    }

    char* PWMDevice::GetFilePath( ){
        switch( this->FT ) {
            case Run : return this->RunPath;
            case Duty : return this->DutyPath;
            case Period : return this->PeriodPath;
            default: return this->DutyPath;
        }
    }

    void PWMDevice::SetFilePaths( ) {
        snprintf( this->DutyPath, sizeof( this->DutyPath ), "%s/%s", this->_PinOverlay->PinOverlayDir, "duty" );
        snprintf( this->PeriodPath, sizeof( this->PeriodPath ), "%s/%s", this->_PinOverlay->PinOverlayDir, "period" );
        snprintf( this->RunPath, sizeof( this->RunPath ), "%s/%s", this->_PinOverlay->PinOverlayDir, "run" );
    }

    void PWMDevice::SetPinNum( PWMPins _pin ) { this->PinNum = _pin; }

    void PWMDevice::SetBlockNum( PinBlocks _block ) { this->BlockNum = _block; }

    void PWMDevice::SetValType( ValType _ft ) { this->FT = _ft; }

    void PWMDevice::SetWriteVal( long _val ) { this->Val2Write = _val; }

}