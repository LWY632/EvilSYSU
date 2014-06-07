#include "GameScene_1.h"
USING_NS_CC;

GameScene_1::GameScene_1()
{
}


GameScene_1::~GameScene_1()
{
}


CCScene* GameScene_1::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_1 *layer = GameScene_1::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_1::init()
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
void GameScene_1::InitScene()
{
	background = CCSprite::create("1_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 1);

	if (userDataFile->getBoolForKey("isNewGame", true))
	{
		showTip_1();
		userDataFile->setBoolForKey("isNewGame", false);
	}
	else
	{
		runGame(this);
	}
}

//tips animation
void GameScene_1::showTip_1()
{
	CCSprite* t = CCSprite::create("tip_1.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.8));
	this->addChild(t, 1);

	CCFadeIn* fi = CCFadeIn::create(6.0f);
	CCFadeOut* fo = CCFadeOut::create(6.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_1::showTip_2));
	CCAction* my_1 = CCSequence::create(fi, fo, cfn, NULL);

	t->runAction(my_1);
}
void GameScene_1::showTip_2(CCNode* sender)
{
	CCSprite* t = CCSprite::create("tip_2.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.8));
	this->addChild(t, 1);

	CCFadeIn* fi = CCFadeIn::create(6.0f);
	CCFadeOut* fo = CCFadeOut::create(6.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_1::runGame));
	CCAction* my_1 = CCSequence::create(fi, fo, cfn, NULL);

	t->runAction(my_1);
}
//run game
void GameScene_1::runGame(CCNode* sender)
{
	CCMenuItemImage *ts2 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_1::toScene_2));
	ts2->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.2));

	CCMenuItemImage *ts3 = CCMenuItemImage::create(
		"sign_3.png",
		"sign_3.png",
		this,
		menu_selector(GameScene_1::toScene_3));
	ts3->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.1, visibleOrigin.y + visibleSize.height * 0.2));

	CCMenu* moveMgr = CCMenu::create(ts2, ts3, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);


	CCSprite* address = CCSprite::create("addr_1.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_1::toScene_2(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_2::scene()));
}
void GameScene_1::toScene_3(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_3::scene()));
}

