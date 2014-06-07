#pragma once
#include "cocos2d.h"
#include "GameScene_6.h"
#include "GameScene_16.h"
#include "GameScene_17.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_15 : public CCLayer
{
public:
	GameScene_15();
	~GameScene_15();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_15);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_6(CCObject* pSender);
	void toScene_16(CCObject* pSender);
	void toScene_17(CCObject* pSender);

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

