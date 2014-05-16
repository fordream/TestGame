//
//  BaseLayer.cpp
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#include "BaseLayer.h"

BaseLayer::BaseLayer()
: mAnimationManager(NULL)
{
    
}

BaseLayer::~BaseLayer()
{
    CC_SAFE_RELEASE(mAnimationManager);
}

SEL_MenuHandler BaseLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)       //重写Menu类按钮回调函数绑定器
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", MainScene::onMenuItemTest);   //设定Menu类按钮对应函数
    return NULL;
}

SEL_CCControlHandler BaseLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)   //重写Control类按钮回调函数绑定器
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "btnMeun", MainScene::onBtnMeun);    //设定Control类按钮对应函数
    return NULL;
}

SEL_CallFuncN BaseLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)         //重写timeline回调函数绑定器
{
    //CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "TimeCall", MainScene::onCallback);
    return NULL;
}

bool BaseLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)   //重写ccbi文件成员对象绑定器
{
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "helloLabel", CCLabelTTF*, this->mLabelText);   //设定成员对象对应变量
    return true;
}

void BaseLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)                                         //重写ccbi加载完成状态监听器
{
    
}

void BaseLayer::setAnimationManager(CCBAnimationManager *pAnimationManager)
{
    CCLog("reg animationManager");    //打印日志
    CC_SAFE_RELEASE_NULL(mAnimationManager);   //释放内存
    mAnimationManager = pAnimationManager;
    CC_SAFE_RETAIN(mAnimationManager);    //保护内存
}

CCBAnimationManager* BaseLayer::getAnimationManager()
{
    return mAnimationManager;
}
