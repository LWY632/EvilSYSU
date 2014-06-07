#include "GameScene_34.h"
USING_NS_CC;

GameScene_34::GameScene_34()
{
}


GameScene_34::~GameScene_34()
{
}


CCScene* GameScene_34::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_34 *layer = GameScene_34::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_34::init()
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
void GameScene_34::InitScene()
{
	background = CCSprite::create("34_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 34);

	runGame();
}

//run game
void GameScene_34::runGame()
{
	CCMenuItemImage *ts5 = CCMenuItemImage::create(
		"sign_10.png",
		"sign_10.png",
		this,
		menu_selector(GameScene_34::toScene_5));
	ts5->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.8, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts35 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_34::toScene_35));
	ts35->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.1, visibleOrigin.y + visibleSize.height * 0.45));

	CCMenu* moveMgr = CCMenu::create(ts5, ts35, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_34.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_34::toScene_5(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_5::scene()));
}
void GameScene_34::toScene_35(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_35::scene()));
}




