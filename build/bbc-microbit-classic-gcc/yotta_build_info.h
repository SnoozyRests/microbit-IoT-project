#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 11 // UTC month 1-12
#define YOTTA_BUILD_DAY 11 // UTC day 1-31
#define YOTTA_BUILD_HOUR 16 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 5 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 32 // UTC second 0-61
#define YOTTA_BUILD_UUID 5e011684-7202-4d13-97b3-71b0c78e10d1 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 9b939f0dd8f214a36d74371e935d419f2feb35fa // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 9b939f0 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
