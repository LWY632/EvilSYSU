#include "DeathLayer.h"
USING_NS_CC;

DeathLayer::DeathLayer()
{
}


DeathLayer::~DeathLayer()
{
}


CCScene* DeathLayer::scene()
{
	CCScene *scene = CCScene::create();
	DeathLayer *layer = DeathLayer::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool DeathLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();

	InitScene();

	this->setTouchEnabled(true);

	return true;
}

//init the game scene
void DeathLayer::InitScene()
{
	background = CCSprite::create("DeathBackground.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);
}


void DeathLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, StartLayer::scene()));
}


