#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include "core/router.h"

int main(int argc, char **argv)
{
  try
  {
    cppcms::service srv(argc, argv);
    srv.applications_pool().mount(
      cppcms::applications_factory<app::core::Router>()
    );
    srv.run();
  }
  catch(std::exception const &e)
  {
    std::cerr << "Failed: " << e.what() << std::endl;
    std::cerr << booster::trace(e) << std::endl;
    return 1;
  }
  return 0;
}
