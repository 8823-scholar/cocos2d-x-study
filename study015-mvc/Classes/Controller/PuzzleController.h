#ifndef __CONTROLLER_PUZZLE_CONTROLLER_H__
#define __CONTROLLER_PUZZLE_CONTROLLER_H__

#include "Controller.h"

namespace Controller
{

    class PuzzleController : public Controller
    {
    public:
        static PuzzleController* create(cocos2d::Scene* scene);
        virtual bool init();
    };
}

#endif // __CONTROLLER_PUZZLE_CONTROLLER_H__
