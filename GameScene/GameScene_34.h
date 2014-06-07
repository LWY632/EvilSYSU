#pragma once
#include "cocos2d.h"
#include "GameScene_5.h"
#include "GameScene_35.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_34 : public CCLayer
{
public:
	GameScene_34();
	~GameScene_34();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_34);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_5(CCObject* pSender);
	void toScene_35(CCObject* pSender);


private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

