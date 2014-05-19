//
//  LoadingLayer.h
//  TestGame
//
//  Created by Jerry on 14-5-19.
//
//

#ifndef __TestGame__LoadingLayer__
#define __TestGame__LoadingLayer__

#include "CCBManage.h"
#include "BaseLayer.h"


USING_NS_CC;
USING_NS_CC_EXT;

class LoadingLayer
: public BaseLayer
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LoadingLayer, create);  //重写生成节点注册器调用函数
    
    LoadingLayer();
    ~LoadingLayer();
    
    static LoadingLayer* load(CCLayer *target);
    
    void show();
    void loadingCallBack(CCObject *obj);
    
    virtual void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);   //重写ccbi文件成员对象绑定器
private:
    CCScale9Sprite *mLoadingBar;
    CCLabelTTF *mLoadingPercent;
    int iCurrentNum;
    int iTotalNum;
};

/* 声明节点注册器 */
class LoadingLayerLoader : public CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LoadingLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(LoadingLayer);
};

#endif /* defined(__TestGame__LoadingLayer__) */
