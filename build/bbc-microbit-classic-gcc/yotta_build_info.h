#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 12 // UTC day 1-31
#define YOTTA_BUILD_HOUR 14 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 14 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 33 // UTC second 0-61
#define YOTTA_BUILD_UUID c6008bb9-52e4-4027-a10d-bbbe78c5a49e // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID fb9dd6e22a6892ef2855a0420b951155670ce811 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION fb9dd6e // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
