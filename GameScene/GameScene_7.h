#pragma once
#include "cocos2d.h"
#include "GameScene_4.h"
#include "GameScene_8.h"
#include "GameScene_9.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_7 : public CCLayer
{
public:
	GameScene_7();
	~GameScene_7();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_7);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_4(CCObject* pSender);
	void toScene_8(CCObject* pSender);
	void toScene_9(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

