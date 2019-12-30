#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 12 // UTC month 1-12
#define YOTTA_BUILD_DAY 30 // UTC day 1-31
#define YOTTA_BUILD_HOUR 18 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 3 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 32 // UTC second 0-61
#define YOTTA_BUILD_UUID c177209d-96fb-4ea1-bf36-ddc16139ee01 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 9dace01442715b211bf36fad90a3730ad043dba9 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 9dace01 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
