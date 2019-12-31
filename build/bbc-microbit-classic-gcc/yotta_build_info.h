#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 31 // UTC day 1-31
#define YOTTA_BUILD_HOUR 14 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 43 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 35 // UTC second 0-61
#define YOTTA_BUILD_UUID 56f894c2-70c2-4a53-a86f-22de547b3a21 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 58f4a2c5372cb5c596b3a5f9ee8c1100a61355e4 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 58f4a2c // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
