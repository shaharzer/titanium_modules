
//
// Copyright 2011 Box.net, Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#import <Foundation/Foundation.h>
#import "BoxOperation.h"

@interface BoxNetworkOperation : BoxOperation {
	BOOL _displayInUI;
	BOOL _isExecuting;
	BOOL _isFinished;
	NSURLConnection *_connection;
	
	BOOL _recordReceivedData;
	NSMutableData *_receivedData;
	unsigned long long _receivedDataLength;
	NSHTTPURLResponse *_networkResponse;
	
	NSString *_path;
	NSString *_uniqueID;
	long long _expectedContentLength;
	
	NSNumber *_completionRatio;
}

@property (nonatomic) long long expectedContentLength;

@property (retain) NSString *path;
@property (retain) NSNumber *completionRatio;
@property (assign) BOOL displayInUI;
@property (assign) BOOL recordReceivedData;

- (id)initForType:(BoxOperationType)type delegate:(id <BoxOperationDelegate>)delegate path:(NSString *)path;

- (NSURLRequest *)URLRequest;
- (NSURL *)url;

- (void)requestDidProgressWithRatio:(NSNumber *)ratio;
- (void)requestDidCompleteWithResponse:(NSHTTPURLResponse *)response;
- (void)requestDidFailWithError:(NSError *)error;

- (void)finish;

@end
