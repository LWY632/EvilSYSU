#include "GameScene_26.h"
USING_NS_CC;

GameScene_26::GameScene_26()
{
}


GameScene_26::~GameScene_26()
{
}


CCScene* GameScene_26::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_26 *layer = GameScene_26::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_26::init()
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
void GameScene_26::InitScene()
{
	background = CCSprite::create("26_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 26);

	runGame();
}

//run game
void GameScene_26::runGame()
{
	CCMenuItemImage *ts24 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_26::toScene_24));
	ts24->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.05, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *ts27 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_26::toScene_27));
	ts27->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.32, visibleOrigin.y + visibleSize.height * 0.3));


	CCMenu* moveMgr = CCMenu::create(ts24, ts27, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_26.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);


	CCSprite* tip = CCSprite::create("tip_22.png");
	tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(tip, 3);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_26::delTips));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	tip->runAction(my_1);
}

//move menu
void GameScene_26::toScene_24(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_24::scene()));
}
void GameScene_26::toScene_27(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_27::scene()));
}

//delete tip
void GameScene_26::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


