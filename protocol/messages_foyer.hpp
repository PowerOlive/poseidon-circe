// 这个文件是 Circe 服务器应用程序框架的一部分。
// Copyleft 2017, LH_Mouse. All wrongs reserved.

#ifndef CIRCE_PROTOCOL_FOYER_HPP_
#define CIRCE_PROTOCOL_FOYER_HPP_

#include <poseidon/cbpp/message_base.hpp>

namespace Circe {
namespace Protocol {
namespace Foyer {

#define MESSAGE_NAME   HttpRequest
#define MESSAGE_ID     1201
#define MESSAGE_FIELDS \
	FIELD_FIXED        (client_uuid, 16)	\
	FIELD_STRING       (client_ip)	\
	FIELD_STRING       (auth_token)	\
	FIELD_VUINT        (verb)	\
	FIELD_STRING       (decoded_uri)	\
	FIELD_ARRAY        (params,	\
	  FIELD_STRING       (key)	\
	  FIELD_STRING       (value)	\
	)	\
	FIELD_ARRAY        (headers,	\
	  FIELD_STRING       (key)	\
	  FIELD_STRING       (value)	\
	)	\
	FIELD_FLEXIBLE     (entity)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   HttpResponse
#define MESSAGE_ID     1202
#define MESSAGE_FIELDS \
	FIELD_VUINT        (status_code)	\
	FIELD_ARRAY        (headers,	\
	  FIELD_STRING       (key)	\
	  FIELD_STRING       (value)	\
	)	\
	FIELD_FLEXIBLE     (entity)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   WebSocketEstablishmentRequest
#define MESSAGE_ID     1203
#define MESSAGE_FIELDS \
	FIELD_FIXED        (client_uuid, 16)	\
	FIELD_STRING       (client_ip)	\
	FIELD_STRING       (auth_token)	\
	FIELD_STRING       (decoded_uri)	\
	FIELD_ARRAY        (params,	\
	  FIELD_STRING       (key)	\
	  FIELD_STRING       (value)	\
	)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   WebSocketEstablishmentResponse
#define MESSAGE_ID     1204
#define MESSAGE_FIELDS \
	FIELD_VUINT        (status_code)	\
	FIELD_STRING       (reason)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   WebSocketClosureNotification
#define MESSAGE_ID     1205
#define MESSAGE_FIELDS \
	FIELD_FIXED        (client_uuid, 16)	\
	FIELD_VUINT        (status_code)	\
	FIELD_STRING       (reason)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   WebSocketKillRequest
#define MESSAGE_ID     1206
#define MESSAGE_FIELDS \
	FIELD_FIXED        (gate_uuid, 16)	\
	FIELD_FIXED        (client_uuid, 16)	\
	FIELD_VUINT        (status_code)	\
	FIELD_STRING       (reason)	\
	//
#include <poseidon/cbpp/message_generator.hpp>

#define MESSAGE_NAME   WebSocketKillResponse
#define MESSAGE_ID     1207
#define MESSAGE_FIELDS \
	//
#include <poseidon/cbpp/message_generator.hpp>

}
}
}

#endif