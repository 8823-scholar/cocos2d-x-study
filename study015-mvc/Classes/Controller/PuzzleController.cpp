#include "PuzzleController.h"

namespace Controller
{
    PuzzleController* PuzzleController::create(cocos2d::Scene* scene)
    {
        PuzzleController* controller = new PuzzleController();
        controller->setScene(scene);
        controller->init();
        return controller;
    }

    bool PuzzleController::init()
    {
        return true;
    }

    void PuzzleController::tap(cocos2d::Node* target)
    {
        CCLOG("PuzzleController::tap");
    }
}
