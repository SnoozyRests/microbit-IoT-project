#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 18 // UTC day 1-31
#define YOTTA_BUILD_HOUR 10 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 23 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 3 // UTC second 0-61
#define YOTTA_BUILD_UUID fd8da1ce-33bd-4af2-acdd-47daec601134 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 36fc6b7cbac6d0dc5e62497c923a7388931a7a9e // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 36fc6b7 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
