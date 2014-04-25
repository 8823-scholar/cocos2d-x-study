#include "PuzzleView.h"
#include "HelloWorldScene.h"
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
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Point origin = Director::getInstance()->getVisibleOrigin();

        auto scene = dynamic_cast<HelloWorldScene*>(this->getScene());
        auto layer = HelloWorldLayer::create();
        scene->addChild(layer);

        // ブロックを並べる
        auto blocks = scene->getBlocks();
        for (auto block : blocks) {
            auto size = block->getContentSize();
            block->setPosition(block->getCoordinateX() * 100 + 50, visibleSize.height/2 + origin.y);
            layer->addChild(block);
        }
        /*
        for (int i = 0; i < blocks->size(); i++) {
            auto block = blocks[i];
        }
        */

        return true;
    }
}
