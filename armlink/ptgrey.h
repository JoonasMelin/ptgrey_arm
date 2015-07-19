#ifndef PTGREY_H
#define PTGREY_H
#include <vector>
#include "flycapture/FlyCapture2.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cstdlib>

enum Error
{
    NOT_ENOUGH,
    NO_INDEX
};

class ptgrey
{
public:
    ptgrey();
    open(unsigned int camNo = 0);

private:
    FlyCapture2::Mode mode_;
    FlyCapture2::PixelFormat color_;
    int width_;
    int height_;
    unsigned char*& pBuffers_;
    FlyCapture2::PGRGuid guid_;
    bool softExpCtrl_;
    int bufferTimeout_;


    printError(FlyCapture2::error error);

    startCamera_();


};

#endif // PTGREY_H
