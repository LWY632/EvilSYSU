#include "GameScene_21.h"
USING_NS_CC;

GameScene_21::GameScene_21()
{
}


GameScene_21::~GameScene_21()
{
}


CCScene* GameScene_21::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_21 *layer = GameScene_21::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_21::init()
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
void GameScene_21::InitScene()
{
	background = CCSprite::create("21_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 21);

	runGame();
}

//run game
void GameScene_21::runGame()
{
	CCMenuItemImage *ts19 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_21::toScene_19));
	ts19->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts28 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_21::toScene_28));
	ts28->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.62, visibleOrigin.y + visibleSize.height * 0.28));


	CCMenu* moveMgr = CCMenu::create(ts19, ts28, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_21.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_21::toScene_19(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_19::scene()));
}
void GameScene_21::toScene_28(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_28::scene()));
}


