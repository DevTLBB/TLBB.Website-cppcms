#ifndef APP_CORE_ROUTE_H_
#define APP_CORE_ROUTE_H_
#include <cppcms/application.h>

namespace app
{
	namespace core
	{
		class Router : public cppcms::application
		{
		 public:
			Router(cppcms::service &s);

			virtual void main(std::string path);
		};
	}
}
#endif
