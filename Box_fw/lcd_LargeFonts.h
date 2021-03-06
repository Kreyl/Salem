/*
 * lcd_LargeFonts.h
 *
 *  Created on: Dec 21, 2013
 *      Author: kreyl
 */

#ifndef LCD_LARGEFONTS_H_
#define LCD_LARGEFONTS_H_

#if 1 // Tahoma11x16
const uint8_t Tahoma11x16[] = {
        46, // First symbol's code
        11, // Max width
        2,  // Height
        0x03, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char .
        0x08, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x30, 0x00, 0x0E, 0x80, 0x01, 0x70, 0x00, 0x0C, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char /
        0x09, 0xF8, 0x07, 0xFC, 0x0F, 0x06, 0x18, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x06, 0x18, 0xFC, 0x0F, 0xF8, 0x07, 0x00, 0x00, 0x00, 0x00,  // Code for char 0
        0x08, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x08, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 1
        0x09, 0x0C, 0x10, 0x0E, 0x18, 0x02, 0x1C, 0x02, 0x16, 0x02, 0x13, 0x82, 0x11, 0xC6, 0x10, 0x7C, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00,  // Code for char 2
        0x09, 0x0C, 0x0C, 0x0E, 0x1C, 0x02, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0xE6, 0x18, 0xBC, 0x0F, 0x18, 0x07, 0x00, 0x00, 0x00, 0x00,  // Code for char 3
        0x0A, 0x80, 0x01, 0x40, 0x01, 0x20, 0x01, 0x10, 0x01, 0x08, 0x01, 0x04, 0x01, 0xFE, 0x1F, 0xFE, 0x1F, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00,  // Code for char 4
        0x09, 0x00, 0x0C, 0x3E, 0x1C, 0x3E, 0x10, 0x22, 0x10, 0x22, 0x10, 0x22, 0x10, 0x62, 0x18, 0xC2, 0x0F, 0x82, 0x07, 0x00, 0x00, 0x00, 0x00,  // Code for char 5
        0x09, 0xF0, 0x07, 0xF8, 0x0F, 0x2C, 0x18, 0x26, 0x10, 0x22, 0x10, 0x22, 0x10, 0x62, 0x18, 0xC2, 0x0F, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00,  // Code for char 6
        0x09, 0x02, 0x00, 0x02, 0x00, 0x02, 0x18, 0x02, 0x1E, 0x82, 0x07, 0xE2, 0x01, 0x7A, 0x00, 0x1E, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 7
        0x09, 0x18, 0x07, 0xBC, 0x0F, 0xE6, 0x18, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0xE6, 0x18, 0xBC, 0x0F, 0x18, 0x07, 0x00, 0x00, 0x00, 0x00,  // Code for char 8
        0x09, 0x78, 0x00, 0xFC, 0x10, 0x86, 0x11, 0x02, 0x11, 0x02, 0x11, 0x02, 0x19, 0x06, 0x0D, 0xFC, 0x07, 0xF8, 0x03, 0x00, 0x00, 0x00, 0x00,  // Code for char 9
        0x04, 0x00, 0x00, 0x00, 0x00, 0x70, 0x1C, 0x70, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   // Code for char :
        };
#endif

