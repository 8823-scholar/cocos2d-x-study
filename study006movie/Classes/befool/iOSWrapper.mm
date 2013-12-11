#include "iOSWrapper.h"
#include "EAGLView.h"

namespace befool {
    static iOSWrapper *instance = NULL;

    void iOSWrapper::playVideo(char *path)
    {
        NSString *string, *stringPath;

        stringPath = [NSString stringWithUTF8String:path];
        string = [[NSBundle mainBundle] pathForResource:stringPath ofType:@"mp4"];
        NSLog(string);

        [[CCEAGLView sharedEGLView] playTutorialVideo:string];
    }

    iOSWrapper *iOSWrapper::getShared()
    {
        if (!instance) {
            instance = new iOSWrapper();
        }
        return instance;
    }
}

