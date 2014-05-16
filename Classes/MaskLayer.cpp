//
//  MaskLayer.cpp
//  TestGame
//
//  Created by Jerry on 14-5-14.
//
//

#include "MaskLayer.h"

bool MaskLayer::init(){
	if (!CCLayer::init() )
	{
		return false;
	}
    
	this->setTouchEnabled(true);
//    this->setTouchPriority(-129);
//    this->setTouchMode(kCCTouchesOneByOne);
    
	return true;
}

void MaskLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority * 2, true);

	CCLayer::registerWithTouchDispatcher();
}

bool MaskLayer::ccTouchBegan (CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("MaskLayer");
	return true;
}

void MaskLayer::ccTouchMoved (CCTouch *pTouch, CCEvent *pEvent)
{
}

void MaskLayer::ccTouchEnded (CCTouch *pTouch, CCEvent *pEvent)
{
}
