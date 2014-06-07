#pragma once
#include "cocos2d.h"
#include "StartLayer.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class DeathLayer : public CCLayer
{
public:
	DeathLayer();
	~DeathLayer();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(DeathLayer);

	//init the game scene
	void InitScene();

	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

