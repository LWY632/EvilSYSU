#pragma once
#include "cocos2d.h"
#include "GameScene_19.h"
#include "GameScene_23.h"

#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_20 : public CCLayer
{
public:
	GameScene_20();
	~GameScene_20();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_20);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_19(CCObject* pSender);
	void toScene_23(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};


