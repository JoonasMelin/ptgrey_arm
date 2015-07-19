#include "ptgrey.h"

ptgrey::ptgrey()
{
}

ptgrey::open(unsigned int camNo)
{
    FlyCapture2::BusManager busMgr;
    unsigned int numCameras;
    FlyCapture2::Error error = busMgr.GetNumOfCameras(&numCameras);
    if (error != FlyCapture2::PGRERROR_OK)
    {
        PrintError( error );
        std::cerr << "Could not get cameras from bus" << std::endl;
    }

    printf( "Number of cameras detected: %u\n", numCameras );

    //Checking if we have enough cameras
    if(camNo > numCameras)
    {
        std::cerr << "Not enough cameras!" << std::endl;
        throw NOT_ENOUGH;
    }


    std::cout << "Connecting to camera no " << camNo << std::endl;
    FlyCapture2::PGRGuid guid;

    error = busMgr.GetCameraFromIndex(camNo, &guid);
    if (error != FlyCapture2::PGRERROR_OK)
    {
        PrintError( error );
        std::cerr << "Could not get camera from index" << std::endl;
        throw NO_INDEX;
    }

    std::cout << "Running the camera " << guid.value <<  std::endl;
    startCamera_();
}//open()


//PRIVATE
void ptgrey::printError( FlyCapture2::Error error )
{
    error.PrintErrorTrace();
}
