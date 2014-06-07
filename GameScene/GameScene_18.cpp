#include "GameScene_18.h"
USING_NS_CC;

GameScene_18::GameScene_18()
{
}


GameScene_18::~GameScene_18()
{
}


CCScene* GameScene_18::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_18 *layer = GameScene_18::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_18::init()
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
void GameScene_18::InitScene()
{
	background = CCSprite::create("18_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 18);

	showTip_1();
}

void GameScene_18::showTip_1()
{
	CCSprite* t = CCSprite::create("tip_17.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeOut* fo = CCFadeOut::create(4.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_18::runGame));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	t->runAction(my_1);
}

//run game
void GameScene_18::runGame(CCNode* sender)
{
	CCMenuItemImage *ts16 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_18::toScene_16));
	ts16->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.4, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts19 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_18::toScene_19));
	ts19->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.4, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *td = CCMenuItemImage::create(
		"sign_7.png",
		"sign_7.png",
		this,
		menu_selector(GameScene_18::toDeath));
	td->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.7, visibleOrigin.y + visibleSize.height * 0.3));


	CCMenu* moveMgr = CCMenu::create(ts16, ts19, td, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_18.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_18::toScene_16(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_16::scene()));
}
void GameScene_18::toScene_19(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_19::scene()));
}

void GameScene_18::toDeath(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, DeathLayer::scene()));
}

