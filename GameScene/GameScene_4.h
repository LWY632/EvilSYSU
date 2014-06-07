#pragma once
#include "cocos2d.h"
#include "GameScene_2.h"
#include "GameScene_7.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_4 : public CCLayer
{
public:
	GameScene_4();
	~GameScene_4();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_4);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_2(CCObject* pSender);
	void toScene_7(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

