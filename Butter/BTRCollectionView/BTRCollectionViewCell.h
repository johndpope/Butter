//
//  BTRCollectionViewCell.h
//
//  Original Source: Copyright (c) 2012 Peter Steinberger. All rights reserved.
//  AppKit Port: Copyright (c) 2012 Indragie Karunaratne and Jonathan Willing. All rights reserved.
//

#import "BTRCollectionViewCommon.h"
#import "BTRView.h"

@class BTRCollectionViewLayout, BTRCollectionView, BTRCollectionViewLayoutAttributes;

@interface BTRCollectionReusableView : BTRView

@property (nonatomic, readonly, copy) NSString *reuseIdentifier;

// Override in subclasses. Called before instance is returned to the reuse queue.
- (void)prepareForReuse;

// Apply layout attributes on cell.
- (void)applyLayoutAttributes:(BTRCollectionViewLayoutAttributes *)layoutAttributes;

- (void)willTransitionFromLayout:(BTRCollectionViewLayout *)oldLayout toLayout:(BTRCollectionViewLayout *)newLayout;
- (void)didTransitionFromLayout:(BTRCollectionViewLayout *)oldLayout toLayout:(BTRCollectionViewLayout *)newLayout;

@end

@interface BTRCollectionReusableView (Internal)
@property (nonatomic, unsafe_unretained) BTRCollectionView *collectionView;
@property (nonatomic, copy) NSString *reuseIdentifier;
@property (nonatomic, strong, readonly) BTRCollectionViewLayoutAttributes *layoutAttributes;
@end


@interface BTRCollectionViewCell : BTRCollectionReusableView

@property (nonatomic, readonly) BTRView *contentView; // add custom subviews to the cell's contentView

// Cells become highlighted when the user touches them.
// The selected state is toggled when the user lifts up from a highlighted cell.
// Override these methods to provide custom PS for a selected or highlighted state.
// The collection view may call the setters inside an animation block.
@property (nonatomic, getter=isSelected) BOOL selected;
@property (nonatomic, getter=isHighlighted) BOOL highlighted;

// The background view is a subview behind all other views.
// If selectedBackgroundView is different than backgroundView, it will be placed above the background view and animated in on selection.
@property (nonatomic, strong) NSView *backgroundView;
@property (nonatomic, strong) NSView *selectedBackgroundView;

@end
