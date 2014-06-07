#pragma once
#include "cocos2d.h"
#include "GameScene_7.h"
#include "GameScene_40.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_8 : public CCLayer
{
public:
	GameScene_8();
	~GameScene_8();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_8);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_7(CCObject* pSender);
	void toScene_40(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

