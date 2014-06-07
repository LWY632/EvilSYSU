#pragma once
#include "cocos2d.h"
#include "GameScene_26.h"

#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_27 : public CCLayer
{
public:
	GameScene_27();
	~GameScene_27();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_27);

	//init the game scene
	void InitScene();


	void showTip_1();
	void showTip_2(CCNode* sender);
	void showTip_3(CCNode* sender);
	void showTip_4(CCNode* sender);
	void showTip_5(CCNode* sender);
	void showTip_6(CCNode* sender);

	//run game
	void runGame(CCNode* sender);

	//move menu
	void toScene_26(CCObject* pSender);

	//delete tip
	void delTips(CCNode* sender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;


	CCSprite* talkback;
};


