//------------------------------------------------------------------------------
//
// Copyright (c) Microsoft Corporation.
// All rights reserved.
//
// This code is licensed under the MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import "MSALDefinitions.h"

@class MSALRedirectUri;
@class MSALAuthority;
@class MSALWebViewConfig;
@class MSALSliceConfig;

NS_ASSUME_NONNULL_BEGIN

@interface MSALPublicClientApplicationConfig : NSObject

/*! The client ID of the application, this should come from the app developer portal. */
@property NSString *clientId;

/*! The redirect URI of the application */
@property NSString *redirecrUri;

/*! The authority the application will use to obtain tokens */
@property MSALAuthority *authority;

/*! Enable to return access token with extended lifttime during server outage. */
@property BOOL extendedLifetimeEnabled;

/*! List of known authorities that application should trust. */
@property(nullable) NSArray<MSALAuthority *> *knownAuthorities;

/*! List of additional ESTS features that client handles. */
@property(nullable) NSArray<NSString *> *clientApplicationCapabilities;

/*! When checking an access token for expiration we check if time to expiration
 is less than this value (in seconds) before making the request. The goal is to
 refresh the token ahead of its expiration and also not to return a token that is
 about to expire. */
@property double tokenExpirationBuffer;

/*! slice configuration for testing. */
@property(nullable) MSALSliceConfig *slice;

/*!
 Initialize a MSALPublicClientApplicationConfig with a given clientId
 
 @param  clientId   The clientID of your application, you should get this from the app portal.
 */
- (nullable instancetype)initWithClientId:(NSString *)clientId NS_DESIGNATED_INITIALIZER;

/*!
 Initialize a MSALPublicClientApplicationConfig with a given clientId
 
 @param  clientId       The clientID of your application, you should get this from the app portal.
 @param  redirectUri    The redirect URI of the application
 */
- (nullable instancetype)initWithClientId:(NSString *)clientId
                              redirectUri:(NSString *)redirectUri;

- (nullable instancetype)init NS_UNAVAILABLE;
+ (nullable instancetype)new NS_UNAVAILABLE;

// Todo: add a init that takes in a config file.

@end

NS_ASSUME_NONNULL_END
