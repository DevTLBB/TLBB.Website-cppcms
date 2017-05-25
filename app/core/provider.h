#ifndef APP_CORE_PROVIDER_H_
#define APP_CORE_PROVIDER_H_
#include <cppcms/application.h>

namespace app
{
	namespace core
	{
		class Router;
		class Provider : public cppcms::application
		{
		 protected:
		 	Router &Route;
		 public:
			Provider(Router &s);

			virtual void main(std::string path);
		};
	}
}
#endif
