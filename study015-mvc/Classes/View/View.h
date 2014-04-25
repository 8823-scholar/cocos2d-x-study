#ifndef __VIEW_H__
#define __VIEW_H__

#include "cocos2d.h"

namespace View
{
    class View : public cocos2d::Ref
    {
    public:
        View();
        virtual ~View();
        virtual bool init();

        static View* create(cocos2d::Scene* scene);
        virtual void setScene(cocos2d::Scene* scene);
        virtual cocos2d::Scene* getScene();

    private:
        cocos2d::Scene* scene;
    };
}

#endif // __VIEW_H__
