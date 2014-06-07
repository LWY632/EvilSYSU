#pragma once
#include "cocos2d.h"
#include "GameScene_15.h"
#include "GameScene_33.h"

#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_17 : public CCLayer
{
public:
	GameScene_17();
	~GameScene_17();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_17);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_15(CCObject* pSender);
	void toScene_33(CCObject* pSender);


private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};


