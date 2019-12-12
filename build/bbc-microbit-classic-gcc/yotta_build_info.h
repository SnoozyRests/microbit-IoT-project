#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 12 // UTC day 1-31
#define YOTTA_BUILD_HOUR 16 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 10 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 16 // UTC second 0-61
#define YOTTA_BUILD_UUID ee50790e-7dd7-4e14-9d35-558b672bfbbc // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 1a717a1966d9bf1677053e7183e524ee1f7c3a26 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 1a717a1 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
