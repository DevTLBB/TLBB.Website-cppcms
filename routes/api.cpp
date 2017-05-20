#include "api.h"

routes::API::API(cppcms::service &s) : cppcms::application(s)
{

}

void routes::API::main(std::string path)
{
	try
  {
    cppcms::application::main(path);
  }
	catch(std::exception &e)
	{
	
	}
}
