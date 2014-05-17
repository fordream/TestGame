//
//  PopLayer.h
//  TestGame
//
//  Created by Jerry on 14-5-14.
//
//

#ifndef __TestGame__PopLayer__
#define __TestGame__PopLayer__

#include "CCBManage.h"
#include "BaseLayer.h"


USING_NS_CC;
USING_NS_CC_EXT;

class PopLayer
: public BaseLayer
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(PopLayer, create);  //重写生成节点注册器调用函数
    
    PopLayer();
    ~PopLayer();
    
    static PopLayer* load(CCLayer *target);
    
    void show();
    void hide();
    
    virtual void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);   //重写ccbi文件成员对象绑定器
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);   //重写Control类按钮回调函数绑定器
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    
    void registerWithTouchDispatcher();
    
    void onClose(CCObject *pSender, CCControlEvent pCCControlEvent);         //Control类按钮执行函数
    
    void callBackAnimationCompleted();

private:
    CCControl *mCloseBtn;
};

/* 声明节点注册器 */
class PopLayerLoader : public CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(PopLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(PopLayer);
};

#endif /* defined(__TestGame__PopLayer__) */
