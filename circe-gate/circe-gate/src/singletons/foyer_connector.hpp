// 这个文件是 Circe 服务器应用程序框架的一部分。
// Copyleft 2017 - 2018, LH_Mouse. All wrongs reserved.

#ifndef CIRCE_GATE_SINGLETONS_FOYER_CONNECTOR_HPP_
#define CIRCE_GATE_SINGLETONS_FOYER_CONNECTOR_HPP_

#include "common/interserver_connection.hpp"

namespace Circe {
namespace Gate {

class Foyer_connector {
private:
	Foyer_connector();

public:
	static boost::shared_ptr<Common::Interserver_connection> get_client(const Poseidon::Uuid &connection_uuid);
	static std::size_t get_all_clients(boost::container::vector<boost::shared_ptr<Common::Interserver_connection> > &clients_ret);
	static std::size_t safe_broadcast_notification(const Poseidon::Cbpp::Message_base &msg) NOEXCEPT;
	static std::size_t clear(long err_code, const char *err_msg = "") NOEXCEPT;
};

}
}

#endif
