// Created by Satoshi Nakagawa <psychs AT limechat DOT net> <http://github.com/psychs/limechat>
// Modifications by Michael Morris <mikey AT codeux DOT com> <http://github.com/mikemac11/Textual>
// You can redistribute it and/or modify it under the new BSD license.

#import <Cocoa/Cocoa.h>

extern NSString* logEscape(NSString* s);

@interface LogRenderer : NSObject

+ (void)setUp;
+ (NSString*)renderBody:(NSString*)body 
				nolinks:(BOOL)showLinks 
			   keywords:(NSArray*)keywords 
		   excludeWords:(NSArray*)excludeWords 
		 exactWordMatch:(BOOL)exactWordMatch 
			highlighted:(BOOL*)highlighted 
			  URLRanges:(NSArray**)urlRanges;

+ (id)renderBody:(NSString*)body 
		 nolinks:(BOOL)showLinks 
		keywords:(NSArray*)keywords 
	excludeWords:(NSArray*)excludeWords 
  exactWordMatch:(BOOL)exactWordMatch 
	 highlighted:(BOOL*)highlighted 
	   URLRanges:(NSArray**)urlRanges
attributedString:(BOOL)attributed;

@end