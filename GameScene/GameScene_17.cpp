#include "GameScene_17.h"
USING_NS_CC;

GameScene_17::GameScene_17()
{
}


GameScene_17::~GameScene_17()
{
}


CCScene* GameScene_17::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_17 *layer = GameScene_17::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_17::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();

	InitScene();

	return true;
}

//init the game scene
void GameScene_17::InitScene()
{
	background = CCSprite::create("17_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 17);

	runGame();
}

//run game
void GameScene_17::runGame()
{
	CCMenuItemImage *ts15 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_17::toScene_15));
	ts15->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts33 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_17::toScene_33));
	ts33->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.05, visibleOrigin.y + visibleSize.height * 0.4));


	CCMenu* moveMgr = CCMenu::create(ts15, ts33, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_17.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_17::toScene_15(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_15::scene()));
}
void GameScene_17::toScene_33(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_33::scene()));
}



