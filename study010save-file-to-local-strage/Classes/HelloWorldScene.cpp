#include "HelloWorldScene.h"
#include "network/HttpClient.h"
#include <stdio.h>
#include <stdlib.h>

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


    auto request = new extension::HttpRequest();
    request->setUrl("http://befool.co.jp/images/logo_befool.jpg");
    request->setRequestType(extension::HttpRequest::Type::GET);
    request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompleted));
    extension::HttpClient::getInstance()->send(request);

    return true;
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

/**
 * ファイルDL正常終了コールバック
 */
void HelloWorld::onHttpRequestCompleted(extension::HttpClient* sender, extension::HttpResponse* response)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto fileUtils = FileUtils::sharedFileUtils();
    std::string filename = fileUtils->getWritablePath() + "hoge.jpg";

    if (fileUtils->isFileExist(filename)) {
        log("file exist. use hoge.jpg.");

        auto sprite = Sprite::create(filename.c_str());
        sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        this->addChild(sprite, 0);
    } else {
        log("no file exist. use default image, and save the file.");

        if (response->isSucceed()) {
            std::vector<char>* buffer = response->getResponseData();
            auto* img = new Image();
            img->initWithImageData(reinterpret_cast<unsigned char*>(&(buffer->front())), buffer->size());
            img->saveToFile(filename.c_str());

            auto* texture = new Texture2D();
            texture->initWithImage(img);
            
            auto sprite = Sprite::createWithTexture(texture);
            sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
            this->addChild(sprite, 0);
        }
    }
}

