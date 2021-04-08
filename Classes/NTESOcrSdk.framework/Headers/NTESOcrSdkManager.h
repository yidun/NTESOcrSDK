//
//  NTESOcrSdkManager.h
//  NTESOcrSdk
//
//  Created by 罗礼豪 on 2020/11/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  @abstract    枚举
 *
 *  @说明         NTESOcrCompletionHandler    对象的参数，用于表示获取token的状态
 *               NTESOcrBusinessIdAvailable 业务ID可用
 *               NTESOcrBusinessIdInvalid     业务ID不可用
 *               NTESOcrCheckPass               身份证检测通过
 *               NTESOcrCheckNotPass         身份证检测不通过
 *               NTESOcrGetConfTimeout       身份证测获取配置信息超时
 *               NTESOcrOperationTimeout     操作超时，用户未在规定时间内完成动作
 *               NTESOcrNonGateway           网络未连接
 *               NTESOcrSDKError             SDK内部发生错误
 *               NTESOcrCameraNotAvailable   App未获取相机权限
 *
 *
 */
typedef NS_ENUM(NSUInteger, NTESOcrStatus) {
    NTESOcrBusinessIdAvailable = 1,
    NTESOcrBusinessIdInvalid,
    NTESOcrCheckPass,
    NTESOcrCheckNotPass,
    NTESOcrGetConfTimeout,
    NTESOcrOperationTimeout,
    NTESOcrOnlineUploadFailure,
    NTESOcrNonGateway,
    NTESOcrSDKError,
    NTESOcrCameraNotAvailable,
};


/**
 *  @abstract    枚举
 *
 *  @说明         NTESCardType    对象的参数，用于表示检测的身份证正反面类型
 *
 *               NTESCardTypeFront           身份证正面检测
 *               NTESCardTypeBack           身份证国徽面检测
 *
 */
typedef NS_ENUM(NSUInteger, NTESCardReverseType) {
    NTESCardReverseTypeFront = 1,
    NTESCardReverseTypeBack,
};

NS_ASSUME_NONNULL_BEGIN

/**
 @说明        获取身份证检测结果的回调
 */
typedef void(^NTESOcrCompletionHandler)(NTESOcrStatus status, NSDictionary * _Nullable params);

@interface NTESOcrSdkManager : NSObject

/**
 初始化检测对象
 
 @param imageView               传入放置检测的imageView对象
 @param scanRect                 身份证扫描框相对于传入放置检测的imageView对象的坐标
 */
- (instancetype)initWithImageView:(UIImageView *)imageView scanRect:(CGRect)scanRect;

/**
 设置检测的超时时间
 
 @param timeout                 请传入1-1800范围内的时间值，默认120，单位s
 */
- (void)setTimeoutInterval:(NSTimeInterval)timeout;

/**
 初始化SDK
 
 @param businessID                     产品编号
 @param cardReverseType          身份证检测的方向 。传入NTESCardReverseTypeFront表示正面检测，NTESCardReverseTypeBack表示国徽面检测
 @param completionHandler     初始化结果的回调，结果状态见NTESLDStatus枚举类型
 */
- (void)startDetectWithBusinessID:(NSString *)businessID
                  cardReverseType:(NTESCardReverseType)cardReverseType
                completionHandler:(NTESOcrCompletionHandler)completionHandler;

/**
 停止身份证检测                     ⚠️ 请在主线程中调用
 
 @abstract                      调用时机：
                                1、在身份证检测结果的回调里（NTESOcrCompletionHandler）调用
                                2、未完成身份证检测，需要中止时调用
 */
- (void)stopDetect;

/**
 SDK版本号获取
 */
- (NSString *)getSDKVersion;

@end

NS_ASSUME_NONNULL_END
