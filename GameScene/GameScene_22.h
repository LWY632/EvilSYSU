#pragma once
#include "cocos2d.h"
#include "GameScene_19.h"
#include "GameScene_29.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_22 : public CCLayer
{
public:
	GameScene_22();
	~GameScene_22();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_22);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_19(CCObject* pSender);
	void toScene_29(CCObject* pSender);

	//delete tip
	void delTips(CCNode* sender);


private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