#if 1 // Times_New_Roman18x16
const uint8_t Times_New_Roman18x16[] = {
        32, // First symbol's code
        18, // Max width
        2,  // Height
        0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char
        0x04, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x19, 0x3E, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char !
        0x07, 0x00, 0x00, 0x3E, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char "
        0x0A, 0x20, 0x02, 0x20, 0x32, 0xA0, 0x0F, 0xF8, 0x02, 0x26, 0x02, 0x20, 0x32, 0xA0, 0x0F, 0xF8, 0x02, 0x26, 0x02, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char #
        0x08, 0x00, 0x00, 0x38, 0x18, 0x7C, 0x30, 0xC4, 0x20, 0xFE, 0x7F, 0x04, 0x23, 0x0C, 0x3E, 0x18, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char $
        0x10, 0x7C, 0x00, 0xFE, 0x00, 0x82, 0x00, 0x82, 0x10, 0xFE, 0x0C, 0x7C, 0x02, 0x00, 0x01, 0x80, 0x00, 0x40, 0x00, 0x30, 0x00, 0x88, 0x0F, 0xC4, 0x1F, 0x42, 0x10, 0x40, 0x10, 0xC0, 0x1F, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00,  // Code for char %
        0x0E, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x1F, 0x00, 0x19, 0xBC, 0x10, 0xFE, 0x10, 0xC2, 0x11, 0xA2, 0x0F, 0x22, 0x0E, 0x1C, 0x0C, 0x40, 0x12, 0xC0, 0x11, 0x40, 0x10, 0x40, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char &
        0x03, 0x00, 0x00, 0x3E, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char '
        0x05, 0x00, 0x00, 0xE0, 0x0F, 0xF8, 0x3F, 0x0C, 0x60, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char (
        0x04, 0x02, 0x80, 0x0C, 0x60, 0xF8, 0x3F, 0xE0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char )
        0x08, 0x00, 0x00, 0x48, 0x00, 0x48, 0x00, 0x30, 0x00, 0xFE, 0x01, 0x30, 0x00, 0x48, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char *
        0x0B, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0xFE, 0x0F, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char +
        0x04, 0x00, 0x00, 0x00, 0x98, 0x00, 0x58, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ,
        0x05, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char -
        0x05, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char .
        0x05, 0x00, 0x30, 0x00, 0x0E, 0xC0, 0x01, 0x38, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char /
        0x08, 0xF0, 0x03, 0xFC, 0x0F, 0x06, 0x18, 0x02, 0x10, 0x02, 0x10, 0x06, 0x18, 0xFC, 0x0F, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 0
        0x07, 0x00, 0x00, 0x04, 0x10, 0x04, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 1
        0x08, 0x08, 0x10, 0x04, 0x18, 0x02, 0x1C, 0x02, 0x1B, 0x86, 0x19, 0x7E, 0x18, 0x3C, 0x18, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 2
        0x08, 0x0C, 0x18, 0x04, 0x18, 0x02, 0x10, 0x42, 0x10, 0x66, 0x10, 0xFE, 0x08, 0xDC, 0x0F, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 3
        0x08, 0x00, 0x03, 0x80, 0x02, 0x60, 0x02, 0x10, 0x02, 0x08, 0x02, 0xFE, 0x1F, 0xFE, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 4
        0x07, 0x00, 0x18, 0x20, 0x18, 0x3C, 0x10, 0x36, 0x10, 0x66, 0x10, 0xE6, 0x08, 0xC6, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 5
        0x08, 0xC0, 0x07, 0xF0, 0x0F, 0x58, 0x18, 0x2C, 0x10, 0x24, 0x10, 0x66, 0x18, 0xC2, 0x0F, 0x82, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 6
        0x08, 0x08, 0x00, 0x06, 0x00, 0x06, 0x10, 0x06, 0x0E, 0x86, 0x01, 0x76, 0x00, 0x0E, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 7
        0x08, 0x00, 0x00, 0x1C, 0x0F, 0xBE, 0x1F, 0xE2, 0x18, 0x42, 0x10, 0xE2, 0x10, 0x9E, 0x0F, 0x0C, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 8
        0x08, 0x78, 0x10, 0xFC, 0x10, 0x86, 0x11, 0x02, 0x09, 0x02, 0x0D, 0x06, 0x07, 0xFC, 0x03, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 9
        0x03, 0x00, 0x00, 0x30, 0x18, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char :
        0x04, 0x00, 0x00, 0x30, 0x98, 0x30, 0x58, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ;
        0x0A, 0x40, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0x10, 0x01, 0x10, 0x01, 0x08, 0x02, 0x08, 0x02, 0x08, 0x02, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char <
        0x0A, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char =
        0x0A, 0x04, 0x04, 0x08, 0x02, 0x08, 0x02, 0x08, 0x02, 0x10, 0x01, 0x10, 0x01, 0xA0, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char >
        0x08, 0x00, 0x00, 0x1C, 0x00, 0x1A, 0x00, 0x02, 0x1B, 0x82, 0x18, 0x46, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ?
        0x11, 0x00, 0x00, 0xE0, 0x0F, 0x38, 0x30, 0x04, 0x40, 0x82, 0x87, 0xE1, 0x8F, 0x71, 0x88, 0x19, 0x84, 0x0D, 0x84, 0x05, 0x8E, 0x89, 0x8F, 0xF9, 0x88, 0x1D, 0x88, 0x03, 0x44, 0x06, 0x23, 0xF8, 0x10, 0x00, 0x08, 0x00, 0x00,  // Code for char @
        0x0D, 0x00, 0x10, 0x00, 0x18, 0x00, 0x1C, 0x80, 0x13, 0x60, 0x01, 0x18, 0x01, 0x06, 0x01, 0x3E, 0x01, 0xF8, 0x11, 0xC0, 0x1F, 0x00, 0x1E, 0x00, 0x18, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char A
        0x0B, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0xFE, 0x18, 0xBC, 0x0F, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char B
        0x0C, 0x00, 0x00, 0xE0, 0x03, 0xF8, 0x07, 0x0C, 0x0C, 0x04, 0x18, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x04, 0x10, 0x04, 0x08, 0x1E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char C
        0x0C, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x06, 0x08, 0x0C, 0x0C, 0xF8, 0x07, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char D
        0x0B, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0xF2, 0x11, 0x02, 0x10, 0x0E, 0x18, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char E
        0x0A, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x42, 0x10, 0x42, 0x10, 0x42, 0x00, 0xF2, 0x01, 0x02, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char F
        0x0E, 0x00, 0x00, 0xE0, 0x03, 0xF8, 0x07, 0x0C, 0x0E, 0x04, 0x08, 0x02, 0x18, 0x02, 0x10, 0x02, 0x10, 0x42, 0x10, 0x44, 0x10, 0xC4, 0x1F, 0xDE, 0x0F, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char G
        0x0D, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x42, 0x10, 0x42, 0x10, 0x40, 0x00, 0x42, 0x10, 0x42, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x02, 0x10, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char H
        0x06, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x02, 0x10, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char I
        0x07, 0x00, 0x08, 0x02, 0x18, 0x02, 0x10, 0xFE, 0x0F, 0xFE, 0x07, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char J
        0x0D, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x42, 0x10, 0xC2, 0x10, 0xA0, 0x01, 0x10, 0x03, 0x0A, 0x16, 0x06, 0x1C, 0x02, 0x18, 0x02, 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char K
        0x0B, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x02, 0x10, 0x02, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x18, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char L
        0x10, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0x0E, 0x10, 0x3C, 0x10, 0xF0, 0x01, 0x80, 0x07, 0x00, 0x1E, 0x00, 0x06, 0xC0, 0x01, 0x30, 0x10, 0x0C, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x02, 0x10, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00,  // Code for char M
        0x0D, 0x02, 0x10, 0x06, 0x10, 0xFE, 0x1F, 0x1C, 0x10, 0x38, 0x10, 0x70, 0x00, 0xC0, 0x00, 0x80, 0x03, 0x02, 0x07, 0x02, 0x0E, 0xFE, 0x1F, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char N
        0x0D, 0x00, 0x00, 0xE0, 0x03, 0xF8, 0x07, 0x1C, 0x0C, 0x04, 0x08, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x06, 0x08, 0x0C, 0x0C, 0xF8, 0x07, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char O
        0x0A, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x82, 0x10, 0x82, 0x10, 0x82, 0x00, 0xC6, 0x00, 0x7C, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char P
        0x0D, 0x00, 0x00, 0xE0, 0x03, 0xF8, 0x07, 0x0C, 0x0C, 0x04, 0x18, 0x02, 0x30, 0x02, 0x30, 0x02, 0x70, 0x02, 0xD0, 0x04, 0x88, 0x0C, 0x8C, 0xF8, 0x07, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char Q
        0x0D, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x82, 0x10, 0x82, 0x10, 0x82, 0x01, 0x46, 0x03, 0x7C, 0x06, 0x38, 0x0C, 0x00, 0x18, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char R
        0x0A, 0x00, 0x00, 0x18, 0x1E, 0x3C, 0x0C, 0x66, 0x08, 0x62, 0x10, 0xC2, 0x10, 0xC2, 0x10, 0x84, 0x19, 0x9E, 0x0F, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char S
        0x0C, 0x0E, 0x00, 0x06, 0x00, 0x02, 0x00, 0x02, 0x10, 0x02, 0x10, 0xFE, 0x1F, 0xFE, 0x1F, 0x02, 0x10, 0x02, 0x10, 0x02, 0x00, 0x06, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char T
        0x0D, 0x02, 0x00, 0x02, 0x00, 0xFE, 0x07, 0xFE, 0x0F, 0x02, 0x18, 0x02, 0x10, 0x00, 0x10, 0x00, 0x10, 0x02, 0x10, 0x02, 0x08, 0xFE, 0x07, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char U
        0x0D, 0x02, 0x00, 0x02, 0x00, 0x0E, 0x00, 0x3E, 0x00, 0xF2, 0x00, 0xC0, 0x03, 0x00, 0x0F, 0x00, 0x1C, 0x00, 0x03, 0xE2, 0x00, 0x1A, 0x00, 0x06, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char V
        0x12, 0x02, 0x00, 0x02, 0x00, 0x0E, 0x00, 0x7E, 0x00, 0xF2, 0x03, 0x80, 0x0F, 0x02, 0x1C, 0x02, 0x03, 0xE6, 0x00, 0x3E, 0x00, 0xF2, 0x01, 0x80, 0x0F, 0x00, 0x1C, 0x00, 0x07, 0xE2, 0x00, 0x1E, 0x00, 0x06, 0x00, 0x02, 0x00,  // Code for char W
        0x0D, 0x02, 0x10, 0x02, 0x10, 0x06, 0x18, 0x0E, 0x14, 0x3A, 0x02, 0x72, 0x01, 0xC0, 0x00, 0xA0, 0x03, 0x10, 0x17, 0x0A, 0x1C, 0x06, 0x18, 0x02, 0x10, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char X
        0x0D, 0x02, 0x00, 0x02, 0x00, 0x06, 0x00, 0x0E, 0x00, 0x3A, 0x10, 0x72, 0x10, 0xC0, 0x1F, 0x80, 0x1F, 0x40, 0x10, 0x32, 0x10, 0x0A, 0x00, 0x06, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char Y
        0x0B, 0x00, 0x10, 0x0E, 0x18, 0x02, 0x1E, 0x02, 0x17, 0x82, 0x11, 0xC2, 0x10, 0x72, 0x10, 0x3A, 0x10, 0x0E, 0x10, 0x06, 0x18, 0x02, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char Z
        0x05, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char [
        0x05, 0x06, 0x00, 0x38, 0x00, 0xC0, 0x01, 0x00, 0x0E, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char BackSlash
        0x05, 0x00, 0x00, 0x01, 0x80, 0x01, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ]
        0x08, 0x80, 0x00, 0x70, 0x00, 0x0C, 0x00, 0x02, 0x00, 0x02, 0x00, 0x0C, 0x00, 0x70, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ^
        0x0A, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char _
        0x04, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char `
        0x08, 0x00, 0x00, 0x60, 0x0E, 0x70, 0x1F, 0x10, 0x11, 0x90, 0x10, 0xF0, 0x1F, 0xE0, 0x1F, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char a
        0x09, 0x02, 0x00, 0xFF, 0x0F, 0xFF, 0x1F, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x18, 0xE0, 0x0F, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char b
        0x08, 0x00, 0x00, 0xC0, 0x07, 0xE0, 0x0F, 0x30, 0x1C, 0x10, 0x18, 0x10, 0x18, 0x30, 0x08, 0x60, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char c
        0x0A, 0x00, 0x00, 0xC0, 0x07, 0xE0, 0x0F, 0x30, 0x18, 0x10, 0x10, 0x10, 0x10, 0x22, 0x08, 0xFF, 0x1F, 0xFF, 0x1F, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char d
        0x08, 0x00, 0x00, 0xC0, 0x07, 0xE0, 0x0F, 0xB0, 0x1C, 0x90, 0x18, 0x90, 0x18, 0xE0, 0x08, 0xC0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char e
        0x08, 0x10, 0x10, 0x10, 0x10, 0xFC, 0x1F, 0xFE, 0x1F, 0x11, 0x10, 0x11, 0x10, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char f
        0x09, 0x00, 0x40, 0xE0, 0xAC, 0xF0, 0x9B, 0x10, 0x9B, 0x10, 0x9A, 0x30, 0x9A, 0xE0, 0x9B, 0xE0, 0x99, 0x20, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char g
        0x09, 0x02, 0x10, 0xFF, 0x1F, 0xFF, 0x1F, 0x20, 0x10, 0x10, 0x00, 0x10, 0x10, 0xF0, 0x1F, 0xE0, 0x1F, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char h
        0x04, 0x20, 0x10, 0xF3, 0x1F, 0xF3, 0x1F, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char i
        0x03, 0x20, 0x80, 0xF3, 0x7F, 0xF3, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char j
        0x09, 0x02, 0x10, 0xFF, 0x1F, 0xFF, 0x1F, 0x00, 0x11, 0x80, 0x03, 0x50, 0x16, 0x30, 0x1C, 0x10, 0x18, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char k
        0x04, 0x02, 0x10, 0xFF, 0x1F, 0xFF, 0x1F, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char l
        0x0E, 0x20, 0x10, 0xF0, 0x1F, 0xF0, 0x1F, 0x20, 0x10, 0x10, 0x00, 0x10, 0x10, 0xF0, 0x1F, 0xE0, 0x1F, 0x20, 0x10, 0x10, 0x00, 0x10, 0x10, 0xF0, 0x1F, 0xE0, 0x1F, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char m
        0x09, 0x20, 0x10, 0xF0, 0x1F, 0xF0, 0x1F, 0x20, 0x10, 0x10, 0x00, 0x10, 0x10, 0xF0, 0x1F, 0xE0, 0x1F, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char n
        0x09, 0x00, 0x00, 0xC0, 0x07, 0xE0, 0x0F, 0x30, 0x18, 0x10, 0x10, 0x10, 0x10, 0x30, 0x18, 0xE0, 0x0F, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char o
        0x09, 0x20, 0x80, 0xF0, 0xFF, 0xF0, 0xFF, 0x20, 0x88, 0x10, 0x10, 0x10, 0x10, 0x30, 0x18, 0xE0, 0x0F, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char p
        0x0A, 0x00, 0x00, 0xC0, 0x07, 0xE0, 0x0F, 0x30, 0x18, 0x10, 0x10, 0x10, 0x10, 0x20, 0x88, 0xF0, 0xFF, 0xF0, 0xFF, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char q
        0x06, 0x20, 0x10, 0xF0, 0x1F, 0xF0, 0x1F, 0x20, 0x10, 0x10, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char r
        0x07, 0x00, 0x00, 0xE0, 0x1C, 0x90, 0x09, 0x90, 0x11, 0x10, 0x13, 0x20, 0x13, 0x70, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char s
        0x05, 0x10, 0x00, 0xFC, 0x1F, 0xFE, 0x1F, 0x10, 0x10, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char t
        0x09, 0x10, 0x00, 0xF0, 0x0F, 0xF0, 0x1F, 0x00, 0x10, 0x00, 0x10, 0x10, 0x08, 0xF0, 0x1F, 0xF0, 0x1F, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char u
        0x09, 0x10, 0x00, 0x70, 0x00, 0xF0, 0x03, 0x90, 0x0F, 0x00, 0x1C, 0x00, 0x0C, 0x90, 0x03, 0x70, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char v
        0x0D, 0x10, 0x00, 0x70, 0x00, 0xF0, 0x03, 0x90, 0x0F, 0x00, 0x1C, 0x10, 0x07, 0xF0, 0x00, 0xF0, 0x03, 0x90, 0x0F, 0x00, 0x1C, 0x90, 0x07, 0x70, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char w
        0x09, 0x10, 0x10, 0x30, 0x18, 0x70, 0x14, 0xD0, 0x02, 0x80, 0x03, 0x50, 0x16, 0x30, 0x1C, 0x10, 0x18, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char x
        0x09, 0x10, 0x80, 0x70, 0x80, 0xF0, 0x81, 0x90, 0xC7, 0x00, 0x3E, 0x00, 0x0E, 0x90, 0x01, 0x70, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char y
        0x08, 0x00, 0x10, 0x30, 0x18, 0x10, 0x1E, 0x10, 0x17, 0x90, 0x11, 0xF0, 0x10, 0x70, 0x10, 0x10, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char z
        0x06, 0x00, 0x00, 0x00, 0x01, 0x80, 0x02, 0xFC, 0x7E, 0x7E, 0xFC, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char {
        0x02, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char |
        0x06, 0x00, 0x00, 0x02, 0x80, 0x7E, 0xFC, 0xFC, 0x7E, 0x80, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char }
        0x09, 0x00, 0x03, 0x80, 0x00, 0x80, 0x00, 0x80, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0x02, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ~
        0x04, 0xFE, 0x0F, 0x02, 0x08, 0x02, 0x08, 0xFE, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   // Code for char 
        };
#endif

#endif /* LCD_LARGEFONTS_H_ */
