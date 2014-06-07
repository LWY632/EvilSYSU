#pragma once
#include "cocos2d.h"
#include "GameScene_19.h"
#include "GameScene_28.h"
#include "DeathLayer.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_21 : public CCLayer
{
public:
	GameScene_21();
	~GameScene_21();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_21);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_19(CCObject* pSender);
	void toScene_28(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};


