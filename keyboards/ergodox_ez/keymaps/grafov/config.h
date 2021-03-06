#ifndef CONFIG_GRAFOV_H
#define CONFIG_GRAFOV_H

#include "../../config.h"

#define TAPPING_TERM 200

#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_DELAY             200 // 300
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         14 // 10
#define MOUSEKEY_TIME_TO_MAX       8  // 20
#define MOUSEKEY_WHEEL_MAX_SPEED   9  // 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 20 // 40
#define MOUSEKEY_WHEEL_DELAY       1

//#define ONESHOT_TAP_TOGGLE 2
//#define ONESHOT_TIMEOUT 3000

//#undef LOCKING_SUPPORT_ENABLE
//#undef LOCKING_RESYNC_ENABLE

//#undef LEADER_TIMEOUT
//#define LEADER_TIMEOUT 1000

//#define LSPO_KEY KC_A
//#define RSPC_KEY TO(2)

// https://github.com/qmk/qmk_firmware/issues/1958
#undef DEBOUNCE
#define DEBOUNCE 5

#endif


