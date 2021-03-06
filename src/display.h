
#ifndef _DISPLAY_H
#define _DISPLAY_H

enum stateTable {
    // Regular display:
        stClock,
        stClockSeconds,

#if HAS_THERMISTOR
        stTemp,
#endif

#if OPT_TEMP_DSP
        stOptTemp,
#endif
#if OPT_DATE_DSP
        stOptDate,
#endif
#if OPT_DAY_DSP
        stOptDay,
#endif
    // setup/config:
        scSet,
        scBeep,
        scDsp,
        scCfg,
        // set:
        msClock,msClockHour,msClockMinute,msClockSeconds,
        msAlarm,msAlarmHour,msAlarmMinute,
        msChime,msChimeStartHour,msChimeStopHour,
#if OPT_DATE_DSP
        msDate,msDateMonth,msDateDay,msDateYear,
#endif
#if OPT_DAY_DSP
        msDay,msDayOfWeek,
#endif
    // beep:
        msAlarmOff,msAlarmOn,           // the next 5 states:
        msChimeOff,msChimeOn,           // OFF must preceed ON state
    // dsp:
#if OPT_TEMP_DSP
        msDspTempOff,msDspTempOn,       // due to assumuptions in
#endif
#if OPT_DATE_DSP
        msDateOff,msDateOn,             // in state change code
#endif
#if OPT_DAY_DSP
        msDayOff,msDayOn,
#endif
    // cfg:
#if OPT_UNITS_GROUP
        msSetUnits,msEU,msUS,
#else
  #if OPT_TIME_FORMAT_SELECTABLE
        msFormatTime,ms24,ms12,
  #endif
  #if OPT_TEMP_UNITS_SELECTABLE
        msTempUnits,msC,msF,
  #endif
  #if OPT_DATE_FORMAT_SELECTABLE
        msFormatDate,ms3112,ms1231,
  #endif
#endif
        msBrightness,msBrtMax,msBrtMin,
#if OPT_TEMP_DSP
        msTempCal,msSetTemp,
#endif
    // exit for all
        msExit
};

enum text2Entry {
    txClock,
    txAlarm,
#if !OPT_RUSSIAN_UI
    txChime,
#endif
#if OPT_DATE_DSP
    txDate,
#endif
#if OPT_DAY_DSP
    txDay,
#endif
#if OPT_TEMP_DSP
    txTemp,
#endif
#if OPT_UNITS_GROUP
    txUS,
    txEU,
#else
  #if OPT_TIME_FORMAT_SELECTABLE
    tx12,
    tx24,
  #endif
  #if OPT_TEMP_UNITS_SELECTABLE
    txF,
    txC,
  #endif
#endif
#if OPT_RUSSIAN_UI
    txSet,
#endif
    NoText2
    };

enum text4Entry {
// set stuff
#if !OPT_RUSSIAN_UI
    txSet,
#endif
    txBeep,
    txDsp,
    txCfg,
// config stuff
#if OPT_UNITS_GROUP
    txUnit,
#else
  #if OPT_TIME_FORMAT_SELECTABLE
    tx1224,
  #endif
  #if OPT_DATE_FORMAT_SELECTABLE
    tx1231,
    tx3112,
  #endif
#endif
    txBrt,
    txCal,
  #if OPT_DATE_FORMAT_SELECTABLE
    txDate4,
  #endif
  #if OPT_TEMP_UNITS_SELECTABLE
    txTemp4,
  #endif
#if OPT_RUSSIAN_UI
    txChime
#endif
    };

enum led_position { H10,H01,M10,M01 };
enum decimal_status { OFF, ON };

void updateClock();
void displayFSM();
void setupHour(uint8_t);

//void displayHours(__bit);
void displayHoursOn();
void displayHoursOff();
void displayHoursFlash();

//void displayMinutes(__bit);
void displayMinutesOn();
void displayMinutesOff();
void displayMinutesFlash();

void displayTemperature();
void displayDate();
void displayDayOfWeek();

void blankDisplay();
void displayUpdateISR();
void setChimeVars();
void getDateVars();
void setText2(uint8_t);
void setText2A(uint8_t);
void setText4(uint8_t);
void setMsgOn();
void setMsgOff();

uint8_t incrementHours(uint8_t);
uint8_t incrementMinutes(uint8_t);
uint8_t incrementYear(uint8_t);
uint8_t incrementDate(uint8_t,uint8_t);
uint8_t incrementDay(uint8_t);
uint8_t incrementBrightness(uint8_t);
uint8_t inc12(uint8_t);
uint8_t inc31(uint8_t);

#define segs CathodeBuf

// these two bits used to flash various things

extern __bit _1hzToggle;
extern __bit _5hzToggle;

extern volatile uint8_t userTimer3;         // decremented every 3ms by timer 0 task
extern volatile uint8_t userTimer100;       // decremented every 100ms by timer 0 task

// and access to the main data source

extern struct Clock clockRam;

// these are saved in DS1302 battery backed ram

extern __bit AlarmOn;     // alarm On/Off status
extern __bit ChimeOn;     // chime On/Off status
extern __bit TempOn;      // Temperature Display On/Off status
extern __bit DateOn;      // Date display On/Off status
extern __bit DowOn;       // Day of Week On/Off status
extern __bit Select_FC;   // select degrees F or C
extern __bit Select_MD;   // select month:day display format MM:DD or DD:MM
extern __bit Select_12;   // = 1 when 12 hr mode

#endif
