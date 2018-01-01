// 这个文件是 Circe 服务器应用程序框架的一部分。
// Copyleft 2017 - 2018, LH_Mouse. All wrongs reserved.

#ifndef CIRCE_BOX_WEBSOCKET_SHADOW_SESSION_HPP_
#define CIRCE_BOX_WEBSOCKET_SHADOW_SESSION_HPP_

#include <poseidon/fwd.hpp>
#include <poseidon/virtual_shared_from_this.hpp>
#include <poseidon/uuid.hpp>
#include <poseidon/mutex.hpp>
#include <poseidon/websocket/status_codes.hpp>
#include <poseidon/websocket/opcodes.hpp>
#include <poseidon/stream_buffer.hpp>
#include <boost/container/deque.hpp>
#include <string>

namespace Circe {
namespace Box {

class WebSocketShadowSession : public virtual Poseidon::VirtualSharedFromThis {
private:
	class ShutdownJob;
	class DeliveryJob;

private:
	const Poseidon::Uuid m_foyer_uuid;
	const Poseidon::Uuid m_gate_uuid;
	const Poseidon::Uuid m_client_uuid;
	const std::string m_client_ip;

	volatile bool m_shutdown;

	mutable Poseidon::Mutex m_delivery_mutex;
	boost::shared_ptr<DeliveryJob> m_delivery_job_spare;
	bool m_delivery_job_active;
	boost::container::deque<std::pair<Poseidon::WebSocket::StatusCode, Poseidon::StreamBuffer> > m_messages_pending;

public:
	WebSocketShadowSession(const Poseidon::Uuid &foyer_uuid, const Poseidon::Uuid &gate_uuid, const Poseidon::Uuid &client_uuid, std::string client_ip);
	~WebSocketShadowSession() OVERRIDE;

public:
	const Poseidon::Uuid &get_foyer_uuid() const {
		return m_foyer_uuid;
	}
	const Poseidon::Uuid &get_gate_uuid() const {
		return m_gate_uuid;
	}
	const Poseidon::Uuid &get_client_uuid() const {
		return m_client_uuid;
	}
	const std::string &get_client_ip() const {
		return m_client_ip;
	}

	void on_sync_connect();
	void on_sync_receive(Poseidon::WebSocket::OpCode opcode, Poseidon::StreamBuffer payload);
	void on_sync_close(Poseidon::WebSocket::StatusCode status_code, const char *reason);

	bool has_been_shutdown() const;
	bool shutdown(Poseidon::WebSocket::StatusCode status_code, const char *reason = "") NOEXCEPT;
	bool send(Poseidon::WebSocket::OpCode opcode, Poseidon::StreamBuffer payload);
};

}
}

#endif