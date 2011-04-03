//
//  MachineConnectionBase.h
//  PlexPad
//
//  Created by Frank Bauer on 19.01.11.
//  Copyright 2011 ambertation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Machine.h"

typedef NSUInteger MachineConnectionPriority;
extern const MachineConnectionPriority MachineConnectionPriorityHigh;
extern const MachineConnectionPriority MachineConnectionPriorityNormal;
extern const MachineConnectionPriority MachineConnectionPriorityLow;
extern const MachineConnectionPriority MachineConnectionPriorityIgnore;

@class MachineManager;
@interface MachineConnectionBase : NSObject<NSCoding> {
	NSDate* lastFullConnectionStateUpdate;
	NSString* hostName;
	NSUInteger port;
	NSString* ip;
	NSDate* lastSeen;
	NSString* etherID;
    
	NSString* machineID;
	NSString* versionStr;
	
	Machine* machine;
	
    MachineStateRecord stateRecord;
	BOOL stateUpdateRunning;
	NSTimeInterval updateTime;
	
	
	NSArray* clientConnections;
    
    NSString* qualityValues;
    NSString* qualityBitrates;
    NSString* qualityHeights;
    
    MachineConnectionPriority priority;
}
+(MachineConnectionBase*)machineConnectionForHostName:(NSString*)hostName ip:(NSString*)ip port:(NSUInteger)port etherID:(NSString*)mac;
-(id)initForHostName:(NSString*)hostName ip:(NSString*)ip port:(NSUInteger)port etherID:(NSString*)mac;

-(Machine*)machineWithServerName:(NSString*)serverName manager:(MachineManager*)parent;
-(BOOL)endpointIsMachine:(Machine*)m;

@property (readwrite) MachineConnectionPriority priority;
@property (readwrite, retain) NSString* hostName;
@property (readwrite) NSUInteger port;
@property (readwrite, retain) NSString* ip;
@property (readonly, retain) NSDate* lastSeen;
@property (readwrite, retain) NSString* etherID;
@property (readonly, retain) NSString* machineID;
@property (readonly, retain) NSString* suggestedServerName;

@property (readwrite, retain) NSString* versionStr;
@property (readwrite, retain) NSString* qualityValues;
@property (readwrite, retain) NSString* qualityBitrates;
@property (readwrite, retain) NSString* qualityHeights;

@property (readonly, assign) BOOL isUsedToConnect;
@property (readonly, assign) BOOL isComplete;

@property (readonly) BOOL inLocalNetwork;
@property (readonly) BOOL canConnect;
@property (readonly) BOOL isOnline;
@property (readonly) BOOL authenticationNeeded;
@property (readonly) NSTimeInterval lastStateUpdateTime;
@property (readonly) NSString* type;
@property (readonly, retain) NSArray* clientConnections;

@property (readwrite, assign) Machine* machine;
-(void)updateMachine;
-(void)machineWillChangeTo:(Machine*)m;
-(void)machineDidChangeFrom:(Machine*)m;

-(void)startUpdateConnectionState;
-(void)updateLocalNetwork;
-(void)updateCanConnect;
-(void)upddateEtherID;

-(void)didUpdateConnectionState;
-(void)didCancelUpdateConnectionState;

-(int)score;
-(BOOL)connectionIsBetterThan:(MachineConnectionBase*)c;
-(void)setNeedsUpdate;

-(void)wol;
@end
