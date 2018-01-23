// 这个文件是 Circe 服务器应用程序框架的一部分。
// Copyleft 2017 - 2018, LH_Mouse. All wrongs reserved.

#include "precompiled.hpp"
#include "pilot_acceptor.hpp"
#include "servlet_container.hpp"
#include "common/interserver_acceptor.hpp"
#include "protocol/error_codes.hpp"
#include "../mmain.hpp"

namespace Circe {
namespace Pilot {

namespace {
	class SpecializedAcceptor : public Common::InterserverAcceptor {
	public:
		SpecializedAcceptor(std::string bind, boost::uint16_t port, std::string application_key)
			: Common::InterserverAcceptor(STD_MOVE(bind), port, STD_MOVE(application_key))
		{ }

	protected:
		boost::shared_ptr<const Common::InterserverServletCallback> sync_get_servlet(boost::uint16_t message_id) const OVERRIDE {
			return ServletContainer::get_servlet(message_id);
		}
	};

	boost::weak_ptr<SpecializedAcceptor> g_weak_acceptor;
}

MODULE_RAII_PRIORITY(handles, INIT_PRIORITY_LOW){
	PROFILE_ME;

	const AUTO(bind, get_config<std::string>("pilot_acceptor_bind"));
	const AUTO(port, get_config<boost::uint16_t>("pilot_acceptor_port"));
	const AUTO(appkey, get_config<std::string>("pilot_acceptor_appkey"));
	LOG_CIRCE_INFO("Initializing PilotAcceptor...");
	const AUTO(acceptor, boost::make_shared<SpecializedAcceptor>(bind, port, appkey));
	acceptor->activate();
	handles.push(acceptor);
	g_weak_acceptor = acceptor;
}

boost::shared_ptr<Common::InterserverConnection> PilotAcceptor::get_session(const Poseidon::Uuid &connection_uuid){
	PROFILE_ME;

	const AUTO(acceptor, g_weak_acceptor.lock());
	if(!acceptor){
		LOG_CIRCE_WARNING("PilotAcceptor has not been initialized.");
		return VAL_INIT;
	}
	return acceptor->get_session(connection_uuid);
}
std::size_t PilotAcceptor::get_all_sessions(boost::container::vector<boost::shared_ptr<Common::InterserverConnection> > &sessions_ret){
	PROFILE_ME;

	const AUTO(acceptor, g_weak_acceptor.lock());
	if(!acceptor){
		LOG_CIRCE_WARNING("PilotAcceptor has not been initialized.");
		return 0;
	}
	return acceptor->get_all_sessions(sessions_ret);
}
std::size_t PilotAcceptor::safe_broadcast_notification(const Poseidon::Cbpp::MessageBase &msg) NOEXCEPT {
	PROFILE_ME;

	const AUTO(acceptor, g_weak_acceptor.lock());
	if(!acceptor){
		LOG_CIRCE_WARNING("PilotAcceptor has not been initialized.");
		return 0;
	}
	return acceptor->safe_broadcast_notification(msg);
}
std::size_t PilotAcceptor::clear(long err_code, const char *err_msg) NOEXCEPT {
	PROFILE_ME;

	const AUTO(acceptor, g_weak_acceptor.lock());
	if(!acceptor){
		LOG_CIRCE_WARNING("PilotAcceptor has not been initialized.");
		return 0;
	}
	return acceptor->clear(err_code, err_msg);
}

}
}