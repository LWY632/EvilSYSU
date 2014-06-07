#pragma once
#include "cocos2d.h"
#include "GameScene_15.h"
#include "GameScene_18.h"
#include "GameScene_30.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_16 : public CCLayer
{
public:
	GameScene_16();
	~GameScene_16();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_16);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_15(CCObject* pSender);
	void toScene_18(CCObject* pSender);
	void toScene_30(CCObject* pSender);


private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;


};

