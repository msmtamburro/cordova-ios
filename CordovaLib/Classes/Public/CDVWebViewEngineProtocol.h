/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import <UIKit/UIKit.h>
@import WebKit;

#define kCDVWebViewEngineScriptMessageHandlers @"kCDVWebViewEngineScriptMessageHandlers"
#define kCDVWebViewEngineWKNavigationDelegate @"kCDVWebViewEngineWKNavigationDelegate"
#define kCDVWebViewEngineWKUIDelegate @"kCDVWebViewEngineWKUIDelegate"
#define kCDVWebViewEngineWebViewPreferences @"kCDVWebViewEngineWebViewPreferences"

/// Worth noting: by default, the CDVWebViewEngine is the WKNavigationDelegate, but only if you haven't either:
/// [a] extended CDVViewController to be a WKNaviagationDelegate
/// [b] called `updateWithInfo` and specified a kCDVWebViewEngineWKNavigationDelegate
/// It would be more explicit to set the navigation delegate in the designated initializer below, but I'll avoid doing that because these two other ways already exist.
@protocol CDVWebViewEngineProtocol <WKNavigationDelegate>

NS_ASSUME_NONNULL_BEGIN

@property (nonatomic, strong, readonly) UIView* engineWebView;

- (id)loadRequest:(NSURLRequest*)request;
- (id)loadHTMLString:(NSString*)string baseURL:(nullable NSURL*)baseURL;
- (void)evaluateJavaScript:(NSString*)javaScriptString completionHandler:(void (^_Nullable)(id, NSError*))completionHandler;

- (NSURL*)URL;
- (BOOL)canLoadRequest:(NSURLRequest*)request;

/// Designated Initializer
/// @param frame The frame for the new web view.
/// @param configuration The configuration for the new web view.
- (nullable instancetype)initWithFrame:(CGRect)frame configuration:(nullable WKWebViewConfiguration *)configuration;

- (void)updateWithInfo:(NSDictionary*)info;

NS_ASSUME_NONNULL_END

@end
