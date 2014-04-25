#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "cocos2d.h"

namespace Controller
{

    class Controller : public cocos2d::Ref
    {
    public:
        Controller();
        virtual ~Controller();
        virtual bool init();

        static Controller* create(cocos2d::Scene* scene);
        virtual void setScene(cocos2d::Scene* scene);

        virtual void tap(cocos2d::Node* target);
        virtual void longTap(cocos2d::Node* target);

    private:
        cocos2d::Scene* scene;
    };
}

#endif // __CONTROLLER_H__
