#include "GameScene_11.h"
USING_NS_CC;

GameScene_11::GameScene_11()
{
}


GameScene_11::~GameScene_11()
{
}


CCScene* GameScene_11::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_11 *layer = GameScene_11::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_11::init()
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
void GameScene_11::InitScene()
{
	background = CCSprite::create("11_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 11);

	showTip_1();
}

void GameScene_11::showTip_1()
{
	CCSprite* t = CCSprite::create("tip_10.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_11::runGame));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	t->runAction(my_1);
}

//run game
void GameScene_11::runGame(CCNode* sender)
{
	CCMenuItemImage *ts5 = CCMenuItemImage::create(
		"sign_10.png",
		"sign_10.png",
		this,
		menu_selector(GameScene_11::toScene_5));
	ts5->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.9, visibleOrigin.y + visibleSize.height * 0.2));

	CCMenuItemImage *ts12 = CCMenuItemImage::create(
		"sign_6.png",
		"sign_6.png",
		this,
		menu_selector(GameScene_11::toScene_12));
	ts12->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.2, visibleOrigin.y + visibleSize.height * 0.45));

	CCMenuItemImage *ts13 = CCMenuItemImage::create(
		"sign_3.png",
		"sign_3.png",
		this,
		menu_selector(GameScene_11::toScene_13));
	ts13->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.8, visibleOrigin.y + visibleSize.height * 0.55));


	CCMenu* moveMgr = CCMenu::create(ts5, ts12, ts13, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_11.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_11::toScene_5(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_5::scene()));
}

void GameScene_11::toScene_12(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_12::scene()));
}

void GameScene_11::toScene_13(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_13::scene()));
}