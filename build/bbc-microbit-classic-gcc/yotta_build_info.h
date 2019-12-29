#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 29 // UTC day 1-31
#define YOTTA_BUILD_HOUR 18 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 21 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 10 // UTC second 0-61
#define YOTTA_BUILD_UUID f1c76e84-1541-4ba4-bed1-47cbe9ad61c4 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID dfc803a931199341543811d57055e31dcc5ed5d8 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION dfc803a // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
