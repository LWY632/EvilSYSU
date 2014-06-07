#include "GameScene_19.h"
USING_NS_CC;

GameScene_19::GameScene_19()
{
}


GameScene_19::~GameScene_19()
{
}


CCScene* GameScene_19::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_19 *layer = GameScene_19::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_19::init()
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
void GameScene_19::InitScene()
{
	background = CCSprite::create("19_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 19);

	runGame();
}

//run game
void GameScene_19::runGame()
{
	CCMenuItemImage *ts18 = CCMenuItemImage::create(
		"sign_10.png",
		"sign_10.png",
		this,
		menu_selector(GameScene_19::toScene_18));
	ts18->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.85, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts20 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_19::toScene_20));
	ts20->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.3, visibleOrigin.y + visibleSize.height * 0.42));

	CCMenuItemImage *ts21 = CCMenuItemImage::create(
		"sign_11.png",
		"sign_11.png",
		this,
		menu_selector(GameScene_19::toScene_21));
	ts21->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.08, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *ts22 = CCMenuItemImage::create(
		"sign_8.png",
		"sign_8.png",
		this,
		menu_selector(GameScene_19::toScene_22));
	ts22->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.95, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *ts37 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_19::toScene_37));
	ts37->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.04, visibleOrigin.y + visibleSize.height * 0.3));


	CCMenu* moveMgr = CCMenu::create(ts18, ts20, ts21, ts22, ts37, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_19.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_19::toScene_18(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_18::scene()));
}
void GameScene_19::toScene_20(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_20::scene()));
}
void GameScene_19::toScene_21(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_21::scene()));
}
void GameScene_19::toScene_22(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_22::scene()));
}
void GameScene_19::toScene_37(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_37::scene()));
}

