//
//  PlexMediaPart.h
//  PlexPad
//
//  Created by Frank Bauer on 20.03.11.
//  Copyright 2011 Ambertation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlexDirectory.h"
#import "PlexMediaStream.h"

@class PlexMediaStream, PlexMediaObject, PlexMediaContainer;
@interface PlexMediaPart : PlexDirectory {
    
}

-(NSArray*)mediaStreams;
-(NSArray*)streamsOfType:(PlexMediaStreamType)t forLangauge:(NSString*)langFilterOrNil haveFallback:(BOOL)fallback;
-(NSArray*)audioStreamsForLanguage:(NSString*)langFilterOrNil haveFallback:(BOOL)fallback;
-(NSArray*)videoStreamsForLanguage:(NSString*)langFilterOrNil haveFallback:(BOOL)fallback;
-(NSArray*)subtitleStreamsForLanguage:(NSString*)langFilterOrNil haveFallback:(BOOL)fallback;

-(void)setSubtitleStream:(PlexMediaStream*)streamOrNil;
-(void)setAudioStream:(PlexMediaStream*)streamOrNil;

-(PlexMediaObject*)parentMediaObject;
-(PlexMedia*)parentMedia;

-(NSURL*)mediaURL;
-(NSURL*)mediaStreamURL;

-(PlexMediaContainer*)contents;
@end
