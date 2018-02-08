// 这个文件是 Circe 服务器应用程序框架的一部分。
// Copyleft 2017 - 2018, LH_Mouse. All wrongs reserved.

#ifndef CIRCE_PROTOCOL_PILOT_HPP_
#define CIRCE_PROTOCOL_PILOT_HPP_

#include <poseidon/cbpp/message_base.hpp>

namespace Circe {
namespace Protocol {
namespace Pilot {

// Constants for `lock_disposition`.
enum {
	LOCK_LEAVE_ALONE            =  0,
	LOCK_TRY_ACQUIRE_SHARED     = 11,
	LOCK_TRY_ACQUIRE_EXCLUSIVE  = 12,
	LOCK_RELEASE_SHARED         = 21,
	LOCK_RELEASE_EXCLUSIVE      = 22,
};

// Constants for `lock_state`.
enum {
	LOCK_FREE_FOR_ACQUISITION   =  0,
	LOCK_SHARED_BY_ME           = 30,
	LOCK_SHARED_BY_OTHERS       = 31,
	LOCK_EXCLUSIVE_BY_ME        = 40,
	LOCK_EXCLUSIVE_BY_OTHERS    = 41,
};

#define MESSAGE_NAME   CompareExchangeRequest
#define MESSAGE_ID     1101
#define MESSAGE_FIELDS \
	FIELD_BLOB         (key)	\
	FIELD_ARRAY        (criteria,	\
	  FIELD_STRING       (value_cmp)	\
	  FIELD_STRING       (value_new)	\
	)	\
	FIELD_VUINT        (lock_disposition)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   CompareExchangeResponse
#define MESSAGE_ID     1102
#define MESSAGE_FIELDS \
	FIELD_STRING       (value_old)	\
	FIELD_VUINT        (version_old)	\
	FIELD_VUINT        (succeeded)	\
	FIELD_VUINT        (criterion_index)	\
	FIELD_VUINT        (lock_state)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   ExchangeRequest
#define MESSAGE_ID     1103
#define MESSAGE_FIELDS \
	FIELD_BLOB         (key)	\
	FIELD_STRING       (value_new)	\
	FIELD_VUINT        (lock_disposition)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   ExchangeResponse
#define MESSAGE_ID     1104
#define MESSAGE_FIELDS \
	FIELD_STRING       (value_old)	\
	FIELD_VUINT        (version_old)	\
	FIELD_VUINT        (succeeded)	\
	FIELD_VUINT        (lock_state)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   AddWatchRequest
#define MESSAGE_ID     1105
#define MESSAGE_FIELDS \
	FIELD_BLOB         (key)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   AddWatchResponse
#define MESSAGE_ID     1106
#define MESSAGE_FIELDS \
	FIELD_FIXED        (watcher_uuid, 16)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   RemoveWatchNotification
#define MESSAGE_ID     1107
#define MESSAGE_FIELDS \
	FIELD_BLOB         (key)	\
	FIELD_FIXED        (watcher_uuid, 16)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   ValueChangeNotification
#define MESSAGE_ID     1108
#define MESSAGE_FIELDS \
	FIELD_FIXED        (watcher_uuid, 16)	\
	FIELD_STRING       (value_new)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

}
}
}

#endif
