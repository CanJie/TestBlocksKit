//
//  NSObject+BKAssociatedObjects.h
//  BlocksKit
//

#import <Foundation/Foundation.h>

/** Objective-C wrapper for 10.6+ associated object API.

 In Mac OS X Snow Leopard and iOS 3.0, Apple introduced an addition to the
 Objective-C Runtime called associated objects. Associated objects allow for the
 pairing of a random key and object pair to be saved on an instance.

 In BlocksKit, associated objects allow us to emulate instance variables in the
 ategories we use.

 Class methods also exist for each association. These associations are unique to
 each class, and exist for the lifetime of the application unless set to `nil`.
 Each class is a unique meta-object; the ultimate singleton.

 Created by [Andy Matuschak](https://github.com/andymatuschak) as
 `AMAssociatedObjects`.
 */
@interface NSObject (BKAssociatedObjects)

/** Strongly associates an object with the reciever.

 The associated value is retained as if it were a property
 synthesized with `nonatomic` and `retain`.

 Using retained association is strongly recommended for most
 Objective-C object derivative of NSObject, particularly
 when it is subject to being externally released or is in an
 `NSAutoreleasePool`.

 @param value Any object.
 @param key A unique key pointer.
 */
//以OBJC_ASSOCIATION_RETAIN_NONATOMIC方式绑定关联对象
- (void)bk_associateValue:(id)value withKey:(const void *)key;

/** Strongly associates an object with the receiving class.

 @see associateValue:withKey:
 @param value Any object.
 @param key A unique key pointer.
 */
+ (void)bk_associateValue:(id)value withKey:(const void *)key;

/** Strongly, thread-safely associates an object with the reciever.

 The associated value is retained as if it were a property
 synthesized with `atomic` and `retain`.

 Using retained association is strongly recommended for most
 Objective-C object derivative of NSObject, particularly
 when it is subject to being externally released or is in an
 `NSAutoreleasePool`.

 @see associateValue:withKey:
 @param value Any object.
 @param key A unique key pointer.
 */
//以OBJC_ASSOCIATION_RETAIN方式绑定关联对象
- (void)bk_atomicallyAssociateValue:(id)value withKey:(const void *)key;

/** Strongly, thread-safely associates an object with the receiving class.

 @see associateValue:withKey:
 @param value Any object.
 @param key A unique key pointer.
 */
+ (void)bk_atomicallyAssociateValue:(id)value withKey:(const void *)key;

/** Associates a copy of an object with the reciever.

 The associated value is copied as if it were a property
 synthesized with `nonatomic` and `copy`.

 Using copied association is recommended for a block or
 otherwise `NSCopying`-compliant instances like NSString.

 @param value Any object, pointer, or value.
 @param key A unique key pointer.
 */
//以OBJC_ASSOCIATION_COPY_NONATOMIC方式绑定关联对象
- (void)bk_associateCopyOfValue:(id)value withKey:(const void *)key;

/** Associates a copy of an object with the receiving class.

 @see associateCopyOfValue:withKey:
 @param value Any object, pointer, or value.
 @param key A unique key pointer.
 */
+ (void)bk_associateCopyOfValue:(id)value withKey:(const void *)key;

/** Thread-safely associates a copy of an object with the reciever.

 The associated value is copied as if it were a property
 synthesized with `atomic` and `copy`.

 Using copied association is recommended for a block or
 otherwise `NSCopying`-compliant instances like NSString.

 @see associateCopyOfValue:withKey:
 @param value Any object, pointer, or value.
 @param key A unique key pointer.
 */
//以OBJC_ASSOCIATION_COPY方式绑定关联对象
- (void)bk_atomicallyAssociateCopyOfValue:(id)value withKey:(const void *)key;

/** Thread-safely associates a copy of an object with the receiving class.

 @see associateCopyOfValue:withKey:
 @param value Any object, pointer, or value.
 @param key A unique key pointer.
 */
+ (void)bk_atomicallyAssociateCopyOfValue:(id)value withKey:(const void *)key;

/** Weakly associates an object with the reciever.

 A weak association will cause the pointer to be set to zero
 or nil upon the disappearance of what it references;
 in other words, the associated object is not kept alive.

 @param value Any object.
 @param key A unique key pointer.
 */
//弱绑定
- (void)bk_weaklyAssociateValue:(__autoreleasing id)value withKey:(const void *)key;

/** Weakly associates an object with the receiving class.

 @see weaklyAssociateValue:withKey:
 @param value Any object.
 @param key A unique key pointer.
 */
+ (void)bk_weaklyAssociateValue:(__autoreleasing id)value withKey:(const void *)key;

#pragma mark -
/** Returns the associated value for a key on the reciever.

 @param key A unique key pointer.
 @return The object associated with the key, or `nil` if not found.
 */
- (id)bk_associatedValueForKey:(const void *)key;

/** Returns the associated value for a key on the receiving class.

 @see associatedValueForKey:
 @param key A unique key pointer.
 @return The object associated with the key, or `nil` if not found.
 */
+ (id)bk_associatedValueForKey:(const void *)key;

/** Returns the reciever to a clean state by removing all
 associated objects, releasing them if necessary. */
//删除所有绑定的关联对象
- (void)bk_removeAllAssociatedObjects;

/** Returns the recieving class to a clean state by removing
 all associated objects, releasing them if necessary. */
+ (void)bk_removeAllAssociatedObjects;

@end
