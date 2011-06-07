//
//  PlexMediaObject + TVShows.h
//  PlexPad
//
//  Created by Frank Bauer on 13.02.11.
//  Copyright 2011 Ambertation. All rights reserved.
//

#import "PlexMediaObject.h"


@interface PlexMediaObject (TVShows)
-(PlexMediaObject*)parentShowMediaObject;
-(PlexMediaObject*)parentSeasonMediaObject;
-(NSString*)showTitle;
-(NSUInteger)episodeNr;
-(NSUInteger)seasonNr;

-(NSString*)caption;
-(NSString*)captionShort;
@end
