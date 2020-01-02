#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 1 // UTC month 1-12
#define YOTTA_BUILD_DAY 2 // UTC day 1-31
#define YOTTA_BUILD_HOUR 15 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 32 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 0 // UTC second 0-61
#define YOTTA_BUILD_UUID b1619d92-658f-4583-8a34-cd78d2efba64 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID e5b43c593c84756e6a1476761fc0888be89849b8 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION e5b43c5 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
