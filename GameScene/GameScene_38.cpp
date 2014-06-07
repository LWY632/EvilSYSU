#include "GameScene_38.h"
USING_NS_CC;

GameScene_38::GameScene_38()
{
}


GameScene_38::~GameScene_38()
{
}


CCScene* GameScene_38::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_38 *layer = GameScene_38::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_38::init()
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
void GameScene_38::InitScene()
{
	background = CCSprite::create("38_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 38);

	showTip_1();
}

void GameScene_38::showTip_1()
{
	CCSprite* t = CCSprite::create("tip_16.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeOut* fo = CCFadeOut::create(4.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_38::runGame));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	t->runAction(my_1);
}

//run game
void GameScene_38::runGame(CCNode* sender)
{
	CCMenuItemImage *ts37 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_38::toScene_37));
	ts37->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.05, visibleOrigin.y + visibleSize.height * 0.1));

	CCMenuItemImage *td = CCMenuItemImage::create(
		"sign_11.png",
		"sign_11.png",
		this,
		menu_selector(GameScene_38::toDeath));
	td->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.4531, visibleOrigin.y + visibleSize.height * 0.05));


	CCMenu* moveMgr = CCMenu::create(ts37, td, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_38.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_38::toScene_37(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_37::scene()));
}

void GameScene_38::toDeath(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, DeathLayer::scene()));
}

