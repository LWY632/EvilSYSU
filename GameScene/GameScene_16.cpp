#include "GameScene_16.h"
USING_NS_CC;

GameScene_16::GameScene_16()
{
}


GameScene_16::~GameScene_16()
{
}


CCScene* GameScene_16::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_16 *layer = GameScene_16::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_16::init()
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
void GameScene_16::InitScene()
{
	background = CCSprite::create("16_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 16);

	runGame();
}

//run game
void GameScene_16::runGame()
{
	CCMenuItemImage *ts15 = CCMenuItemImage::create(
		"sign_6.png",
		"sign_6.png",
		this,
		menu_selector(GameScene_16::toScene_15));
	ts15->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.35, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts18 = CCMenuItemImage::create(
		"sign_5.png",
		"sign_5.png",
		this,
		menu_selector(GameScene_16::toScene_18));
	ts18->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.8, visibleOrigin.y + visibleSize.height * 0.45));

	CCMenuItemImage *ts30 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_16::toScene_30));
	ts30->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.2, visibleOrigin.y + visibleSize.height * 0.48));

	CCMenu* moveMgr = CCMenu::create(ts15, ts18, ts30, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_16.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_16::toScene_15(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_15::scene()));
}
void GameScene_16::toScene_18(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_18::scene()));
}
void GameScene_16::toScene_30(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_30::scene()));
}






