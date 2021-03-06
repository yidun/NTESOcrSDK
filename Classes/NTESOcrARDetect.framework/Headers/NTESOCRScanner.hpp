//
//  NTESOCRScanner.h
//  NTESOcrSdk
//
//  Created by 徐国智 on 2020/11/24.
//

#ifndef NTESOCRScanner_h
#define NTESOCRScanner_h

// 20220422-1.1

#include <stdio.h>
// OpenCV includes
/*
#include <opencv2/videoio/videoio.hpp>  // Video write
#include <opencv2/videoio/videoio_c.h>  // Video write
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking_c.h>
#include <opencv2/video/tracking.hpp>
#include <opencv2/core/core_c.h>
*/
using namespace std;
//using namespace cv;


#endif /* NTESOCRScanner_h */

@interface OCRDetectIOS : NSObject

//-(id) initWithSensitivityType:(int)type;
-(id) initWithSensitivityType:(int)type x:(int) roi_x y:(int) roi_y height:(int) roi_height width:(int) roi_width windowsH:(float)windowsH  windowsW:(float)windowsW;

-(BOOL) run_DetectOCR:(unsigned char *)captured_image frame__:(int)frame_count reverseType:(int)reverseType imgWidth__:(int)imgWidth imgHeight__:(int)imgHeight;
- (BOOL)clear_engine;


@end
