#include "GameScene_10.h"
USING_NS_CC;

GameScene_10::GameScene_10()
{
}


GameScene_10::~GameScene_10()
{
}


CCScene* GameScene_10::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_10 *layer = GameScene_10::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_10::init()
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
void GameScene_10::InitScene()
{
	background = CCSprite::create("10_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 10);

	showTip_1();
}

void GameScene_10::showTip_1()
{
	CCSprite* t = CCSprite::create("tip_9.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeOut* fo = CCFadeOut::create(4.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_10::runGame));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	t->runAction(my_1);
}

//run game
void GameScene_10::runGame(CCNode* sender)
{
	CCMenuItemImage *ts9 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_10::toScene_9));
	ts9->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.04, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *td = CCMenuItemImage::create(
		"sign_4.png",
		"sign_4.png",
		this,
		menu_selector(GameScene_10::toDeath));
	td->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.68, visibleOrigin.y + visibleSize.height * 0.43));


	CCMenu* moveMgr = CCMenu::create(ts9, td, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_10.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_10::toScene_9(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_9::scene()));
}

void GameScene_10::toDeath(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, DeathLayer::scene()));
}

