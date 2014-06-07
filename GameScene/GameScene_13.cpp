#include "GameScene_13.h"
USING_NS_CC;

GameScene_13::GameScene_13()
{
}


GameScene_13::~GameScene_13()
{
}


CCScene* GameScene_13::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_13 *layer = GameScene_13::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_13::init()
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
void GameScene_13::InitScene()
{
	background = CCSprite::create("13_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 13);

	showTip_1();
}

void GameScene_13::showTip_1()
{
	CCSprite* t = CCSprite::create("tip_11.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_13::runGame));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	t->runAction(my_1);
}

//run game
void GameScene_13::runGame(CCNode* sender)
{
	CCMenuItemImage *ts11 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_13::toScene_11));
	ts11->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts14 = CCMenuItemImage::create(
		"sign_11.png",
		"sign_11.png",
		this,
		menu_selector(GameScene_13::toScene_14));
	ts14->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.18, visibleOrigin.y + visibleSize.height * 0.4));


	CCMenu* moveMgr = CCMenu::create(ts11, ts14, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_13.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_13::toScene_11(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_11::scene()));
}

void GameScene_13::toScene_14(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_14::scene()));
}

