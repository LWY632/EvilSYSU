#pragma once
#include "cocos2d.h"
#include "GameScene_16.h"
#include "GameScene_19.h"
#include "DeathLayer.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_18 : public CCLayer
{
public:
	GameScene_18();
	~GameScene_18();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_18);

	//init the game scene
	void InitScene();

	void showTip_1();

	//run game
	void runGame(CCNode* sender);

	//move menu
	void toScene_16(CCObject* pSender);
	void toScene_19(CCObject* pSender);
	void toDeath(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

