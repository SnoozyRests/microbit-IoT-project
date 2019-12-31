#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 31 // UTC day 1-31
#define YOTTA_BUILD_HOUR 13 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 56 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 1 // UTC second 0-61
#define YOTTA_BUILD_UUID cb4a1b08-b9f8-427a-a6a3-1dd5faaf9845 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 4ae3f4af9a373092c1650b0908fcd464667fb307 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 4ae3f4a // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
