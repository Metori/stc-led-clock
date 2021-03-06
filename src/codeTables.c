
const uint8_t textDesc2[]= {
#if DIGIT_3_FLIP
    0xC6,0xC7,  // CL txClock
    0x88,0xC7,  // AL txAlarm
    0xC6,0x89,  // CH txChime
  #if OPT_DATE_DSP
    0xA1,0x88,  // dA txDate
  #endif
  #if OPT_DAY_DSP
    0xA1,0x91,  // dy txDay
  #endif
  #if OPT_TEMP_DSP
    0x87,0x8C,  // tP txTemp
  #endif
    #if OPT_UNITS_GROUP
        0xC8,0x92,  // US
        0xB0,0xC1   // EU
    #else
      #if OPT_TIME_FORMAT_SELECTABLE
        0xCF,0xA4,  // 12
        0xA4,0x99,  // 24
      #endif
      #if OPT_TEMP_UNITS_SELECTABLE
        0xFF,0x8E,  // F
        0xFF,0xC6   // C
      #endif
    #endif
#else
    0xC6,0xC7,  // CL txClock
    0x88,0xC7,  // AL txAlarm
    0xC6,0x89,  // CH txChime
  #if OPT_DATE_DSP
    0xA1,0x88,  // dA txDate
  #endif
  #if OPT_DAY_DSP
    0xA1,0x91,  // dy txDay
  #endif
  #if OPT_TEMP_DSP
    0x87,0x8C,  // tP txTemp
 #endif
    #if OPT_UNITS_GROUP
        0xC1,0x92,  // US
        0x86,0xC1   // EU
    #else
      #if OPT_TIME_FORMAT_SELECTABLE
        0xF9,0xA4,  // 12
        0xA4,0x99,  // 24
      #endif
      #if OPT_TEMP_UNITS_SELECTABLE
        0xFF,0x8E,  // F
        0xFF,0xC6   // C
      #endif
    #endif

#endif
};

const uint8_t textDesc4[]= {
#if DIGIT_3_FLIP
    0x92,0x86,0xB8,0xFF,    // SEt
    0x83,0x86,0xB0,0x8C,    // bEEP
    0xA1,0x92,0xA1,0xFF,    // dSP
    0xC6,0x8E,0x82,0xFF,    // CFg
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
    0x83,0xAF,0xB8,0xFF,    // brt
    0xC6,0x88,0xF8,0xFF,    // CAL
  #if OPT_DATE_FORMAT_SELECTABLE
    0xA1,0x88,0xB8,0x86,    // DAtE
  #endif
  #if OPT_TEMP_UNITS_SELECTABLE
    0x87,0x86,0xC9,0x8C,    // TEMP
  #endif

#else
    0x92,0x86,0x87,0xFF,    // SEt
    0x83,0x86,0x86,0x8C,    // bEEP
    0xA1,0x92,0x8C,0xFF,    // dSP
    0xC6,0x8E,0x90,0xFF,    // CFg
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
    0x83,0xAF,0x87,0xFF,    // brt
    0xC6,0x88,0xC7,0xFF,    // CAL
  #if OPT_DATE_FORMAT_SELECTABLE
    0xA1,0x88,0x87,0x86,    // DAtE
  #endif
  #if OPT_TEMP_UNITS_SELECTABLE
    0x87,0x86,0xC9,0x8C,    // TEMP
  #endif
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
