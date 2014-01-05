//
//  JTTextView.h
//  JustType
//
//  Created by Alexander Koglin on 27.12.13.
//  Copyright (c) 2013 Alexander Koglin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JTTextController.h"

/**
 *  A view displaying text. It is a class derived from UITextView and tries not to change any behavior of the UITextView.
 */
@interface JTTextView : UITextView <JTTextControllerDelegate>

/**
 *  Indicates if syntax highlighting is turned on, i.e. if the currently selected word is highlighted with a certain color.
 */
@property (nonatomic, assign, getter = isSyntaxHighlightingUsed) BOOL useSyntaxHighlighting;

/**
 *  Indicates if syntax completion is turned on, i.e. if the currently selected word will trigger proposing suggestions to the user.
 */
@property (nonatomic, assign, getter = isSyntaxCompletionUsed) BOOL useSyntaxCompletion;

/**
 *  You can add your own highlighting style to a textView by creating and own UIView for highlighting, overwriting its drawRect: method and adding this highlightView to the textView.
 */
@property (nonatomic, retain) UIView *highlightView;

/**
 *  This is a delegate, which can be implemented by the caller of this
 textView to get informed, if the currently selected word changed or if suggestions for the currently selected word were chosen.
 */
@property (nonatomic, assign) id<JTTextSuggestionDelegate> textSuggestionDelegate;

/**
 *  This triggers the textView to move the cursor to the previous word. If it does not exist the cursor just stays where it was.
 */
- (void)moveToPreviousWord;

/**
 *  This triggers the textView to move the cursor to the next word.
 */
- (void)moveToNextWord;

/**
 *  This triggers the textView to move the cursor to the previous letter. If it does not exist the cursor just stays where it was.
 */
- (void)moveToPreviousLetter;

/**
 *  This triggers the textView to move the cursor to the next letter.
 */
- (void)moveToNextLetter;

/**
 *  This triggers the textView to select the previous suggestion.
 */
- (void)selectPreviousSuggestion;

/**
 *  This triggers the textView to select the next suggestion.
 */
- (void)selectNextSuggestion;

/**
 *  This triggers the textView to select a suggestion with a suggestion index. The index can be -1 if no suggestion should be selected.
 *
 *  @param index suggestion index that sets the selected suggestion of this word
 */
- (void)selectSuggestionByIndex:(NSInteger)index;

@end
