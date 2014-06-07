#include "GameScene_37.h"
USING_NS_CC;

GameScene_37::GameScene_37()
{
}


GameScene_37::~GameScene_37()
{
}


CCScene* GameScene_37::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_37 *layer = GameScene_37::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_37::init()
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
void GameScene_37::InitScene()
{
	background = CCSprite::create("37_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 37);

	runGame();
}

//run game
void GameScene_37::runGame()
{
	CCMenuItemImage *ts36 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_37::toScene_36));
	ts36->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts38 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_37::toScene_38));
	ts38->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.05, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *ts19 = CCMenuItemImage::create(
		"sign_8.png",
		"sign_8.png",
		this,
		menu_selector(GameScene_37::toScene_19));
	ts19->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.95, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenu* moveMgr = CCMenu::create(ts36, ts38, ts19, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_37.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);

}

//move menu
void GameScene_37::toScene_36(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_36::scene()));
}
void GameScene_37::toScene_38(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_38::scene()));
}
void GameScene_37::toScene_19(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_19::scene()));
}



