//
//  MainLayer.h
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#ifndef __TestGame__MainLayer__
#define __TestGame__MainLayer__

#include "CCBManage.h"
#include "BaseLayer.h"
#include "PopLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;



class MainLayer
: public BaseLayer
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MainLayer, create);  //重写生成节点注册器调用函数
    
    MainLayer();
    
    ~MainLayer();
    
    static MainLayer* load(CCLayer *target);
    
    void show();
    
    virtual void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);   //重写Control类按钮回调函数绑定器
    
    void onClickMe(CCObject *pSender, CCControlEvent pCCControlEvent);         //Control类按钮执行函数
};

/* 声明节点注册器 */
class MainLayerLoader : public CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainLayer);
};

#endif /* defined(__TestGame__MainLayer__) */
