#pragma once
#include "cocos2d.h"
#include "GameScene_24.h"
#include "GameScene_27.h"

#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_26 : public CCLayer
{
public:
	GameScene_26();
	~GameScene_26();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_26);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_24(CCObject* pSender);
	void toScene_27(CCObject* pSender);

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


