#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 31 // UTC day 1-31
#define YOTTA_BUILD_HOUR 11 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 31 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 0 // UTC second 0-61
#define YOTTA_BUILD_UUID 4a8adbda-c16b-4576-afe2-c9d17a7c7075 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 0fbae12259ef36aa0f20e1fda94d15a38b1ce8d5 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 1 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 0fbae12 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
