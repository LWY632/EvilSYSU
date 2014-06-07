#include "GameScene_9.h"
USING_NS_CC;

GameScene_9::GameScene_9()
{
}


GameScene_9::~GameScene_9()
{
}


CCScene* GameScene_9::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_9 *layer = GameScene_9::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_9::init()
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
void GameScene_9::InitScene()
{
	background = CCSprite::create("9_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 9);

	showTip_1();
}

void GameScene_9::showTip_1()
{
	CCSprite* t = CCSprite::create("tip_8.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeOut* fo = CCFadeOut::create(4.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_9::runGame));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	t->runAction(my_1);
}

//run game
void GameScene_9::runGame(CCNode* sender)
{
	CCMenuItemImage *ts7 = CCMenuItemImage::create(
		"sign_10.png",
		"sign_10.png",
		this,
		menu_selector(GameScene_9::toScene_7));
	ts7->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.7, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts10 = CCMenuItemImage::create(
		"sign_11.png",
		"sign_11.png",
		this,
		menu_selector(GameScene_9::toScene_10));
	ts10->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.6, visibleOrigin.y + visibleSize.height * 0.43));


	CCMenu* moveMgr = CCMenu::create(ts7, ts10, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_9.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_9::toScene_7(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_7::scene()));
}
void GameScene_9::toScene_10(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_10::scene()));
}



