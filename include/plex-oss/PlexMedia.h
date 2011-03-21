//
//  PlexMedia.h
//  PlexPad
//
//  Created by Frank Bauer on 20.03.11.
//  Copyright 2011 Ambertation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlexDirectory.h"

@class PlexMediaPart, PlexMediaObject;
@interface PlexMedia : PlexDirectory {
    
}

-(NSArray*)mediaParts;
-(PlexMediaPart*)partAtIndex:(NSInteger)idx;
-(NSInteger)indexOfPart:(PlexMediaPart*)p;
-(PlexMediaObject*)parentMediaObject;

  

-(BOOL)canPlayWithoutTranscoder;
-(void)setCanPlayWithoutTranscoder:(BOOL)v;
-(BOOL)redirectionNeededBeforePlay;
@end
