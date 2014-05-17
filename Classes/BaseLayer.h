//
//  BaseLayer.h
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#ifndef __TestGame__BaseLayer__
#define __TestGame__BaseLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class BaseLayer
: public CCLayer
, public cocos2d::extension::CCBSelectorResolver  //继承按钮回调方法类
, public cocos2d::extension::CCBMemberVariableAssigner  //继承成员变量获取类
, public cocos2d::extension::CCNodeLoaderListener       //继承节点加载监听类
{
public:
    
    BaseLayer();
    ~BaseLayer();
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);       //重写Menu类按钮回调函数绑定器
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);   //重写Control类按钮回调函数绑定器
    
    virtual SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);         //重写timeline回调函数绑定器
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);   //重写ccbi文件成员对象绑定器
    
    virtual void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);                                         //重写ccbi加载完成状态监听器
    
    void onMenuItemTest(cocos2d::CCObject *pSender);                                                        //Menu类按钮执行函数
    
    void onBtnMeun(cocos2d::CCObject *pSender, cocos2d::extension::CCControlEvent pCCControlEvent);         //Control类按钮执行函数
    
    void onCallback(CCNode* sender);                                                                        //timeline 回调执行函数
    
    void setAnimationManager(CCBAnimationManager *pAnimationManager);
    
    //CCNode *load()
    
    CCBAnimationManager* getAnimationManager();
    
protected:
    CCBAnimationManager *mAnimationManager;
    CCLayer  *pTarget;
};

#endif /* defined(__TestGame__BaseLayer__) */
