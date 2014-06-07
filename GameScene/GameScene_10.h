#pragma once
#include "cocos2d.h"
#include "GameScene_9.h"
#include "DeathLayer.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_10 : public CCLayer
{
public:
	GameScene_10();
	~GameScene_10();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_10);

	//init the game scene
	void InitScene();

	void showTip_1();

	//run game
	void runGame(CCNode* sender);

	//move menu
	void toScene_9(CCObject* pSender);
	void toDeath(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

