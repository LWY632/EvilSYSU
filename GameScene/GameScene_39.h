#pragma once
#include "cocos2d.h"
#include "StartLayer.h"
#include "GameScene_39.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_39 : public CCLayer
{
public:
	GameScene_39();
	~GameScene_39();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_39);

	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

