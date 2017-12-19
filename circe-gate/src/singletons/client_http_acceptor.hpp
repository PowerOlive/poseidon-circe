// 这个文件是 Circe 服务器应用程序框架的一部分。
// Copyleft 2017, LH_Mouse. All wrongs reserved.

#ifndef CIRCE_GATE_SINGLETONS_CLIENT_HTTP_ACCEPTOR_HPP_
#define CIRCE_GATE_SINGLETONS_CLIENT_HTTP_ACCEPTOR_HPP_

#include "../client_http_session.hpp"

namespace Circe {
namespace Gate {

class ClientHttpAcceptor {
private:
	ClientHttpAcceptor();

public:
	static boost::shared_ptr<ClientHttpSession> get_session(const Poseidon::Uuid &session_uuid);
	static void insert_session(const boost::shared_ptr<ClientHttpSession> &session);
	static bool remove_session(const volatile ClientHttpSession *ptr) NOEXCEPT;
};

}
}

#endif
