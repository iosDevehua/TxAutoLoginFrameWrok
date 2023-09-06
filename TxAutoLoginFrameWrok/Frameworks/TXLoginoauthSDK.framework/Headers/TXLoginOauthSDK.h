//
//  TXLoginOauthSDK.h
//  TXLoginoauthSDK
//
//  Created by zhouguanghui on 2020/9/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TXLoginUIModel.h"
#import <TYRZUISDK/TYRZUISDK.h>


#define TXSDKVERSION @"quick_login_iOS_4.1.1"

NS_ASSUME_NONNULL_BEGIN

@interface TXLoginOauthSDK : NSObject

/*声明一个block
 @param resultDic 网络返回的data的解析结果
 */
typedef void (^richSuccessBlock) (NSDictionary * _Nonnull resultDic);
/**
 声明一个block
 @param error 网络返回的错误或者其它错误
 */
typedef void (^richFailureBlock) (id error);

//初始化方法
+(void)initLoginWithId:(NSString*)apiId;

/**
 设置超时

 @param timeout 超时，
 设置取号、授权请求和本机号码校验请求时的超时时间，开发者不配置时，默认所有请求的超时时间都为8000，单位毫秒
 */
+(void)setTimeoutInterval:(NSTimeInterval)timeout;

//预登录,调用loginWithBack 这个之前必须使用一下预登录方法
//************注意注意注意*************
//preLoginWithBack 方法要调用成功之后才可以调用 loginWithBack 这个方法

+(void)preLoginWithBack:(richSuccessBlock)successBlock failBlock:(richFailureBlock)failBlock;

//调用登录界面进行免密码认证的功能
/*
===============================================================
======= 注意注意一定要先调用preLoginWithBack进行预登录才有用=======
===============================================================
 uiModel 设置登录授权页面UI
successBlock 成功返回回调
failBlock    失败返回回调
 controller 当前跳转控制器
 */
+(void)loginWithController:(UIViewController*)controller andUIModel:(TXLoginUIModel *)uiModel  successBlock:(richSuccessBlock)successBlock failBlock:(richFailureBlock)failBlock;

// 一键登录
+(void)loginUIModel:(TXLoginUIModel *)uiModel successBlock:(richSuccessBlock)successBlock failBlock:(richFailureBlock)failBlock;


/* getSimInfo
 //networkType 类型NSString
 //值 == 0.无网络; 1.数据流量; 2.wifi; 3.数据+wifi
 //carrier 类型NSNumber
 //值 == 0.未知(未插sim卡，其它运营商等); 1.中国移动mobile;2.中国联通unicom;3.中国电信telecom
 */
+(NSDictionary*)getSimInfo;

/**
 删除取号缓存数据 + 重置网络开关（自定义按钮事件里dimiss授权界面需调用）
 
 @return YES：有缓存已执行删除操作，NO：无缓存不执行删除操作
 */
+ (BOOL)delectScrip;

/**
 关闭授权界面
 @param flag 动画开关
 @param completion 回调参数
 */
+ (void)dismissViewControllerAnimated: (BOOL)flag completion: (void (^ __nullable)(void))txCompletion;

+ (void)setLoginDelegate:(UIViewController *)vc;

@end

NS_ASSUME_NONNULL_END


