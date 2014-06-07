#include "GameScene_28.h"
USING_NS_CC;

GameScene_28::GameScene_28()
{
}


GameScene_28::~GameScene_28()
{
}


CCScene* GameScene_28::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_28 *layer = GameScene_28::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_28::init()
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
void GameScene_28::InitScene()
{
	background = CCSprite::create("28_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 28);

	showTip_1();
}

void GameScene_28::showTip_1()
{
	CCSprite* t = CCSprite::create("tip_18.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeOut* fo = CCFadeOut::create(4.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_28::runGame));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	t->runAction(my_1);
}

//run game
void GameScene_28::runGame(CCNode* sender)
{
	CCMenuItemImage *ts21 = CCMenuItemImage::create(
		"sign_10.png",
		"sign_10.png",
		this,
		menu_selector(GameScene_28::toScene_21));
	ts21->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.4, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *td = CCMenuItemImage::create(
		"sign_11.png",
		"sign_11.png",
		this,
		menu_selector(GameScene_28::toDeath));
	td->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.1, visibleOrigin.y + visibleSize.height * 0.5));


	CCMenu* moveMgr = CCMenu::create(ts21, td, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_28.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_28::toScene_21(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_21::scene()));
}

void GameScene_28::toDeath(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, DeathLayer::scene()));
}

