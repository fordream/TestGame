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
{
    
}

PopLayer::~PopLayer()
{
    CC_SAFE_RELEASE(mCloseBtn);
    CC_SAFE_RELEASE(pTarget);
}

PopLayer* PopLayer::load(CCLayer *target)
{
    PopLayer *node = (PopLayer *) CCBManage::loadCCB("PopLayer.ccbi", PopLayer::create(), "PopLayer", PopLayerLoader::loader());
    
    node->setAnimationManager((CCBAnimationManager *) node->getUserObject());
    
    node->pTarget = target;
    
    return node;
}

void PopLayer::show()
{
    pTarget->addChild(this);
    
    CCLOG("===show===");
    CCLOG("this->%p",this);
    //CCLOG("pTarget->%p",pTarget);
    CCLOG("mCloseBtn->%p",mCloseBtn);
    
}

void PopLayer::hide()
{
    CCLOG("===hide===");
    CCLOG("this->%p",this);
    //CCLOG("pTarget->%p",pTarget);
    CCLOG("mCloseBtn->%p",mCloseBtn);
    
    mCloseBtn->setEnabled(false);
    mAnimationManager->runAnimationsForSequenceNamed("Display");
    mAnimationManager->setAnimationCompletedCallback(this, callfunc_selector(PopLayer::callBackAnimationCompleted));
}

void PopLayer::callBackAnimationCompleted()
{
    std::string lastSeqName = mAnimationManager->getLastCompletedSequenceName();
    
    if (lastSeqName == "Display")
    {
        pTarget->removeChild(this);
        //CCLOG("pPopLayer remove");
    }
}

void PopLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    CCLOG("PopLayer OnLoad");
    this->setTouchEnabled(true);
    mCloseBtn->setTouchPriority(kCCMenuHandlerPriority * 2);
    CCLOG("===onNodeLoaded===");
    CCLOG("this->%p",this);
    CCLOG("mCloseBtn->%p",mCloseBtn);
    
}

bool PopLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)   //重写ccbi文件成员对象绑定器
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mCloseBtn", CCControl*, this->mCloseBtn);        //设定成员对象对应变量
    CCLOG("===onAssignCCBMemberVariable===");
    CCLOG("this->%p",this);
    CCLOG("mCloseBtn->%p",mCloseBtn);
    return true;
}

SEL_CCControlHandler PopLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)   //重写Control类按钮回调函数绑定器
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClose", PopLayer::onClose);        //设定Control类按钮对应函数
    return NULL;
}

void PopLayer::onClose(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    this->hide();
    CCLOG("Close Btn Clicked");
}

/**
 * 设置触摸等级
 **/
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
