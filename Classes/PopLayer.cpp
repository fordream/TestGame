//
//  PopLayer.cpp
//  TestGame
//
//  Created by Jerry on 14-5-14.
//
//

#include "PopLayer.h"

PopLayer::PopLayer()
: mShowBox(NULL)
, mMaskLayer(NULL)
, mCloseBtn(NULL)
{
    
}

PopLayer::~PopLayer()
{
    CC_SAFE_RELEASE(mShowBox);
    CC_SAFE_RELEASE(mMaskLayer);
    CC_SAFE_RELEASE(mCloseBtn);
}

PopLayer* PopLayer::load()
{
    PopLayer *layer = PopLayer::create();
        
    CCNode *node = CCBLoader::loadCCB("PopLayer.ccbi", layer, "PopLayer", PopLayerLoader::loader());
        
    layer->addChild(node);
        
    return layer;
}

void PopLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    CCLOG("PopLayer OnLoad");
    this->setTouchEnabled(true);
    mCloseBtn->setTouchPriority(kCCMenuHandlerPriority * 2);
}

bool PopLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)   //重写ccbi文件成员对象绑定器
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mShowBox", CCLayerColor*, this->mShowBox);   //设定成员对象对应变量
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mMaskLayer", CCLayerColor*, this->mMaskLayer);   //设定成员对象对应变量
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mCloseBtn", CCControl*, this->mCloseBtn);   //设定成员对象对应变量
    return true;
}

void PopLayer::registerWithTouchDispatcher()
{
	CCDirector *pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this,kCCMenuHandlerPriority * 2,true);
}

bool PopLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("Touch Bengan");
    
    return true;
}
//void PopLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
//{
//    
//}
//
//void PopLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
//{
//    
//}

//void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
//{
//    
//}
