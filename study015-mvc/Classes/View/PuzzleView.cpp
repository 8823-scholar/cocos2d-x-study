#include "PuzzleView.h"
#include "HelloWorldLayer.h"
#include "cocos2d.h"

namespace View
{
    PuzzleView* PuzzleView::create(cocos2d::Scene* scene)
    {
        PuzzleView* view = new PuzzleView();
        view->setScene(scene);
        view->init();
        return view;
    }


    bool PuzzleView::init()
    {
        auto scene = this->getScene();
        auto layer = HelloWorldLayer::create();
        scene->addChild(layer);

        return true;
    }
}
