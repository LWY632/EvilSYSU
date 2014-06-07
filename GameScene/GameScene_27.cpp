#include "GameScene_27.h"
USING_NS_CC;

GameScene_27::GameScene_27()
{
}


GameScene_27::~GameScene_27()
{
}


CCScene* GameScene_27::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_27 *layer = GameScene_27::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_27::init()
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
void GameScene_27::InitScene()
{
	background = CCSprite::create("27_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 27);

	if (!userDataFile->getBoolForKey("GameScene27_In", false))
	{
		showTip_1();
	}
	else
	{
		runGame(this);
	}
}

void GameScene_27::showTip_1()
{
	talkback = CCSprite::create("talkback.png");
	talkback->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(talkback, 1);


	CCSprite* t = CCSprite::create("tip_23.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.9));
	this->addChild(t, 1);

	CCFadeIn* fi = CCFadeIn::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_27::showTip_2));
	CCAction* my_1 = CCSequence::create(fi, cfn, NULL);

	t->runAction(my_1);
}
void GameScene_27::showTip_2(CCNode* sender)
{
	CCSprite* t = CCSprite::create("tip_24.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.8));
	this->addChild(t, 1);

	CCFadeIn* fi = CCFadeIn::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_27::showTip_3));
	CCAction* my_1 = CCSequence::create(fi, cfn, NULL);

	t->runAction(my_1);
}
void GameScene_27::showTip_3(CCNode* sender)
{
	CCSprite* t = CCSprite::create("tip_25.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.7));
	this->addChild(t, 1);

	CCFadeIn* fi = CCFadeIn::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_27::showTip_4));
	CCAction* my_1 = CCSequence::create(fi, cfn, NULL);

	t->runAction(my_1);
}
void GameScene_27::showTip_4(CCNode* sender)
{
	CCSprite* t = CCSprite::create("tip_26.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.6));
	this->addChild(t, 1);

	CCFadeIn* fi = CCFadeIn::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_27::showTip_5));
	CCAction* my_1 = CCSequence::create(fi, cfn, NULL);

	t->runAction(my_1);
}
void GameScene_27::showTip_5(CCNode* sender)
{
	CCSprite* t = CCSprite::create("tip_27.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeIn* fi = CCFadeIn::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_27::showTip_6));
	CCAction* my_1 = CCSequence::create(fi, cfn, NULL);

	t->runAction(my_1);
}
void GameScene_27::showTip_6(CCNode* sender)
{
	CCSprite* ttt = CCSprite::create("tip_28.png");
	ttt->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(ttt, 1);


	CCSprite* t = CCSprite::create("tip_28.png");
	t->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(t, 1);

	CCFadeIn* fi = CCFadeIn::create(15.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_27::runGame));
	CCAction* my_1 = CCSequence::create(fi, cfn, NULL);

	t->runAction(my_1);
}

//run game
void GameScene_27::runGame(CCNode* sender)
{
	if (!userDataFile->getBoolForKey("GameScene27_In", false))
	{
		userDataFile->setBoolForKey("GameScene27_In", true);
		CCDirector::sharedDirector()->replaceScene(GameScene_27::scene());
	}
	CCMenuItemImage *ts26 = CCMenuItemImage::create(
		"sign_10.png",
		"sign_10.png",
		this,
		menu_selector(GameScene_27::toScene_26));
	ts26->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.3, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenu* moveMgr = CCMenu::create(ts26, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_27.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);

}

//move menu
void GameScene_27::toScene_26(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_26::scene()));
}

//delete tip
void GameScene_27::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


