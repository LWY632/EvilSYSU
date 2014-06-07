#include "GameScene_20.h"
USING_NS_CC;

GameScene_20::GameScene_20()
{
}


GameScene_20::~GameScene_20()
{
}


CCScene* GameScene_20::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_20 *layer = GameScene_20::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_20::init()
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
void GameScene_20::InitScene()
{
	background = CCSprite::create("20_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 20);

	runGame();
}

//run game
void GameScene_20::runGame()
{
	CCMenuItemImage *ts19 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_20::toScene_19));
	ts19->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.85, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts23 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_20::toScene_23));
	ts23->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.82, visibleOrigin.y + visibleSize.height * 0.35));


	CCMenu* moveMgr = CCMenu::create(ts19, ts23, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_20.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_20::toScene_19(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_19::scene()));
}
void GameScene_20::toScene_23(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_23::scene()));
}


