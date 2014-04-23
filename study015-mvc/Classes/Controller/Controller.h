#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "cocos2d.h"

namespace Controller
{

    class Controller
    {
    public:
        Controller();
        virtual ~Controller();
        virtual bool init();

        static Controller* create(cocos2d::Scene* scene);

        virtual void setScene(cocos2d::Scene* scene);

    private:
        cocos2d::Scene* scene;
    };
}

#endif // __CONTROLLER_H__
