
const uint8_t textDesc2[]= {
#if DIGIT_3_FLIP
    0x99,0x88,  // ЧА txClock
    0x82,0x91,  // БУ txAlarm
  #if OPT_DATE_DSP
    0x99,0xC6,  // ЧС txDate
  #endif
  #if OPT_DAY_DSP
    0x99,0x89,  // ЧН txDay
  #endif
  #if OPT_TEMP_DSP
    0xCE,0x8C,  // ГР txTemp
  #endif
    #if OPT_UNITS_GROUP
        0xC8,0x92,  // US
        0xB0,0xC1,  // EU
    #else
      #if OPT_TIME_FORMAT_SELECTABLE
        0xCF,0xA4,  // 12
        0xA4,0x99,  // 24
      #endif
      #if OPT_TEMP_UNITS_SELECTABLE
        0xFF,0x8E,  // F
        0xFF,0xC6,  // C
      #endif
    #endif
    0x91,0xC6,  // УС
#else
    0x99,0x88,  // ЧА txClock
    0x82,0x91,  // БУ txAlarm
  #if OPT_DATE_DSP
    0x99,0xC6,  // ЧС txDate
  #endif
  #if OPT_DAY_DSP
    0x99,0x89,  // ЧН txDay
  #endif
  #if OPT_TEMP_DSP
    0xCE,0x8C,  // ГР txTemp
 #endif
    #if OPT_UNITS_GROUP
        0xC1,0x92,  // US
        0x86,0xC1,  // EU
    #else
      #if OPT_TIME_FORMAT_SELECTABLE
        0xF9,0xA4,  // 12
        0xA4,0x99,  // 24
      #endif
      #if OPT_TEMP_UNITS_SELECTABLE
        0xFF,0x8E,  // F
        0xFF,0xC6,  // C
      #endif
    #endif
    0x91,0xC6,  // УС
#endif
};

const uint8_t textDesc4[]= {
#if DIGIT_3_FLIP
    0xC6,0xCE,0x89,0xFF,    // СГН
    0xB0,0xBF,0x89,0xFF,    // Э-Н
    0x89,0x88,0xF0,0xFF,    // НАС
    #if OPT_UNITS_GROUP
        0xC1,0xAB,0xFD,0x87,    // Unit
    #else
      #if OPT_TIME_FORMAT_SELECTABLE
        0xF9,0x24,0xA4,0x99,    // 12.24
      #endif
      #if OPT_DATE_FORMAT_SELECTABLE
        0xF9,0x24,0x86,0xF9,    // 12.31
        0xB0,0x79,0xCF,0xA4,    // 31.12
      #endif
    #endif
    0xC6,0x80,0xB0,0xFF,    // СВЕ
    0xCE,0x8C,0x81,0xFF,    // ГРА
  #if OPT_DATE_FORMAT_SELECTABLE
    0xA1,0x88,0xB8,0x86,    // DAtE
  #endif
  #if OPT_TEMP_UNITS_SELECTABLE
    0x87,0x86,0xC9,0x8C,    // TEMP
  #endif
    0x19,0xC6,0xF1,0xFF,    //Ч.СГ txChime

#else
    0xC6,0xCE,0x89,0xFF,    // СГН
    0xB0,0xBF,0x89,0xFF,    // Э-Н
    0x89,0x88,0xC6,0xFF,    // НАС
    #if OPT_UNITS_GROUP
        0xC1,0xAB,0xEF,0x87,    // Unit
    #else
      #if OPT_TIME_FORMAT_SELECTABLE
        0xF9,0x24,0xA4,0x99,    // 12.24
      #endif
      #if OPT_DATE_FORMAT_SELECTABLE
        0xF9,0x24,0xB0,0xF9,    // 12.31
        0xB0,0x79,0xF9,0xA4,    // 31.12
      #endif
    #endif
    0xC6,0x80,0x86,0xFF,    // СВЕ
    0xCE,0x8C,0x88,0xFF,    // ГРА
  #if OPT_DATE_FORMAT_SELECTABLE
    0xA1,0x88,0x87,0x86,    // DAtE
  #endif
  #if OPT_TEMP_UNITS_SELECTABLE
    0x87,0x86,0xC9,0x8C,    // TEMP
  #endif
    0x19,0xC6,0xCE,0xFF,    //Ч.СГ txChime
#endif
};

const uint8_t ledSegTB[]  = {
    0b11000000, // '0'  abcdef--
    0b11111001, // '1'  -bc-----
    0b10100100, // '2'  ab-de-g-
    0b10110000, // '3'  abcd--g-
    0b10011001, // '4'  -bc--fg-
    0b10010010, // '5'  a-cd-fg-
    0b10000010, // '6'  a-cdefg-
    0b11111000, // '7'  abc-----
    0b10000000, // '8'  abcdefg-
    0b10010000, // '9'  abcf-fg-
};

// Same digit pattern but for the up-side-down LED...
// This is for the special case where the usual HH:MM
// display has the --:X- LED installed with the decimal
// at the top to form the colon without a real clock LED
// This is "anode 2" in the clocks with 1 inch LED's.
//
// BT = Bottom to Top
//
const uint8_t ledSegBT[] ={
#if DIGIT_3_FLIP
    0b11000000, // '0'  abcdef--
    0b11001111, // '1'  ----ef--
    0b10100100, // '2'  ab-de-g-
    0b10000110, // '3'  a--defg-
    0b10001011, // '4'  --c-efg-
    0b10010010, // '5'  a-cd-fg-
    0b10010000, // '6'  abcd-fg-
    0b11000111, // '7'  ---def--
    0b10000000, // '8'  abcdefg-
    0b10000010, // '9'  a-cdefg-
#else
    0b11000000, // '0'  abcdef--
    0b11111001, // '1'  -bc-----
    0b10100100, // '2'  ab-de-g-
    0b10110000, // '3'  abcd--g-
    0b10011001, // '4'  -bc--fg-
    0b10010010, // '5'  a-cd-fg-
    0b10000010, // '6'  a-cdefg-
    0b11111000, // '7'  abc-----
    0b10000000, // '8'  abcdefg-
    0b10010000, // '9'  abcf-fg-
#endif
};
