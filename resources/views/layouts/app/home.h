#ifndef RESOURCES_VIEWS_LAYOUTS_APP_HOME_H_
#define RESOURCES_VIEWS_LAYOUTS_APP_HOME_H_
#include <cppcms/view.h>
#include <string>
#include "../app.h"

namespace views
{
  namespace layouts
  {
    struct App;
    namespace app
    {
      struct Home : public views::layouts::App
      {
        // std::string title;
        // std::string text;
      };
    }
  }
}

#endif
