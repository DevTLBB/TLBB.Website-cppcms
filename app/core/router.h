#ifndef APP_CORE_ROUTE_H_
#define APP_CORE_ROUTE_H_
#include <cppcms/application.h>
#include "../../routes/web.h"
#include "../../routes/api.h"

#include <stdio.h>
#include <cppcms/http_request.h>

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
