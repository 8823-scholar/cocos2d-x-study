#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    /**
     * 動作ボタン
     */
    auto runItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuRunCallback, this));
	runItem->setPosition(Point(origin.x + visibleSize.width - runItem->getContentSize().width*2 ,
                                origin.y + runItem->getContentSize().height/2));
    auto menu2 = Menu::create(runItem, NULL);
    menu2->setPosition(Point::ZERO);
    this->addChild(menu2, 1);

    this->sprite = Sprite::create("miku.JK.jpg");
    this->sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->sprite->setScale(0.5);
    this->addChild(this->sprite, 0);

    return true;
}

void HelloWorld::menuRunCallback(Object* pSender)
{
    /*
    // 移動
    FiniteTimeAction* move = MoveTo::create(1.0f, Point(0, 0));
    this->sprite->runAction(move);
    */
    
    /*
    // スケール
    FiniteTimeAction* scale = ScaleTo::create(1.0f, 2.0f);
    this->sprite->runAction(scale);
    */

    /*
    // 回転
    FiniteTimeAction* rotate = RotateTo::create(1.0f, 180.0f);
    this->sprite->runAction(rotate);
    */
    
    /*
    // スキュー
    FiniteTimeAction* skew = SkewTo::create(1.0f, 30.0f, 45.0f);
    this->sprite->runAction(skew);
    */
    
    /*
    // 透明度
    FiniteTimeAction* fade = FadeTo::create(1.0f, 10);
    this->sprite->runAction(fade);
    */

    ActionInterval* action = MoveTo::create(2.0f, Point(0, 0));
    /*
    // Ease
    this->sprite->runAction(EaseInOut::create(action, 2));
    */
    
    /*
    // EaseExponential
    this->sprite->runAction(EaseExponentialInOut::create(action));
    */
    
    /*
    // EaseSine
    this->sprite->runAction(EaseSineInOut::create(action));
    */
    
    /*
    // EaseElastic
    this->sprite->runAction(EaseElasticOut::create(action, 0.3f));
    */
    
    /*
    // EaseBounce
    this->sprite->runAction(EaseBounceOut::create(action));
    */
    
    /*
    // EaseBack
    this->sprite->runAction(EaseBackOut::create(action));
    */
    
    /*
    // Sequence
    Sequence* seq = Sequence::create(
        EaseInOut::create(MoveTo::create(2.0f, Point(0, 0)), 2),
        EaseInOut::create(ScaleTo::create(1.0f, 2.0f), 2)
    );
    this->sprite->runAction(seq);
    */
    
    /*
    // With Tow Actions
    Spawn* spawn = Spawn::createWithTwoActions(
        EaseInOut::create(MoveTo::create(2.0f, Point(0, 0)), 2),
        EaseInOut::create(ScaleTo::create(1.0f, 2.0f), 2)
    );
    this->sprite->runAction(spawn);
    */
    
    // Delay
    Sequence* seq = Sequence::create(
        EaseInOut::create(MoveTo::create(2.0f, Point(0, 0)), 2),
        DelayTime::create(3.0f),
        EaseInOut::create(ScaleTo::create(1.0f, 2.0f), 2)
    );
    this->sprite->runAction(seq);
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
