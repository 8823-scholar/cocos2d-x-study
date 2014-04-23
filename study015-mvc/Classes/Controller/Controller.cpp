#include "Controller.h"
#include "cocos2d.h"

namespace Controller
{
    Controller::Controller()
    {
    }

    Controller::~Controller()
    {
    }

    Controller* Controller::create(cocos2d::Scene* scene)
    {
        Controller* controller = new Controller();
        controller->setScene(scene);
        controller->init();
        return controller;
    }


    bool Controller::init()
    {
        return true;
    }

    void Controller::setScene(cocos2d::Scene* scene)
    {
        this->scene = scene;
    }
}
