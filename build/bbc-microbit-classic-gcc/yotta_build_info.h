#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 16 // UTC day 1-31
#define YOTTA_BUILD_HOUR 16 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 36 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 36 // UTC second 0-61
#define YOTTA_BUILD_UUID 88114cc6-fa7b-4e92-8eb5-80ee7bd46452 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 6153f708b83c8ed9fc0559fffa21742b52147273 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 6153f70 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
