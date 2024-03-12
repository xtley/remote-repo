#include <iostream>

extern "C"{
 #include "libavutil/avutil.h"
}
using namespace std;

int main()
{
    cout<<"Hello FFMPEG, version is "<<av_version_info()<<endl;
    return 0;
}
