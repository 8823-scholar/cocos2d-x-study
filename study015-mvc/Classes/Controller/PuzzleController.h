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

        virtual void tap(cocos2d::Node* target);
    };
}

#endif // __CONTROLLER_PUZZLE_CONTROLLER_H__
