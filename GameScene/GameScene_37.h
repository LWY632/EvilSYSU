#pragma once
#include "cocos2d.h"
#include "GameScene_36.h"
#include "GameScene_38.h"
#include "GameScene_19.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_37 : public CCLayer
{
public:
	GameScene_37();
	~GameScene_37();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_37);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_36(CCObject* pSender);
	void toScene_38(CCObject* pSender);
	void toScene_19(CCObject* pSender);


private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

