#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 19 // UTC day 1-31
#define YOTTA_BUILD_HOUR 16 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 4 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 11 // UTC second 0-61
#define YOTTA_BUILD_UUID 5a55defb-6891-48ab-9a7c-c26d7f24837c // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 5709e0b787d035b20174de8e2d2da3e6970ee513 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 5709e0b // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
