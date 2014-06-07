#pragma once
#include "cocos2d.h"
#include "GameScene_20.h"
#include "GameScene_24.h"

#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_23 : public CCLayer
{
public:
	GameScene_23();
	~GameScene_23();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_23);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_20(CCObject* pSender);
	void toScene_24(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};


