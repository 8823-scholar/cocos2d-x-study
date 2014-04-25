#include "View.h"
#include "cocos2d.h"


namespace View
{
    View::View()
    {
    }

    View::~View()
    {
    }

    View* View::create(cocos2d::Scene* scene)
    {
        View* view = new View();
        view->setScene(scene);
        view->init();
        return view;
    }


    bool View::init()
    {
        return true;
    }

    void View::setScene(cocos2d::Scene* scene)
    {
        this->scene = scene;
    }

    cocos2d::Scene* View::getScene()
    {
        return this->scene;
    }
}
