// Created by Satoshi Nakagawa <psychs AT limechat DOT net> <http://github.com/psychs/limechat>
// Modifications by Michael Morris <mikey AT codeux DOT com> <http://github.com/mikemac11/Textual>
// You can redistribute it and/or modify it under the new BSD license.

#import <Cocoa/Cocoa.h>
#import "TCPClient.h"
#import "Timer.h"

@interface IRCConnection : NSObject
{
	id delegate;
	
	NSString* host;
	NSInteger port;
	NSStringEncoding encoding;
	
	NSString* proxyHost;
	NSInteger proxyPort;
	NSString* proxyUser;
	NSInteger socksVersion;
	NSString* proxyPassword;
	
	TCPClient* conn;
	
	Timer* timer;
	NSInteger maxMsgCount;
	NSMutableArray* sendQueue;
	
	BOOL useSystemSocks;
	BOOL loggedIn;
	BOOL useSocks;
	BOOL sending;
	BOOL useSSL;
}

@property (nonatomic, assign) id delegate;
@property (nonatomic, assign) Timer* timer;
@property (nonatomic, retain) NSString* host;
@property (nonatomic, assign) NSInteger port;
@property (nonatomic, assign) BOOL useSSL;
@property (nonatomic, assign) NSStringEncoding encoding;
@property (nonatomic, assign) BOOL useSystemSocks;
@property (nonatomic, assign) BOOL useSocks;
@property (nonatomic, assign) NSInteger socksVersion;
@property (nonatomic, assign) NSInteger maxMsgCount;
@property (nonatomic, retain) NSString* proxyHost;
@property (nonatomic, assign) NSInteger proxyPort;
@property (nonatomic, retain) NSString* proxyUser;
@property (nonatomic, retain) NSString* proxyPassword;
@property (nonatomic, readonly) BOOL active;
@property (nonatomic, readonly) BOOL connecting;
@property (nonatomic, readonly) BOOL connected;
@property (nonatomic, readonly) BOOL readyToSend;
@property (nonatomic, assign) BOOL loggedIn;
@property (nonatomic, retain) TCPClient* conn;
@property (nonatomic, retain) NSMutableArray* sendQueue;
@property (nonatomic, assign) BOOL sending;

- (void)open;
- (void)close;
- (void)clearSendQueue;
- (void)sendLine:(NSString*)line;

- (NSData*)convertToCommonEncoding:(NSString*)s;
@end

@interface NSObject (IRCConnectionDelegate)
- (void)ircConnectionDidConnect:(IRCConnection*)sender;
- (void)ircConnectionDidDisconnect:(IRCConnection*)sender;
- (void)ircConnectionDidError:(NSString*)error;
- (void)ircConnectionDidReceive:(NSData*)data;
- (void)ircConnectionWillSend:(NSString*)line;
@end