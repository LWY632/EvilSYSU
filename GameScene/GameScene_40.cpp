#include "GameScene_40.h"
USING_NS_CC;

GameScene_40::GameScene_40()
{
}


GameScene_40::~GameScene_40()
{
}


CCScene* GameScene_40::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_40 *layer = GameScene_40::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_40::init()
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
void GameScene_40::InitScene()
{
	background = CCSprite::create("40_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 40);

	if (!userDataFile->getBoolForKey("GameScene11_Open", false))
	{
		CCMenuItemImage *_card = CCMenuItemImage::create(
			"40_scene_ex.png",
			"40_scene_ex.png",
			this,
			menu_selector(GameScene_40::pickCard));
		_card->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.30156, visibleOrigin.y + visibleSize.height * 0.38889));

		card = CCMenu::create(_card, NULL);
		card->setPosition(CCPointZero);
		this->addChild(card, 1);
	}

	runGame();
}

//run game
void GameScene_40::runGame()
{
	CCMenuItemImage *ts8 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_40::toScene_8));
	ts8->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.1, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenu* moveMgr = CCMenu::create(ts8, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_40.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_40::toScene_8(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_8::scene()));
}

void GameScene_40::pickCard(CCObject* pSender)
{
	this->removeChild(card);
	userDataFile->setBoolForKey("GameScene11_Open", true);

	CCSprite* tip = CCSprite::create("tip_7.png");
	tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(tip, 3);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_40::delTips));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	tip->runAction(my_1);
}

//delete tip
void GameScene_40::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


