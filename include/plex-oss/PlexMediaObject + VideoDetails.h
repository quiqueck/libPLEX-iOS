//
//  PlexMediaObject + VideoDetails.h
//  PlexPad
//
//  Created by Frank Bauer on 12.02.11.
//  Copyright 2011 Ambertation. All rights reserved.
//

#import "PlexMediaObject.h"
#import "PlexMediaStream.h"

@class PlexMediaPart;

@interface PlexMediaObject (VideoDetails)
-(PlexMediaObject*)loadVideoDetails;
-(PlexMediaPart*)partAtIndex:(NSUInteger)idx;

-(NSArray*)streamsOfType:(PlexMediaStreamType)t forLangauge:(NSString*)langFilterOrNil haveFallback:(BOOL)fallback;
-(NSArray*)audioStreamsForLanguage:(NSString*)langFilterOrNil haveFallback:(BOOL)fallback;
-(NSArray*)videoStreamsForLanguage:(NSString*)langFilterOrNil haveFallback:(BOOL)fallback;
-(NSArray*)subtitleStreamsForLanguage:(NSString*)langFilterOrNil haveFallback:(BOOL)fallback;

-(void)setAudioStream:(PlexMediaStream*)streamOrNil;
-(void)setSubtitleStream:(PlexMediaStream*)streamOrNil;

-(NSArray*)actors;
-(NSArray*)writers;
-(NSArray*)directors;
-(NSArray*)genres;
@end
