//
//  MaskLayer.h
//  TestGame
//
//  Created by Jerry on 14-5-14.
//
//

#ifndef __TestGame__MaskLayer__
#define __TestGame__MaskLayer__

#include "cocos2d.h"
USING_NS_CC;

class MaskLayer :
public CCLayer
{
public:
	virtual bool init();
    
	// implement the "static node()" method manually
	CREATE_FUNC(MaskLayer);
    
	virtual void registerWithTouchDispatcher();
    
	virtual bool ccTouchBegan (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__TestGame__MaskLayer__) */
