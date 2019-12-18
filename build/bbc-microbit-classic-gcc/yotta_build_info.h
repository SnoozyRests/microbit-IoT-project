#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 18 // UTC day 1-31
#define YOTTA_BUILD_HOUR 14 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 57 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 53 // UTC second 0-61
#define YOTTA_BUILD_UUID f408a061-7e62-4b0b-a84c-4b5a53ca16ac // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID efd66750c4067972a6b4956b08639212636092a4 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION efd6675 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
