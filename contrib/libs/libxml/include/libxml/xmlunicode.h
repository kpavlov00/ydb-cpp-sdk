/* 
 * Summary: Unicode character APIs 
 * Description: API for the Unicode character APIs 
 * 
 * This file is automatically generated from the 
 * UCS description files of the Unicode Character Database 
 * http://www.unicode.org/Public/4.0-Update1/UCD-4.0.1.html 
 * using the genUnicode.py Python script. 
 * 
 * Generation date: Mon Mar 27 11:09:52 2006 
 * Sources: Blocks-4.0.1.txt UnicodeData-4.0.1.txt 
 * Author: Daniel Veillard 
 */ 
 
#ifndef __XML_UNICODE_H__ 
#define __XML_UNICODE_H__ 
 
#include "xmlversion.h" 
 
#ifdef LIBXML_UNICODE_ENABLED 
 
#ifdef __cplusplus 
extern "C" { 
#endif 
 
XMLPUBFUN int XMLCALL xmlUCSIsAegeanNumbers	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsAlphabeticPresentationForms	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsArabic	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsArabicPresentationFormsA	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsArabicPresentationFormsB	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsArmenian	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsArrows	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsBasicLatin	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsBengali	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsBlockElements	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsBopomofo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsBopomofoExtended	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsBoxDrawing	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsBraillePatterns	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsBuhid	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsByzantineMusicalSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKCompatibility	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKCompatibilityForms	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKCompatibilityIdeographs	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKCompatibilityIdeographsSupplement	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKRadicalsSupplement	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKSymbolsandPunctuation	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKUnifiedIdeographs	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKUnifiedIdeographsExtensionA	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCJKUnifiedIdeographsExtensionB	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCherokee	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCombiningDiacriticalMarks	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCombiningDiacriticalMarksforSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCombiningHalfMarks	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCombiningMarksforSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsControlPictures	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCurrencySymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCypriotSyllabary	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCyrillic	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCyrillicSupplement	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsDeseret	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsDevanagari	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsDingbats	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsEnclosedAlphanumerics	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsEnclosedCJKLettersandMonths	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsEthiopic	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGeneralPunctuation	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGeometricShapes	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGeorgian	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGothic	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGreek	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGreekExtended	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGreekandCoptic	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGujarati	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsGurmukhi	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHalfwidthandFullwidthForms	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHangulCompatibilityJamo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHangulJamo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHangulSyllables	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHanunoo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHebrew	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHighPrivateUseSurrogates	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHighSurrogates	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsHiragana	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsIPAExtensions	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsIdeographicDescriptionCharacters	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsKanbun	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsKangxiRadicals	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsKannada	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsKatakana	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsKatakanaPhoneticExtensions	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsKhmer	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsKhmerSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLao	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLatin1Supplement	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLatinExtendedA	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLatinExtendedB	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLatinExtendedAdditional	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLetterlikeSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLimbu	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLinearBIdeograms	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLinearBSyllabary	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsLowSurrogates	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMalayalam	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMathematicalAlphanumericSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMathematicalOperators	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMiscellaneousMathematicalSymbolsA	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMiscellaneousMathematicalSymbolsB	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMiscellaneousSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMiscellaneousSymbolsandArrows	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMiscellaneousTechnical	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMongolian	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMusicalSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsMyanmar	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsNumberForms	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsOgham	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsOldItalic	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsOpticalCharacterRecognition	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsOriya	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsOsmanya	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsPhoneticExtensions	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsPrivateUse	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsPrivateUseArea	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsRunic	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsShavian	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSinhala	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSmallFormVariants	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSpacingModifierLetters	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSpecials	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSuperscriptsandSubscripts	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSupplementalArrowsA	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSupplementalArrowsB	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSupplementalMathematicalOperators	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSupplementaryPrivateUseAreaA	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSupplementaryPrivateUseAreaB	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsSyriac	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsTagalog	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsTagbanwa	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsTags	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsTaiLe	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsTaiXuanJingSymbols	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsTamil	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsTelugu	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsThaana	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsThai	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsTibetan	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsUgaritic	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsUnifiedCanadianAboriginalSyllabics	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsVariationSelectors	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsVariationSelectorsSupplement	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsYiRadicals	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsYiSyllables	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsYijingHexagramSymbols	(int code); 
 
XMLPUBFUN int XMLCALL xmlUCSIsBlock	(int code, const char *block); 
 
XMLPUBFUN int XMLCALL xmlUCSIsCatC	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatCc	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatCf	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatCo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatCs	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatL	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatLl	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatLm	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatLo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatLt	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatLu	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatM	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatMc	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatMe	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatMn	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatN	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatNd	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatNl	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatNo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatP	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatPc	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatPd	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatPe	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatPf	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatPi	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatPo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatPs	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatS	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatSc	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatSk	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatSm	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatSo	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatZ	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatZl	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatZp	(int code); 
XMLPUBFUN int XMLCALL xmlUCSIsCatZs	(int code); 
 
XMLPUBFUN int XMLCALL xmlUCSIsCat	(int code, const char *cat); 
 
#ifdef __cplusplus 
} 
#endif 
 
#endif /* LIBXML_UNICODE_ENABLED */ 
 
#endif /* __XML_UNICODE_H__ */ 
