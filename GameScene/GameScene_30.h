#pragma once
#include "cocos2d.h"
#include "GameScene_16.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_30 : public CCLayer
{
public:
	GameScene_30();
	~GameScene_30();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_30);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_16(CCObject* pSender);
	void toDeath(CCObject* pSender);

	void pickCZ(CCObject* pSender);

	//delete tip
	void delTips(CCNode* sender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

	CCMenu* CZ;

};

