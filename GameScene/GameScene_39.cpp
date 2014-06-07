#include "GameScene_39.h"
USING_NS_CC;

GameScene_39::GameScene_39()
{
}


GameScene_39::~GameScene_39()
{
}


CCScene* GameScene_39::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_39 *layer = GameScene_39::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_39::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();


	background = CCSprite::create("39_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background);


	this->setTouchEnabled(true);

	return true;
}


void GameScene_39::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCDirector::sharedDirector()->replaceScene(StartLayer::scene());
}



