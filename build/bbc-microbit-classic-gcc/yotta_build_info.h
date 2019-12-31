#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 31 // UTC day 1-31
#define YOTTA_BUILD_HOUR 11 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 1 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 4 // UTC second 0-61
#define YOTTA_BUILD_UUID d9edd39f-9361-4f04-ac56-487f528f502a // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID d251e8d17e277a687e8317ac2aaba38cb76a82f2 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION d251e8d // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
