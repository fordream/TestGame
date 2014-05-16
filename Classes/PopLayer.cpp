//
//  PopLayer.cpp
//  TestGame
//
//  Created by Jerry on 14-5-14.
//
//

#include "PopLayer.h"

PopLayer::PopLayer()
: mCloseBtn(NULL)
, pTarget(NULL)
{
    
}

PopLayer::~PopLayer()
{
    CC_SAFE_RELEASE(mCloseBtn);
    CC_SAFE_RELEASE(pTarget);
}

void PopLayer::show(CCLayer *target)
{
    pTarget = (target == NULL) ? this : target;
    
    CCNode *node = CCBManage::loadCCB("PopLayer.ccbi", pTarget, "PopLayer", PopLayerLoader::loader());
    
    this->setAnimationManager((CCBAnimationManager *) node->getUserObject());
    
    this->addChild(node);
    
    pTarget->addChild(this);
    
    CCLOG("%p",this);
}

void PopLayer::hide()
{
    CCLOG("%p",this);
    
    //pTarget->removeChild(this);
    //mAnimationManager->runAnimationsForSequenceNamed("Display");
    //mAnimationManager->setAnimationCompletedCallback(this, callfunc_selector(PopLayer::callBackAnimationCompleted));
}

void PopLayer::callBackAnimationCompleted()
{
    std::string lastSeqName = mAnimationManager->getLastCompletedSequenceName();
    
    if (lastSeqName == "Display")
    {
        //this->getParent()->removeChild(this);
        pTarget->removeChild(this);
        CCLOG("pPopLayer remove");
    }
}

void PopLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    CCLOG("PopLayer OnLoad");
    this->setTouchEnabled(true);
    mCloseBtn->setTouchPriority(kCCMenuHandlerPriority * 2);
}

bool PopLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)   //重写ccbi文件成员对象绑定器
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mCloseBtn", CCControl*, this->mCloseBtn);        //设定成员对象对应变量
    return true;
}

SEL_CCControlHandler PopLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)   //重写Control类按钮回调函数绑定器
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClose", PopLayer::onClose);        //设定Control类按钮对应函数
    return NULL;
}

void PopLayer::onClose(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    hide();
    CCLOG("Close Btn Clicked");
}

void PopLayer::registerWithTouchDispatcher()
{
	CCDirector *pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this,kCCMenuHandlerPriority * 2,true);
}

bool PopLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("PopLayer Touch Bengan");
    
    return true;
}
